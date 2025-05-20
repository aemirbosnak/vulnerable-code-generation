//GEMINI-pro DATASET v1.0 Category: Procedurally Generated Maze ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#define SIZE 100
#define WALL '@'
#define SPACE ' '

// Function to generate a maze using Wilson's algorithm
char** generate_maze() {
    // Initialize the maze
    char **maze = (char **)malloc(SIZE * sizeof(char *));
    for (int i = 0; i < SIZE; i++) {
        maze[i] = (char *)malloc(SIZE * sizeof(char));
        for (int j = 0; j < SIZE; j++) {
            maze[i][j] = WALL;
        }
    }

    // Create a set of unvisited cells
    int unvisited_count = SIZE * SIZE;
    int *unvisited = (int *)malloc(unvisited_count * sizeof(int));
    for (int i = 0; i < unvisited_count; i++) {
        unvisited[i] = i;
    }

    // Start at a random cell
    srand(time(NULL));
    int current_cell = rand() % unvisited_count;

    // While there are unvisited cells
    while (unvisited_count > 0) {
        // Carve a path from the current cell
        int next_cell = -1;
        while (next_cell == -1) {
            // Choose a random direction
            int direction = rand() % 4;

            // Get the next cell in that direction
            switch (direction) {
                case 0:
                    next_cell = current_cell - SIZE;
                    break;
                case 1:
                    next_cell = current_cell + 1;
                    break;
                case 2:
                    next_cell = current_cell + SIZE;
                    break;
                case 3:
                    next_cell = current_cell - 1;
                    break;
            }

            // If the next cell is out of bounds or has already been visited, choose a different direction
            if (next_cell < 0 || next_cell >= unvisited_count || unvisited[next_cell] == -1) {
                next_cell = -1;
            }
        }

        // Remove the next cell from the set of unvisited cells
        unvisited[next_cell] = -1;
        unvisited_count--;

        // Carve a path from the current cell to the next cell
        int row1 = current_cell / SIZE;
        int col1 = current_cell % SIZE;
        int row2 = next_cell / SIZE;
        int col2 = next_cell % SIZE;
        if (row1 == row2) {
            for (int i = col1; i <= col2; i++) {
                maze[row1][i] = SPACE;
            }
        } else {
            for (int i = row1; i <= row2; i++) {
                maze[i][col1] = SPACE;
            }
        }

        // Set the current cell to the next cell
        current_cell = next_cell;
    }

    // Free the set of unvisited cells
    free(unvisited);

    // Return the maze
    return maze;
}

// Function to print a maze
void print_maze(char **maze) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

// Function to main
int main() {
    // Generate a maze
    char **maze = generate_maze();

    // Print the maze
    print_maze(maze);

    // Free the maze
    for (int i = 0; i < SIZE; i++) {
        free(maze[i]);
    }
    free(maze);

    return 0;
}