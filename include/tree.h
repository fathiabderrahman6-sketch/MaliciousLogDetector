#ifndef TREE_H
#define TREE_H

typedef struct Node {
    char label[15];
    struct Node *left, *right;
} Node;

Node *create_node(char *);
void classify(int fail_count);

#endif
