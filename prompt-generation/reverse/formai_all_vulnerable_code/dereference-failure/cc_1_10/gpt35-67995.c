//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: satisfied
#include <stdio.h>
#define MAX 100

// data structure for the graph
typedef struct Graph{
    int numVertices;
    int adjMatrix[MAX][MAX];
}Graph;

// function to initialize the graph
void initializeGraph(Graph *G, int n){
    int i,j;
    G->numVertices = n;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            G->adjMatrix[i][j] = 0;
        }
    }
}

// function to add edge in the graph
void addEdge(Graph *G, int u, int v){
    G->adjMatrix[u][v] = 1;
    G->adjMatrix[v][u] = 1;
}

// function to print the graph
void printGraph(Graph *G){
    int i,j;
    printf("Graph:\n");
    for(i=0;i<G->numVertices;i++){
        for(j=0;j<G->numVertices;j++){
            printf("%d ", G->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// function to check if the given color can be assigned to given vertex
int isSafe(Graph *G, int vertex, int color, int colors[]){
    int i;
    for(i=0;i<G->numVertices;i++){
        if(G->adjMatrix[vertex][i] && colors[i]==color){
            return 0;
        }
    }
    return 1;
}

// recursive function to assign colors to the vertices
int assignColors(Graph *G, int colors[], int vertex){
    int i,j,flag;
    if(vertex == G->numVertices){
        // all vertices are colored successfully
        return 1;
    }
    for(i=1;i<=G->numVertices;i++){
        flag = 1;
        if(isSafe(G, vertex, i, colors)){
            for(j=0;j<G->numVertices;j++){
                if(G->adjMatrix[vertex][j] && i == colors[j]){
                    // color already used by adjacent vertex
                    flag = 0;
                    break;
                }
            }
            if(flag == 1){
                // assign color to current vertex
                colors[vertex] = i;
                if(assignColors(G, colors, vertex+1) == 1){
                    return 1;
                }
                // backtrack and try other colors
                colors[vertex] = 0;
            }
        }
    }
    return 0;
}

// function to solve the graph coloring problem
void graphColoring(Graph *G){
    int colors[MAX], i,j;
    for(i=0;i<G->numVertices;i++){
        colors[i] = 0;
    }
    if(assignColors(G, colors, 0) == 1){
        printf("Colors assigned to vertices:\n");
        for(i=0;i<G->numVertices;i++){
            printf("%d ", colors[i]);
        }
        printf("\n");
    }else{
        printf("Graph cannot be colored with given number of colors.\n");
    }
}

int main(){
    Graph G;
    int n, m, u, v, i;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &n);
    initializeGraph(&G, n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);
    for(i=0;i<m;i++){
        printf("Enter edge %d: ", i+1);
        scanf("%d %d", &u, &v);
        addEdge(&G, u, v);
    }
    printGraph(&G);
    graphColoring(&G);
    return 0;
}