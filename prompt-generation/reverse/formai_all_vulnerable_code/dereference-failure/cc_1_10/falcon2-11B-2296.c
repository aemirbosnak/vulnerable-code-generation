//Falcon2-11B DATASET v1.0 Category: Pathfinding algorithms ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

// Function to calculate shortest path length using Breadth First Search
int pathfinding(int n, int start[], int end[]) {
    // Create adjacency matrix
    int** graph = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        graph[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0; // Initialize all edges to zero
        }
    }
    
    // Set starting point
    int* visited = (int*)calloc(n, sizeof(int));
    visited[start[0]] = 1; // Mark start node as visited
    
    // Perform Breadth First Search
    int queue[n];
    int front = 0;
    int rear = 0;
    queue[rear++] = start[0];
    
    while (front < rear) {
        int current = queue[front++];
        for (int i = 0; i < n; i++) {
            if (!visited[i] && graph[current][i]!= 0) {
                visited[i] = 1; // Mark neighbor as visited
                queue[rear++] = i; // Add neighbor to queue
            }
        }
    }
    
    // Calculate path length
    int path_length = 0;
    int current = end[0];
    while (current!= start[0]) {
        path_length++;
        current = graph[current][current];
    }
    
    free(graph);
    free(visited);
    
    return path_length;
}

int main() {
    int n = 4;
    int start[4] = {0, 1, 2, 3};
    int end[4] = {3, 2, 1, 0};
    
    int result = pathfinding(n, start, end);
    
    printf("Shortest path length: %d\n", result);
    
    return 0;
}