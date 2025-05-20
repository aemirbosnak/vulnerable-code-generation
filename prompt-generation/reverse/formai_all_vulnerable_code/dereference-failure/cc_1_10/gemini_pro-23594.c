//GEMINI-pro DATASET v1.0 Category: Pathfinding algorithms ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

// Node in the graph
typedef struct Node {
    int x, y;
    struct Node *parent;
    int g, h, f;
} Node;

// Node comparison function for priority queue
int compareNodes(const void *a, const void *b) {
    Node *n1 = (Node *)a;
    Node *n2 = (Node *)b;
    return n1->f - n2->f;
}

// Find the path from the start node to the end node
int findPath(Node **grid, int width, int height, Node *start, Node *end) {
    // Create a priority queue to store the nodes to be evaluated
    Node **queue = malloc(sizeof(Node *) * width * height);
    int queueSize = 0;

    // Initialize the start node
    start->g = 0;
    start->h = abs(end->x - start->x) + abs(end->y - start->y);
    start->f = start->g + start->h;

    // Add the start node to the priority queue
    queue[queueSize++] = start;

    // While the priority queue is not empty
    while (queueSize > 0) {
        // Get the node with the lowest f-value from the priority queue
        Node *current = queue[0];
        for (int i = 1; i < queueSize; i++) {
            if (queue[i]->f < current->f) {
                current = queue[i];
            }
        }

        // Remove the node from the priority queue
        for (int i = 0; i < queueSize; i++) {
            if (queue[i] == current) {
                queue[i] = queue[queueSize - 1];
                queueSize--;
                break;
            }
        }

        // If the current node is the end node, return true
        if (current == end) {
            return 1;
        }

        // For each neighbor of the current node
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                // If the neighbor is not the current node
                if (i == 0 && j == 0) {
                    continue;
                }

                // If the neighbor is within the bounds of the grid
                if (current->x + i >= 0 && current->x + i < width && current->y + j >= 0 && current->y + j < height) {
                    // If the neighbor is not an obstacle
                    if (grid[current->x + i][current->y + j].f != INT_MAX) {
                        // Calculate the neighbor's g-value
                        int g = current->g + 1;

                        // Calculate the neighbor's h-value
                        int h = abs(end->x - (current->x + i)) + abs(end->y - (current->y + j));

                        // Calculate the neighbor's f-value
                        int f = g + h;

                        // If the neighbor is not already in the priority queue
                        int found = 0;
                        for (int k = 0; k < queueSize; k++) {
                            if (queue[k] == &grid[current->x + i][current->y + j]) {
                                found = 1;
                                break;
                            }
                        }
                        if (!found) {
                            // Add the neighbor to the priority queue
                            grid[current->x + i][current->y + j].parent = current;
                            grid[current->x + i][current->y + j].g = g;
                            grid[current->x + i][current->y + j].h = h;
                            grid[current->x + i][current->y + j].f = f;
                            queue[queueSize++] = &grid[current->x + i][current->y + j];
                        }
                    }
                }
            }
        }
    }

    // If the end node was not found, return false
    return 0;
}

// Print the path from the start node to the end node
void printPath(Node *end) {
    if (end->parent != NULL) {
        printPath(end->parent);
    }
    printf("(%d, %d)\n", end->x, end->y);
}

// Main function
int main() {
    // Create the grid
    int width = 10;
    int height = 10;
    Node **grid = malloc(sizeof(Node *) * width * height);
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            grid[i][j].x = i;
            grid[i][j].y = j;
            grid[i][j].parent = NULL;
            grid[i][j].g = INT_MAX;
            grid[i][j].h = INT_MAX;
            grid[i][j].f = INT_MAX;
        }
    }

    // Set the obstacles
    grid[3][2].f = INT_MAX;
    grid[3][3].f = INT_MAX;
    grid[3][4].f = INT_MAX;
    grid[4][3].f = INT_MAX;
    grid[4][4].f = INT_MAX;

    // Set the start and end nodes
    Node start = {0, 0, NULL, 0, 0, 0};
    Node end = {9, 9, NULL, 0, 0, 0};

    // Find the path
    int found = findPath(grid, width, height, &start, &end);

    // Print the path
    if (found) {
        printPath(&end);
    } else {
        printf("No path found.\n");
    }

    // Free the grid
    for (int i = 0; i < width; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}