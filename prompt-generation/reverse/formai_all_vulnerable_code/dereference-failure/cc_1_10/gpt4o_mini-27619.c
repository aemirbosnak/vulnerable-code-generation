//GPT-4o-mini DATASET v1.0 Category: Pathfinding algorithms ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define WIDTH 10
#define HEIGHT 10
#define MAX_PATH 100

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point point;
    int gCost; // Cost from start to current node
    int hCost; // Heuristic cost from current node to end
    int fCost; // gCost + hCost
    struct Node* parent; // To retrace path
} Node;

Node* createNode(int x, int y, Node* parent) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->point.x = x;
    node->point.y = y;
    node->parent = parent;
    node->gCost = 0;
    node->hCost = 0;
    node->fCost = 0;
    return node;
}

void freeNode(Node* node) {
    if (node) {
        free(node);
    }
}

int calculateH(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

bool isValid(Point p) {
    return (p.x >= 0 && p.x < WIDTH && p.y >= 0 && p.y < HEIGHT);
}

bool contains(Point* arr, int size, Point p) {
    for (int i = 0; i < size; i++) {
        if (arr[i].x == p.x && arr[i].y == p.y) {
            return true;
        }
    }
    return false;
}

void retracePath(Node* node) {
    if (node == NULL) {
        return;
    }
    retracePath(node->parent);
    printf(" -> (%d, %d)", node->point.x, node->point.y);
}

void aStar(Point start, Point end) {
    Node* openList[MAX_PATH];
    Point closedList[MAX_PATH];
    int openSize = 0, closedSize = 0;

    Node* startNode = createNode(start.x, start.y, NULL);
    startNode->gCost = 0;
    startNode->hCost = calculateH(start, end);
    startNode->fCost = startNode->gCost + startNode->hCost;

    openList[openSize++] = startNode;

    while (openSize > 0) {
        int bestIndex = 0;
        for (int i = 1; i < openSize; i++) {
            if (openList[i]->fCost < openList[bestIndex]->fCost) {
                bestIndex = i;
            }
        }

        Node* currentNode = openList[bestIndex];

        if (currentNode->point.x == end.x && currentNode->point.y == end.y) {
            printf("Path found: ");
            retracePath(currentNode);
            printf(" -> (%d, %d)\n", end.x, end.y);
            freeNode(currentNode);
            return;
        }

        openSize--;
        for (int i = bestIndex; i < openSize; i++) {
            openList[i] = openList[i + 1];
        }

        closedList[closedSize++] = currentNode->point;

        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (abs(dx) == abs(dy)) continue; // Skip diagonals

                Point nextPoint = {currentNode->point.x + dx, currentNode->point.y + dy};

                if (!isValid(nextPoint) || contains(closedList, closedSize, nextPoint)) {
                    continue;
                }

                Node* neighbor = createNode(nextPoint.x, nextPoint.y, currentNode);
                neighbor->gCost = currentNode->gCost + 1;
                neighbor->hCost = calculateH(nextPoint, end);
                neighbor->fCost = neighbor->gCost + neighbor->hCost;

                bool inOpen = contains((Point*)openList, openSize, nextPoint);
                if (!inOpen || neighbor->fCost < openList[bestIndex]->fCost) {
                    if (inOpen) {
                        // Update the existing node
                        freeNode(openList[bestIndex]);
                    }
                    openList[openSize++] = neighbor;
                } else {
                    freeNode(neighbor);
                }
            }
        }
        freeNode(currentNode);
    }

    printf("No path found!\n");
}

int main() {
    Point start = {0, 0};
    Point end = {9, 9};
    aStar(start, end);
    return 0;
}