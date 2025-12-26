#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "login.h"
#include "stack.h"
#include "sort.h"
#include "search.h"
#include "tree.h"

#define MAX_USERS 100

User users[MAX_USERS];
int user_count = 0;

/* Trouver ou créer utilisateur */
int find_or_create_user(char *username, char *ip) {
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0 ||
            strcmp(users[i].ip, ip) == 0)
            return i;
    }

    strcpy(users[user_count].username, username);
    strcpy(users[user_count].ip, ip);
    users[user_count].top = -1;
    users[user_count].fail_count = 0;
    users[user_count].flagged = 0;
    return user_count++;
}

int main() {
    FILE *file = fopen("logs.csv", "r");
    if (!file) {
        printf("Erreur: impossible d'ouvrir logs.csv\n");
        return 1;
    }

    char line[100];
    fgets(line, sizeof(line), file); // ignorer header

    Login *head = NULL;

    while (fgets(line, sizeof(line), file)) {
        char *token;
        char timestamp[20], username[10], ip[15];
        int status;

        line[strcspn(line, "\n")] = '\0';

        token = strtok(line, ",");
        strcpy(timestamp, token);

        token = strtok(NULL, ",");
        strcpy(username, token);

        token = strtok(NULL, ",");
        strcpy(ip, token);

        token = strtok(NULL, ",");
        status = atoi(token);

        Login *node = create_node(timestamp, username, ip, status);
        if (!head) head = node;
        else add_at_end(head, node);

        int idx = find_or_create_user(username, ip);
        scan_user(&users[idx], username, ip, status);
    }

    fclose(file);

    int choice;
    while (1) {
        printf("\n====== Malicious Login Detector ======\n");
        printf("1. Afficher les logs\n");
        printf("2. Utilisateurs suspects\n");
        printf("3. Ranking (failures)\n");
        printf("4. Blacklist check\n");
        printf("5. Classification\n");
        printf("6. Quitter\n");
        printf("Choix: ");
        scanf("%d", &choice);

        if (choice == 1) {
            print_logs(head);
        }

        else if (choice == 2) {
            for (int i = 0; i < user_count; i++) {
                if (users[i].flagged)
                    printf("Suspect: %s (%d fails)\n",
                           users[i].username,
                           users[i].fail_count);
            }
        }

        else if (choice == 3) {
            bubble_sort(users, user_count);
            for (int i = 0; i < user_count; i++) {
                printf("%s -> %d fails\n",
                       users[i].username,
                       users[i].fail_count);
            }
        }

        else if (choice == 4) {
            Blacklist bl[50];
            int bcount = 0;

            for (int i = 0; i < user_count; i++) {
                if (users[i].fail_count >= 5) {
                    strcpy(bl[bcount++].username,
                           users[i].username);
                }
            }

            char name[10];
            printf("Username à chercher: ");
            scanf("%s", name);

            sort_blacklist(bl, bcount);
            if (binary_search(bl, bcount, name))
                printf("❌ BLACKLISTED\n");
            else
                printf("✅ Autorisé\n");
        }

        else if (choice == 5) {
            for (int i = 0; i < user_count; i++) {
                printf("%s => ", users[i].username);
                classify(users[i].fail_count);
            }
        }

        else if (choice == 6) {
            printf("Fin du programme.\n");
            break;
        }

        else {
            printf("Choix invalide.\n");
        }
    }

    return 0;
}
