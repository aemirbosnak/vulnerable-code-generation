//FormAI DATASET v1.0 Category: Graph representation ; Style: curious
#include <stdio.h>
#include <stdlib.h>

// Function for printing the graph
void printGraph(int** graph, int rows, int cols) {
    printf("Here is the graph representation:\n");

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (graph[i][j] == 1) {
                printf("X ");  // represent an edge
            } else {
                printf("O ");  // represent no edge
            }
        }
        printf("\n");
    }
}

int main() {
    printf("Welcome to the Graph Representation Program\n");
    printf("Today we will be representing a graph using a 2D array\n\n");

    // Generate a random number between 3 and 6 for the graph size
    int size = rand() % 4 + 3;
    printf("The size of our graph will be %d\n", size);

    // Allocate memory for our graph
    int** graph = (int**) malloc(size * sizeof(int*));  
    for (int i = 0; i < size; i++) {
        graph[i] = (int*) malloc(size * sizeof(int));
    }

    // Initialize the graph with random values
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j) {
                graph[i][j] = 0;  // no self-loop
            } else {
                graph[i][j] = rand() % 2;  // randomly add an edge or not
            }
        }
    }

    // Print the generated graph
    printGraph(graph, size, size);

    // Free the memory
    for (int i = 0; i < size; i++) {
        free(graph[i]);
    }
    free(graph);

    return 0;
}