//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: modular
#include <stdio.h>
#include <stdlib.h>

//Function to allocate memory to the adjacency matrix and initialize it with 0
int **createAdjMatrix(int numVertices) {
    int **adjMatrix = (int **) malloc(numVertices * sizeof(int *));
    for (int i = 0; i < numVertices; i++) {
        adjMatrix[i] = (int *) calloc(numVertices, sizeof(int));
    }
    return adjMatrix;
}

//Function to assign colors to vertices in a way that no two adjacent vertices have the same color
void graphColoring(int **adjMatrix, int numVertices, int numColors) {
    int *colorArray = (int *) calloc(numVertices, sizeof(int));

    //Initially, all vertices are assigned color 0
    for(int i = 0; i < numVertices; i++) {
        colorArray[i] = 0;
    }

    //Start coloring vertices one by one, using the recursive utility function
    if(!graphColoringUtil(adjMatrix, colorArray, 0, numVertices, numColors)) {
        printf("No solution exists");
    }

    //Printing the solution
    for(int i = 0; i < numVertices; i++) {
        printf("Vertex %d --> Color %d\n", i+1, colorArray[i] + 1);
    }
}

//Utility function to recursively assign colors to vertices
int graphColoringUtil(int **adjMatrix, int *colorArray, int vertex, int numVertices, int numColors) {
    //Base case: if all vertices have been assigned a color, the solution is complete
    if(vertex == numVertices) {
        return 1;
    }

    //Assigning each possible color to the current vertex and checking if it is valid
    for(int i = 1; i <= numColors; i++) {
        if(isValid(adjMatrix, colorArray, vertex, numVertices, numColors, i)) {
            colorArray[vertex] = i-1;

            //Recursive call to assign colors to the remaining vertices
            if(graphColoringUtil(adjMatrix, colorArray, vertex+1, numVertices, numColors)) {
                return 1;
            }

            //Backtracking step: assigning color 0 to the current vertex
            colorArray[vertex] = 0;
        }
    }

    //If no valid color is found, the solution is impossible
    return 0;
}

//Function to check if a given vertex can be assigned a given color
int isValid(int **adjMatrix, int *colorArray, int vertex, int numVertices, int numColors, int color) {
    for(int i = 0; i < numVertices; i++) {
        if(adjMatrix[vertex][i]) {
            if(colorArray[i] == color-1) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    //Creating the adjacency matrix
    int numVertices, numEdges;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);
    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);
    int **adjMatrix = createAdjMatrix(numVertices);
    int source, dest;
    for(int i = 0; i < numEdges; i++) {
        printf("Enter the source and destination vertices for edge %d: ", i+1);
        scanf("%d %d", &source, &dest);
        adjMatrix[source-1][dest-1] = 1;
        adjMatrix[dest-1][source-1] = 1;
    }

    //Assigning colors to the vertices
    int numColors;
    printf("Enter the number of colors: ");
    scanf("%d", &numColors);
    graphColoring(adjMatrix, numVertices, numColors);

    //Freeing the dynamically allocated memory
    for (int i = 0; i < numVertices; i++) {
        free(adjMatrix[i]);
    }
    free(adjMatrix);

    return 0;
}