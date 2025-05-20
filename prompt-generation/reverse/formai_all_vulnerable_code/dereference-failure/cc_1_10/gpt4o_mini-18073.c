//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define WIDTH 10
#define HEIGHT 10
#define MAX_NODES (WIDTH * HEIGHT)
#define INF 9999

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point point;
    int gCost; // Cost from start to node
    int hCost; // Heuristic cost to goal
    int fCost; // Total cost (g + h)
    bool walkable;
    bool open;
    bool closed;
    struct Node* parent; // Pointer to parent node
} Node;

Node* grid[WIDTH][HEIGHT]; // The grid of nodes

// Heuristic function for A* (Manhattan Distance)
int heuristic(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

// Initialize the grid with walkable nodes
void initializeGrid() {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            grid[i][j] = (Node*)malloc(sizeof(Node));
            grid[i][j]->point.x = i;
            grid[i][j]->point.y = j;
            grid[i][j]->gCost = INF;
            grid[i][j]->hCost = INF;
            grid[i][j]->fCost = INF;
            grid[i][j]->walkable = true; // All nodes are walkable by default
            grid[i][j]->open = false;
            grid[i][j]->closed = false;
            grid[i][j]->parent = NULL;
        }
    }
}

// Function to find the path using A* algorithm
bool aStar(Point start, Point goal) {
    grid[start.x][start.y]->gCost = 0;
    grid[start.x][start.y]->hCost = heuristic(start, goal);
    grid[start.x][start.y]->fCost = grid[start.x][start.y]->gCost + grid[start.x][start.y]->hCost;
    grid[start.x][start.y]->open = true;

    Node* openSet[MAX_NODES];
    int openSetSize = 0;

    openSet[openSetSize++] = grid[start.x][start.y];

    while (openSetSize > 0) {
        // Find the node with the lowest fCost
        int lowestIndex = 0;
        for (int i = 1; i < openSetSize; i++) {
            if (openSet[i]->fCost < openSet[lowestIndex]->fCost) {
                lowestIndex = i;
            }
        }

        Node* currentNode = openSet[lowestIndex];

        // If we reached the goal
        if (currentNode->point.x == goal.x && currentNode->point.y == goal.y) {
            // Backtrack through parents to find the path
            Node* pathNode = currentNode;
            while (pathNode) {
                printf("Path: (%d, %d)\n", pathNode->point.x, pathNode->point.y);
                pathNode = pathNode->parent;
            }
            return true; // Path found
        }

        // Move current node to closed set
        currentNode->open = false;
        currentNode->closed = true;

        // Explore neighbors
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (abs(dx) + abs(dy) == 1) { // Only horizontal and vertical
                    int neighborX = currentNode->point.x + dx;
                    int neighborY = currentNode->point.y + dy;

                    // Check bounds
                    if (neighborX >= 0 && neighborX < WIDTH && neighborY >= 0 && neighborY < HEIGHT) {
                        Node* neighbor = grid[neighborX][neighborY];
                        if (neighbor->walkable && !neighbor->closed) {
                            int tentativeGCost = currentNode->gCost + 1;

                            if (!neighbor->open || tentativeGCost < neighbor->gCost) {
                                neighbor->gCost = tentativeGCost;
                                neighbor->hCost = heuristic(neighbor->point, goal);
                                neighbor->fCost = neighbor->gCost + neighbor->hCost;
                                neighbor->parent = currentNode;

                                // Add to open set if not already present
                                if (!neighbor->open) {
                                    neighbor->open = true;

                                    // Ensure the neighbor is in the open set array
                                    openSet[openSetSize++] = neighbor;
                                }
                            }
                        }
                    }
                }
            }
        }

        // Remove the current node from the open set
        openSet[lowestIndex] = openSet[--openSetSize];
    }

    return false; // No path found
}

// Cleanup the allocated memory for the grid
void cleanupGrid() {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            free(grid[i][j]);
        }
    }
}

int main() {
    printf("A* Pathfinding Demo\n");

    // Initialize the grid and set some nodes as non-walkable.
    initializeGrid();
    grid[5][5]->walkable = false; // Example obstacle
    grid[4][5]->walkable = false; // Example obstacle

    Point start = {0, 0};
    Point goal = {7, 7};

    if (!aStar(start, goal)) {
        printf("No path found from (%d, %d) to (%d, %d).\n", start.x, start.y, goal.x, goal.y);
    }

    // Clean up
    cleanupGrid();

    return 0;
}