//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define V 9
#define C 4

int n, m, i, j, k, l, u, v, w, color[V], graph[V][V], parent[V], depth[V], dfs_num[V], dfs_low[V], scc_num;
int *stack, top;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

void init() {
    for (i = 0; i < V; i++)
        graph[i][i] = 1;
}

void add_edge(int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

void dfs(int v, int c) {
    static int time = 0;
    int i;
    color[v] = c;
    dfs_low[v] = depth[v] = ++time;
    scc_num++;
    stack[++top] = v;
    for (i = 0; i < V; i++)
        if (graph[v][i] &&!color[i]) {
            parent[i] = v;
            if (depth[v] < depth[i])
                dfs_low[v] = depth[i];
            push(i);
        }
}

void kosaraju() {
    int i, j, k, l, u, v, w;
    for (i = 0; i < V; i++)
        if (!color[i])
            dfs(i, ++scc_num);
    for (i = V - 1; i >= 0; i--) {
        v = stack[i];
        for (j = 0; j < V; j++)
            if (parent[j] == v && color[j] == scc_num) {
                color[j] = ++scc_num;
                push(j);
            }
    }
}

int main() {
    int i, j, k, l, u, v, w;
    init();
    for (i = 0; i < V; i++)
        for (j = i + 1; j < V; j++)
            add_edge(i, j);
    for (i = 0; i < V; i++)
        if (!color[i])
            dfs(i, ++scc_num);
    printf("Number of SCCs = %d\n", scc_num);
    return 0;
}