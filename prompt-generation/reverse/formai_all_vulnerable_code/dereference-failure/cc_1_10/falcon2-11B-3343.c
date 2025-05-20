//Falcon2-11B DATASET v1.0 Category: Procedurally Generated Maze ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Define a struct to represent a cell in the maze
struct cell {
    int x;
    int y;
    int z;
    struct cell* next;
};

// Function to generate a 3D maze using recursive backtracking
void generateMaze(struct cell* start, struct cell* end) {
    // Check if the start and end cells are the same
    if (start == end) {
        return;
    }

    // Define the direction of the current cell
    int dx = start->x - end->x;
    int dy = start->y - end->y;
    int dz = start->z - end->z;

    // Check if the current cell is a valid step in the maze
    if (dx == 0 && dy == 0 && dz == 0) {
        // The current cell is not a valid step, so return
        return;
    }

    // Create a new cell and add it to the maze
    struct cell* newCell = malloc(sizeof(struct cell));
    newCell->x = start->x;
    newCell->y = start->y;
    newCell->z = start->z;
    newCell->next = NULL;

    // Add the new cell to the maze
    if (dx!= 0) {
        newCell->next = start->next;
        start->next = newCell;
    }
    if (dy!= 0) {
        newCell->next = start->next->next;
        start->next->next = newCell;
    }
    if (dz!= 0) {
        newCell->next = start->next->next->next;
        start->next->next->next = newCell;
    }

    // Recursively generate the maze
    if (dx!= 0) {
        generateMaze(start->next, end);
    }
    if (dy!= 0) {
        generateMaze(start->next->next, end);
    }
    if (dz!= 0) {
        generateMaze(start->next->next->next, end);
    }

    // Free the new cell
    free(newCell);
}

// Function to print the maze
void printMaze(struct cell* start) {
    // Check if the start cell is NULL
    if (start == NULL) {
        return;
    }

    // Print the start cell
    printf("(%d, %d, %d)\n", start->x, start->y, start->z);

    // Print the next cells
    if (start->next!= NULL) {
        printf("-> ");
        printMaze(start->next);
    }
}

// Function to check if a cell is in the maze
int isInMaze(struct cell* maze, int x, int y, int z) {
    // Check if the cell is NULL
    if (maze == NULL) {
        return 0;
    }

    // Check if the cell is in the maze
    if (maze->x == x && maze->y == y && maze->z == z) {
        return 1;
    }

    // Check the next cells
    if (maze->next!= NULL) {
        if (isInMaze(maze->next, x, y, z) == 1) {
            return 1;
        }
    }

    // Check the next next cells
    if (maze->next->next!= NULL) {
        if (isInMaze(maze->next->next, x, y, z) == 1) {
            return 1;
        }
    }

    // Check the next next next cells
    if (maze->next->next->next!= NULL) {
        if (isInMaze(maze->next->next->next, x, y, z) == 1) {
            return 1;
        }
    }

    // The cell is not in the maze
    return 0;
}

// Main function
int main() {
    // Define the start and end cells
    struct cell* start = malloc(sizeof(struct cell));
    struct cell* end = malloc(sizeof(struct cell));
    start->x = 0;
    start->y = 0;
    start->z = 0;
    end->x = 3;
    end->y = 3;
    end->z = 3;

    // Generate the maze
    generateMaze(start, end);

    // Print the maze
    printMaze(start);

    // Check if a cell is in the maze
    if (isInMaze(start, 1, 1, 1) == 1) {
        printf("Cell is in the maze\n");
    } else {
        printf("Cell is not in the maze\n");
    }

    // Free the memory
    free(start);
    free(end);

    return 0;
}