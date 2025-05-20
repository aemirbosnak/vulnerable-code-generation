//FormAI DATASET v1.0 Category: Graph representation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 6

struct Graph {
    int num_vertices;
    int **adj_matrix;
};

struct Graph *createGraph() {
    struct Graph *G = (struct Graph*) malloc(sizeof(struct Graph));
    if(G == NULL) exit(1);

    G->num_vertices = MAX_VERTICES;
    G->adj_matrix = (int **) calloc(MAX_VERTICES, sizeof(int*));
    if(G->adj_matrix == NULL) exit(1);

    for(int i=0; i<MAX_VERTICES; i++) {
        G->adj_matrix[i] = (int*) calloc(MAX_VERTICES, sizeof(int));
        if(G->adj_matrix[i] == NULL) exit(1);
    }
    return G;
}

void deleteGraph(struct Graph *G) {
    for(int i=0; i<MAX_VERTICES; i++) {
        free(G->adj_matrix[i]);
    }
    free(G->adj_matrix);
    free(G);
}

void addEdge(struct Graph *G, int src, int dest) {
    G->adj_matrix[src][dest] = 1;
    G->adj_matrix[dest][src] = 1;
}

void printGraph(struct Graph *G) {
    printf("Graph Representation:\n");
    printf("   ");
    for(int i=0; i<G->num_vertices; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for(int i=0; i<G->num_vertices; i++) {
        printf("%d: ", i);
        for(int j=0; j<G->num_vertices; j++) {
            printf("%d ", G->adj_matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    struct Graph *G;
    G = createGraph();

    addEdge(G, 0, 1);
    addEdge(G, 0, 3);
    addEdge(G, 1, 2);
    addEdge(G, 1, 4);
    addEdge(G, 2, 5);
    addEdge(G, 3, 4);
    addEdge(G, 4, 5);

    printGraph(G);

    deleteGraph(G);
    return 0;
}