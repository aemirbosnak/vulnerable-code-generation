//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define ROW 6
#define COL 8

// A structure to represent a cell in the grid
struct Cell {
    int row, col;
    struct Cell* parent;
    int f, g, h;
};

// Utility function to check whether a given cell is within the grid or not.
int isCellValid(int row, int col)
{
    if (row >= 0 && row < ROW && col >= 0 && col < COL) {
        return 1;
    } else {
        return 0;
    }
}

// Utility function to check whether a given cell is blocked or not.
int isCellBlocked(int grid[ROW][COL], int row, int col)
{
    if (grid[row][col] == 1) {
        return 1;
    } else {
        return 0;
    }
}

// Utility function to check whether a given cell is destination or not.
int isDestination(int row, int col, struct Cell dest)
{
    if (row == dest.row && col == dest.col) {
        return 1;
    } else {
        return 0;
    }
}

// Utility function to calculate the heuristic cost of a given cell using Manhattan distance.
int heuristicCost(int row, int col, struct Cell dest)
{
    int h = abs(row - dest.row) + abs(col - dest.col);
    return h;
}

// Utility function to trace the path from the source to destination cell.
void tracePath(struct Cell* dest)
{
    printf("\nThe shortest path from the source to destination is:\n");
    struct Cell* temp = dest;
    while (temp != NULL) {
        printf("(%d, %d) ", temp->row, temp->col);
        temp = temp->parent;
    }
    printf("\n\n");
}

// Recursive function to the A* Pathfinding Algorithm to find the shortest path from source to destination.
void aStarSearch(int grid[ROW][COL], struct Cell src, struct Cell dest, int openList[ROW][COL])
{
    static int row[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    static int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    int i, j, nrow, ncol;

    if (isDestination(src.row, src.col, dest) == 1) {
        tracePath(&src);
        return;
    }

    openList[src.row][src.col] = 1;

    struct Cell* currentCell = (struct Cell*) malloc(sizeof(struct Cell));
    currentCell->row = src.row;
    currentCell->col = src.col;
    currentCell->parent = NULL;
    currentCell->f = 0;
    currentCell->g = 0;
    currentCell->h = 0;

    // Find all neighbours of the current cell
    for (i = 0; i < 8; i++) {
        nrow = currentCell->row + row[i];
        ncol = currentCell->col + col[i];

        // check if the neighbour is valid
        if (isCellValid(nrow, ncol) == 1) {
            // check if the neighbour is blocked
            if (isCellBlocked(grid, nrow, ncol) == 0) {
                // check if the neighbour is already in the open list
                if (openList[nrow][ncol] == 0) {
                    struct Cell* neighbourCell = (struct Cell*) malloc(sizeof(struct Cell));
                    neighbourCell->row = nrow;
                    neighbourCell->col = ncol;
                    neighbourCell->parent = currentCell;
                    neighbourCell->g = currentCell->g + 1;
                    neighbourCell->h = heuristicCost(nrow, ncol, dest);
                    neighbourCell->f = neighbourCell->g + neighbourCell->h;

                    aStarSearch(grid, *neighbourCell, dest, openList);
                }
            }
        }
    }

    free(currentCell);
    return;
}

int main()
{
    int grid[ROW][COL] = {
        {0, 0, 0, 0, 0, 0, 0, 1},
        {0, 1, 1, 1, 1, 0, 0, 1},
        {0, 1, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 1, 1, 1, 1, 0},
        {0, 1, 0, 1, 0, 0, 0, 0},
        {0, 1, 0, 1, 0, 1, 1, 0},
    };

    struct Cell src = {0, 0, NULL, 0, 0, 0};
    struct Cell dest = {5, 7, NULL, 0, 0, 0};

    int openList[ROW][COL];
    memset(openList, 0, sizeof(openList));

    aStarSearch(grid, src, dest, openList);

    return 0;
}