//GPT-4o-mini DATASET v1.0 Category: Pathfinding algorithms ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define WIDTH 10
#define HEIGHT 10
#define MAX_SIZE 100

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point point;           // Current point
    int gCost;            // Cost from start to the current node
    int hCost;            // Heuristic cost to the target
    int fCost;            // Total cost (gCost + hCost)
    struct Node* parent;  // Pointer to parent node
} Node;

Node* openList[MAX_SIZE];
Node* closedList[MAX_SIZE];
int openListCount = 0;
int closedListCount = 0;

int grid[HEIGHT][WIDTH] = {
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 1, 1, 1, 0, 1, 0, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0}
};

int heuristic(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

bool isPointInList(Point point, Node** list, int count) {
    for (int i = 0; i < count; i++) {
        if (list[i]->point.x == point.x && list[i]->point.y == point.y) {
            return true;
        }
    }
    return false;
}

void addToOpenList(Node* node) {
    openList[openListCount++] = node;
}

void addToClosedList(Node* node) {
    closedList[closedListCount++] = node;
}

Node* popLowestFCostNode() {
    Node* lowestFNode = openList[0];
    int lowestIndex = 0;

    for (int i = 1; i < openListCount; i++) {
        if (openList[i]->fCost < lowestFNode->fCost) {
            lowestFNode = openList[i];
            lowestIndex = i;
        }
    }

    openListCount--;
    openList[lowestIndex] = openList[openListCount];

    return lowestFNode;
}

void tracePath(Node* node) {
    Node* current = node;
    while (current != NULL) {
        printf("(%d, %d) <- ", current->point.x, current->point.y);
        current = current->parent;
    }
    printf("START\n");
}

void aStar(Point start, Point target) {
    Node* startNode = malloc(sizeof(Node));
    startNode->point = start;
    startNode->gCost = 0;
    startNode->hCost = heuristic(start, target);
    startNode->fCost = startNode->gCost + startNode->hCost;
    startNode->parent = NULL;

    addToOpenList(startNode);

    while (openListCount > 0) {
        Node* currentNode = popLowestFCostNode();
        
        if (currentNode->point.x == target.x && currentNode->point.y == target.y) {
            tracePath(currentNode);
            return;
        }

        addToClosedList(currentNode);

        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if ((dx == 0 && dy == 0) || (dx != 0 && dy != 0)) {
                    continue;
                }

                Point neighbor = {currentNode->point.x + dx, currentNode->point.y + dy};

                if (neighbor.x < 0 || neighbor.x >= WIDTH || neighbor.y < 0 || neighbor.y >= HEIGHT || grid[neighbor.y][neighbor.x] == 1) {
                    continue;
                }

                if (isPointInList(neighbor, closedList, closedListCount)) {
                    continue;
                }

                int tentativeGCost = currentNode->gCost + 1;

                Node* neighborNode = malloc(sizeof(Node));
                neighborNode->point = neighbor;
                neighborNode->gCost = tentativeGCost;
                neighborNode->hCost = heuristic(neighbor, target);
                neighborNode->fCost = neighborNode->gCost + neighborNode->hCost;
                neighborNode->parent = currentNode;

                if (isPointInList(neighbor, openList, openListCount) && tentativeGCost >= neighborNode->gCost) {
                    free(neighborNode);
                    continue;
                }

                addToOpenList(neighborNode);
            }
        }
    }

    printf("No path found!\n");
}

int main() {
    Point start = {0, 0};
    Point target = {9, 9};

    printf("Finding path from (%d, %d) to (%d, %d)\n", start.x, start.y, target.x, target.y);
    aStar(start, target);

    return 0;
}