//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define GRID_SIZE 10
#define OBSTACLE '#'
#define PATH '.'
#define OPEN ' '
#define START 'S'
#define GOAL 'G'

typedef struct Node {
    int x;
    int y;
    int g; // cost from start to node
    int h; // heuristic cost to goal
    int f; // total cost
    struct Node* parent;
} Node;

Node* createNode(int x, int y, int g, int h, Node* parent) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->g = g;
    newNode->h = h;
    newNode->f = g + h;
    newNode->parent = parent;
    return newNode;
}

int heuristic(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2); // Manhattan distance
}

bool isValid(int grid[GRID_SIZE][GRID_SIZE], int x, int y) {
    return (x >= 0 && x < GRID_SIZE && y >= 0 && y < GRID_SIZE && grid[y][x] == OPEN);
}

void printPath(Node* node) {
    if (node == NULL) return;
    printPath(node->parent);
    if (node->parent != NULL) {
        printf("-> (%d, %d) ", node->x, node->y);
    } else {
        printf("Start: (%d, %d) ", node->x, node->y);
    }
}

void freeNodes(Node* nodes[], int count) {
    for (int i = 0; i < count; i++) {
        free(nodes[i]);
    }
}

void aStar(int grid[GRID_SIZE][GRID_SIZE], int startX, int startY, int goalX, int goalY) {
    Node* openList[GRID_SIZE * GRID_SIZE] = {NULL};
    Node* closedList[GRID_SIZE * GRID_SIZE] = {NULL};
    int openCount = 0, closedCount = 0;

    Node* startNode = createNode(startX, startY, 0, heuristic(startX, startY, goalX, goalY), NULL);
    openList[openCount++] = startNode;

    while (openCount > 0) {
        int minIndex = 0;
        for (int i = 1; i < openCount; i++) {
            if (openList[i]->f < openList[minIndex]->f) {
                minIndex = i;
            }
        }

        Node* currentNode = openList[minIndex];

        if (currentNode->x == goalX && currentNode->y == goalY) {
            printf("Path Found:\n");
            printPath(currentNode);
            printf("-> Goal: (%d, %d)\n", goalX, goalY);
            freeNodes(openList, openCount);
            freeNodes(closedList, closedCount);
            return;
        }

        // Move current node to closed list
        closedList[closedCount++] = currentNode;
        openCount--;
        for (int i = minIndex; i < openCount; i++) {
            openList[i] = openList[i + 1];
        }

        // Explore neighbors
        int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // Up, Right, Down, Left
        for (int i = 0; i < 4; i++) {
            int neighborX = currentNode->x + directions[i][0];
            int neighborY = currentNode->y + directions[i][1];

            if (!isValid(grid, neighborX, neighborY)) continue;

            int gCost = currentNode->g + 1;
            Node* neighbor = createNode(neighborX, neighborY, gCost, heuristic(neighborX, neighborY, goalX, goalY), currentNode);

            bool inClosedList = false;
            for (int j = 0; j < closedCount; j++) {
                if (closedList[j]->x == neighbor->x && closedList[j]->y == neighbor->y) {
                    inClosedList = true;
                    free(neighbor);
                    break;
                }
            }

            if (inClosedList) continue;

            bool inOpenList = false;
            for (int j = 0; j < openCount; j++) {
                if (openList[j]->x == neighbor->x && openList[j]->y == neighbor->y) {
                    inOpenList = true;
                    if (gCost < openList[j]->g) {
                        openList[j]->g = gCost;
                        openList[j]->f = gCost + openList[j]->h;
                        openList[j]->parent = currentNode;
                    }
                    free(neighbor);
                    break;
                }
            }

            if (!inOpenList) {
                openList[openCount++] = neighbor;
            }
        }
    }

    printf("No Path Found\n");
    freeNodes(openList, openCount);
    freeNodes(closedList, closedCount);
}

int main() {
    int grid[GRID_SIZE][GRID_SIZE] = {
        {OPEN, OPEN, OPEN, OPEN, OBSTACLE, OPEN, OPEN, OPEN, OPEN, OPEN},
        {OPEN, OBSTACLE, OPEN, OBSTACLE, OBSTACLE, OPEN, OBSTACLE, OBSTACLE, OPEN, OPEN},
        {OPEN, OBSTACLE, OPEN, OPEN, OPEN, OPEN, OPEN, OBSTACLE, OPEN, OPEN},
        {OPEN, OPEN, OPEN, OBSTACLE, OBSTACLE, OBSTACLE, OPEN, OBSTACLE, OBSTACLE, OPEN},
        {OPEN, OBSTACLE, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN},
        {OPEN, OPEN, OBSTACLE, OBSTACLE, OBSTACLE, OPEN, OBSTACLE, OBSTACLE, OBSTACLE, OPEN},
        {OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OBSTACLE, OPEN, OPEN},
        {OPEN, OBSTACLE, OBSTACLE, OBSTACLE, OBSTACLE, OPEN, OPEN, OPEN, OPEN, OPEN},
        {OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OBSTACLE, OBSTACLE, OBSTACLE, OPEN},
        {OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN}
    };

    grid[0][0] = START;
    grid[9][9] = GOAL;

    aStar(grid, 0, 0, 9, 9);

    return 0;
}