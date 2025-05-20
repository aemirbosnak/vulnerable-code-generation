//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX 20 // maximum dimensions of the grid

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point pos;
    float f, g, h;
    struct Node* parent;
} Node;

Node* createNode(int x, int y, float g, float h, Node* parent) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->pos.x = x;
    node->pos.y = y;
    node->g = g;
    node->h = h;
    node->f = g + h;
    node->parent = parent;
    return node;
}

float heuristic(Point a, Point b) {
    // Using the Manhattan distance as heuristic
    return fabs(a.x - b.x) + fabs(a.y - b.y);
}

bool isValid(int grid[MAX][MAX], int row, int col, int ROW, int COL) {
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL) && (grid[row][col] == 0);
}

bool isDestination(Point dest, Point curr) {
    return (curr.x == dest.x && curr.y == dest.y);
}

void tracePath(Node* node) {
    while (node != NULL) {
        printf("(%d, %d) <- ", node->pos.x, node->pos.y);
        node = node->parent;
    }
    printf("Start\n");
}

void aStar(int grid[MAX][MAX], Point start, Point dest, int ROW, int COL) {
    Node* openList[MAX * MAX];
    int openCount = 0;

    Node* closedList[MAX * MAX];
    int closedCount = 0;

    openList[openCount++] = createNode(start.x, start.y, 0.0, heuristic(start, dest), NULL);

    while (openCount > 0) {
        int lowestIndex = 0;
        for (int i = 1; i < openCount; i++) {
            if (openList[i]->f < openList[lowestIndex]->f) {
                lowestIndex = i;
            }
        }
        
        Node* currentNode = openList[lowestIndex];

        if (isDestination(dest, currentNode->pos)) {
            printf("Path found: ");
            tracePath(currentNode);
            return;
        }

        openList[lowestIndex] = openList[--openCount];
        closedList[closedCount++] = currentNode;

        // Possible moves: down, up, right, left
        int row[] = {1, -1, 0, 0};
        int col[] = {0, 0, 1, -1};

        for (int i = 0; i < 4; i++) {
            int newX = currentNode->pos.x + row[i];
            int newY = currentNode->pos.y + col[i];

            if (isValid(grid, newX, newY, ROW, COL)) {
                bool inClosedList = false;
                for (int j = 0; j < closedCount; j++) {
                    if (closedList[j]->pos.x == newX && closedList[j]->pos.y == newY) {
                        inClosedList = true;
                        break;
                    }
                }

                if (inClosedList) continue;

                float newG = currentNode->g + 1.0;
                Node* successor = NULL;
                for (int j = 0; j < openCount; j++) {
                    if (openList[j]->pos.x == newX && openList[j]->pos.y == newY) {
                        successor = openList[j];
                        break;
                    }
                }

                if (successor == NULL) {
                    successor = createNode(newX, newY, newG, heuristic((Point){newX, newY}, dest), currentNode);
                    openList[openCount++] = successor;
                } else if (successor->g > newG) {
                    successor->g = newG;
                    successor->f = newG + successor->h;
                    successor->parent = currentNode;
                }
            }
        }
    }

    printf("No path found\n");
}

int main() {
    int grid[MAX][MAX] = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0},
    };

    Point start = {0, 0};
    Point destination = {4, 4};

    printf("Finding path from (%d, %d) to (%d, %d)\n", start.x, start.y, destination.x, destination.y);
    aStar(grid, start, destination, 5, 5);

    return 0;
}