//FormAI DATASET v1.0 Category: Graph representation ; Style: recursive
#include<stdio.h>
#include<stdlib.h>

struct Graph{
    int vertices;
    int **adjMatrix;
};

// function prototype
struct Graph* createGraph(int vertices);
void addEdge(struct Graph *graph, int src, int dest);
void printGraph(struct Graph *graph);

int main(){
    int vertices = 5; // for 5 vertices
    struct Graph *graph = createGraph(vertices);

    //generating edge
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printf("Graph: \n\n");
    
    //printing the adjacency Matrix
    printGraph(graph);

	return 0;
}

struct Graph* createGraph(int vertices){
    struct Graph *graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    graph->adjMatrix = (int**) malloc(vertices * sizeof(int*));

    for(int i = 0; i < vertices; i++){
        graph->adjMatrix[i] = (int*) malloc(vertices * sizeof(int));
        for(int j = 0; j < vertices; j++){
            graph->adjMatrix[i][j] = 0;
        }
    }

    return graph;
}

//function to add edge between two vertices
void addEdge(struct Graph *graph, int src, int dest){
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1;
}

void printGraph(struct Graph *graph){
    for(int i = 0; i < graph->vertices; i++){
        for(int j = 0; j < graph->vertices; j++){
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}