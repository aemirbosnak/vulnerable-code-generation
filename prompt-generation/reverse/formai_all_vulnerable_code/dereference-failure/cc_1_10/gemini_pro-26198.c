//GEMINI-pro DATASET v1.0 Category: Procedurally Generated Maze ; Style: multi-threaded
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#define MAZE_SIZE 100

// Define the directions
enum direction {
    NORTH,
    EAST,
    SOUTH,
    WEST
};

// Define the maze structure
struct maze {
    int width;
    int height;
    int **cells;
};

// Create a new maze
struct maze *create_maze(int width, int height) {
    struct maze *maze = malloc(sizeof(struct maze));
    maze->width = width;
    maze->height = height;
    maze->cells = malloc(sizeof(int *) * height);
    for (int i = 0; i < height; i++) {
        maze->cells[i] = malloc(sizeof(int) * width);
    }
    return maze;
}

// Free the maze
void free_maze(struct maze *maze) {
    for (int i = 0; i < maze->height; i++) {
        free(maze->cells[i]);
    }
    free(maze->cells);
    free(maze);
}

// Generate a random maze
void generate_maze(struct maze *maze) {
    // Initialize the maze
    for (int i = 0; i < maze->height; i++) {
        for (int j = 0; j < maze->width; j++) {
            maze->cells[i][j] = 0;
        }
    }

    // Create a stack of cells to visit
    struct stack {
        int x;
        int y;
    };
    struct stack stack[MAZE_SIZE * MAZE_SIZE];
    int top = 0;

    // Push the starting cell onto the stack
    stack[top].x = 0;
    stack[top].y = 0;
    top++;

    // While the stack is not empty
    while (top > 0) {
        // Pop the top cell from the stack
        top--;
        int x = stack[top].x;
        int y = stack[top].y;

        // Mark the cell as visited
        maze->cells[y][x] = 1;

        // Get a list of unvisited neighbor cells
        struct stack neighbors[4];
        int num_neighbors = 0;
        if (y > 0 && maze->cells[y - 1][x] == 0) {
            neighbors[num_neighbors].x = x;
            neighbors[num_neighbors].y = y - 1;
            num_neighbors++;
        }
        if (x < maze->width - 1 && maze->cells[y][x + 1] == 0) {
            neighbors[num_neighbors].x = x + 1;
            neighbors[num_neighbors].y = y;
            num_neighbors++;
        }
        if (y < maze->height - 1 && maze->cells[y + 1][x] == 0) {
            neighbors[num_neighbors].x = x;
            neighbors[num_neighbors].y = y + 1;
            num_neighbors++;
        }
        if (x > 0 && maze->cells[y][x - 1] == 0) {
            neighbors[num_neighbors].x = x - 1;
            neighbors[num_neighbors].y = y;
            num_neighbors++;
        }

        // If there are any unvisited neighbor cells
        if (num_neighbors > 0) {
            // Choose a random neighbor cell
            int r = rand() % num_neighbors;
            int next_x = neighbors[r].x;
            int next_y = neighbors[r].y;

            // Remove the wall between the current cell and the neighbor cell
            if (next_y == y - 1) {
                maze->cells[y][x] &= NORTH;
            } else if (next_x == x + 1) {
                maze->cells[y][x] &= EAST;
            } else if (next_y == y + 1) {
                maze->cells[y][x] &= SOUTH;
            } else if (next_x == x - 1) {
                maze->cells[y][x] &= WEST;
            }

            // Push the neighbor cell onto the stack
            stack[top].x = next_x;
            stack[top].y = next_y;
            top++;
        }
    }
}

// Print the maze to the console
void print_maze(struct maze *maze) {
    for (int i = 0; i < maze->height; i++) {
        for (int j = 0; j < maze->width; j++) {
            if (maze->cells[i][j] & NORTH) {
                printf("+--");
            } else {
                printf("+  ");
            }
        }
        printf("+\n");
        for (int j = 0; j < maze->width; j++) {
            if (maze->cells[i][j] & WEST) {
                printf("|  ");
            } else {
                printf("   ");
            }
        }
        printf("|\n");
    }
    for (int j = 0; j < maze->width; j++)
        printf("+--");
    printf("+\n");
}

// Main function
int main() {
    // Create a new maze
    struct maze *maze = create_maze(MAZE_SIZE, MAZE_SIZE);

    // Generate the maze
    generate_maze(maze);

    // Print the maze to the console
    print_maze(maze);

    // Free the maze
    free_maze(maze);

    return 0;
}