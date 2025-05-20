//FormAI DATASET v1.0 Category: Graph representation ; Style: modular
#include <stdio.h>
#include <stdlib.h>

struct Graph {
    int V;
    int E;
    int **adj;
};

struct Graph *create_graph(int V, int E) {
    struct Graph *G = (struct Graph *) malloc(sizeof(struct Graph));
    G->V = V;
    G->E = E;
    G->adj = (int **) malloc(V*sizeof(int *));
    for(int i=0; i<V; i++) {
        G->adj[i] = (int *) malloc(V*sizeof(int));
        for(int j=0; j<V; j++) {
            G->adj[i][j] = 0;
        }
    }
    return G;
}

void add_edge(struct Graph *G, int src, int dest) {
    G->adj[src][dest] = 1;
    G->adj[dest][src] = 1;
}

void print_graph(struct Graph *G) {
    for(int i=0; i<G->V; i++) {
        printf("Adjacent vertices of vertex %d: ", i);
        for(int j=0; j<G->V; j++) {
            if(G->adj[i][j] == 1) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

int main() {
    int V, E;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);
    struct Graph *G = create_graph(V, E);
    printf("Enter edges:\n");
    for(int i=0; i<E; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        add_edge(G, src, dest);
    }
    printf("\n");
    print_graph(G);
    return 0;
}