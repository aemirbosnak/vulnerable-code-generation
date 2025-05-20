//GEMINI-pro DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Node structure
typedef struct Node {
    int x, y;
    float g, h, f;
    struct Node *parent;
} Node;

// Node comparison function
int compareNodes(const void *a, const void *b) {
    Node *node1 = (Node *)a;
    Node *node2 = (Node *)b;
    return (node1->f > node2->f) - (node1->f < node2->f);
}

// Manhattan distance heuristic
float heuristic(Node *node1, Node *node2) {
    return abs(node1->x - node2->x) + abs(node1->y - node2->y);
}

// A* pathfinding algorithm
Node *AStar(Node *start, Node *goal, int width, int height, int **grid) {
    // Initialize the open and closed sets
    Node **openSet = malloc(sizeof(Node *) * width * height);
    Node **closedSet = malloc(sizeof(Node *) * width * height);
    int openSetSize = 0;
    int closedSetSize = 0;

    // Add the start node to the open set
    openSet[openSetSize++] = start;

    // While the open set is not empty
    while (openSetSize > 0) {
        // Find the node with the lowest f-score in the open set
        Node *current = openSet[0];
        for (int i = 1; i < openSetSize; i++) {
            if (openSet[i]->f < current->f) {
                current = openSet[i];
            }
        }

        // If the current node is the goal node, return the path
        if (current == goal) {
            return current;
        }

        // Move the current node from the open set to the closed set
        openSetSize--;
        for (int i = 0; i < openSetSize; i++) {
            if (openSet[i] == current) {
                openSet[i] = openSet[openSetSize];
                break;
            }
        }
        closedSet[closedSetSize++] = current;

        // Generate the current node's neighbors
        Node *neighbors[4];
        neighbors[0] = (Node *)malloc(sizeof(Node));
        neighbors[0]->x = current->x - 1;
        neighbors[0]->y = current->y;
        neighbors[1] = (Node *)malloc(sizeof(Node));
        neighbors[1]->x = current->x + 1;
        neighbors[1]->y = current->y;
        neighbors[2] = (Node *)malloc(sizeof(Node));
        neighbors[2]->x = current->x;
        neighbors[2]->y = current->y - 1;
        neighbors[3] = (Node *)malloc(sizeof(Node));
        neighbors[3]->x = current->x;
        neighbors[3]->y = current->y + 1;

        // For each neighbor
        for (int i = 0; i < 4; i++) {
            Node *neighbor = neighbors[i];

            // If the neighbor is valid and not in the closed set
            if (neighbor->x >= 0 && neighbor->x < width && neighbor->y >= 0 && neighbor->y < height && grid[neighbor->x][neighbor->y] == 0 && !contains(closedSet, closedSetSize, neighbor)) {
                // Calculate the neighbor's g-score
                neighbor->g = current->g + 1;

                // Calculate the neighbor's h-score
                neighbor->h = heuristic(neighbor, goal);

                // Calculate the neighbor's f-score
                neighbor->f = neighbor->g + neighbor->h;

                // If the neighbor is not in the open set, add it to the open set
                if (!contains(openSet, openSetSize, neighbor)) {
                    neighbor->parent = current;
                    openSet[openSetSize++] = neighbor;
                }
            }
        }
    }

    // If the goal node was not found, return NULL
    return NULL;
}

// Function to check if a node is in a set
int contains(Node **set, int setSize, Node *node) {
    for (int i = 0; i < setSize; i++) {
        if (set[i] == node) {
            return 1;
        }
    }
    return 0;
}

// Main function
int main() {
    // Create the grid
    int width = 10;
    int height = 10;
    int **grid = malloc(sizeof(int *) * width);
    for (int i = 0; i < width; i++) {
        grid[i] = malloc(sizeof(int) * height);
        for (int j = 0; j < height; j++) {
            grid[i][j] = 0;
        }
    }

    // Set the start and goal nodes
    Node *start = (Node *)malloc(sizeof(Node));
    start->x = 0;
    start->y = 0;
    Node *goal = (Node *)malloc(sizeof(Node));
    goal->x = width - 1;
    goal->y = height - 1;

    // Find the path
    Node *path = AStar(start, goal, width, height, grid);

    // Print the path
    if (path != NULL) {
        while (path != NULL) {
            printf("(%d, %d)\n", path->x, path->y);
            path = path->parent;
        }
    } else {
        printf("No path found.\n");
    }

    // Free the memory
    free(start);
    free(goal);
    free(path);
    for (int i = 0; i < width; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}