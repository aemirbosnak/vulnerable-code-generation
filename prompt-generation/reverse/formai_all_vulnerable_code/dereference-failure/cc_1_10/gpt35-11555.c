//FormAI DATASET v1.0 Category: Graph representation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

struct Graph{
    int numVertices;
    int **adjList;
};

struct Graph* createGraph(int numVertices){
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph -> numVertices = numVertices;

    graph -> adjList = malloc(numVertices * sizeof(int*));

    int i;
    for(i = 0; i < numVertices; i++){
        graph -> adjList[i] = malloc(numVertices * sizeof(int));
        int j;
        for(j = 0; j < numVertices; j++){
            graph -> adjList[i][j] = 0;
        }
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest){
    graph -> adjList[src][dest] = 1;
    graph -> adjList[dest][src] = 1;
}

void printGraph(struct Graph* graph){
    int i, j;
    for(i = 0; i < graph -> numVertices; i++){
        printf("Node %d: ", i);
        for(j = 0; j < graph -> numVertices; j++){
            if(graph -> adjList[i][j] == 1){
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

int main(){
    int numVertices = 5;
    struct Graph* graph = createGraph(numVertices);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph);

    return 0;
}