//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: Romeo and Juliet
#include<stdio.h> 
#include<stdbool.h> 

int V;
int graph[100][100];
int m;

//Function to check if the current color assignment is safe
bool isSafe (int v, int color[], int c) {
    for(int i = 0; i < V; i++) {
        if(graph[v][i] && color[i] == c) {
            return false;
        }
    }
    return true;
}

//Recursive function to solve the Graph Coloring Problem
bool graphColoringUtil(int color[], int v) {
    if(v == V) { //All vertices are assigned a color
        return true;
    }

    for(int c = 1; c <= m; c++) {
        if(isSafe(v, color, c)) {
            color[v] = c;
            if(graphColoringUtil(color, v+1) == true) {
                return true;
            }
            color[v] = 0; //Backtrack
        }
    }
    return false;
}

//Function to solve the Graph Coloring Problem
bool graphColoring() {
    int color[V];
    for(int i = 0; i < V; i++) {
        color[i] = 0; //Initialize all vertices with no color
    }

    if(graphColoringUtil(color, 0) == false) { //Start at vertex 0
        return false;
    }

    //Print the vertex assignments
    printf("Vertex color assignments:\n");
    for(int i = 0; i < V; i++) {
        printf("Vertex %d ---> Color %d\n", i+1, color[i]);
    }
    return true;
}

int main() {
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &V);
    printf("Enter the adjacency matrix of the graph:\n");
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter the number of colors to use: ");
    scanf("%d", &m);
    if(graphColoring() == true) {
        printf("Graph coloring is possible using %d colors.\n", m);
    }
    else {
        printf("Graph coloring is not possible using %d colors.\n", m);
    }
    return 0;
}