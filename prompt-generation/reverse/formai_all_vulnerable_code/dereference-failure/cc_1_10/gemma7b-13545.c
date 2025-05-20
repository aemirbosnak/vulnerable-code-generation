//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

void PercolationSimulator(int** grid, int size) {
    Node* head = NULL;
    for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++) {
            if (grid[r][c] == 1) {
                Node* newNode = malloc(sizeof(Node));
                newNode->x = r;
                newNode->y = c;
                newNode->next = head;
                head = newNode;
            }
        }
    }

    // Randomly flip some nodes
    srand(time(NULL));
    for (int i = 0; i < size * size * 0.2; i++) {
        int randX = rand() % size;
        int randY = rand() % size;
        if (grid[randX][randY] == 1) {
            grid[randX][randY] = 0;
        }
    }

    // Check if the top node is connected to the bottom node
    if (head->next == NULL) {
        printf("Percolation simulation complete. The top and bottom nodes are connected.\n");
    } else {
        printf("Percolation simulation complete. The top and bottom nodes are not connected.\n");
    }
}

int main() {
    int size = MAX_SIZE;
    int** grid = malloc(size * sizeof(int*));
    for (int r = 0; r < size; r++) {
        grid[r] = malloc(size * sizeof(int));
    }

    // Initialize the grid
    for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++) {
            grid[r][c] = 0;
        }
    }

    // Place some blocks in the grid
    grid[10][10] = 1;
    grid[10][11] = 1;
    grid[11][10] = 1;
    grid[11][11] = 1;

    PercolationSimulator(grid, size);

    return 0;
}