//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

#define WIDTH 10
#define HEIGHT 10
#define INF 999999

typedef struct {
    int x, y;
    float g, h;
    struct Node* parent;
} Node;

Node* createNode(int x, int y, Node* parent) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->g = INF;
    newNode->h = INF;
    newNode->parent = parent;
    return newNode;
}

float heuristic(int x1, int y1, int x2, int y2) {
    return fabs(x1 - x2) + fabs(y1 - y2); // Manhattan distance
}

bool isInBounds(int x, int y) {
    return (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT);
}

void printPath(Node* node) {
    if (node == NULL) {
        return;
    }
    printPath(node->parent);
    printf("(%d, %d) -> ", node->x, node->y);
}

int main() {
    int maze[HEIGHT][WIDTH] = {
        {0, 1, 0, 0, 0, 1, 0, 1, 0, 0},
        {0, 1, 0, 1, 1, 1, 0, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {1, 1, 1, 1, 1, 0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 1, 1, 1, 1, 1, 0, 1, 0, 1},
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 1, 1, 1, 1, 1, 1, 1, 0, 0}};

    Node* openList[WIDTH * HEIGHT];
    Node* closedList[WIDTH * HEIGHT];
    int openCount = 0, closedCount = 0;

    int startX = 0, startY = 0;
    int targetX = 9, targetY = 9;

    Node* startNode = createNode(startX, startY, NULL);
    startNode->g = 0;
    startNode->h = heuristic(startX, startY, targetX, targetY);

    openList[openCount++] = startNode;

    while (openCount > 0) {
        Node* currentNode = openList[0];
        int currentIndex = 0;

        for (int i = 1; i < openCount; i++) {
            if (openList[i]->g + openList[i]->h < currentNode->g + currentNode->h) {
                currentNode = openList[i];
                currentIndex = i;
            }
        }

        if (currentNode->x == targetX && currentNode->y == targetY) {
            printf("Path found! -> ");
            printPath(currentNode);
            printf("End\n");
            break;
        }

        // remove current from openList
        for (int i = currentIndex; i < openCount - 1; i++) {
            openList[i] = openList[i + 1];
        }
        openCount--;

        closedList[closedCount++] = currentNode;

        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int newX = currentNode->x + dx[i];
            int newY = currentNode->y + dy[i];

            if (!isInBounds(newX, newY) || maze[newY][newX] == 1) {
                continue; // Ignore walls and out of bounds
            }

            Node* neighbor = createNode(newX, newY, currentNode);
            if (neighbor->parent == NULL) {
                neighbor->g = currentNode->g + 1;
                neighbor->h = heuristic(newX, newY, targetX, targetY);
                
                // Check if neighbor exists in closedList
                bool inClosed = false;
                for (int j = 0; j < closedCount; j++) {
                    if (closedList[j]->x == newX && closedList[j]->y == newY) {
                        inClosed = true;
                        break;
                    }
                }
                if (!inClosed) {
                    // Check if neighbor already in openList
                    bool inOpen = false;
                    for (int j = 0; j < openCount; j++) {
                        if (openList[j]->x == newX && openList[j]->y == newY) {
                            inOpen = true;
                            if (neighbor->g < openList[j]->g) {
                                openList[j]->g = neighbor->g;
                                openList[j]->parent = currentNode;
                            }
                            break;
                        }
                    }
                    if (!inOpen) {
                        openList[openCount++] = neighbor;
                    }
                }
            }
            free(neighbor);
        }
    }

    for (int i = 0; i < openCount; i++) {
        free(openList[i]);
    }
    for (int i = 0; i < closedCount; i++) {
        free(closedList[i]);
    }

    return 0;
}