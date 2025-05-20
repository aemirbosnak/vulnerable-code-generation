//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: standalone
#include<stdio.h>
#include<stdlib.h>

#define MAXVERTICES 100

/* To store graph information. */
typedef struct Graph {
    int vertices;
    int edges;
    int AdjMatrix[MAXVERTICES][MAXVERTICES];
} Graph;

/* To print the adjacency matrix representation of the graph */
void printGraph(Graph* graph){
    printf("Adjacency Matrix Representation of the Graph:\n\n   ");
    for(int i=0; i<graph->vertices; i++){
        printf("%d ", i);
    }
    printf("\n\n");
    for (int i = 0; i < graph->vertices; i++) {
        printf("%2d ", i);
        for (int j = 0; j < graph->vertices; j++) {
            printf("%2d ", graph->AdjMatrix[i][j]);
        }
        printf("\n");
    }
}

/* Check if the vertex has the selected color */
int checkColor(int vertex, int color, Graph* graph, int colors[]){
    for(int i=0; i<graph->vertices; i++){
        if(graph->AdjMatrix[vertex][i] && color == colors[i]){
            return 0;
        }
    }
    return 1;
}

/* Function to apply graph coloring to the given graph */
void graphColoring(int vertex, Graph* graph, int colors[]){
    /* If all vertices are colored */
    if(vertex == graph->vertices){
        printf("The vertices can be colored as follows:\n\n");
        for(int i=0; i<graph->vertices; i++){
            printf("Vertex %d ---> Color %d\n", i, colors[i]);
        }
        printf("\n");
        return;
    }
    
    /* Index 0 represents no color */
    for(int c=1; c<=graph->vertices; c++){
        if(checkColor(vertex, c, graph, colors)){
            colors[vertex] = c;
            graphColoring(vertex+1, graph, colors);
            colors[vertex] = 0;
        }
    }
}

int main(){
    int n, m, x, y;
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    
    /* Get graph vertices and edges from user */
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &n);
    printf("Enter the number of edges in the graph: ");
    scanf("%d", &m);
    
    graph->vertices = n;
    graph->edges = m;
    
    /* Initialize adjacency matrix to have all values as 0 */
    for (int i = 0; i < graph->vertices; i++) {
        for (int j = 0; j < graph->vertices; j++) {
            graph->AdjMatrix[i][j] = 0;
        }
    }
    
    /* Get edge information from user */
    printf("\nEnter the edges in the following format (Vertex1 Vertex2):\n");
    for(int i=0; i<m; i++){
        scanf("%d %d", &x, &y);
        graph->AdjMatrix[x][y] = 1;
        graph->AdjMatrix[y][x] = 1;
    }
    
     /* Color array stores the color assigned to each vertex */
    int colors[MAXVERTICES] = {0}; // Initialize all colors to 0
    
    /* Find a way to color the graph vertices */
    graphColoring(0, graph, colors);
    
    printGraph(graph);
    
    /* Deallocate graph memory */
    free(graph);
    return 0;
}