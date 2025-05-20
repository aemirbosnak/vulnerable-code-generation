//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#define ROW 10
#define COL 10
#define INF 99999

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point pos;
    int gCost; // Cost from start
    int hCost; // Heuristic cost to target
    int fCost; // Total cost
    struct Node* parent;
} Node;

Node* createNode(int x, int y, Node* parent) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->pos.x = x;
    n->pos.y = y;
    n->gCost = INF;
    n->hCost = INF;
    n->fCost = INF;
    n->parent = parent;
    return n;
}

int heuristic(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

bool isValid(int row, int col) {
    return (row >= 0 && row < ROW && col >= 0 && col < COL);
}

void tracePath(Node* node) {
    if (node == NULL) return;
    tracePath(node->parent);
    printf("-> (%d, %d) ", node->pos.x, node->pos.y);
}

void aStar(Point start, Point target, int grid[ROW][COL]) {
    Node* openList[ROW * COL] = {NULL};
    Node* closedList[ROW * COL] = {NULL};
    int openCount = 0, closedCount = 0;
    
    Node* startNode = createNode(start.x, start.y, NULL);
    startNode->gCost = 0;
    startNode->hCost = heuristic(start, target);
    startNode->fCost = startNode->gCost + startNode->hCost;
    
    openList[openCount++] = startNode;

    while (openCount > 0) {
        int index = 0;
        for (int i = 1; i < openCount; i++) {
            if (openList[i]->fCost < openList[index]->fCost) {
                index = i;
            }
        }

        Node* currentNode = openList[index];
        if (currentNode->pos.x == target.x && currentNode->pos.y == target.y) {
            printf("Path found: ");
            tracePath(currentNode);
            printf("\n");
            return;
        }

        openList[index] = openList[--openCount];
        closedList[closedCount++] = currentNode;

        // Explore neighbors
        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int i = 0; i < 4; i++) {
            int newX = currentNode->pos.x + directions[i][0];
            int newY = currentNode->pos.y + directions[i][1];

            if (isValid(newX, newY) && grid[newX][newY] == 0) {
                Node* neighbor = createNode(newX, newY, currentNode);
                bool skip = false;

                for (int j = 0; j < closedCount; j++) {
                    if (closedList[j]->pos.x == neighbor->pos.x && closedList[j]->pos.y == neighbor->pos.y) {
                        skip = true;
                        free(neighbor);
                        break;
                    }
                }

                if (skip) continue;

                neighbor->gCost = currentNode->gCost + 1;
                neighbor->hCost = heuristic(neighbor->pos, target);
                neighbor->fCost = neighbor->gCost + neighbor->hCost;

                for (int j = 0; j < openCount; j++) {
                    if (openList[j]->pos.x == neighbor->pos.x && openList[j]->pos.y == neighbor->pos.y && 
                        openList[j]->gCost <= neighbor->gCost) {
                        skip = true;
                        free(neighbor);
                        break;
                    }
                }

                if (!skip) {
                    openList[openCount++] = neighbor;
                }
            }
        }
    }

    printf("No path found!\n");
}

int main() {
    int grid[ROW][COL] = {
        {0, 0, 0, 0, 0, 1, 0, 1, 0, 0},
        {0, 1, 1, 0, 1, 1, 0, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 1, 1, 1, 1, 1, 0, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 0},
        {0, 1, 1, 1, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 1, 1, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0}
    };

    Point start = {0, 0};
    Point target = {9, 9};

    aStar(start, target, grid);
    return 0;
}