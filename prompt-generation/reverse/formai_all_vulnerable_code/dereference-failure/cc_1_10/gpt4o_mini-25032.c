//GPT-4o-mini DATASET v1.0 Category: Pathfinding algorithms ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define WIDTH 10
#define HEIGHT 10
#define MAX_NODES (WIDTH * HEIGHT)

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point position;
    float gCost;  // Cost from start to node
    float hCost;  // Heuristic cost to goal
    float fCost;  // Total cost
    struct Node* parent;
} Node;

Node* grid[WIDTH][HEIGHT];
Node* openSet[MAX_NODES];
int openSetSize = 0;

Point start = {0, 0};
Point goal = {9, 9};
int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // Right, Left, Down, Up

void initGrid() {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            grid[i][j] = (Node*)malloc(sizeof(Node));
            grid[i][j]->position.x = i;
            grid[i][j]->position.y = j;
            grid[i][j]->gCost = INFINITY;
            grid[i][j]->hCost = INFINITY;
            grid[i][j]->fCost = INFINITY;
            grid[i][j]->parent = NULL;
        }
    }
}

float heuristic(Point a, Point b) {
    return fabs(a.x - b.x) + fabs(a.y - b.y); // Manhattan distance
}

void addToOpenSet(Node* node) {
    openSet[openSetSize++] = node;
}

bool isInOpenSet(Node* node) {
    for (int i = 0; i < openSetSize; i++) {
        if (openSet[i] == node) {
            return true;
        }
    }
    return false;
}

Node* getLowestFCostNode() {
    Node* lowest = openSet[0];
    for (int i = 1; i < openSetSize; i++) {
        if (openSet[i]->fCost < lowest->fCost) {
            lowest = openSet[i];
        }
    }
    return lowest;
}

void removeFromOpenSet(Node* node) {
    for (int i = 0; i < openSetSize; i++) {
        if (openSet[i] == node) {
            openSet[i] = openSet[--openSetSize]; // Remove by replacing with the last element
            break;
        }
    }
}

void findPath() {
    grid[start.x][start.y]->gCost = 0;
    grid[start.x][start.y]->hCost = heuristic(start, goal);
    grid[start.x][start.y]->fCost = grid[start.x][start.y]->hCost;
    addToOpenSet(grid[start.x][start.y]);

    while (openSetSize > 0) {
        Node* currentNode = getLowestFCostNode();
        if (currentNode->position.x == goal.x && currentNode->position.y == goal.y) {
            printf("Path found:\n");
            Node* pathNode = currentNode;
            while (pathNode != NULL) {
                printf("(%d, %d) ", pathNode->position.x, pathNode->position.y);
                pathNode = pathNode->parent;
            }
            printf("\n");
            return;
        }

        removeFromOpenSet(currentNode);

        for (int i = 0; i < 4; i++) {
            int newX = currentNode->position.x + directions[i][0];
            int newY = currentNode->position.y + directions[i][1];

            if (newX >= 0 && newX < WIDTH && newY >= 0 && newY < HEIGHT) {
                Node* neighbor = grid[newX][newY];
                float tentativeGCost = currentNode->gCost + 1; // Assuming each move costs 1

                if (tentativeGCost < neighbor->gCost) {
                    neighbor->parent = currentNode;
                    neighbor->gCost = tentativeGCost;
                    neighbor->hCost = heuristic(neighbor->position, goal);
                    neighbor->fCost = neighbor->gCost + neighbor->hCost;

                    if (!isInOpenSet(neighbor)) {
                        addToOpenSet(neighbor);
                    }
                }
            }
        }
    }
    printf("No path found.\n");
}

void freeMemory() {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            free(grid[i][j]);
        }
    }
}

int main() {
    initGrid();
    findPath();
    freeMemory();
    return 0;
}