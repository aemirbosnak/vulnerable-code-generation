//GEMINI-pro DATASET v1.0 Category: Procedurally Generated Maze ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent a cell in the maze
typedef struct Cell {
    int x;
    int y;
    int visited;
    int walls[4]; // 0: north, 1: east, 2: south, 3: west
} Cell;

// Structure to represent the maze
typedef struct Maze {
    int width;
    int height;
    Cell **cells;
} Maze;

// Create a new maze with the given width and height
Maze *createMaze(int width, int height) {
    // Allocate memory for the maze
    Maze *maze = malloc(sizeof(Maze));
    maze->width = width;
    maze->height = height;

    // Allocate memory for the cells
    maze->cells = malloc(sizeof(Cell *) * height);
    for (int i = 0; i < height; i++) {
        maze->cells[i] = malloc(sizeof(Cell) * width);
    }

    // Initialize the cells
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            maze->cells[i][j].x = j;
            maze->cells[i][j].y = i;
            maze->cells[i][j].visited = 0;
            for (int k = 0; k < 4; k++) {
                maze->cells[i][j].walls[k] = 1;
            }
        }
    }

    return maze;
}

// Free the memory allocated for the maze
void freeMaze(Maze *maze) {
    for (int i = 0; i < maze->height; i++) {
        free(maze->cells[i]);
    }
    free(maze->cells);
    free(maze);
}

// Generate a random maze using the Eller's algorithm
Maze *generateMaze(int width, int height) {
    // Create a new maze
    Maze *maze = createMaze(width, height);

    // Initialize the sets
    int *sets = malloc(sizeof(int) * width * height);
    for (int i = 0; i < width * height; i++) {
        sets[i] = i;
    }

    // Iterate over the rows
    for (int i = 0; i < height; i++) {
        // Iterate over the columns
        for (int j = 0; j < width; j++) {
            // Check if the cell is in the same set as the cell to the west
            if (j > 0 && sets[i * width + j] == sets[i * width + j - 1]) {
                // Remove the wall between the two cells
                maze->cells[i][j].walls[3] = 0;
                maze->cells[i][j - 1].walls[1] = 0;
            }

            // Check if the cell is in the same set as the cell to the north
            if (i > 0 && sets[i * width + j] == sets[(i - 1) * width + j]) {
                // Remove the wall between the two cells
                maze->cells[i][j].walls[0] = 0;
                maze->cells[i - 1][j].walls[2] = 0;
            }

            // Union the set of the cell with the set of the cell to the east
            if (j < width - 1) {
                sets[i * width + j + 1] = sets[i * width + j];
            }

            // Union the set of the cell with the set of the cell to the south
            if (i < height - 1) {
                sets[(i + 1) * width + j] = sets[i * width + j];
            }
        }
    }

    // Free the sets
    free(sets);

    return maze;
}

// Print the maze to the console
void printMaze(Maze *maze) {
    for (int i = 0; i < maze->height; i++) {
        for (int j = 0; j < maze->width; j++) {
            // Print the top wall
            if (maze->cells[i][j].walls[0] == 1) {
                printf("+---");
            } else {
                printf("+   ");
            }
        }
        printf("+\n");

        // Print the left wall
        for (int j = 0; j < maze->width; j++) {
            if (maze->cells[i][j].walls[3] == 1) {
                printf("|   ");
            } else {
                printf("    ");
            }
        }
        printf("|\n");
    }

    // Print the bottom wall
    for (int j = 0; j < maze->width; j++) {
        printf("+---");
    }
    printf("+\n");
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a new maze
    Maze *maze = generateMaze(20, 10);

    // Print the maze to the console
    printMaze(maze);

    // Free the maze
    freeMaze(maze);

    return 0;
}