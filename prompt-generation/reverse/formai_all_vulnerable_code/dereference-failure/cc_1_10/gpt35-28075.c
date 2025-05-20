//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

#define ROW 10
#define COL 10

// Define a struct to represent a grid cell
struct Node {
    int x;
    int y;
    int f;
    int g;
    int h;
    bool obstacle;
    struct Node* parent;
};

// Define a function to create a new node
struct Node* newNode(int x, int y) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->x = x;
    node->y = y;
    node->f = 0;
    node->g = 0;
    node->h = 0;
    node->obstacle = false;
    node->parent = NULL;
    return node;
}

// Define a function to check if a cell is within bounds
bool isWithinBounds(int x, int y) {
    return (x >= 0 && x < ROW && y >= 0 && y < COL);
}

// Define a function to check if a cell is an obstacle
bool isObstacle(int grid[][COL], int x, int y) {
    return (grid[x][y] == 1);
}

// Define a function to calculate the Manhattan distance between two cells
int getManhattanDistance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

// Define the A* pathfinding algorithm
void AstarPathfinding(int grid[][COL], struct Node* start, struct Node* end) {
    // Define arrays to store all the open and closed nodes
    struct Node* openList[ROW * COL];
    struct Node* closedList[ROW * COL];
    int openCount = 0;
    int closedCount = 0;

    // Add the start node to the open list
    openList[openCount] = start;
    openCount++;

    // Loop while the open list is not empty
    while (openCount > 0) {
        // Find the node with the lowest f value in the open list
        int minFIndex = 0;
        for (int i = 0; i < openCount; i++) {
            if (openList[i]->f < openList[minFIndex]->f) {
                minFIndex = i;
            }
        }

        // Set the current node as the node with the lowest f value
        struct Node* current = openList[minFIndex];

        // If the current node is the end node, then we have found the path
        if (current->x == end->x && current->y == end->y) {
            // Trace back the path and mark it on the grid
            while (current->parent != NULL) {
                grid[current->x][current->y] = 2;
                current = current->parent;
            }
            return;
        }

        // Remove the current node from the open list and add it to the closed list
        for (int i = minFIndex; i < openCount - 1; i++) {
            openList[i] = openList[i + 1];
        }
        openCount--;
        closedList[closedCount] = current;
        closedCount++;

        // Generate all the neighbors of the current node
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                int neighborX = current->x + i;
                int neighborY = current->y + j;
                if (!isWithinBounds(neighborX, neighborY) || isObstacle(grid, neighborX, neighborY)) {
                    continue;
                }

                // Set the neighbor node
                struct Node* neighbor = newNode(neighborX, neighborY);

                // If the neighbor is already in the closed list, skip it
                bool neighborInClosedList = false;
                for (int k = 0; k < closedCount; k++) {
                    if (closedList[k]->x == neighbor->x && closedList[k]->y == neighbor->y) {
                        neighborInClosedList = true;
                        break;
                    }
                }
                if (neighborInClosedList) {
                    continue;
                }

                // Calculate the g, h, and f values for the neighbor node
                int neighborG = current->g + getManhattanDistance(current->x, current->y, neighbor->x, neighbor->y);
                int neighborH = getManhattanDistance(neighbor->x, neighbor->y, end->x, end->y);
                int neighborF = neighborG + neighborH;

                // If the neighbor is already in the open list and its f value is lower, skip it
                bool neighborInOpenList = false;
                for (int k = 0; k < openCount; k++) {
                    if (openList[k]->x == neighbor->x && openList[k]->y == neighbor->y) {
                        if (openList[k]->f > neighborF) {
                            openList[k]->f = neighborF;
                            openList[k]->g = neighborG;
                            openList[k]->h = neighborH;
                            openList[k]->parent = current;
                        }
                        neighborInOpenList = true;
                        break;
                    }
                }
                if (neighborInOpenList) {
                    continue;
                }

                // Add the neighbor to the open list
                neighbor->f = neighborF;
                neighbor->g = neighborG;
                neighbor->h = neighborH;
                neighbor->parent = current;
                openList[openCount] = neighbor;
                openCount++;
            }
        }
    }
}

int main() {
    int grid[ROW][COL] = {
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };

    struct Node* start = newNode(0, 0);
    struct Node* end = newNode(9, 9);

    AstarPathfinding(grid, start, end);

    // Print the grid
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (grid[i][j] == 0) {
                printf(".");
            }
            else if (grid[i][j] == 1) {
                printf("#");
            }
            else if (grid[i][j] == 2) {
                printf("*");
            }
        }
        printf("\n");
    }

    return 0;
}