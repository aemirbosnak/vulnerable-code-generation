//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// Dimensions of the grid
#define WIDTH 10
#define HEIGHT 10

// Node structure for the grid
typedef struct Node {
    int x, y;
    int g;  // Cost from start to this node
    int h;  // Heuristic cost to goal
    int f;  // Total cost
    struct Node* parent;
} Node;

Node* createNode(int x, int y, int g, int h, Node* parent);
int heuristic(int x1, int y1, int x2, int y2);
bool isValid(int x, int y);
void addOpen(Node*** openList, Node* node, int* openCount);
void removeOpen(Node*** openList, int* openCount, int index);
int getLowestF(Node** openList, int openCount);
void printPath(Node* node);
void aStar(int startX, int startY, int goalX, int goalY, int grid[HEIGHT][WIDTH]);

int main() {
    int grid[HEIGHT][WIDTH] = {
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 1, 1, 0, 1, 0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 0, 1, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 1, 1, 1, 1, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 0},
        {0, 1, 1, 1, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    int startX = 0, startY = 0;
    int goalX = 9, goalY = 9;

    printf("Starting A* Pathfinding from (%d, %d) to (%d, %d)\n", startX, startY, goalX, goalY);
    aStar(startX, startY, goalX, goalY, grid);
    return 0;
}

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

bool isValid(int x, int y) {
    return (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT);
}

void addOpen(Node*** openList, Node* node, int* openCount) {
    (*openList)[*openCount] = node;
    (*openCount)++;
}

void removeOpen(Node*** openList, int* openCount, int index) {
    free((*openList)[index]);
    for (int i = index; i < *openCount - 1; i++) {
        (*openList)[i] = (*openList)[i + 1];
    }
    (*openCount)--;
}

int getLowestF(Node** openList, int openCount) {
    int lowestIndex = 0;
    for (int i = 1; i < openCount; i++) {
        if (openList[i]->f < openList[lowestIndex]->f) {
            lowestIndex = i;
        }
    }
    return lowestIndex;
}

void printPath(Node* node) {
    if (node == NULL) return;
    printPath(node->parent);
    printf("(%d, %d) -> ", node->x, node->y);
}

void aStar(int startX, int startY, int goalX, int goalY, int grid[HEIGHT][WIDTH]) {
    Node** openList = (Node**)malloc(WIDTH * HEIGHT * sizeof(Node*));
    int openCount = 0;
    
    Node* startNode = createNode(startX, startY, 0, heuristic(startX, startY, goalX, goalY), NULL);
    addOpen(&openList, startNode, &openCount);

    bool found = false;

    while (openCount > 0) {
        int lowestIndex = getLowestF(openList, openCount);
        Node* currentNode = openList[lowestIndex];

        if (currentNode->x == goalX && currentNode->y == goalY) {
            found = true;
            printf("Path found: ");
            printPath(currentNode);
            printf("(%d, %d)\n", currentNode->x, currentNode->y);
            break;
        }

        removeOpen(&openList, &openCount, lowestIndex);

        for (int deltaY = -1; deltaY <= 1; deltaY++) {
            for (int deltaX = -1; deltaX <= 1; deltaX++) {
                if (abs(deltaX) + abs(deltaY) != 1) continue; // Only consider orthogonal moves

                int newX = currentNode->x + deltaX;
                int newY = currentNode->y + deltaY;

                if (isValid(newX, newY) && grid[newY][newX] == 0) {
                    int gCost = currentNode->g + 1; // Cost from start to neighbor
                    int hCost = heuristic(newX, newY, goalX, goalY);
                    Node* neighborNode = createNode(newX, newY, gCost, hCost, currentNode);
                    addOpen(&openList, neighborNode, &openCount);
                }
            }
        }
    }

    if (!found) {
        printf("No path found!\n");
    }

    for (int i = 0; i < openCount; i++) {
        free(openList[i]);
    }
    free(openList);
}