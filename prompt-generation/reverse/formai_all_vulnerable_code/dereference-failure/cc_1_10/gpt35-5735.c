//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

#define ROWS 7
#define COLS 9

// Define the structure of a node
typedef struct {
    int row, col;
    int f, g, h;
    struct Node* parent;
} Node;

// Function declarations
void printPath(Node* destination);
void calculateHeuristic(Node* node, Node* destination);
void findPath(Node* start, Node* destination, int maze[ROWS][COLS]);

int main() {
    // Define the maze
    int maze[ROWS][COLS] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 1, 0, 0, 0, 0, 0, 1, 0},
        {0, 1, 1, 1, 0, 0, 0, 1, 0},
        {0, 1, 0, 0, 0, 0, 0, 1, 0},
        {0, 1, 1, 1, 1, 1, 1, 1, 0}
    };

    // Define the start and destination nodes
    Node start = {1, 1, 0, 0, 0, NULL};
    Node destination = {ROWS - 2, COLS - 2, 0, 0, 0, NULL};

    // Find the path from start to destination
    findPath(&start, &destination, maze);

    // Print the path
    printf("The path from (%d,%d) to (%d,%d) is:\n", start.row, start.col, destination.row, destination.col);
    printPath(&destination);

    return 0;
}

// Function to print the path
void printPath(Node* node) {
    if (node == NULL) {
        return;
    }
    printPath(node->parent);
    printf("(%d,%d)\n", node->row, node->col);
}

// Function to calculate the heuristic value of a node
void calculateHeuristic(Node* node, Node* destination) {
    node->h = abs(node->row - destination->row) + abs(node->col - destination->col);
}

// Function to find the path from start to destination
void findPath(Node* start, Node* destination, int maze[ROWS][COLS]) {
    // Define the open and closed lists
    Node* openList[ROWS * COLS] = {NULL};
    Node* closedList[ROWS * COLS] = {NULL};
    int openListSize = 0, closedListSize = 0;

    // Add the start node to the open list
    openList[openListSize++] = start;

    // Loop until the destination node is found or the open list is empty
    while (openListSize > 0) {
        // Find the node in the open list with the lowest f cost
        Node* current = openList[0];
        int currentIndex = 0;
        for (int i = 1; i < openListSize; i++) {
            if (openList[i]->f < current->f) {
                current = openList[i];
                currentIndex = i;
            }
        }

        // Remove the current node from the open list and add it to the closed list
        openList[currentIndex] = openList[--openListSize];
        closedList[closedListSize++] = current;

        // If the current node is the destination, we've found the path
        if (current->row == destination->row && current->col == destination->col) {
            return;
        }

        // Loop through the current node's neighbors
        for (int row = -1; row <= 1; row++) {
            for (int col = -1; col <= 1; col++) {
                // Skip the current node and diagonal neighbors
                if (row == 0 && col == 0) {
                    continue;
                }
                if (row != 0 && col != 0) {
                    continue;
                }

                // Calculate the neighbor's coordinates
                int neighborRow = current->row + row;
                int neighborCol = current->col + col;

                // Skip neighbors outside of the maze
                if (neighborRow < 0 || neighborRow >= ROWS) {
                    continue;
                }
                if (neighborCol < 0 || neighborCol >= COLS) {
                    continue;
                }

                // Skip blocked nodes
                if (maze[neighborRow][neighborCol] == 1) {
                    continue;
                }

                // Create the neighbor node
                Node* neighbor = malloc(sizeof(Node));
                neighbor->row = neighborRow;
                neighbor->col = neighborCol;
                neighbor->parent = current;

                // Calculate the neighbor's f, g, and h values
                neighbor->g = current->g + 1;
                calculateHeuristic(neighbor, destination);
                neighbor->f = neighbor->g + neighbor->h;

                // Skip neighbors already in the closed list
                int skip = 0;
                for (int i = 0; i < closedListSize; i++) {
                    if (closedList[i]->row == neighbor->row && closedList[i]->col == neighbor->col) {
                        skip = 1;
                        break;
                    }
                }
                if (skip) {
                    continue;
                }

                // Add the neighbor to the open list
                openList[openListSize++] = neighbor;
            }
        }
    }
}