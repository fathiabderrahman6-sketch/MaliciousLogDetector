#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "login.h"

Login *create_node(char *timestamp, char *username, char *ip, int status) {
    Login *n = malloc(sizeof(Login));
    strcpy(n->timestamp, timestamp);
    strcpy(n->username, username);
    strcpy(n->ip, ip);
    n->status = status;
    n->next = NULL;
    return n;
}

void add_at_end(Login *head, Login *new_node) {
    Login *t = head;
    while (t->next) t = t->next;
    t->next = new_node;
}

void print_logs(Login *head) {
    while (head) {
        printf("%s %s %s %s\n",
               head->timestamp,
               head->username,
               head->ip,
               head->status ? "SUCCESS" : "FAIL");
        head = head->next;
    }
}
