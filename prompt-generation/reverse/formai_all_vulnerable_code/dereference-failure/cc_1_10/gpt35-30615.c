//FormAI DATASET v1.0 Category: Graph representation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

typedef struct Graph {
    int edges[MAX_NODES][MAX_NODES];
    int num_nodes;
} Graph;

Graph* createGraph(int nodes) {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->num_nodes = nodes;
    int i,j;
    for(i=0;i<g->num_nodes;i++) {
        for(j=0;j<g->num_nodes;j++) {
            g->edges[i][j] = 0;
        }
    }
    return g;
}

void addEdge(Graph* g, int source, int destination) {
    if(source >= g->num_nodes || destination >= g->num_nodes) {
        printf("Node does not exist\n");
    } else {
        g->edges[source][destination] = 1;
    }
}

void printGraph(Graph* g) {
    printf("Nodes: %d\n", g->num_nodes);
    int i,j;
    for(i=0;i<g->num_nodes;i++) {
        for(j=0;j<g->num_nodes;j++) {
            printf("%d ", g->edges[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Graph* g = createGraph(5);
    addEdge(g,0,1);
    addEdge(g,2,4);
    addEdge(g,3,1);
    addEdge(g,4,0);
    addEdge(g,1,2);
    printGraph(g);
    return 0;
}