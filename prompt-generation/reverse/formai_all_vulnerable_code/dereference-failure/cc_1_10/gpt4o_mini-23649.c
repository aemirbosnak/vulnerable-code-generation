//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define GRID_WIDTH 10
#define GRID_HEIGHT 10

typedef struct {
    int x, y;
} Point;

typedef struct Node {
    Point point;
    struct Node *parent;
    float g;  // Cost from start to this node
    float h;  // Heuristic cost to goal
    float f;  // Total cost
} Node;

Node *createNode(int x, int y, Node *parent, float g, float h) {
    Node *newNode = malloc(sizeof(Node));
    newNode->point.x = x;
    newNode->point.y = y;
    newNode->parent = parent;
    newNode->g = g;
    newNode->h = h;
    newNode->f = g + h;
    return newNode;
}

float heuristic(Point a, Point b) {
    return fabs(a.x - b.x) + fabs(a.y - b.y); // Manhattan distance
}

bool isValidPoint(int grid[GRID_HEIGHT][GRID_WIDTH], int x, int y) {
    return (x >= 0 && x < GRID_WIDTH && y >= 0 && y < GRID_HEIGHT && grid[y][x] == 0);
}

void tracePath(Node *node) {
    if (node == NULL) return;
    tracePath(node->parent);
    printf("(%d, %d) ", node->point.x, node->point.y);
}

void aStar(int grid[GRID_HEIGHT][GRID_WIDTH], Point start, Point goal) {
    Node *openList[GRID_WIDTH * GRID_HEIGHT] = {NULL};
    Node *closeList[GRID_WIDTH * GRID_HEIGHT] = {NULL};
    int openCount = 0, closeCount = 0;

    Node *startNode = createNode(start.x, start.y, NULL, 0.0, heuristic(start, goal));
    openList[openCount++] = startNode;

    while (openCount > 0) {
        int currentNodeIndex = -1;
        float lowestF = INFINITY;

        for (int i = 0; i < openCount; i++) {
            if (openList[i]->f < lowestF) {
                lowestF = openList[i]->f;
                currentNodeIndex = i;
            }
        }

        Node *currentNode = openList[currentNodeIndex];
        
        if (currentNode->point.x == goal.x && currentNode->point.y == goal.y) {
            printf("Path found: ");
            tracePath(currentNode);
            printf("\n");
            return;
        }

        closeList[closeCount++] = currentNode;
        openList[currentNodeIndex] = openList[--openCount];

        for (int deltaY = -1; deltaY <= 1; deltaY++) {
            for (int deltaX = -1; deltaX <= 1; deltaX++) {
                if (deltaY == 0 && deltaX == 0) continue; // Skip the current node

                int newX = currentNode->point.x + deltaX;
                int newY = currentNode->point.y + deltaY;

                if (!isValidPoint(grid, newX, newY)) continue;

                bool inCloseList = false;
                for (int j = 0; j < closeCount; j++) {
                    if (closeList[j]->point.x == newX && closeList[j]->point.y == newY) {
                        inCloseList = true;
                        break;
                    }
                }

                if (inCloseList) continue;

                float gNew = currentNode->g + sqrt(deltaX * deltaX + deltaY * deltaY);
                Node *neighborNode = NULL;

                for (int j = 0; j < openCount; j++) {
                    if (openList[j]->point.x == newX && openList[j]->point.y == newY) {
                        neighborNode = openList[j];
                        break;
                    }
                }

                if (neighborNode == NULL) {
                    neighborNode = createNode(newX, newY, currentNode, gNew, heuristic((Point){newX, newY}, goal));
                    openList[openCount++] = neighborNode;
                } else if (gNew < neighborNode->g) {
                    neighborNode->g = gNew;
                    neighborNode->f = gNew + neighborNode->h;
                    neighborNode->parent = currentNode;
                }
            }
        }
    }

    printf("No path found\n");
}

int main() {
    int grid[GRID_HEIGHT][GRID_WIDTH] = {
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 1, 1, 0, 1, 0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 1, 1, 1, 1, 0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 0, 1, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 0, 0, 0}
    };
    
    Point start = {0, 0}; // Starting point
    Point goal = {9, 9};  // Goal point

    aStar(grid, start, goal);

    return 0;
}