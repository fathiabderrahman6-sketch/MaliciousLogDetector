#include <stdio.h>
#include "graph.h"

void add_edge(int g[MAX][MAX], int u, int v) {
    g[u][v] = g[v][u] = 1;
}

void bfs(int g[MAX][MAX], int start, int n) {
    int q[MAX], vis[MAX]={0};
    int f=0, r=0;
    q[r++] = start;
    vis[start] = 1;

    while (f < r) {
        int u = q[f++];
        printf("Visited node %d\n", u);
        for (int v=0; v<n; v++)
            if (g[u][v] && !vis[v]) {
                vis[v]=1;
                q[r++]=v;
            }
    }
}
