//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

// Function to print the graph
void printGraph(char **adjList, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("Node %d:\n", i);
        for (int j = 0; j < n; j++) {
            if (adjList[i][j]!= '\0') {
                printf("Edge: %d -> %d\n", i, j);
            }
        }
    }
}

int main() {
    // Define the size of the graph
    int n = 5;

    // Allocate memory for the adjacency list
    char **adjList = malloc(n * sizeof(char*));

    // Initialize the adjacency list with NULL
    for (int i = 0; i < n; i++) {
        adjList[i] = malloc(n * sizeof(char));
        for (int j = 0; j < n; j++) {
            adjList[i][j] = '\0';
        }
    }

    // Create edges in the graph
    adjList[0][1] = 'E';
    adjList[0][2] = 'F';
    adjList[1][0] = 'E';
    adjList[1][2] = 'F';
    adjList[2][0] = 'F';
    adjList[2][1] = 'G';
    adjList[2][3] = 'I';
    adjList[3][2] = 'I';
    adjList[3][4] = 'J';
    adjList[4][3] = 'J';

    // Print the graph
    printGraph(adjList, n);

    return 0;
}