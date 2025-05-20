//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: recursive
#include<stdio.h>
#include<stdlib.h>

struct Graph{
    int vertices;
    int edges;
    int **adjList;
};

void addEdge(struct Graph *g, int v1, int v2) {
    g->adjList[v1] = realloc(g->adjList[v1], sizeof(int)*(g->edges+1));
    g->adjList[v2] = realloc(g->adjList[v2], sizeof(int)*(g->edges+1));
    g->adjList[v1][g->edges] = v2;
    g->adjList[v2][g->edges] = v1;
    g->edges++;
}

void printGraph(struct Graph *g) {
    for (int i=0; i<g->vertices; i++) {
        printf("%d ", i);
        for (int j=0; j<g->edges; j++) {
            if (g->adjList[i][j]!= -1) {
                printf("%d ", g->adjList[i][j]);
            }
        }
        printf("\n");
    }
}

void createGraph(struct Graph *g, int vertices, int edges) {
    g->vertices = vertices;
    g->edges = edges;
    g->adjList = (int **)malloc(vertices * sizeof(int*));
    for (int i=0; i<vertices; i++) {
        g->adjList[i] = (int *)malloc(edges * sizeof(int));
        for (int j=0; j<edges; j++) {
            g->adjList[i][j] = -1;
        }
    }
}

void dfs(struct Graph *g, int v) {
    printf("%d ", v);
    for (int i=0; i<g->vertices; i++) {
        if (g->adjList[v][i]!= -1) {
            dfs(g, g->adjList[v][i]);
        }
    }
}

void bfs(struct Graph *g, int start) {
    int visited[g->vertices];
    int queue[g->vertices];
    int front = 0, rear = 0;
    visited[start] = 1;
    queue[rear++] = start;
    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);
        for (int i=0; i<g->vertices; i++) {
            if (g->adjList[v][i]!= -1 &&!visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    struct Graph g;
    createGraph(&g, 5, 4);
    addEdge(&g, 0, 1);
    addEdge(&g, 0, 2);
    addEdge(&g, 1, 3);
    addEdge(&g, 1, 4);
    addEdge(&g, 2, 3);
    addEdge(&g, 2, 4);
    printGraph(&g);
    dfs(&g, 0);
    printf("\n");
    bfs(&g, 1);
    printf("\n");
    return 0;
}