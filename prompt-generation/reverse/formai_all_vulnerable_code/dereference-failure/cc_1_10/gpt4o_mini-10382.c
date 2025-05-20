//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define GRID_SIZE 10
#define MAX_NEIGHBORS 8

typedef struct Node {
    int x, y;
    int gCost; // Cost from start to current
    int hCost; // Heuristic cost to goal
    int fCost; // Total cost
    struct Node* parent;
} Node;

Node* createNode(int x, int y, int gCost, int hCost) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->gCost = gCost;
    newNode->hCost = hCost;
    newNode->fCost = gCost + hCost;
    newNode->parent = NULL;
    return newNode;
}

int heuristic(Node* a, Node* b) {
    return abs(a->x - b->x) + abs(a->y - b->y);
}

bool isValid(int x, int y) {
    return (x >= 0 && x < GRID_SIZE && y >= 0 && y < GRID_SIZE);
}

void reconstructPath(Node* node) {
    if (node == NULL) return;
    reconstructPath(node->parent);
    printf("-> (%d, %d) ", node->x, node->y);
}

int main() {
    int grid[GRID_SIZE][GRID_SIZE] = {
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 1, 1, 1, 0, 1, 0, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 1, 1, 1, 1, 1, 0, 1, 1, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 1, 1, 1, 0, 0, 0, 1, 1, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 1, 1, 0, 1, 0, 0}
    };

    Node* start = createNode(0, 0, 0, 0);
    Node* goal = createNode(9, 9, 0, 0);
    
    // Placeholder for open and closed lists.
    Node* openList[GRID_SIZE * GRID_SIZE];
    Node* closedList[GRID_SIZE * GRID_SIZE];
    int openCount = 0, closedCount = 0;

    openList[openCount++] = start;

    while (openCount > 0) {
        // Find the node with the least fCost.
        Node* current = openList[0];
        int currentIndex = 0;

        for (int i = 1; i < openCount; ++i) {
            if (openList[i]->fCost < current->fCost) {
                current = openList[i];
                currentIndex = i;
            }
        }

        // Check if we've reached the goal
        if (current->x == goal->x && current->y == goal->y) {
            printf("Path found: ");
            reconstructPath(current);
            printf("\n");
            break;
        }

        // Move current node to closed list
        for (int i = currentIndex; i < openCount - 1; ++i) {
            openList[i] = openList[i + 1];
        }
        openCount--;

        closedList[closedCount++] = current;

        // Explore neighbors
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (dx == 0 && dy == 0) continue; // Skip the node itself
                if (abs(dx) + abs(dy) > 1) continue; // Avoid diagonal movements

                int neighborX = current->x + dx;
                int neighborY = current->y + dy;

                if (!isValid(neighborX, neighborY) || grid[neighborX][neighborY] == 1) {
                    continue; // Skip invalid nodes
                }

                Node* neighbor = createNode(neighborX, neighborY, current->gCost + 1, heuristic(goal, createNode(neighborX, neighborY, 0, 0)));
                neighbor->parent = current;

                // Check if neighbor is in closed list
                bool inClosedList = false;
                for (int i = 0; i < closedCount; i++) {
                    if (closedList[i]->x == neighbor->x && closedList[i]->y == neighbor->y) {
                        inClosedList = true;
                        break;
                    }
                }
                if (inClosedList) continue;

                // Check if neighbor is in open list
                bool inOpenList = false;
                for (int i = 0; i < openCount; i++) {
                    if (openList[i]->x == neighbor->x && openList[i]->y == neighbor->y) {
                        inOpenList = true;
                        if (neighbor->gCost < openList[i]->gCost) {
                            openList[i]->gCost = neighbor->gCost;
                            openList[i]->parent = current;
                        }
                        break;
                    }
                }

                if (!inOpenList) {
                    openList[openCount++] = neighbor;
                }
            }
        }
    }

    // Clean up memory
    for (int i = 0; i < closedCount; i++) {
        free(closedList[i]);
    }
    for (int i = 0; i < openCount; i++) {
        free(openList[i]);
    }

    return 0;
}