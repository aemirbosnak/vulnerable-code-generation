//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTEX 100

// Data Structure for Graph
typedef struct Graph {
    int V;
    int E;
    int vertexList[MAX_VERTEX];
    int adjList[MAX_VERTEX][MAX_VERTEX];
}Graph;

// Function to add edges in graph
void addEdge(Graph *graph, int vertex1, int vertex2){
    graph->adjList[vertex1][vertex2] = 1;
    graph->adjList[vertex2][vertex1] = 1;
}

// Function to check if coloring of graph is possible
int isGraphColorable(Graph *graph, int vertex, int colors[], int color){
    int i;
    for(i=0;i<graph->V;i++){
        if(graph->adjList[vertex][i] && colors[i]==color) {
            return 0;
        }
    }
    return 1;
}

// Function to print colors of vertices
void printVertexColors(int colors[], int n) {
    int i;
    printf("\nVertices Color:");
    for(i=0;i<n;i++) {
        printf("\n%d: %d", i, colors[i]);
    }
}

// Function to Color the Graph
int colorGraph(Graph *graph, int vertex, int colors[], int maxColors) {
    int i, color;
    if(vertex==graph->V) {
        return 1;
    }
    for(color=1;color<=maxColors;color++) {
        if(isGraphColorable(graph, vertex, colors, color)){
            colors[vertex] = color;
            if(colorGraph(graph, vertex+1, colors, maxColors)) {
                return 1;
            }
            colors[vertex] = 0;
        }
    }
    return 0;
}

int main(){
    int i, j, maxColors;
    Graph *graph;
    graph = (Graph*)malloc(sizeof(Graph));
    printf("Enter the Number of Vertices: ");
    scanf("%d", &graph->V);
    printf("Enter the Number of Edges: ");
    scanf("%d", &graph->E);
    printf("\nEnter the Vertices: ");
    for(i=0;i<graph->V;i++) {
        scanf("%d", &graph->vertexList[i]);
    }
    for(i=0;i<graph->V;i++) {
        for(j=0;j<graph->V;j++) {
            graph->adjList[i][j] = 0;
        }
    }
    printf("\nEnter the Edges:\n");
    for(i=0;i<graph->E;i++) {
        int vertex1, vertex2;
        scanf("%d %d", &vertex1, &vertex2);
        addEdge(graph, vertex1, vertex2);
    }
    printf("\nEnter the Maximum Number of Colors: ");
    scanf("%d", &maxColors);
    int colors[graph->V];
    for(i=0;i<graph->V;i++) {
        colors[i] = 0;
    }
    if(!colorGraph(graph, 0, colors, maxColors)){
        printf("\nGraph cannot be colored with %d colors", maxColors);
    } else {
        printVertexColors(colors, graph->V);
    }
    return 0;
}