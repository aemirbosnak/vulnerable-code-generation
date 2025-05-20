//FormAI DATASET v1.0 Category: Graph representation ; Style: satisfied
#include<stdio.h>

//Structure for a Graph
struct Graph {
    int vertexCount; //Number of vertices in the graph
    int** adjMatrix; //Adjacency matrix of the graph
};

//Creates a new graph with given number of vertices
struct Graph* createGraph(int vertexCount) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->vertexCount = vertexCount;

    //Allocate memory for adjacency matrix
    graph->adjMatrix = (int**) malloc(vertexCount * sizeof(int*));
    int i;
    for(i=0; i<vertexCount; i++) {
        graph->adjMatrix[i] = (int*) malloc(vertexCount * sizeof(int));
        int j;
        for(j=0; j<vertexCount; j++) {
            graph->adjMatrix[i][j] = 0; //Initialize all values to 0
        }
    }

    return graph;
}

//Function to add an edge to the graph
void addEdge(struct Graph* graph, int srcVertex, int destVertex) {
    graph->adjMatrix[srcVertex][destVertex] = 1;
    graph->adjMatrix[destVertex][srcVertex] = 1;
}

//Function to print the graph
void printGraph(struct Graph* graph) {
    int i,j;
    for(i=0; i<graph->vertexCount; i++) {
        for(j=0; j<graph->vertexCount; j++) {
            printf("%d ",graph->adjMatrix[i][j]);
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

    printGraph(graph);

    return 0;
}