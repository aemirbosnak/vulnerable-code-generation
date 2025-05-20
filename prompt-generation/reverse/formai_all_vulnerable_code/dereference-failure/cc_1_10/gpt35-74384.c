//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define ROW 5
#define COL 5

// Define a struct to contain information about each cell
struct Cell {
    int row, col, distance, fCost;
    bool isVisited;
    struct Cell* prevCell;
};

// Define a function to create a new cell
struct Cell* createCell(int row, int col, int distance, int fCost, bool isVisited, struct Cell* prevCell) {
    struct Cell* newCell = (struct Cell*) malloc(sizeof(struct Cell));
    newCell->row = row;
    newCell->col = col;
    newCell->distance = distance;
    newCell->fCost = fCost;
    newCell->isVisited = isVisited;
    newCell->prevCell = prevCell;
    return newCell;
}

// Define a function to check if a cell is valid
bool isValidCell(int row, int col) {
    if (row >= 0 && row < ROW && col >= 0 && col < COL) {
        return true;
    }
    return false;
}

// Define a function to check if a cell is blocked
bool isBlockedCell(int grid[][COL], int row, int col) {
    if (grid[row][col] == 1) {
        return true;
    }
    return false;
}

// Define a function to calculate the H cost (Manhattan distance)
int calculateHCost(int row, int col, int targetRow, int targetCol) {
    return abs(row - targetRow) + abs(col - targetCol);
}

// Define the A* pathfinding algorithm
void aStar(int grid[][COL], int startX, int startY, int targetX, int targetY) {
    
    // Create the open and closed lists
    struct Cell* openList[ROW*COL];
    struct Cell* closedList[ROW*COL];
    int openListIndex = 0;
    int closedListIndex = 0;
    
    // Create the starting cell and add it to the open list
    struct Cell* startCell = createCell(startX, startY, 0, 0, true, NULL);
    openList[openListIndex] = startCell;
    openListIndex++;
    
    // Loop until we find the destination or run out of cells to search
    while (openListIndex > 0) {
        
        // Get the cell with the lowest F cost from the open list
        int currentCellIndex = 0;
        int lowestFCost = INT_MAX;
        for (int i = 0; i < openListIndex; i++) {
            if (openList[i]->fCost < lowestFCost) {
                currentCellIndex = i;
                lowestFCost = openList[i]->fCost;
            }
        }
        struct Cell* currentCell = openList[currentCellIndex];
        
        // Remove the current cell from the open list and add it to the closed list
        openList[currentCellIndex] = NULL;
        openListIndex--;
        closedList[closedListIndex] = currentCell;
        closedListIndex++;
        
        // Check if we have found the destination
        if (currentCell->row == targetX && currentCell->col == targetY) {
            
            // Create a path from the target cell to the starting cell
            int pathLength = 0;
            struct Cell* tempCell = currentCell;
            while (tempCell != NULL) {
                pathLength++;
                tempCell = tempCell->prevCell;
            }
            int path[pathLength][2];
            tempCell = currentCell;
            for (int i = pathLength-1; i >= 0; i--) {
                path[i][0] = tempCell->row;
                path[i][1] = tempCell->col;
                tempCell = tempCell->prevCell;
            }
            
            // Print the path
            printf("The path from (%d,%d) to (%d,%d) is:\n", startX, startY, targetX, targetY);
            for (int i = 0; i < pathLength; i++) {
                printf("(%d,%d)", path[i][0], path[i][1]);
                if (i < pathLength-1) {
                    printf(" -> ");
                }
            }
            printf("\n");
            
            // End the search
            return;
        }
        
        // Check the adjacent cells
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                int newRow = currentCell->row + i;
                int newCol = currentCell->col + j;
                if (isValidCell(newRow, newCol) && !isBlockedCell(grid, newRow, newCol)) {
                    int newDistance = currentCell->distance + 1;
                    int newHCost = calculateHCost(newRow, newCol, targetX, targetY);
                    int newFCost = newDistance + newHCost;
                    bool inOpenList = false;
                    bool inClosedList = false;
                    for (int k = 0; k < openListIndex; k++) {
                        if (openList[k]->row == newRow && openList[k]->col == newCol) {
                            inOpenList = true;
                            if (newFCost < openList[k]->fCost) {
                                openList[k]->distance = newDistance;
                                openList[k]->fCost = newFCost;
                                openList[k]->prevCell = currentCell;
                            }
                        }
                    }
                    for (int k = 0; k < closedListIndex; k++) {
                        if (closedList[k]->row == newRow && closedList[k]->col == newCol) {
                            inClosedList = true;
                            break;
                        }
                    }
                    if (!inOpenList && !inClosedList) {
                        struct Cell* newCell = createCell(newRow, newCol, newDistance, newFCost, true, currentCell);
                        openList[openListIndex] = newCell;
                        openListIndex++;
                    }
                }
            }
        }
    }
    
    // If we reach this point, there is no path from the start to the target
    printf("There is no path from (%d,%d) to (%d,%d).\n", startX, startY, targetX, targetY);
}

int main() {
    int grid[ROW][COL] = {
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 1},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0}
    };
    aStar(grid, 0, 0, 4, 4);
    return 0;
}