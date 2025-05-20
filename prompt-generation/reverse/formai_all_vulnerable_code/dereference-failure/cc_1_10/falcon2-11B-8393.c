//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Initialize an array to store the adjacency matrix
    int vertices = 0;
    int* adjMatrix = (int*)malloc(sizeof(int) * vertices * vertices);
    int* visited = (int*)calloc(vertices, sizeof(int));
    
    // Prompt user to enter the number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    
    // Prompt user to enter the edges between vertices
    printf("Enter the edges between vertices (separated by spaces): ");
    char* edges = (char*)malloc(sizeof(char) * (vertices * vertices * 2 + 1));
    fgets(edges, vertices * vertices * 2 + 1, stdin);
    
    // Parse the edges and update the adjacency matrix
    char* edge = strtok(edges, " ");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (i == j) {
                adjMatrix[i * vertices + j] = 0;
            } else {
                adjMatrix[i * vertices + j] = 0;
                adjMatrix[j * vertices + i] = 0;
            }
        }
    }
    
    while (edge!= NULL) {
        int u = 0;
        int v = 0;
        
        sscanf(edge, "%d %d", &u, &v);
        adjMatrix[u * vertices + v] = 1;
        adjMatrix[v * vertices + u] = 1;
        
        edge = strtok(NULL, " ");
    }
    
    // Print the adjacency matrix
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (adjMatrix[i * vertices + j] == 1) {
                printf("1 ");
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
    
    // Free allocated memory
    free(adjMatrix);
    free(visited);
    free(edges);
    
    return 0;
}