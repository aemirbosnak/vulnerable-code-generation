//FormAI DATASET v1.0 Category: Graph representation ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#define MAX 200

typedef struct graph {
    int v;
    int e;
    int **adjMatrix;
}Graph;

Graph *createGraph(int vertices, int edges) {
    Graph *G = (Graph*)malloc(sizeof(Graph));
    G->v = vertices;
    G->e = edges;
    G->adjMatrix = (int**)malloc(sizeof(int*) * vertices);

    for(int i = 0; i < vertices; i++) {
        G->adjMatrix[i] = (int*)malloc(sizeof(int) * vertices);

        for(int j = 0; j < vertices; j++) {
            G->adjMatrix[i][j] = 0;
        }
    }
    return G;
}

void addEdge(Graph *G, int u, int v) {
    G->adjMatrix[u][v] = 1;
    G->adjMatrix[v][u] = 1;
}

void printGraph(Graph *G) {
    for(int i = 0; i < G->v; i++) {
        for(int j = 0; j < G->v; j++) {
            printf("%d ", G->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int vertices, edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    Graph *G = createGraph(vertices, edges);

    int u, v;
    printf("Enter the pairs of vertices for each edge:\n");

    for(int i = 0; i < edges; i++) {
        printf("Edge %d: ", i + 1);
        scanf("%d %d", &u, &v);
        addEdge(G, u - 1, v - 1);
    }

    printf("The Adjacency Matrix Representation of the Graph: \n");
    printGraph(G);

    return 0;
}