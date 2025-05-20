//GEMINI-pro DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

// Node struct
typedef struct Node {
    int x;
    int y;
    int f;
    int g;
    int h;
    struct Node *parent;
} Node;

// Node comparison function
int compareNodes(const void *a, const void *b) {
    Node *n1 = (Node *)a;
    Node *n2 = (Node *)b;
    return n1->f - n2->f;
}

// Heuristic function
int heuristic(Node *n1, Node *n2) {
    return abs(n1->x - n2->x) + abs(n1->y - n2->y);
}

// Pathfinding function
Node* AStar(Node *start, Node *goal, int **grid, int width, int height) {
    // Open list
    Node **openList = malloc(sizeof(Node *) * width * height);
    int openListSize = 0;

    // Closed list
    Node **closedList = malloc(sizeof(Node *) * width * height);
    int closedListSize = 0;

    // Add start node to open list
    openList[openListSize++] = start;

    // While open list is not empty
    while (openListSize > 0) {
        // Get node with lowest f-score from open list
        Node *n = openList[0];
        for (int i = 1; i < openListSize; i++) {
            if (openList[i]->f < n->f) {
                n = openList[i];
            }
        }

        // Remove node from open list
        for (int i = 0; i < openListSize; i++) {
            if (openList[i] == n) {
                openList[i] = openList[openListSize - 1];
                openListSize--;
                break;
            }
        }

        // Add node to closed list
        closedList[closedListSize++] = n;

        // If node is goal, return it
        if (n == goal) {
            return n;
        }

        // Get neighbors of node
        Node *neighbors[4];
        neighbors[0] = (Node *)malloc(sizeof(Node));
        neighbors[0]->x = n->x - 1;
        neighbors[0]->y = n->y;
        neighbors[1] = (Node *)malloc(sizeof(Node));
        neighbors[1]->x = n->x + 1;
        neighbors[1]->y = n->y;
        neighbors[2] = (Node *)malloc(sizeof(Node));
        neighbors[2]->x = n->x;
        neighbors[2]->y = n->y - 1;
        neighbors[3] = (Node *)malloc(sizeof(Node));
        neighbors[3]->x = n->x;
        neighbors[3]->y = n->y + 1;

        // For each neighbor
        for (int i = 0; i < 4; i++) {
            // If neighbor is valid
            if (neighbors[i]->x >= 0 && neighbors[i]->x < width && neighbors[i]->y >= 0 && neighbors[i]->y < height && grid[neighbors[i]->y][neighbors[i]->x] != 1) {
                // If neighbor is not in closed list
                int found = 0;
                for (int j = 0; j < closedListSize; j++) {
                    if (closedList[j] == neighbors[i]) {
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    // Calculate neighbor's g-score
                    neighbors[i]->g = n->g + 1;

                    // Calculate neighbor's h-score
                    neighbors[i]->h = heuristic(neighbors[i], goal);

                    // Calculate neighbor's f-score
                    neighbors[i]->f = neighbors[i]->g + neighbors[i]->h;

                    // Add neighbor to open list
                    openList[openListSize++] = neighbors[i];

                    // Set neighbor's parent to current node
                    neighbors[i]->parent = n;
                }
            }
        }
    }

    // If no path found, return NULL
    return NULL;
}

// Print path
void printPath(Node *n) {
    if (n->parent != NULL) {
        printPath(n->parent);
    }
    printf("(%d, %d)\n", n->x, n->y);
}

// Free memory
void freeNodes(Node *n) {
    if (n->parent != NULL) {
        freeNodes(n->parent);
    }
    free(n);
}

// Main function
int main() {
    // Grid
    int grid[5][5] = {
        {0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    // Start node
    Node start;
    start.x = 0;
    start.y = 0;

    // Goal node
    Node goal;
    goal.x = 4;
    goal.y = 4;

    // Find path
    Node *path = AStar(&start, &goal, grid, 5, 5);

    // Print path
    if (path != NULL) {
        printPath(path);
    } else {
        printf("No path found\n");
    }

    // Free memory
    freeNodes(path);

    return 0;
}