//FormAI DATASET v1.0 Category: Graph representation ; Style: systematic
#include<stdio.h>
#include<stdlib.h>

struct Graph{
    int V;          //Number of vertices
    int E;          //Number of Edges
    int **AdjMat;   //2D matrix for adjacency matrix representation
};
typedef struct Graph Graph;

Graph* createGraph(int V){
    Graph* G = (Graph*)malloc(sizeof(Graph));       //Dynamic memory allocation for graph
    if(!G){
        printf("Graph memory allocation error!");
        return NULL;
    }
    G->V = V;                       //Assigning value of vertices to graph
    G->E = 0;                       //Initializing edges as zero
    G->AdjMat = (int**)malloc(sizeof(int*)*V);    //Dynamic memory allocation for adjacency matrix of graph
    if(!G->AdjMat){
        printf("Graph adjacency matrix memory allocation error!");
        return NULL;
    }
    for(int i=0;i<V;i++){
        G->AdjMat[i] = (int*)calloc(V,sizeof(int));   //Allocating memory for each row of adjacency matrix
        if(!G->AdjMat[i]){
            printf("Error allocating memory!");
            return NULL;
        }
    }
    return G;
}

void insertEdge(Graph* G,int u,int v){
    G->AdjMat[u][v] = 1;                //Marking the edge as present in adjacency matrix
    G->AdjMat[v][u] = 1;                //Undirected graph, so marking both edge present
    G->E++;                             //Increasing edge count
}

void displayGraph(Graph* G){
    printf("Adjacency matrix representation:\n");
    for(int i=0;i<G->V;i++){
        for(int j=0;j<G->V;j++){
            printf("%d ",G->AdjMat[i][j]);  //Printing adjacency matrix
        }
        printf("\n");
    }
}

void destroyGraph(Graph* G){
    for(int i=0;i<G->V;i++){
        free(G->AdjMat[i]);         //Deallocating memory for each row of adjacency matrix of graph
    }
    free(G->AdjMat);                //Deallocating memory for adjacency matrix of graph
    free(G);                        //Deallocating memory for graph itself
}

int main(){
    Graph* G = createGraph(5);          //Creating graph with 5 vertices

    //Adding edges to the graph
    insertEdge(G,0,1);
    insertEdge(G,0,2);
    insertEdge(G,1,2);
    insertEdge(G,1,3);
    insertEdge(G,2,4);
    insertEdge(G,3,4);

    displayGraph(G);                   //Displaying the graph in adjacency matrix representation

    destroyGraph(G);                   //Deallocating memory for graph

    return 0;
}