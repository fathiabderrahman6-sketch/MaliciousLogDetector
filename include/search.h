#ifndef SEARCH_H
#define SEARCH_H

typedef struct {
    char username[10];
} Blacklist;

int linear_search(Blacklist *, int, char *);
int binary_search(Blacklist *, int, char *);
void sort_blacklist(Blacklist *, int);

#endif
