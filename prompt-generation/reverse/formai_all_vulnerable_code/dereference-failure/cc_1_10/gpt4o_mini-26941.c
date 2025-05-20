//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define WIDTH 10
#define HEIGHT 10

// Node structure to represent each cell on the grid
typedef struct Node {
    int x;
    int y;
    int g; // Cost from start to this node
    int h; // Heuristic cost estimate to the goal
    int f; // Total cost (g + h)
    struct Node* parent; // Pointer to the parent node
} Node;

// Creating a node with specified coordinates
Node* createNode(int x, int y, Node* parent) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->g = 0;
    node->h = 0;
    node->f = 0;
    node->parent = parent;
    return node;
}

// Heuristic: Manhattan distance
int heuristic(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

// Check if a position is within the grid bounds
bool isValid(int x, int y) {
    return (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT);
}

// Print the path traversed by the A* algorithm
void printPath(Node* node) {
    if (node == NULL) return;
    printPath(node->parent);
    printf("(%d, %d) -> ", node->x, node->y);
}

// The main A* algorithm to find the path
void astar(int grid[WIDTH][HEIGHT], Node* start, Node* goal) {
    Node* openList[WIDTH * HEIGHT]; // List of nodes to be evaluated
    int openCount = 0; // Number of nodes in the open list

    openList[openCount++] = start; // Start by adding the start node to the open list

    while (openCount > 0) {
        // Find the node with the lowest f value
        int lowestIndex = 0;
        for (int i = 1; i < openCount; i++) {
            if (openList[i]->f < openList[lowestIndex]->f) {
                lowestIndex = i;
            }
        }

        Node* currentNode = openList[lowestIndex];

        // If we reach the goal, print the path
        if (currentNode->x == goal->x && currentNode->y == goal->y) {
            printf("Path found: ");
            printPath(currentNode);
            printf("Goal reached!\n");
            return;
        }

        // Remove current node from the open list
        openList[lowestIndex] = openList[--openCount];

        // Explore the neighboring nodes (up, down, left, right)
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if ((dx == 0 && dy == 0) || (dx != 0 && dy != 0)) continue; // Skip diagonals
                int newX = currentNode->x + dx;
                int newY = currentNode->y + dy;

                if (isValid(newX, newY) && grid[newX][newY] != 1) { // Check for obstacles
                    Node* neighbor = createNode(newX, newY, currentNode);
                    neighbor->g = currentNode->g + 1; // Distance from start
                    neighbor->h = heuristic(newX, newY, goal->x, goal->y); // Heuristic
                    neighbor->f = neighbor->g + neighbor->h; // Total cost

                    // Check if this neighbor is already in the open list
                    bool inOpenList = false;
                    for (int i = 0; i < openCount; i++) {
                        if (openList[i]->x == neighbor->x && openList[i]->y == neighbor->y && openList[i]->g <= neighbor->g) {
                            inOpenList = true;
                            break;
                        }
                    }

                    if (!inOpenList) {
                        openList[openCount++] = neighbor; // Add neighbor to open list
                    }
                }
            }
        }
    }

    printf("No path found.\n");
}

// Main function
int main() {
    // Define the grid: 0 is walkable, 1 is an obstacle
    int grid[WIDTH][HEIGHT] = {
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 1, 1, 0, 0, 1, 0, 1, 1, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 1, 0},
        {0, 1, 1, 1, 1, 0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 1, 1, 0, 0, 0},
    };

    Node* start = createNode(0, 0, NULL); // Define the start point
    Node* goal = createNode(9, 9, NULL); // Define the goal point

    // Begin the A* pathfinding process
    astar(grid, start, goal);

    // Cleanup
    free(start);
    free(goal);

    return 0;
}