#include <string.h>
#include "search.h"

int linear_search(Blacklist *b, int n, char *u) {
    for (int i = 0; i < n; i++)
        if (!strcmp(b[i].username, u)) return 1;
    return 0;
}

void sort_blacklist(Blacklist *b, int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (strcmp(b[j].username, b[j+1].username) > 0) {
                Blacklist t = b[j];
                b[j] = b[j+1];
                b[j+1] = t;
            }
}

int binary_search(Blacklist *b, int n, char *u) {
    int l = 0, r = n-1;
    while (l <= r) {
        int m = (l+r)/2;
        int c = strcmp(b[m].username, u);
        if (c == 0) return 1;
        if (c < 0) l = m + 1;
        else r = m - 1;
    }
    return 0;
}
