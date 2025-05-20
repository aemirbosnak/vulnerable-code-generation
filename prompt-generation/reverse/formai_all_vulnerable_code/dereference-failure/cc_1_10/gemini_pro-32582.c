//GEMINI-pro DATASET v1.0 Category: Procedurally Generated Maze ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 10
#define MAZE_HEIGHT 10

// An enum to represent the different states of a cell in the maze
typedef enum {
    WALL,
    VISITED,
    PATH
} cell_state;

// A struct to represent a cell in the maze
typedef struct {
    cell_state state;
    int north;
    int east;
    int south;
    int west;
} cell;

// A struct to represent the maze
typedef struct {
    cell cells[MAZE_WIDTH][MAZE_HEIGHT];
} maze;

// Function to generate a new maze
maze *generate_maze() {
    // Create a new maze
    maze *m = malloc(sizeof(maze));

    // Initialize the maze cells
    for (int i = 0; i < MAZE_WIDTH; i++) {
        for (int j = 0; j < MAZE_HEIGHT; j++) {
            m->cells[i][j].state = WALL;
            m->cells[i][j].north = 1;
            m->cells[i][j].east = 1;
            m->cells[i][j].south = 1;
            m->cells[i][j].west = 1;
        }
    }

    // Set the starting cell
    m->cells[0][0].state = VISITED;

    // Generate the maze
    while (1) {
        // Find a random unvisited cell
        int i = rand() % MAZE_WIDTH;
        int j = rand() % MAZE_HEIGHT;
        if (m->cells[i][j].state == WALL) {
            // Visit the cell
            m->cells[i][j].state = VISITED;

            // Check if the cell has any unvisited neighbors
            int num_unvisited_neighbors = 0;
            if (i > 0 && m->cells[i - 1][j].state == WALL) {
                num_unvisited_neighbors++;
            }
            if (i < MAZE_WIDTH - 1 && m->cells[i + 1][j].state == WALL) {
                num_unvisited_neighbors++;
            }
            if (j > 0 && m->cells[i][j - 1].state == WALL) {
                num_unvisited_neighbors++;
            }
            if (j < MAZE_HEIGHT - 1 && m->cells[i][j + 1].state == WALL) {
                num_unvisited_neighbors++;
            }

            // If the cell has no unvisited neighbors, then we have reached the end of the maze
            if (num_unvisited_neighbors == 0) {
                break;
            }

            // Choose a random unvisited neighbor
            int neighbor = rand() % num_unvisited_neighbors;
            switch (neighbor) {
                case 0:
                    // North neighbor
                    m->cells[i][j].north = 0;
                    m->cells[i - 1][j].south = 0;
                    break;
                case 1:
                    // East neighbor
                    m->cells[i][j].east = 0;
                    m->cells[i + 1][j].west = 0;
                    break;
                case 2:
                    // South neighbor
                    m->cells[i][j].south = 0;
                    m->cells[i + 1][j].north = 0;
                    break;
                case 3:
                    // West neighbor
                    m->cells[i][j].west = 0;
                    m->cells[i - 1][j].east = 0;
                    break;
            }
        }
    }

    // Return the maze
    return m;
}

// Function to print a maze
void print_maze(maze *m) {
    for (int i = 0; i < MAZE_WIDTH; i++) {
        for (int j = 0; j < MAZE_HEIGHT; j++) {
            if (m->cells[i][j].state == WALL) {
                printf("#");
            } else if (m->cells[i][j].state == VISITED) {
                printf(".");
            } else if (m->cells[i][j].state == PATH) {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// Function to free a maze
void free_maze(maze *m) {
    free(m);
}

// Function to main
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a new maze
    maze *m = generate_maze();

    // Print the maze
    print_maze(m);

    // Free the maze
    free_maze(m);

    return 0;
}