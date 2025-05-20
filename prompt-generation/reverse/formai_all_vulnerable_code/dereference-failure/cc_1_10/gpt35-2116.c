//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_VERTICES 100

// This function is used to print the color assigned to each vertex
void PrintColors(int *color, int vertices) {
    printf("\nColor code:");
    for(int i=0; i<vertices; i++)
        printf("\nVertex %d => Color %d", i+1, *(color+i)); // print color assigned to each vertex
}

// This function is used to check if a vertex can be assigned a particular color or not
bool IsSafe(int vertex, bool **adjMatrix, int vertices, int *color, int currColor) {
    for(int i=0; i<vertices; i++) {
        if(*(adjMatrix[vertex] + i) == true && *(color+i) == currColor) // check if neighbors of vertex have same color
            return false;
    }
    return true;
}

// This function is used for graph coloring, using backtracking approach
bool GraphColoringUtil(bool **adjMatrix, int vertices, int *color, int vertexCount, int maxColors) {
    // if all vertices are assigned a color
    if(vertexCount == vertices)
        return true;
        
    // assign colors to next vertices and check if it's safe
    for(int i=1; i<=maxColors; i++) {
        if(IsSafe(vertexCount, adjMatrix, vertices, color, i)) {
            *(color+vertexCount) = i; // assign color to vertex
            if(GraphColoringUtil(adjMatrix, vertices, color, vertexCount+1, maxColors) == true) // recursive call
                return true;
            *(color+vertexCount) = 0; // if current color does not work, backtrack and remove the current color
        }
    }
    return false;
}

// This function is used to solve the Graph Coloring problem
void GraphColoring(bool **adjMatrix, int vertices, int maxColors) {
    if(vertices <= 0 || maxColors <= 0)
        return;
        
    // allocating memory for color array and initializing it with 0
    int *color = (int*)malloc(vertices * sizeof(int));
    for(int i=0; i<vertices; i++)
        *(color+i) = 0;
    
    if(GraphColoringUtil(adjMatrix, vertices, color, 0, maxColors) == true) { // graph coloring using backtracking
        printf("Solution exists\n");
        PrintColors(color, vertices);
    }
    else
        printf("Solution does not exist\n");
    
    free(color);
}

int main() {
    int vertices, maxColor;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    
    bool **adjMatrix = (bool**)malloc(vertices * sizeof(bool*));
    for(int i=0; i<vertices; i++)
        *(adjMatrix+i) = (bool*)malloc(vertices * sizeof(bool));
        
    printf("Enter the adjacency matrix:\n");
    for(int i=0; i<vertices; i++) {
        for(int j=0; j<vertices; j++) {
            scanf("%d", (*(adjMatrix+i) + j));
        }
    }
    
    printf("Enter the maximum number of colors: ");
    scanf("%d", &maxColor);
    
    GraphColoring(adjMatrix, vertices, maxColor);
    
    for(int i=0; i<vertices; i++)
        free(*(adjMatrix+i));
    free(adjMatrix);
    
    return 0;
}