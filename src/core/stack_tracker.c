#include <string.h>
#include "stack.h"

void scan_user(User *u, char *username, char *ip, int status) {
    if (strcmp(u->username, username) != 0 &&
        strcmp(u->ip, ip) != 0)
        return;

    if (status == 1) {
        u->top = -1;
        return;
    }

    u->fail_count++;
    if (u->top < MAX_FAILURES - 1)
        u->stack[++u->top] = 0;
    else
        u->flagged = 1;
}
