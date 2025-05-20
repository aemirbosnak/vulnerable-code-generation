//GEMINI-pro DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// A-star pathfinding algorithm
// Node struct
typedef struct Node {
    int x;
    int y;
    int f;
    int g;
    int h;
    struct Node* parent;
} Node;

// Node comparison function for priority queue
int compareNodes(const void* a, const void* b) {
    const Node* na = (const Node*)a;
    const Node* nb = (const Node*)b;
    return na->f - nb->f;
}

// Find the path from the start node to the end node
Node* findPath(Node* start, Node* end, int** grid, int width, int height) {
    // Create a priority queue of nodes to visit
    Node** queue = malloc(sizeof(Node*) * width * height);
    int queueSize = 0;

    // Add the start node to the queue
    queue[queueSize++] = start;

    // Create a closed set of nodes that have already been visited
    bool** closedSet = malloc(sizeof(bool*) * width * height);
    for (int i = 0; i < width; i++) {
        closedSet[i] = malloc(sizeof(bool) * height);
    }
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            closedSet[i][j] = false;
        }
    }

    // While the queue is not empty
    while (queueSize > 0) {
        // Get the node with the lowest f-score from the queue
        Node* current = queue[0];
        for (int i = 1; i < queueSize; i++) {
            if (queue[i]->f < current->f) {
                current = queue[i];
            }
        }

        // Remove the current node from the queue
        for (int i = 0; i < queueSize; i++) {
            if (queue[i] == current) {
                queue[i] = queue[queueSize - 1];
                queueSize--;
                break;
            }
        }

        // If the current node is the end node, return the path
        if (current == end) {
            return current;
        }

        // Add the current node to the closed set
        closedSet[current->x][current->y] = true;

        // For each neighbor of the current node
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                // If the neighbor is not the current node, is not in the closed set, and is not an obstacle
                if ((i != 0 || j != 0) && !closedSet[current->x + i][current->y + j] && grid[current->x + i][current->y + j] != 1) {
                    // Create a new node for the neighbor
                    Node* neighbor = malloc(sizeof(Node));
                    neighbor->x = current->x + i;
                    neighbor->y = current->y + j;
                    neighbor->g = current->g + 1;
                    neighbor->h = abs(neighbor->x - end->x) + abs(neighbor->y - end->y);
                    neighbor->f = neighbor->g + neighbor->h;
                    neighbor->parent = current;

                    // Add the neighbor to the queue
                    queue[queueSize++] = neighbor;
                }
            }
        }

        // Sort the queue by f-score
        qsort(queue, queueSize, sizeof(Node*), compareNodes);
    }

    // Return null if no path was found
    return NULL;
}

// Free the memory used by the path
void freePath(Node* path) {
    if (path != NULL) {
        freePath(path->parent);
        free(path);
    }
}

// Print the path from the start node to the end node
void printPath(Node* path) {
    if (path != NULL) {
        printPath(path->parent);
        printf("(%d, %d)\n", path->x, path->y);
    }
}

// Main function
int main() {
    // Create a grid of 10x10 cells
    int grid[10][10] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    // Create the start node
    Node* start = malloc(sizeof(Node));
    start->x = 0;
    start->y = 0;
    start->f = 0;
    start->g = 0;
    start->h = 0;
    start->parent = NULL;

    // Create the end node
    Node* end = malloc(sizeof(Node));
    end->x = 9;
    end->y = 9;
    end->f = 0;
    end->g = 0;
    end->h = 0;
    end->parent = NULL;

    // Find the path from the start node to the end node
    Node* path = findPath(start, end, grid, 10, 10);

    // Print the path
    printPath(path);

    // Free the memory used by the path
    freePath(path);

    return 0;
}