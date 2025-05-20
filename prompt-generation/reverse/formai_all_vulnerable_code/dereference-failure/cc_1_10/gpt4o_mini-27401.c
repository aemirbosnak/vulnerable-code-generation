//GPT-4o-mini DATASET v1.0 Category: Pathfinding algorithms ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>

#define N 10 // Size of the grid

// Creating a structure for a cell in the grid which holds coordinates, fCost, gCost and hCost
typedef struct {
    int x, y;
    int fCost, gCost, hCost;
    bool isObstacle;
    bool visited;
    struct Cell *parent; // Pointer to the parent cell
} Cell;

Cell* createCell(int x, int y, bool isObstacle) {
    Cell* newCell = (Cell*)malloc(sizeof(Cell));
    newCell->x = x;
    newCell->y = y;
    newCell->fCost = INT_MAX;
    newCell->gCost = INT_MAX;
    newCell->hCost = INT_MAX;
    newCell->isObstacle = isObstacle;
    newCell->visited = false;
    newCell->parent = NULL;
    return newCell;
}

Cell* grid[N][N]; // Create a grid of cells

// Prototypes
void initializeGrid();
void displayGrid();
void aStarPathfinding(int startX, int startY, int destX, int destY);
int heuristic(int x1, int y1, int x2, int y2);
void retracePath(Cell* destinationCell);

int main() {
    initializeGrid();
    
    // Example obstacles
    grid[1][2]->isObstacle = true;
    grid[2][2]->isObstacle = true;
    grid[3][2]->isObstacle = true;

    int startX = 0, startY = 0; // Starting position
    int destX = 4, destY = 4;   // Destination position

    aStarPathfinding(startX, startY, destX, destY);
    
    return 0;
}

void initializeGrid() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            grid[i][j] = createCell(i, j, false);
        }
    }
}

int heuristic(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2); // Manhattan distance
}

void aStarPathfinding(int startX, int startY, int destX, int destY) {
    Cell* startCell = grid[startX][startY];
    Cell* destCell = grid[destX][destY];

    startCell->gCost = 0;
    startCell->hCost = heuristic(startX, startY, destX, destY);
    startCell->fCost = startCell->gCost + startCell->hCost;

    Cell* openList[N * N];
    int openCount = 0;

    openList[openCount++] = startCell;

    while (openCount > 0) {
        int lowestIndex = 0;
        for (int i = 1; i < openCount; i++) {
            if (openList[i]->fCost < openList[lowestIndex]->fCost) {
                lowestIndex = i;
            }
        }

        Cell* currentCell = openList[lowestIndex];

        if (currentCell == destCell) {
            retracePath(currentCell);
            return;
        }

        // Remove current cell from open list
        for (int i = lowestIndex; i < openCount - 1; i++) {
            openList[i] = openList[i + 1];
        }
        openCount--;

        currentCell->visited = true;

        // Check neighbors (4 directions: up, down, left, right)
        for (int deltaX = -1; deltaX <= 1; deltaX++) {
            for (int deltaY = -1; deltaY <= 1; deltaY++) {
                if ((abs(deltaX) == abs(deltaY)) || (deltaX == 0 && deltaY == 0)) {
                    continue; // Skip diagonals and self
                }

                int neighborX = currentCell->x + deltaX;
                int neighborY = currentCell->y + deltaY;

                if (neighborX >= 0 && neighborX < N && neighborY >= 0 && neighborY < N) {
                    Cell* neighborCell = grid[neighborX][neighborY];

                    if (neighborCell->isObstacle || neighborCell->visited) {
                        continue; // Skip obstacles and already visited cells
                    }

                    int newGCost = currentCell->gCost + 1; // Assume cost between cells is 1
                    if (newGCost < neighborCell->gCost) {
                        neighborCell->gCost = newGCost;
                        neighborCell->hCost = heuristic(neighborX, neighborY, destX, destY);
                        neighborCell->fCost = neighborCell->gCost + neighborCell->hCost;
                        neighborCell->parent = currentCell;

                        // Add to open list if not already present
                        bool inOpenList = false;
                        for (int i = 0; i < openCount; i++) {
                            if (openList[i] == neighborCell) {
                                inOpenList = true;
                                break;
                            }
                        }
                        if (!inOpenList) {
                            openList[openCount++] = neighborCell;
                        }
                    }
                }
            }
        }
    }
    printf("Path not found!\n");
}

void retracePath(Cell* destinationCell) {
    Cell* currentCell = destinationCell;

    while (currentCell != NULL) {
        printf("Cell: (%d, %d)\n", currentCell->x, currentCell->y);
        currentCell = currentCell->parent;
    }
}