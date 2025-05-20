//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: sophisticated
#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 

#define ROW 8
#define COL 8

/* Data Structure to store a cell details
   for A* Search Algorithm */
struct cell 
{ 
    int row, col; 
    int f, g, h; 
    struct cell *parent; 
}; 

/* Function to create a new cell */
struct cell* createCell(int row, int col, int f, int g, int h, struct cell *parent) 
{ 
    struct cell* newCell = (struct cell*) malloc(sizeof(struct cell)); 

    newCell->row = row; 
    newCell->col = col; 
    newCell->f = f; 
    newCell->g = g; 
    newCell->h = h; 
    newCell->parent = parent; 

    return newCell; 
} 

/* Check whether given cell (row, col) is a valid cell or not */
int isValid(int row, int col) 
{ 
    return (row >= 0 && row < ROW && col >= 0 && col < COL); 
} 

/* Check whether given cell (row, col) is blocked or not */
int isBlocked(int row, int col, int grid[][COL]) 
{ 
    return (grid[row][col] == 1); 
} 

/* Calculate the Manhattan distance from the given cell to the final cell */
int calculateHValue(int row, int col, int finalRow, int finalCol) 
{ 
    return abs(finalRow - row) + abs(finalCol - col); 
} 

/* Function to implement A* search algorithm */
void aStarSearch(int grid[][COL], int startRow, int startCol, int finalRow, int finalCol) 
{ 
    /* Check whether start and final cells are valid or not */
    if (!isValid(startRow, startCol)) 
    { 
        printf("Invalid start coordinate\n"); 
        return; 
    } 

    if (!isValid(finalRow, finalCol)) 
    { 
        printf("Invalid final coordinate\n"); 
        return; 
    } 

    /* Check whether start and final cells are not blocked */
    if (isBlocked(startRow, startCol, grid) || isBlocked(finalRow, finalCol, grid)) 
    { 
        printf("Invalid start or final coordinate\n"); 
        return; 
    } 

    /* Create an open list and a closed list */
    struct cell **openList = (struct cell **)malloc(sizeof(struct cell *));
    struct cell **closedList = (struct cell **)malloc(sizeof(struct cell *));
    int openListSize = 0, closedListSize = 0; 

    /* Create a start cell with f, g and h values */
    struct cell* startCell = createCell(startRow, startCol, 0, 0, 0, NULL); 
    startCell->h = calculateHValue(startRow, startCol, finalRow, finalCol); 

    /* Add the start cell to the open list */
    openList[openListSize++] = startCell; 

    /* Loop until the open list is empty or the final cell is found */
    while (openListSize > 0) 
    { 
        /* Find the cell in the open list with lowest f value */
        int minf = INT_MAX, index = 0; 
        for (int i = 0; i < openListSize; i++) 
        { 
            int f = openList[i]->f; 
            if (f < minf) 
            { 
                minf = f; 
                index = i; 
            } 
        } 

        /* Remove the cell from the open list and add it to the closed list */
        struct cell* currentCell = openList[index]; 
        openList[index] = openList[--openListSize]; 
        closedList[closedListSize++] = currentCell; 

        /* Check whether the final cell is found or not */
        if (currentCell->row == finalRow && currentCell->col == finalCol) 
        { 
            /* Print the path from start to final cell */
            while (currentCell) 
            { 
                printf("(%d,%d) ", currentCell->row, currentCell->col); 
                currentCell = currentCell->parent; 
            } 
            printf("\n");

            /* Deallocate the memory used by open and closed lists */
            for (int i = 0; i < openListSize; i++) 
                free(openList[i]); 

            for (int i = 0; i < closedListSize; i++) 
                free(closedList[i]); 
                
            free(openList);
            free(closedList);

            return; 
        } 

        /* Generate all possible successors of the current cell */
        int row = currentCell->row; 
        int col = currentCell->col; 
        for (int i = -1; i <= 1; i++) 
        { 
            for (int j = -1; j <= 1; j++) 
            { 
                if (!(i == 0 && j == 0) && isValid(row+i, col+j) && !isBlocked(row+i, col+j, grid)) 
                { 
                    /* Calculate the f, g, and h values of the child cell */
                    int g = currentCell->g + 1; 
                    int h = calculateHValue(row+i, col+j, finalRow, finalCol); 
                    int f = g + h; 

                    /* Check whether the child cell is already in the closed list or not */
                    int foundInClosedList = 0; 
                    for (int k = 0; k < closedListSize; k++) 
                    { 
                        if (closedList[k]->row == row+i && closedList[k]->col == col+j) 
                        { 
                            foundInClosedList = 1; 
                            break; 
                        } 
                    } 

                    /* If the child cell is not in the closed list, add it to the open list with f, g, and h values */
                    if (!foundInClosedList) 
                    { 
                        struct cell* newCell = createCell(row+i, col+j, f, g, h, currentCell); 
                        openList = (struct cell **)realloc(openList, sizeof(struct cell *) * (openListSize + 1));
                        openList[openListSize++] = newCell; 
                    } 
                } 
            } 
        } 
    } 

    printf("No path found\n");

    /* Deallocate the memory used by open and closed lists */
    for (int i = 0; i < openListSize; i++) 
        free(openList[i]); 

    for (int i = 0; i < closedListSize; i++) 
        free(closedList[i]); 

    free(openList);
    free(closedList);
} 

int main() 
{ 
    int grid[][COL] = 
    { 
        { 0, 0, 1, 0, 0, 0, 0, 1 }, 
        { 0, 0, 0, 0, 0, 0, 0, 0 }, 
        { 0, 0, 1, 0, 1, 0, 0, 0 }, 
        { 0, 0, 1, 0, 1, 0, 0, 0 }, 
        { 0, 0, 1, 0, 1, 0, 0, 0 }, 
        { 0, 0, 0, 0, 0, 0, 0, 0 }, 
        { 0, 0, 0, 0, 0, 0, 0, 0 }, 
        { 0, 0, 0, 0, 0, 0, 0, 0 } 
    }; 

    int startRow = 0, startCol = 0; 
    int finalRow = 7, finalCol = 7; 

    aStarSearch(grid, startRow, startCol, finalRow, finalCol); 

    return 0; 
}