//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: surrealist
#include <stdio.h>

// Define the size of the grid
#define ROW 5
#define COL 5

// Define the coordinates for the start and end points
#define START_X 0
#define START_Y 0
#define END_X 4
#define END_Y 4

// Create a struct for each grid cell
struct cell {
    int x, y, f, g, h;
    struct cell* parent;
};

// Create a function to calculate the heuristic distance between two cells
int heuristicDist(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

// Create a function to check if a cell is valid
int isValid(int row, int col, int x, int y) {
    return (x >= 0) && (y >= 0) && (x < row) && (y < col);
}

// Create a function to check if a cell is blocked
int isBlocked(int grid[][COL], int x, int y) {
    return (grid[x][y] == 1);
}

// Create a function to trace the path from end to start
void tracePath(struct cell* cell) {
    while (cell != NULL) {
        printf("(%d, %d)\n", cell->x, cell->y);
        cell = cell->parent;
    }
}

// Create the main function for the A* algorithm
void aStar(int grid[][COL], struct cell start, struct cell end) {
    // Create open and closed lists
    int closedList[ROW][COL];
    memset(closedList, 0, sizeof(closedList));
    struct cell* openList[ROW * COL];
    int openCount = 0;
    
    // Create a starting cell with initial values
    struct cell* origin = (struct cell*)malloc(sizeof(struct cell));
    origin->x = start.x;
    origin->y = start.y;
    origin->f = 0;
    origin->g = 0;
    origin->h = 0;
    origin->parent = NULL;
    openList[openCount++] = origin;
    
    // Loop through the open list until it is empty
    while (openCount > 0) {
        // Find the cell with the minimum f value
        int min = 0;
        for (int i = 0; i < openCount; i++) {
            if (openList[i]->f < openList[min]->f) {
                min = i;
            }
        }
        struct cell* current = openList[min];
        
        // If the end cell has been reached, trace the path and return
        if (current->x == end.x && current->y == end.y) {
            tracePath(current);
            return;
        }
        
        // Remove the current cell from the open list and add it to the closed list
        for (int i = 0; i < openCount; i++) {
            if (openList[i] == current) {
                openList[i] = openList[--openCount];
                break;
            }
        }
        closedList[current->x][current->y] = 1;
        
        // Loop through the neighbors of the current cell
        for (int x = -1; x <= 1; x++) {
            for (int y = -1; y <= 1; y++) {
                if (x == 0 && y == 0) {
                    // Ignore the current cell
                    continue;
                }
                
                int nextX = current->x + x;
                int nextY = current->y + y;
                
                if (isValid(ROW, COL, nextX, nextY) == 0) {
                    // Ignore cells outside the grid
                    continue;
                }
                
                if (isBlocked(grid, nextX, nextY) == 1) {
                    // Ignore blocked cells
                    continue;
                }
                
                if (closedList[nextX][nextY] == 1) {
                    // Ignore cells already in the closed list
                    continue;
                }
                
                // Calculate the g, h, and f values for the neighbor
                int g = current->g + 1;
                int h = heuristicDist(nextX, nextY, end.x, end.y);
                int f = g + h;
                
                // Add the neighbor to the open list if it is not already there
                struct cell* neighbor = NULL;
                for (int i = 0; i < openCount; i++) {
                    if (openList[i]->x == nextX && openList[i]->y == nextY) {
                        neighbor = openList[i];
                        break;
                    }
                }
                if (neighbor == NULL) {
                    neighbor = (struct cell*)malloc(sizeof(struct cell));
                    neighbor->x = nextX;
                    neighbor->y = nextY;
                    neighbor->f = f;
                    neighbor->g = g;
                    neighbor->h = h;
                    neighbor->parent = current;
                    openList[openCount++] = neighbor;
                } else if (g < neighbor->g) {
                    neighbor->g = g;
                    neighbor->f = g + neighbor->h;
                    neighbor->parent = current;
                }
            }
        }
    }
    
    // If the end cell cannot be reached, print a message
    printf("No path found.");
}

// Define the main function
int main() {
    // Define the grid
    int grid[ROW][COL] = {
        { 0, 1, 0, 0, 0 },
        { 0, 1, 0, 1, 0 },
        { 0, 1, 0, 1, 0 },
        { 0, 1, 0, 1, 0 },
        { 0, 0, 0, 1, 0 }
    };
    
    // Define the start and end points
    struct cell start = { START_X, START_Y };
    struct cell end = { END_X, END_Y };
    
    // Run the A* algorithm
    aStar(grid, start, end);
    
    return 0;
}