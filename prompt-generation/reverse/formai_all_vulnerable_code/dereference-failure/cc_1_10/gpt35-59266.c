//FormAI DATASET v1.0 Category: Graph representation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

struct graph{
    int V;
    int E;
    int **adj;
};

struct graph *createGraph(int V, int E){
    int i;
    struct graph *g = (struct graph*)malloc(sizeof(struct graph));
    g->V = V;
    g->E = E;

    g->adj = (int**)malloc(V*sizeof(int*));
    for(i=0;i<V;i++){
        g->adj[i] = (int*)malloc(V*sizeof(int));
    }

    return g;   
}

void addEdge(struct graph *g, int u, int v){
    g->adj[u][v] = 1;
    g->adj[v][u] = 1;
}

void printGraph(struct graph *g){
    int i,j;

    printf("Adjacency Matrix representation of Graph:\n");
    for(i=0;i<g->V;i++){
        for(j=0;j<g->V;j++){
            printf("%d ",g->adj[i][j]);
        }
        printf("\n");
    }
}

int main(){
    struct graph *g = createGraph(5,7);

    addEdge(g,0,1);
    addEdge(g,0,2);
    addEdge(g,0,4);
    addEdge(g,1,3);
    addEdge(g,1,4);
    addEdge(g,2,4);
    addEdge(g,3,4);

    printGraph(g);

    return 0;
}