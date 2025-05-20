//FormAI DATASET v1.0 Category: Graph representation ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>

struct graph{
    int V; //No of vertices
    int E; //No of edges
    int** adjacencyMatrix; //2D array to store edges
};

//Function to create a graph with V vertices and E edges
struct graph* createGraph(int V, int E) {
    int i,j;
    struct graph* G = malloc(sizeof(struct graph));
    G->V = V;
    G->E = E;
    
    //Allocating memory to adjacency matrix
    G->adjacencyMatrix = malloc(V * sizeof(int*));
    for(i=0; i<V; i++){
        G->adjacencyMatrix[i] = malloc(V * sizeof(int));
        for(j=0; j<V; j++){
            G->adjacencyMatrix[i][j] = 0;
        }
    }
    return G;
}

//Function to add an edge to the graph
void addEdge(struct graph* G, int u, int v){
    G->adjacencyMatrix[u][v] = 1;
    G->adjacencyMatrix[v][u] = 1;
}

//Function to print the adjacency matrix of the graph
void printGraph(struct graph* G){
    int i,j;
    for(i=0;i<G->V;i++){
        for(j=0;j<G->V;j++){
            printf("%d ",G->adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

//Main function
int main(){
    int V = 5; //No of vertices
    int E = 6; //No of edges
    struct graph* G = createGraph(V, E);
    addEdge(G, 0, 1);
    addEdge(G, 0, 4);
    addEdge(G, 1, 2);
    addEdge(G, 1, 3);
    addEdge(G, 1, 4);
    addEdge(G, 2, 3);
    printGraph(G);
    return 0;
}