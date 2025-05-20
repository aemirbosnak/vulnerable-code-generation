//GPT-4o-mini DATASET v1.0 Category: Pathfinding algorithms ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define GRID_SIZE 10
#define OBSTACLE 'X'
#define PATH '.'
#define START 'S'
#define END 'E'

// Node structure for A*
typedef struct Node {
    int x;
    int y;
    int g;
    int h;
    int f;
    struct Node* parent;
} Node;

// Grid representation
char grid[GRID_SIZE][GRID_SIZE] = {
    {'.', '.', '.', '.', '.', 'X', '.', '.', '.', '.'},
    {'.', 'X', 'X', 'X', '.', 'X', '.', 'X', 'X'},
    {'.', '.', '.', 'X', '.', '.', '.', 'X', '.'},
    {'X', 'X', '.', 'X', 'X', 'X', 'X', 'X', '.'},
    {'.', '.', '.', '.', '.', '.', 'X', '.', '.'},
    {'.', 'X', 'X', 'X', 'X', '.', 'X', 'X', '.'},
    {'.', '.', '.', '.', 'X', '.', '.', '.', '.'},
    {'.', 'X', 'X', 'X', 'X', 'X', 'X', 'X', '.'},
    {'.', 'E', '.', '.', '.', '.', 'X', '.', 'S'},
    {'.', '.', '.', '.', 'X', 'X', 'X', 'X', '.'}
};

Node* createNode(int x, int y, int g, int h, Node* parent) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->g = g;
    newNode->h = h;
    newNode->f = g + h;
    newNode->parent = parent;
    return newNode;
}

int heuristic(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

bool isWithinGrid(int x, int y) {
    return (x >= 0 && x < GRID_SIZE && y >= 0 && y < GRID_SIZE);
}

bool isTraversable(int x, int y) {
    return isWithinGrid(x, y) && (grid[x][y] == PATH || grid[x][y] == 'E');
}

void printPath(Node* endNode) {
    Node* current = endNode;
    while (current) {
        grid[current->x][current->y] = '*'; // Mark path on grid
        current = current->parent;
    }
    
    // Print the grid with the path
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

void aStar(int startX, int startY, int endX, int endY) {
    Node* openList[GRID_SIZE * GRID_SIZE] = { NULL };
    int openListCount = 0;

    Node* startNode = createNode(startX, startY, 0, heuristic(startX, startY, endX, endY), NULL);
    openList[openListCount++] = startNode;

    while (openListCount > 0) {
        int lowestIndex = 0;
        for (int i = 1; i < openListCount; i++) {
            if (openList[i]->f < openList[lowestIndex]->f) {
                lowestIndex = i;
            }
        }

        Node* currentNode = openList[lowestIndex];

        if (currentNode->x == endX && currentNode->y == endY) {
            printPath(currentNode);
            return;
        }

        openList[lowestIndex] = openList[--openListCount]; // Remove currentNode from openList

        // Check neighboring nodes
        int neighbors[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} }; // right, down, left, up
        for (int i = 0; i < 4; i++) {
            int neighborX = currentNode->x + neighbors[i][0];
            int neighborY = currentNode->y + neighbors[i][1];

            if (isTraversable(neighborX, neighborY)) {
                int gCost = currentNode->g + 1;
                int hCost = heuristic(neighborX, neighborY, endX, endY);
                Node* neighborNode = createNode(neighborX, neighborY, gCost, hCost, currentNode);

                // Add neighbor if it's not already in openList
                bool inOpenList = false;
                for (int j = 0; j < openListCount; j++) {
                    if (openList[j]->x == neighborNode->x && openList[j]->y == neighborNode->y) {
                        inOpenList = true;
                        break;
                    }
                }
                if (!inOpenList) {
                    openList[openListCount++] = neighborNode;
                } else {
                    free(neighborNode);
                }
            }
        }
    }

    printf("No path found\n");
}

int main() {
    int startX = 8, startY = 8; // Starting point (S)
    int endX = 8, endY = 1; // Ending point (E)

    aStar(startX, startY, endX, endY);
    return 0;
}