//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

#define WIDTH 10
#define HEIGHT 10
#define MAX_COST 1000
#define MAX_NODES (WIDTH * HEIGHT)

typedef struct Node {
    int x, y;
    float g; // Cost from start to current node
    float h; // Heuristic cost from current to end node
    float f; // Total cost
    struct Node* parent;
} Node;

Node* openSet[MAX_NODES];
int openSetCount = 0;
bool closedSet[WIDTH][HEIGHT];
Node* nodes[WIDTH][HEIGHT];

float heuristic(int x1, int y1, int x2, int y2) {
    return fabs(x1 - x2) + fabs(y1 - y2); // Manhattan distance
}

bool isInOpenSet(Node* node) {
    for (int i = 0; i < openSetCount; i++) {
        if (openSet[i]->x == node->x && openSet[i]->y == node->y) {
            return true;
        }
    }
    return false;
}

bool isInClosedSet(int x, int y) {
    return closedSet[x][y];
}

void addToOpenSet(Node* node) {
    openSet[openSetCount++] = node;
}

void removeFromOpenSet(Node* node) {
    for (int i = 0; i < openSetCount; i++) {
        if (openSet[i] == node) {
            openSet[i] = openSet[--openSetCount]; // Replace with last element
            return;
        }
    }
}

Node* getLowestFCostNode() {
    Node* lowest = openSet[0];
    for (int i = 1; i < openSetCount; i++) {
        if (openSet[i]->f < lowest->f) {
            lowest = openSet[i];
        }
    }
    return lowest;
}

void reconstructPath(Node* endNode) {
    Node* current = endNode;
    while (current != NULL) {
        printf("(%d, %d) ", current->x, current->y);
        current = current->parent;
    }
    printf("\n");
}

void initializeNodes() {
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            nodes[x][y] = (Node*)malloc(sizeof(Node));
            nodes[x][y]->x = x;
            nodes[x][y]->y = y;
            nodes[x][y]->g = MAX_COST;
            nodes[x][y]->h = 0;
            nodes[x][y]->f = MAX_COST;
            nodes[x][y]->parent = NULL;
            closedSet[x][y] = false;
        }
    }
}

void freeNodes() {
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            free(nodes[x][y]);
        }
    }
}

bool isWalkable(int x, int y) {
    // Example: Any node is walkable
    return x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT;
}

void aStarPathfinding(int startX, int startY, int endX, int endY) {
    Node* startNode = nodes[startX][startY];
    Node* endNode = nodes[endX][endY];

    startNode->g = 0;
    startNode->h = heuristic(startX, startY, endX, endY);
    startNode->f = startNode->h;

    addToOpenSet(startNode);

    while (openSetCount > 0) {
        Node* currentNode = getLowestFCostNode();

        if (currentNode->x == endNode->x && currentNode->y == endNode->y) {
            printf("Path found: ");
            reconstructPath(currentNode);
            return;
        }

        removeFromOpenSet(currentNode);
        closedSet[currentNode->x][currentNode->y] = true;

        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if ((dx == 0 && dy == 0) || (fabs(dx) + fabs(dy) > 2)) {
                    continue;
                }

                int neighborX = currentNode->x + dx;
                int neighborY = currentNode->y + dy;

                if (!isWalkable(neighborX, neighborY) || isInClosedSet(neighborX, neighborY)) {
                    continue;
                }

                Node* neighbor = nodes[neighborX][neighborY];
                float tempG = currentNode->g + 1;

                if (!isInOpenSet(neighbor)) {
                    addToOpenSet(neighbor);
                } else if (tempG >= neighbor->g) {
                    continue;
                }

                neighbor->parent = currentNode;
                neighbor->g = tempG;
                neighbor->h = heuristic(neighborX, neighborY, endX, endY);
                neighbor->f = neighbor->g + neighbor->h;
            }
        }
    }
    printf("No path found\n");
}

int main() {
    initializeNodes();

    int startX = 0, startY = 0;
    int endX = 7, endY = 8;

    printf("Starting A* Pathfinding from (%d, %d) to (%d, %d)\n", startX, startY, endX, endY);
    aStarPathfinding(startX, startY, endX, endY);

    freeNodes();
    return 0;
}