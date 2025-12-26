#ifndef STACK_H
#define STACK_H

#define MAX_FAILURES 5

typedef struct {
    char username[10];
    char ip[15];
    int stack[MAX_FAILURES];
    int top;
    int fail_count;
    int flagged;
} User;

void scan_user(User *, char *, char *, int);

#endif
