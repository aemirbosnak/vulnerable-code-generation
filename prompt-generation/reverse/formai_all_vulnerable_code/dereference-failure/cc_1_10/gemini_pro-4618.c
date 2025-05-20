//GEMINI-pro DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define ROWS 5
#define COLS 5

// A-star search algorithm
struct Node {
    int x, y;
    int f, g, h;
    struct Node *parent;
};

struct Node *makeNode(int x, int y, int f, int g, int h, struct Node *parent) {
    struct Node *node = malloc(sizeof(struct Node));
    node->x = x;
    node->y = y;
    node->f = f;
    node->g = g;
    node->h = h;
    node->parent = parent;
    return node;
}

struct Node *findMinNode(struct Node **openList, int size) {
    struct Node *minNode = NULL;
    int minF = INT_MAX;
    for (int i = 0; i < size; i++) {
        if (openList[i] != NULL && openList[i]->f < minF) {
            minNode = openList[i];
            minF = openList[i]->f;
        }
    }
    return minNode;
}

bool isWalkable(int x, int y, int **grid) {
    return (x >= 0 && x < ROWS && y >= 0 && y < COLS && grid[x][y] != 1);
}

struct Node **createOpenList(int **grid) {
    struct Node **openList = malloc(sizeof(struct Node *) * ROWS * COLS);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (isWalkable(i, j, grid)) {
                openList[i * COLS + j] = makeNode(i, j, 0, 0, 0, NULL);
            } else {
                openList[i * COLS + j] = NULL;
            }
        }
    }
    return openList;
}

void calculateFGH(struct Node *node, int endX, int endY) {
    int g = node->g + 1;
    int h = abs(node->x - endX) + abs(node->y - endY);
    int f = g + h;
    node->g = g;
    node->h = h;
    node->f = f;
}

struct Node **findPath(int **grid, int startX, int startY, int endX, int endY) {
    struct Node **openList = createOpenList(grid);
    struct Node *startNode = openList[startX * COLS + startY];
    startNode->g = 0;
    startNode->h = abs(startX - endX) + abs(startY - endY);
    startNode->f = startNode->g + startNode->h;

    struct Node **closedList = malloc(sizeof(struct Node *) * ROWS * COLS);
    for (int i = 0; i < ROWS * COLS; i++) {
        closedList[i] = NULL;
    }

    while (true) {
        struct Node *currentNode = findMinNode(openList, ROWS * COLS);
        if (currentNode == NULL) {
            break;
        }

        openList[currentNode->x * COLS + currentNode->y] = NULL;
        closedList[currentNode->x * COLS + currentNode->y] = currentNode;

        if (currentNode->x == endX && currentNode->y == endY) {
            break;
        }

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int newX = currentNode->x + dx[i];
            int newY = currentNode->y + dy[i];
            if (isWalkable(newX, newY, grid) && closedList[newX * COLS + newY] == NULL) {
                struct Node *newNode = openList[newX * COLS + newY];
                if (newNode == NULL) {
                    newNode = makeNode(newX, newY, 0, 0, 0, NULL);
                    openList[newX * COLS + newY] = newNode;
                }
                calculateFGH(newNode, endX, endY);
                if (newNode->parent == NULL || newNode->g < newNode->parent->g) {
                    newNode->parent = currentNode;
                }
            }
        }
    }

    struct Node **path = NULL;
    if (closedList[endX * COLS + endY] != NULL) {
        int pathSize = 0;
        struct Node *node = closedList[endX * COLS + endY];
        while (node != NULL) {
            pathSize++;
            node = node->parent;
        }
        path = malloc(sizeof(struct Node *) * pathSize);
        int i = pathSize - 1;
        node = closedList[endX * COLS + endY];
        while (node != NULL) {
            path[i] = node;
            i--;
            node = node->parent;
        }
    }

    free(openList);
    free(closedList);
    return path;
}

void printPath(struct Node **path) {
    if (path == NULL) {
        printf("No path found\n");
        return;
    }
    for (int i = 0; path[i] != NULL; i++) {
        printf("(%d, %d)\n", path[i]->x, path[i]->y);
    }
}

int main() {
    int **grid = malloc(sizeof(int *) * ROWS);
    for (int i = 0; i < ROWS; i++) {
        grid[i] = malloc(sizeof(int) * COLS);
    }

    // Initialize the grid
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = 0;
        }
    }

    // Set some obstacles
    grid[1][2] = 1;
    grid[2][3] = 1;

    // Find the path from (0, 0) to (4, 4)
    struct Node **path = findPath(grid, 0, 0, 4, 4);

    // Print the path
    printPath(path);

    // Free the allocated memory
    for (int i = 0; i < ROWS; i++) {
        free(grid[i]);
    }
    free(grid);
    for (int i = 0; path[i] != NULL; i++) {
        free(path[i]);
    }
    free(path);
    return 0;
}