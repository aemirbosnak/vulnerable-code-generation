//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

// A structure to represent a grid cell
struct Cell
{
    int row;
    int col;
    int fCost;
    int gCost;
    int hCost;
    struct Cell* parent;
};

// A function to create a new cell
struct Cell* createCell(int row, int col)
{
    struct Cell* cell = (struct Cell*)malloc(sizeof(struct Cell));
    cell->row = row;
    cell->col = col;
    cell->fCost = 0;
    cell->gCost = 0;
    cell->hCost = 0;
    cell->parent = NULL;
    return cell;
}

// A function to check if a cell is valid or not
int isValid(int row, int col)
{
    // Returns true if row and col are in range
    return (row >= 0) && (row < ROWS) &&
           (col >= 0) && (col < COLS);
}

// A function to check if a cell is blocked or not
int isBlocked(int** grid, int row, int col)
{
    // Returns true if the cell is blocked else false
    return (grid[row][col] == 1);
}

// A function to calculate H cost
int calculateHCost(struct Cell* current, struct Cell* end)
{
    // Distance formula
    return (abs(current->row - end->row) +
            abs(current->col - end->col));
}

// A function to find the shortest path using A* algorithm
void aStar(int** grid, struct Cell* start, struct Cell* end)
{
    // Open list
    struct Cell* openList[ROWS*COLS];

    // Close list
    int closedList[ROWS][COLS];

    // Initialize open list and close list
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            closedList[i][j] = 0;
        }
    }

    // Add start cell to open list
    int openIndex = 0;
    openList[openIndex] = start;
    openIndex++;

    // Loop until you find the end cell
    int found = 0;
    struct Cell* current;
    while (!found)
    {
        // Find the cell with minimum fCost
        int minFCostIndex = 0;
        int minFCost = openList[0]->fCost;
        for (int i = 1; i < openIndex; i++)
        {
            if (openList[i]->fCost < minFCost)
            {
                minFCost = openList[i]->fCost;
                minFCostIndex = i;
            }
        }

        // Get the cell with minimum fCost from open list
        current = openList[minFCostIndex];

        // Remove the current cell from open list
        for (int i = minFCostIndex; i < openIndex-1; i++)
        {
            openList[i] = openList[i+1];
        }
        openIndex--;

        // Add the current cell to the close list
        closedList[current->row][current->col] = 1;

        // Check if the current cell is the end cell
        if (current->row == end->row && current->col == end->col)
        {
            found = 1;
            break;
        }

        // Generate children for the current cell
        int childRow, childCol;
        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                // Skip if it's the current cell or out of range
                if (i == 0 && j == 0) 
                {
                    continue;
                }
                childRow = current->row + i;
                childCol = current->col + j;
                if (isValid(childRow, childCol) && !isBlocked(grid, childRow, childCol))
                {
                    // Create new child cell and calculate its cost
                    struct Cell* child = createCell(childRow, childCol);
                    child->gCost = current->gCost + 10; // cost of moving to a neighbour is 10
                    child->hCost = calculateHCost(child, end);
                    child->fCost = child->gCost + child->hCost;
                    child->parent = current;

                    // Check if child is already in open list and if its fCost is lower than before
                    int inOpenList = 0;
                    for (int k = 0; k < openIndex; k++)
                    {
                        if (openList[k]->row == child->row && openList[k]->col == child->col)
                        {
                            inOpenList = 1;
                            if (openList[k]->fCost > child->fCost)
                            {
                                openList[k]->fCost = child->fCost;
                                openList[k]->gCost = child->gCost;
                                openList[k]->hCost = child->hCost;
                                openList[k]->parent = child->parent;
                            }
                            break;
                        }
                    }

                    // Add the child to open list if it's not already in
                    if (!inOpenList)
                    {
                        openList[openIndex] = child;
                        openIndex++;
                    }
                }
            }
        }

        // If there is no path, break out of the loop
        if (openIndex == 0)
        {
            break;
        }
    }

    // Print the shortest path if found
    if (found)
    {
        printf("Path found:\n");
        while (current != start)
        {
            printf("(%d,%d)\n", current->row, current->col);
            current = current->parent;
        }
        printf("(%d,%d)\n", start->row, start->col);
    }
    else
    {
        printf("No path found!\n");
    }
}

int main()
{
    int** grid = (int**)malloc(sizeof(int*)*ROWS);
    for (int i = 0; i < ROWS; i++)
    {
        grid[i] = (int*)malloc(sizeof(int)*COLS);
    }

    // Initialize the grid with random values
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            grid[i][j] = rand() % 2;
        }
    }

    // Set start and end points
    struct Cell* start = createCell(0, 0);
    struct Cell* end = createCell(ROWS-1, COLS-1);

    // Find shortest path using A* algorithm
    aStar(grid, start, end);
    
    return 0;
}