#ifndef LOGIN_H
#define LOGIN_H

typedef struct Login {
    char timestamp[20];
    char username[10];
    char ip[15];
    int status;
    struct Login *next;
} Login;

Login *create_node(char *, char *, char *, int);
void add_at_end(Login *, Login *);
void print_logs(Login *);

#endif
