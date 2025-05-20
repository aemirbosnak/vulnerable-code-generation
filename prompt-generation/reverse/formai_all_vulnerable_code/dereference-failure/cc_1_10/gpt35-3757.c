//FormAI DATASET v1.0 Category: Graph representation ; Style: active
#include<stdio.h>
#include<stdlib.h>

struct graph{
    int V;
    int E;
    int **adjMatrix;
};

struct graph * createGraph(int V, int E){
    struct graph *G = malloc(sizeof(struct graph));
    G->V = V;
    G->E = E;

    G->adjMatrix = malloc(V * sizeof(int *));

    for(int i = 0; i < V; i++){
        G->adjMatrix[i] = malloc(V * sizeof(int));
    }

    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            G->adjMatrix[i][j] = 0;
        }
    }
    return G;
}

void addEdge(struct graph *G, int u, int v, int w){
    G->adjMatrix[u][v] = w;
}

void printGraph(struct graph * G){
    printf("Graph Representation using Adjacency Matrix:\n");
    printf("Vertices: %d, Edges: %d\n", G->V, G->E);
    for(int i = 0; i < G->V; i++){
        for(int j = 0; j < G->V; j++){
            printf("%d ", G->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main(){
    struct graph *G;
    int n, m, u, v, w;

    printf("Enter the number of vertices: \n");
    scanf("%d", &n);

    printf("Enter the number of edges: \n");
    scanf("%d", &m);

    G = createGraph(n, m);

    printf("Enter the details of the edges (vertex1 vertex2 weight): \n");
    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &u, &v, &w);
        addEdge(G, u, v, w);
    }

    printGraph(G);

    return 0;
}