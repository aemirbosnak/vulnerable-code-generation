//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define WIDTH 10
#define HEIGHT 10
#define OBSTACLE -1
#define FREE 0

typedef struct Node {
    int x, y;
    int g; // Cost from start to this node
    int h; // Heuristic cost to target
    struct Node *parent;
} Node;

Node *createNode(int x, int y, Node *parent, int g, int h) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->g = g;
    node->h = h;
    node->parent = parent;
    return node;
}

int heuristic(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2); // Manhattan Distance
}

bool isValid(int grid[HEIGHT][WIDTH], int x, int y) {
    return x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT && grid[y][x] != OBSTACLE;
}

bool isInList(Node **list, int totalNodes, int x, int y) {
    for (int i = 0; i < totalNodes; i++) {
        if (list[i]->x == x && list[i]->y == y) {
            return true;
        }
    }
    return false;
}

void printPath(Node *node) {
    if (node == NULL) return;
    printPath(node->parent);
    printf("(%d, %d) ", node->x, node->y);
}

void aStar(int grid[HEIGHT][WIDTH], int startX, int startY, int goalX, int goalY) {
    Node *openList[WIDTH * HEIGHT];
    int openCount = 0;

    Node *closedList[WIDTH * HEIGHT];
    int closedCount = 0;

    Node *startNode = createNode(startX, startY, NULL, 0, heuristic(startX, startY, goalX, goalY));
    openList[openCount++] = startNode;

    while (openCount > 0) {
        // Find the node with the lowest F cost
        int lowestIndex = 0;
        for (int i = 1; i < openCount; i++) {
            if (openList[i]->g + openList[i]->h < openList[lowestIndex]->g + openList[lowestIndex]->h) {
                lowestIndex = i;
            }
        }

        Node *currentNode = openList[lowestIndex];

        // Goal check
        if (currentNode->x == goalX && currentNode->y == goalY) {
            printf("Path found: ");
            printPath(currentNode);
            printf("\n");
            return;
        }

        // Move current node to closed list
        closedList[closedCount++] = currentNode;

        // Remove current node from open list
        openList[lowestIndex] = openList[--openCount];

        // Check adjacent nodes
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (abs(dx) == abs(dy)) continue; // Skip diagonals
                int nextX = currentNode->x + dx;
                int nextY = currentNode->y + dy;
                if (!isValid(grid, nextX, nextY)) continue;

                int gCost = currentNode->g + 1; // Cost from start to neighbor
                int hCost = heuristic(nextX, nextY, goalX, goalY);

                // Create a new node for neighbor
                Node *neighbor = createNode(nextX, nextY, currentNode, gCost, hCost);

                // Skip if already in closed list
                if (isInList(closedList, closedCount, nextX, nextY)) {
                    free(neighbor);
                    continue;
                }

                // Check if this node is already in open list
                if (!isInList(openList, openCount, nextX, nextY)) {
                    openList[openCount++] = neighbor; // Add new node to open list
                } else {
                    // Check if this path is better (lower g cost)
                    for (int i = 0; i < openCount; i++) {
                        if (openList[i]->x == nextX && openList[i]->y == nextY && openList[i]->g <= gCost) {
                            free(neighbor);
                            break;
                        }
                    }
                }
            }
        }
    }

    printf("No path found.\n");
}

int main() {
    int grid[HEIGHT][WIDTH] = {
        {FREE, FREE, FREE, FREE, OBSTACLE, FREE, FREE, FREE, FREE, FREE},
        {FREE, OBSTACLE, OBSTACLE, FREE, OBSTACLE, FREE, OBSTACLE, OBSTACLE, OBSTACLE, FREE},
        {FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, OBSTACLE, FREE},
        {OBSTACLE, OBSTACLE, OBSTACLE, OBSTACLE, OBSTACLE, FREE, OBSTACLE, OBSTACLE, FREE, FREE},
        {FREE, FREE, FREE, FREE, OBSTACLE, FREE, FREE, FREE, FREE, FREE},
        {FREE, OBSTACLE, OBSTACLE, FREE, OBSTACLE, OBSTACLE, OBSTACLE, FREE, OBSTACLE, FREE},
        {FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE},
        {FREE, OBSTACLE, OBSTACLE, OBSTACLE, OBSTACLE, FREE, OBSTACLE, OBSTACLE, OBSTACLE, FREE},
        {FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE},
        {FREE, OBSTACLE, OBSTACLE, FREE, OBSTACLE, FREE, OBSTACLE, FREE, OBSTACLE, FREE}
    };

    int startX = 0, startY = 0;
    int goalX = 9, goalY = 9;

    aStar(grid, startX, startY, goalX, goalY);

    return 0;
}