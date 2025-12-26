#include "sort.h"

void bubble_sort(User *u, int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (u[j].fail_count < u[j+1].fail_count) {
                User t = u[j];
                u[j] = u[j+1];
                u[j+1] = t;
            }
}
