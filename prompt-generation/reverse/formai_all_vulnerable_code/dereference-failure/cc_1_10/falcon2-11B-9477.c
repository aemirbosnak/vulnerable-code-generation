//Falcon2-11B DATASET v1.0 Category: Percolation Simulator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

// Function to check if a given node is connected to at least one of its neighbors
int isConnected(int** graph, int size, int node) {
    int connected = 0;
    
    for (int i = 0; i < size; i++) {
        if (graph[node][i] == 1) {
            connected = 1;
            break;
        }
    }
    
    return connected;
}

// Function to perform percolation simulation
void percolationSimulation(int** graph, int size, int** visited, int** occupied, int iterations) {
    int connectedCells = 0;
    
    for (int i = 0; i < iterations; i++) {
        int randomNode = rand() % size;
        
        // Check if the random node is already occupied
        if (occupied[randomNode] == 1) {
            continue;
        }
        
        // Mark the random node as visited
        visited[randomNode] = 1;
        
        // Check if the random node is connected to at least one of its neighbors
        if (isConnected(graph, size, randomNode)) {
            connectedCells++;
        }
        
        // Mark the random node as occupied
        occupied[randomNode] = 1;
    }
    
    // Print the number of connected cells
    printf("Number of connected cells: %d\n", connectedCells);
}

int main() {
    int size = 20; // Size of the grid
    int iterations = 1000; // Number of iterations
    
    // Create an array to represent the graph
    int** graph = (int**)malloc(size * sizeof(int*));
    
    // Initialize the graph
    for (int i = 0; i < size; i++) {
        graph[i] = (int*)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            graph[i][j] = 0;
        }
    }
    
    // Mark the center cell as occupied
    graph[10][10] = 1;
    
    // Create arrays to store visited and occupied cells
    int** visited = (int**)malloc(size * sizeof(int*));
    int** occupied = (int**)malloc(size * sizeof(int*));
    
    // Initialize the visited and occupied arrays
    for (int i = 0; i < size; i++) {
        visited[i] = (int*)malloc(size * sizeof(int));
        occupied[i] = (int*)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            visited[i][j] = 0;
            occupied[i][j] = 0;
        }
    }
    
    // Perform percolation simulation
    percolationSimulation(graph, size, visited, occupied, iterations);
    
    // Free allocated memory
    for (int i = 0; i < size; i++) {
        free(visited[i]);
        free(occupied[i]);
    }
    free(visited);
    free(occupied);
    free(graph);
    
    return 0;
}