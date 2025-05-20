//FormAI DATASET v1.0 Category: Graph representation ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define TRUE 1
#define FALSE 0

typedef struct {
    int destination;
    int weight;
    struct EdgeNode* next;
} EdgeNode;

typedef struct {
    EdgeNode *adjList[MAX_VERTICES];
    int visited[MAX_VERTICES];
} Graph;

void insertEdge(Graph *g, int u, int v, int weight) {
    EdgeNode *e = (EdgeNode*)malloc(sizeof(EdgeNode));
    e->destination = v;
    e->weight = weight;
    e->next = g->adjList[u];
    g->adjList[u] = e;
}

void printGraph(Graph *g, int n) {
    EdgeNode *e;
    for (int i = 1; i <= n; i++) {
        printf("Vertex %d: ", i);
        e = g->adjList[i];
        while (e != NULL) {
            printf("%d (%d) ", e->destination, e->weight);
            e = e->next;
        }
        printf("\n");
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Graph *g = (Graph*)malloc(sizeof(Graph));
    for (int i = 1; i <= n; i++) {
        g->visited[i] = FALSE;
        g->adjList[i] = NULL;
    }

    int u, v, weight;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &weight);
        insertEdge(g, u, v, weight);
    }

    printGraph(g, n);

    return 0;
}