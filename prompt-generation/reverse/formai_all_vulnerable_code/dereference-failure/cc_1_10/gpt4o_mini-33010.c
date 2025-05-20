//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define WIDTH 10
#define HEIGHT 10
#define MAX_NODES_WIDTH (WIDTH * HEIGHT)
#define INF 9999

typedef struct Node {
    int x, y;
    float g; // cost from start to current node
    float h; // heuristic cost to target node
    float f; // total cost
    struct Node* parent;
} Node;

Node* openList[MAX_NODES_WIDTH];
Node* closedList[MAX_NODES_WIDTH];
int openCount = 0, closedCount = 0;

float heuristic(Node* a, Node* b) {
    return fabs(a->x - b->x) + fabs(a->y - b->y);
}

Node* createNode(int x, int y, Node* parent) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->g = parent ? parent->g + 1 : 0; 
    node->h = 0;
    node->f = 0;
    node->parent = parent;
    return node;
}

void addToOpenList(Node* node) {
    openList[openCount++] = node;
}

void addToClosedList(Node* node) {
    closedList[closedCount++] = node;
}

bool isOnList(Node* node, Node** list, int count) {
    for (int i = 0; i < count; i++) {
        if (list[i]->x == node->x && list[i]->y == node->y) {
            return true;
        }
    }
    return false;
}

Node* getLowestFNode() {
    Node* lowest = NULL;
    for (int i = 0; i < openCount; i++) {
        if (lowest == NULL || openList[i]->f < lowest->f) {
            lowest = openList[i];
        }
    }
    return lowest;
}

void reconstructPath(Node* node) {
    printf("Path: ");
    while (node) {
        printf("(%d, %d) ", node->x, node->y);
        node = node->parent;
    }
    printf("\n");
}

void aStar(int startX, int startY, int targetX, int targetY) {
    Node* startNode = createNode(startX, startY, NULL);
    Node* targetNode = createNode(targetX, targetY, NULL);

    addToOpenList(startNode);

    while (openCount > 0) {
        Node* currentNode = getLowestFNode();
        if (currentNode->x == targetNode->x && currentNode->y == targetNode->y) {
            reconstructPath(currentNode);
            return;
        }
        
        addToClosedList(currentNode);

        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (fabs(dx) + fabs(dy) != 1) continue; // skip diagonals

                int newX = currentNode->x + dx;
                int newY = currentNode->y + dy;

                if (newX < 0 || newX >= WIDTH || newY < 0 || newY >= HEIGHT) continue; // out of bounds
                
                Node* neighbor = createNode(newX, newY, currentNode);
                if (isOnList(neighbor, closedList, closedCount)) {
                    free(neighbor);
                    continue; // already evaluated
                }

                neighbor->h = heuristic(neighbor, targetNode);
                neighbor->f = neighbor->g + neighbor->h;

                if (!isOnList(neighbor, openList, openCount)) {
                    addToOpenList(neighbor);
                } else {
                    // check if new path is better
                    for (int i = 0; i < openCount; i++) {
                        if (openList[i]->x == neighbor->x && openList[i]->y == neighbor->y && neighbor->g < openList[i]->g) {
                            openList[i]->g = neighbor->g;
                            openList[i]->h = neighbor->h;
                            openList[i]->f = neighbor->f;
                            openList[i]->parent = currentNode;
                        }
                    }
                    free(neighbor); // We do not need the node anymore if it's already in the open list
                }
            }
        }
    }

    printf("No path found!\n");
}

int main() {
    int start_x = 0, start_y = 0;
    int target_x = 7, target_y = 8;

    aStar(start_x, start_y, target_x, target_y);

    for (int i = 0; i < openCount; i++) {
        free(openList[i]);
    }
    for (int i = 0; i < closedCount; i++) {
        free(closedList[i]);
    }

    return 0;
}