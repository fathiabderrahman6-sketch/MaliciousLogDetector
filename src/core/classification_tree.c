#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

Node *create_node(char *label) {
    Node *n = malloc(sizeof(Node));
    strcpy(n->label, label);
    n->left = n->right = NULL;
    return n;
}

void classify(int fails) {
    if (fails == 0) printf("NORMAL\n");
    else if (fails < 5) printf("SUSPICIOUS\n");
    else printf("ATTACK\n");
}
