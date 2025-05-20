//GEMINI-pro DATASET v1.0 Category: Procedurally Generated Maze ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// An individual cell in the maze
typedef struct {
    int x, y; // Coordinates
    int walls; // Bitmask representing which walls are present (0: up, 1: right, 2: down, 3: left)
} Cell;

// The entire maze
typedef struct {
    Cell *cells; // Array of cells
    int width, height; // Dimensions of the maze
} Maze;

// Generate a new maze of the specified dimensions
Maze *generate_maze(int width, int height) {
    // Allocate memory for the maze
    Maze *maze = malloc(sizeof(Maze));
    maze->width = width;
    maze->height = height;
    maze->cells = malloc(width * height * sizeof(Cell));

    // Initialize all cells to have all walls
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            maze->cells[i + j * width].x = i;
            maze->cells[i + j * width].y = j;
            maze->cells[i + j * width].walls = 15;
        }
    }

    // Set the starting cell to be the top-left corner
    Cell *current_cell = maze->cells;

    // Set the ending cell to be the bottom-right corner
    Cell *end_cell = maze->cells + (width - 1) + (height - 1) * width;

    // Create a stack to keep track of visited cells
    Cell *stack[width * height];
    int stack_top = 0;

    // While the current cell is not the ending cell
    while (current_cell != end_cell) {
        // Push the current cell onto the stack
        stack[stack_top++] = current_cell;

        // Choose a random neighbor to visit
        int neighbor_index = rand() % 4;
        Cell *neighbor = NULL;
        switch (neighbor_index) {
            case 0: // Up
                if (current_cell->y > 0) {
                    neighbor = maze->cells + current_cell->x + (current_cell->y - 1) * width;
                }
                break;
            case 1: // Right
                if (current_cell->x < width - 1) {
                    neighbor = maze->cells + (current_cell->x + 1) + current_cell->y * width;
                }
                break;
            case 2: // Down
                if (current_cell->y < height - 1) {
                    neighbor = maze->cells + current_cell->x + (current_cell->y + 1) * width;
                }
                break;
            case 3: // Left
                if (current_cell->x > 0) {
                    neighbor = maze->cells + (current_cell->x - 1) + current_cell->y * width;
                }
                break;
        }

        // If the neighbor is valid and unvisited
        if (neighbor && (neighbor->walls & (1 << neighbor_index)) != 0) {
            // Remove the wall between the current cell and the neighbor
            current_cell->walls &= ~(1 << neighbor_index);
            neighbor->walls &= ~(1 << (neighbor_index ^ 2));

            // Set the current cell to the neighbor
            current_cell = neighbor;
        } else {
            // Pop the current cell off the stack
            stack_top--;
            current_cell = stack[stack_top];
        }
    }

    // Return the generated maze
    return maze;
}

// Print the maze to the console
void print_maze(Maze *maze) {
    // Print the top border
    for (int i = 0; i < maze->width * 2 + 1; i++) {
        printf("#");
    }
    printf("\n");

    // Print each row of the maze
    for (int j = 0; j < maze->height; j++) {
        // Print the left border
        printf("#");

        // Print the cells in the row
        for (int i = 0; i < maze->width; i++) {
            Cell *cell = maze->cells + i + j * maze->width;

            // Print the top wall
            if (cell->walls & 4) {
                printf("##");
            } else {
                printf("  ");
            }

            // Print the right wall
            if (cell->walls & 2) {
                printf("#");
            } else {
                printf(" ");
            }
        }

        printf("\n");
    }

    // Print the bottom border
    for (int i = 0; i < maze->width * 2 + 1; i++) {
        printf("#");
    }
    printf("\n");
}

// Free the memory allocated for the maze
void free_maze(Maze *maze) {
    free(maze->cells);
    free(maze);
}

// Main function
int main(int argc, char *argv[]) {
    // Set the random seed
    srand(time(NULL));

    // Generate a maze of size 20x20
    Maze *maze = generate_maze(20, 20);

    // Print the maze to the console
    print_maze(maze);

    // Free the memory allocated for the maze
    free_maze(maze);

    return 0;
}