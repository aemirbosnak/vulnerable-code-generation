//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define WIDTH 10
#define HEIGHT 10
#define MAX 10000

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point pos;
    int g_cost;
    int h_cost;
    int f_cost;
    struct Node* parent;
} Node;

Node* createNode(int x, int y, Node* parent) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->pos.x = x;
    newNode->pos.y = y;
    newNode->g_cost = 0;
    newNode->h_cost = 0;
    newNode->f_cost = 0;
    newNode->parent = parent;
    return newNode;
}

int heuristic(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

void addOpenList(Node** openList, int* openCount, Node* newNode) {
    openList[(*openCount)++] = newNode;
}

bool isInOpenList(Node** openList, int openCount, Node* node) {
    for (int i = 0; i < openCount; i++) {
        if (openList[i]->pos.x == node->pos.x && openList[i]->pos.y == node->pos.y) {
            return true;
        }
    }
    return false;
}

bool isInClosedList(Node** closedList, int closedCount, Node* node) {
    for (int i = 0; i < closedCount; i++) {
        if (closedList[i]->pos.x == node->pos.x && closedList[i]->pos.y == node->pos.y) {
            return true;
        }
    }
    return false;
}

void printPath(Node* node) {
    if (node == NULL) return;
    printPath(node->parent);
    printf("(%d, %d) ", node->pos.x, node->pos.y);
}

void aStar(Point start, Point end, int grid[HEIGHT][WIDTH]) {
    Node* openList[MAX];
    Node* closedList[MAX];
    int openCount = 0;
    int closedCount = 0;

    Node* startNode = createNode(start.x, start.y, NULL);
    startNode->g_cost = 0;
    startNode->h_cost = heuristic(start, end);
    startNode->f_cost = startNode->h_cost;

    addOpenList(openList, &openCount, startNode);

    while (openCount > 0) {
        int lowestIndex = 0;
        for (int i = 0; i < openCount; i++) {
            if (openList[i]->f_cost < openList[lowestIndex]->f_cost) {
                lowestIndex = i;
            }
        }

        Node* currentNode = openList[lowestIndex];

        if (currentNode->pos.x == end.x && currentNode->pos.y == end.y) {
            printf("Path found: ");
            printPath(currentNode);
            printf("\n");
            return;
        }

        // Move current node to closed list
        closedList[closedCount++] = currentNode;

        // Remove current node from open list
        for (int i = lowestIndex; i < openCount - 1; i++) {
            openList[i] = openList[i + 1];
        }
        openCount--;

        // Check neighboring nodes
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if ((dx == 0 && dy == 0) || (abs(dx) == abs(dy))) continue;

                int neighborX = currentNode->pos.x + dx;
                int neighborY = currentNode->pos.y + dy;

                if (neighborX < 0 || neighborX >= WIDTH || neighborY < 0 || neighborY >= HEIGHT || grid[neighborY][neighborX] != 0) {
                    continue;
                }

                Node* neighborNode = createNode(neighborX, neighborY, currentNode);
                neighborNode->g_cost = currentNode->g_cost + 1;
                neighborNode->h_cost = heuristic(neighborNode->pos, end);
                neighborNode->f_cost = neighborNode->g_cost + neighborNode->h_cost;

                if (isInClosedList(closedList, closedCount, neighborNode)) {
                    free(neighborNode);
                    continue;
                }

                if (!isInOpenList(openList, openCount, neighborNode) || neighborNode->f_cost < currentNode->f_cost) {
                    addOpenList(openList, &openCount, neighborNode);
                } else {
                    free(neighborNode);
                }
            }
        }
    }

    printf("No path found.\n");
}

int main() {
    Point start = {0, 0};
    Point end = {9, 9};
    int grid[HEIGHT][WIDTH] = {
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 1, 0, 1, 1, 0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 1, 1, 1, 1, 1, 0, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 0, 1, 1, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0}
    };

    aStar(start, end, grid);
    
    return 0;
}