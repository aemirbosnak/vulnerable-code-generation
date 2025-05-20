//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define WIDTH 10
#define HEIGHT 10
#define INF 99999

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point point;
    int gCost;  // Cost from start to this node
    int hCost;  // Heuristic cost to end node
    int fCost;  // Total cost (g + h)
    Point *parent;
} Node;

Node *createNode(int x, int y, int gCost, int hCost, Node *parent) {
    Node *node = malloc(sizeof(Node));
    node->point = (Point){x, y};
    node->gCost = gCost;
    node->hCost = hCost;
    node->fCost = gCost + hCost;
    node->parent = parent;
    return node;
}

int heuristic(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

bool isValid(int grid[WIDTH][HEIGHT], int x, int y) {
    return (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT && grid[x][y] == 0);
}

void printPath(Node *node) {
    if (node == NULL) return;
    printPath(node->parent);
    printf("-> (%d, %d) ", node->point.x, node->point.y);
}

void cleanup(Node **nodes, int count) {
    for (int i = 0; i < count; i++) {
        free(nodes[i]);
    }
}

int aStar(int grid[WIDTH][HEIGHT], Point start, Point end) {
    Node *openList[WIDTH * HEIGHT];
    int openCount = 0;

    Node *closedList[WIDTH * HEIGHT];
    int closedCount = 0;

    openList[openCount++] = createNode(start.x, start.y, 0, heuristic(start, end), NULL);

    while (openCount > 0) {
        int lowestIndex = 0;
        for (int i = 1; i < openCount; i++) {
            if (openList[i]->fCost < openList[lowestIndex]->fCost) {
                lowestIndex = i;
            }
        }

        Node *current = openList[lowestIndex];

        // Check if we have reached the end node
        if (current->point.x == end.x && current->point.y == end.y) {
            printf("Path: ");
            printPath(current);
            printf("\n");
            cleanup(openList, openCount);
            cleanup(closedList, closedCount);
            return 0; // Path found
        }

        // Remove current from openList and add it to closedList
        openCount--;
        closedList[closedCount++] = current;
        openList[lowestIndex] = openList[openCount];

        // Explore neighbors
        int neighbors[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // 4 directions
        for (int i = 0; i < 4; i++) {
            int newX = current->point.x + neighbors[i][0];
            int newY = current->point.y + neighbors[i][1];

            if (!isValid(grid, newX, newY)) continue;

            bool inClosedList = false;
            for (int j = 0; j < closedCount; j++) {
                if (closedList[j]->point.x == newX && closedList[j]->point.y == newY) {
                    inClosedList = true;
                    break;
                }
            }
            if (inClosedList) continue;

            int newGCost = current->gCost + 1;
            bool inOpenList = false;
            for (int j = 0; j < openCount; j++) {
                if (openList[j]->point.x == newX && openList[j]->point.y == newY) {
                    inOpenList = true;
                    if (newGCost < openList[j]->gCost) {
                        openList[j]->gCost = newGCost;
                        openList[j]->fCost = newGCost + openList[j]->hCost;
                        openList[j]->parent = current;
                    }
                    break;
                }
            }

            if (!inOpenList) {
                openList[openCount++] = createNode(newX, newY, newGCost, heuristic((Point){newX, newY}, end), current);
            }
        }
    }

    printf("No path found!\n");
    cleanup(openList, openCount);
    cleanup(closedList, closedCount);
    return -1; // No path found
}

int main() {
    int grid[WIDTH][HEIGHT] = {
        {0, 0, 0, 1, 0, 0, 0, 1, 0, 0},
        {0, 1, 0, 1, 0, 1, 0, 0, 0, 0},
        {0, 1, 0, 1, 0, 0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 1, 1, 0, 1, 0},
        {1, 1, 1, 0, 0, 0, 0, 0, 1, 1},
        {0, 0, 0, 1, 1, 1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1, 0, 1, 1, 1, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 1, 1, 1, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };

    Point start = {0, 0};
    Point end = {9, 9};

    aStar(grid, start, end);

    return 0;
}