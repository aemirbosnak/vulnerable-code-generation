//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

#define GRID_SIZE 10
#define MAX_NODES GRID_SIZE * GRID_SIZE

typedef struct Node {
    int x, y;
    int gCost; // Cost from start node
    int hCost; // Heuristic cost to target node
    int fCost; // Total cost
    struct Node* parent;
} Node;

Node* openList[MAX_NODES];
Node* closedList[MAX_NODES];
int openListCount = 0;
int closedListCount = 0;

int startX = 0, startY = 0;
int targetX = 8, targetY = 8;

int grid[GRID_SIZE][GRID_SIZE] = {
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 0, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
    {0, 1, 1, 1, 1, 0, 0, 1, 0, 0},
    {0, 1, 0, 0, 0, 0, 1, 1, 1, 0},
    {0, 0, 0, 1, 1, 1, 0, 0, 0, 0},
    {0, 1, 0, 0, 1, 0, 1, 1, 1, 0},
    {0, 1, 1, 1, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

int heuristic(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

Node* createNode(int x, int y, Node* parent) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->parent = parent;
    node->gCost = parent ? parent->gCost + 1 : 0;
    node->hCost = heuristic(x, y, targetX, targetY);
    node->fCost = node->gCost + node->hCost;
    return node;
}

bool isNodeInList(Node* node, Node** list, int count) {
    for (int i = 0; i < count; i++) {
        if (list[i]->x == node->x && list[i]->y == node->y) return true;
    }
    return false;
}

void addToOpenList(Node* node) {
    openList[openListCount++] = node;
}

Node* getLowestFCostNode() {
    Node* lowestNode = NULL;
    for (int i = 0; i < openListCount; i++) {
        if (!lowestNode || openList[i]->fCost < lowestNode->fCost) {
            lowestNode = openList[i];
        }
    }
    return lowestNode;
}

void removeFromOpenList(Node* node) {
    for (int i = 0; i < openListCount; i++) {
        if (openList[i] == node) {
            openList[i] = openList[--openListCount];
            return;
        }
    }
}

void addToClosedList(Node* node) {
    closedList[closedListCount++] = node;
}

bool isWalkable(int x, int y) {
    return (x >= 0 && x < GRID_SIZE && y >= 0 && y < GRID_SIZE && grid[y][x] == 0);
}

void findPath() {
    Node* startNode = createNode(startX, startY, NULL);
    addToOpenList(startNode);

    while (openListCount > 0) {
        Node* currentNode = getLowestFCostNode();
        
        if (currentNode->x == targetX && currentNode->y == targetY) {
            printf("Path found:\n");
            Node* node = currentNode;
            while (node) {
                printf("(%d, %d) <- ", node->x, node->y);
                node = node->parent;
            }
            printf("Start\n");
            return;
        }

        removeFromOpenList(currentNode);
        addToClosedList(currentNode);

        int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        for (int i = 0; i < 4; i++) {
            int newX = currentNode->x + directions[i][0];
            int newY = currentNode->y + directions[i][1];
            
            if (isWalkable(newX, newY)) {
                Node* neighbor = createNode(newX, newY, currentNode);
                
                if (isNodeInList(neighbor, closedList, closedListCount)) {
                    free(neighbor);
                    continue;
                }

                if (!isNodeInList(neighbor, openList, openListCount)) {
                    addToOpenList(neighbor);
                } else {
                    for (int j = 0; j < openListCount; j++) {
                        if (openList[j]->x == neighbor->x && openList[j]->y == neighbor->y) {
                            if (openList[j]->gCost > neighbor->gCost) {
                                openList[j]->gCost = neighbor->gCost;
                                openList[j]->parent = currentNode;
                            }
                            free(neighbor);
                            break;
                        }
                    }
                }
            }
        }
    }

    printf("No path found!\n");
}

int main() {
    printf("A* Pathfinding Algorithm Example\n");
    printf("Starting at (%d, %d)\n", startX, startY);
    printf("Target at (%d, %d)\n\n", targetX, targetY);

    findPath();

    // Free memory
    for (int i = 0; i < openListCount; i++) {
        free(openList[i]);
    }
    for (int i = 0; i < closedListCount; i++) {
        free(closedList[i]);
    }

    return 0;
}