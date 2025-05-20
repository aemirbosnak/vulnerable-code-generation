//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXN 1000
#define MAXM (MAXN * MAXN)
#define MAXK 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n, m, k;
int graph[MAXN][MAXN];
int color[MAXN];
int count = 0;

void dfs(int v) {
    color[v] = GRAY;
    count++;
    int u;
    for (u = 0; u < n; u++) {
        if (graph[v][u] == 1) {
            if (color[u] == WHITE) {
                dfs(u);
            } else if (color[u] == GRAY) {
                fprintf(stderr, "Cycle detected at vertex %d\n", v);
                exit(1);
            }
        }
    }
    color[v] = BLACK;
    count--;
}

int main(int argc, char *argv[]) {
    srand(time(NULL));
    scanf("%d %d %d", &n, &m, &k);
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            graph[i][j] = rand() % 2;
        }
    }
    for (i = 0; i < n; i++) {
        color[i] = WHITE;
    }
    int num_colors = 0;
    while (count < k) {
        int v = rand() % n;
        if (color[v] == WHITE) {
            dfs(v);
            num_colors++;
        }
    }
    printf("Minimum number of colors required: %d\n", num_colors);
    return 0;
}