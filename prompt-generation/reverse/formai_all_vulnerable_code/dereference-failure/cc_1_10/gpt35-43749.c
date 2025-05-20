//FormAI DATASET v1.0 Category: Graph representation ; Style: accurate
#include<stdio.h>
#include<stdlib.h>

struct Graph{
    int V;
    int E;
    int **Adj;
};

struct Graph* createGraph(int V, int E){
    struct Graph* G = (struct Graph*) malloc(sizeof(struct Graph));

    G->V = V;
    G->E = E;

    G->Adj = (int**) malloc(V * sizeof(int*));

    for(int i = 0; i < V; i++){
        G->Adj[i] = (int*) calloc(V, sizeof(int));
    }

    return G;
}

void addEdge(struct Graph* G, int u, int v, int w){
    G->Adj[u][v] = w;
    G->Adj[v][u] = w; //If undirected graph
}

void displayGraph(struct Graph* G){
    printf("\nThe Adjacency Matrix:\n");
    for(int i = 0; i < G->V; i++){
        for(int j = 0; j < G->V; j++){
            printf("%d ", G->Adj[i][j]);
        }
        printf("\n");
    }
}

int main(){
    //Initializing graph variables
    int V = 5;
    int E = 6;
    struct Graph* G = createGraph(V, E);

    //Adding edges to the graph
    addEdge(G, 0, 1, 10);
    addEdge(G, 0, 2, 20);
    addEdge(G, 1, 2, 30);
    addEdge(G, 1, 3, 40);
    addEdge(G, 2, 4, 50);
    addEdge(G, 3, 4, 60);

    //Displaying the graph
    displayGraph(G);

    return 0;
}