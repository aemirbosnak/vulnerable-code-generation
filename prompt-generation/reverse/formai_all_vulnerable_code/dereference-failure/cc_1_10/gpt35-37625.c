//FormAI DATASET v1.0 Category: Graph representation ; Style: Linus Torvalds
#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTICES 50
#define FALSE 0
#define TRUE 1

struct Graph {
    int numVertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
};

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    int i, j;
    for(i=0; i<vertices; i++) {
        for(j=0; j<vertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = TRUE;
    graph->adjMatrix[dest][src] = TRUE;
}

void removeEdge(struct Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = FALSE;
    graph->adjMatrix[dest][src] = FALSE;
}

void printGraph(struct Graph* graph) {
    int i, j;
    for(i=0; i<graph->numVertices; i++) {
        printf("Vertex %d: ", i);
        for(j=0; j<graph->numVertices; j++) {
            if(graph->adjMatrix[i][j]) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

int main() {
    struct Graph* graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printf("Initial Graph: \n");
    printGraph(graph);

    removeEdge(graph, 1, 4);

    printf("\nGraph after removing edge between vertices 1 and 4: \n");
    printGraph(graph);

    return 0;
}