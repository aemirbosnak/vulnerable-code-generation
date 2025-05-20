//GPT-4o-mini DATASET v1.0 Category: Pathfinding algorithms ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define WIDTH 10
#define HEIGHT 10
#define MAX_NODES 100

typedef struct Node {
    int x, y;
    int gCost;  // Cost from start node
    int hCost;  // Heuristic cost to goal
    int fCost;  // Total cost
    struct Node* parent;
} Node;

Node* openList[MAX_NODES];
Node* closedList[MAX_NODES];
int openListCount = 0;
int closedListCount = 0;
int grid[HEIGHT][WIDTH] = {
    {0, 0, 1, 0, 0, 0, 1, 0, 1, 0},
    {0, 0, 1, 0, 1, 1, 1, 0, 1, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
    {1, 1, 1, 1, 0, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 1, 1, 1, 1, 1, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 1, 1, 1, 0},
    {0, 1, 1, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 1, 1, 1, 0},
    {0, 0, 1, 0, 0, 0, 0, 0, 0, 0}
};

void addToOpenList(Node* node) {
    openList[openListCount++] = node;
}

void addToClosedList(Node* node) {
    closedList[closedListCount++] = node;
}

bool isInClosedList(Node* node) {
    for (int i = 0; i < closedListCount; i++) {
        if (closedList[i]->x == node->x && closedList[i]->y == node->y) {
            return true;
        }
    }
    return false;
}

bool isInOpenList(Node* node) {
    for (int i = 0; i < openListCount; i++) {
        if (openList[i]->x == node->x && openList[i]->y == node->y) {
            return true;
        }
    }
    return false;
}

int calculateHCost(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2); // Manhattan distance
}

Node* createNode(int x, int y, Node* parent) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->gCost = parent->gCost + 1;
    newNode->hCost = calculateHCost(x, y, WIDTH - 1, HEIGHT - 1);
    newNode->fCost = newNode->gCost + newNode->hCost;
    newNode->parent = parent;
    return newNode;
}

void reconstructPath(Node* node) {
    while (node != NULL) {
        printf("(%d, %d) ", node->x, node->y);
        node = node->parent;
    }
    printf("\n");
}

void aStarPathfinding(int startX, int startY) {
    Node* startNode = createNode(startX, startY, NULL);
    addToOpenList(startNode);

    while (openListCount > 0) {
        // Find node with the lowest fCost
        int lowestIndex = 0;
        for (int i = 1; i < openListCount; i++) {
            if (openList[i]->fCost < openList[lowestIndex]->fCost) {
                lowestIndex = i;
            }
        }

        Node* currentNode = openList[lowestIndex];

        // Check for goal
        if (currentNode->x == WIDTH - 1 && currentNode->y == HEIGHT - 1) {
            printf("Path found: ");
            reconstructPath(currentNode);
            return;
        }

        // Move current node to closed list
        addToClosedList(currentNode);
        openListCount--;
        for (int i = lowestIndex; i < openListCount; i++) {
            openList[i] = openList[i + 1];
        }

        // Explore neighbors
        int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // DOWN, RIGHT, UP, LEFT
        for (int i = 0; i < 4; i++) {
            int newX = currentNode->x + directions[i][0];
            int newY = currentNode->y + directions[i][1];

            if (newX >= 0 && newX < WIDTH && newY >= 0 && newY < HEIGHT && grid[newY][newX] == 0) {
                Node* neighbor = createNode(newX, newY, currentNode);
                if (isInClosedList(neighbor)) {
                    free(neighbor);
                    continue;
                }
                if (!isInOpenList(neighbor)) {
                    addToOpenList(neighbor);
                } else if (neighbor->gCost < currentNode->gCost + 1) {
                    // Update parent node if the new path is better
                    free(neighbor);
                }
            }
        }
    }
    printf("No path found.\n");
}

int main() {
    aStarPathfinding(0, 0);
    return 0;
}