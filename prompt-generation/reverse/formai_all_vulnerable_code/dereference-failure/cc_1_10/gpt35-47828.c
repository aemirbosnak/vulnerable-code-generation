//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define ROWS 10
#define COLS 10

struct Node {
    int row, col;
    int gCost, hCost;
    bool open, closed;
    struct Node* parent;
};

struct Node* grid[ROWS][COLS];

struct Node* createNode(int row, int col) {
    struct Node* node = malloc(sizeof(struct Node));
    node->row = row;
    node->col = col;
    node->gCost = 0;
    node->hCost = 0;
    node->open = false;
    node->closed = false;
    node->parent = NULL;
    return node;
}

int manhattanDistance(struct Node* a, struct Node* b) {
    int dx = abs(a->col - b->col);
    int dy = abs(a->row - b->row);
    return dx + dy;
}

void insertNode(struct Node* node) {
    grid[node->row][node->col] = node;
}

struct Node* getNode(int row, int col) {
    return grid[row][col];
}

struct Node* lowestFCostNode(struct Node* openNodes[]) {
    struct Node* lowest = openNodes[0];
    for (int i = 0; i < ROWS*COLS; i++) {
        if (openNodes[i] == NULL) {
            break;
        }
        if (openNodes[i]->gCost + openNodes[i]->hCost < lowest->gCost + lowest->hCost) {
            lowest = openNodes[i];
        }
    }
    return lowest;
}

struct Node** getNeighbours(struct Node* node) {
    static struct Node* neighbours[8];
    int i = 0;
    for (int r = -1; r <= 1; r++) {
        for (int c = -1; c <= 1; c++) {
            if (r == 0 && c == 0) {
                continue;
            }
            int nr = node->row + r;
            int nc = node->col + c;
            if (nr < 0 || nr >= ROWS || nc < 0 || nc >= COLS) {
                continue;
            }
            neighbours[i++] = getNode(nr, nc);
        }
    }
    return neighbours;
}

void printGrid() {
    printf("\n");
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            if (grid[r][c]->closed) {
                printf("x ");
            } else if (grid[r][c]->open) {
                printf("o ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

void printPath(struct Node* node) {
    if (node->parent != NULL) {
        printPath(node->parent);
    }
    printf("(%d,%d) ", node->row, node->col);
}

void findPath(int startRow, int startCol, int endRow, int endCol) {
    struct Node* startNode = getNode(startRow, startCol);
    struct Node* endNode = getNode(endRow, endCol);

    struct Node* openNodes[ROWS*COLS] = {0};
    int openCount = 0;

    startNode->open = true;
    openNodes[openCount++] = startNode;

    while (openCount > 0) {
        struct Node* currentNode = lowestFCostNode(openNodes);
        if (currentNode == endNode) {
            printf("\nPath: ");
            printPath(currentNode);
            printf("\n");
            return;
        }
        currentNode->open = false;
        currentNode->closed = true;

        struct Node** neighbours = getNeighbours(currentNode);
        for (int i = 0; i < 8; i++) {
            if (neighbours[i] == NULL) {
                break;
            }
            if (neighbours[i]->closed) {
                continue;
            }
            int tentativeGCost = currentNode->gCost + 1;
            if (!neighbours[i]->open) {
                neighbours[i]->hCost = manhattanDistance(neighbours[i], endNode);
                openNodes[openCount++] = neighbours[i];
                neighbours[i]->open = true;
            } else if (tentativeGCost >= neighbours[i]->gCost) {
                continue;
            }
            neighbours[i]->parent = currentNode;
            neighbours[i]->gCost = tentativeGCost;
        }
        printGrid();
    }
    printf("\nNo path found.\n");
}

int main() {
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            insertNode(createNode(r, c));
        }
    }
    int startRow = 2, startCol = 2;
    int endRow = 8, endCol = 8;
    findPath(startRow, startCol, endRow, endCol);
    return 0;
}