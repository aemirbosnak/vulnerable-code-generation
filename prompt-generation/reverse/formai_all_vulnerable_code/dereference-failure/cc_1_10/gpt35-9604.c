//FormAI DATASET v1.0 Category: Graph representation ; Style: bold
#include<stdio.h>
#include<stdlib.h>

//creating the graph structure 
typedef struct Graph {
    int V; //no of vertices in the graph
    int E; //no of edges in the graph
    int **adjMatrix; //2D array to store the graph
}Graph;

//function to create a new graph
Graph * createGraph(int V, int E){
    int i, j;
    Graph *G = (Graph*)malloc(sizeof(Graph)); // allocating memory to the graph structure 
    G->V = V; //assigning the no of vertices of graph
    G->E = E; //assigning the no of edges of graph
    G->adjMatrix = (int**)malloc(sizeof(int*) * V); //allocating memory to the adjacency matrix
    for(i = 0; i < V; i++){
        G->adjMatrix[i] = (int*)malloc(sizeof(int) * V); //allocating memory to the columns of the matrix
        for(j = 0; j < V; j++){
            G->adjMatrix[i][j] = 0; //initializing the values of the adjacency matrix to 0
        }
    }
    return G; //returning the graph
}

//function to add edge in the graph
void addEdge(Graph* G, int u, int v){
    G->adjMatrix[u][v] = 1; //setting the value of edge to 1
    G->adjMatrix[v][u] = 1; //graph is undirected, thus setting both values
}

//function to print the graph
void printGraph(Graph* G){
    int i, j;
    printf("The Graph Represented in Adjacency Matrix:\n");
    for(i = 0; i < G->V; i++){
        for(j = 0; j < G->V; j++){
            printf("%d ", G->adjMatrix[i][j]); //printing the adjacency matrix values
        }
        printf("\n");
    }
}

//main function
int main(){
    Graph* G = createGraph(5,7); //creating a new graph with 5 vertices and 7 edges
    addEdge(G,0,1); //adding edges in the graph
    addEdge(G,1,2);
    addEdge(G,2,3);
    addEdge(G,3,4);
    addEdge(G,4,0);
    addEdge(G,1,4);
    addEdge(G,2,4);
    printGraph(G); //printing the graph
    return 0; //Terminating the program
}