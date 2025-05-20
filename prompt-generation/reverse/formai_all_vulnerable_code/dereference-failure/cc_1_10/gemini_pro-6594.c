//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maze size
#define MAZE_WIDTH  10
#define MAZE_HEIGHT 10

// Define the maze data type
typedef struct maze {
    int width;
    int height;
    int **data;
} maze_t;

// Create a new maze
maze_t *maze_create(int width, int height) {
    maze_t *maze = malloc(sizeof(maze_t));
    maze->width = width;
    maze->height = height;
    maze->data = malloc(sizeof(int *) * height);
    for (int i = 0; i < height; i++) {
        maze->data[i] = malloc(sizeof(int) * width);
    }
    return maze;
}

// Destroy a maze
void maze_destroy(maze_t *maze) {
    for (int i = 0; i < maze->height; i++) {
        free(maze->data[i]);
    }
    free(maze->data);
    free(maze);
}

// Print a maze
void maze_print(maze_t *maze) {
    for (int i = 0; i < maze->height; i++) {
        for (int j = 0; j < maze->width; j++) {
            printf("%d ", maze->data[i][j]);
        }
        printf("\n");
    }
}

// Generate a random maze
void maze_generate(maze_t *maze) {
    // Initialize the maze with walls
    for (int i = 0; i < maze->height; i++) {
        for (int j = 0; j < maze->width; j++) {
            maze->data[i][j] = 1;
        }
    }

    // Create a stack to store the cells that have been visited
    int stack[MAZE_WIDTH * MAZE_HEIGHT];
    int top = 0;

    // Start at a random cell
    int x = rand() % maze->width;
    int y = rand() % maze->height;

    // While there are still cells to visit
    while (top > 0) {
        // Push the current cell onto the stack
        stack[top++] = y * maze->width + x;

        // Mark the current cell as visited
        maze->data[y][x] = 0;

        // Get the neighbors of the current cell
        int neighbors[4];
        int num_neighbors = 0;
        if (x > 0) {
            neighbors[num_neighbors++] = y * maze->width + (x - 1);
        }
        if (y > 0) {
            neighbors[num_neighbors++] = (y - 1) * maze->width + x;
        }
        if (x < maze->width - 1) {
            neighbors[num_neighbors++] = y * maze->width + (x + 1);
        }
        if (y < maze->height - 1) {
            neighbors[num_neighbors++] = (y + 1) * maze->width + x;
        }

        // If there are no unvisited neighbors, pop the current cell from the stack
        if (num_neighbors == 0) {
            top--;
        } else {
            // Choose a random unvisited neighbor
            int neighbor = neighbors[rand() % num_neighbors];

            // Remove the wall between the current cell and the neighbor
            int dx = neighbor % maze->width - x;
            int dy = neighbor / maze->width - y;
            maze->data[y + dy][x + dx] = 0;

            // Move to the neighbor
            x += dx;
            y += dy;
        }
    }
}

// Find a path through a maze
int maze_solve(maze_t *maze, int x, int y) {
    // If we have reached the end of the maze, return true
    if (x == maze->width - 1 && y == maze->height - 1) {
        return 1;
    }

    // If we have hit a wall, return false
    if (maze->data[y][x] == 1) {
        return 0;
    }

    // Mark the current cell as visited
    maze->data[y][x] = 2;

    // Try all possible moves
    int moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    for (int i = 0; i < 4; i++) {
        int next_x = x + moves[i][0];
        int next_y = y + moves[i][1];

        // If the next move is valid, try it
        if (next_x >= 0 && next_x < maze->width && next_y >= 0 && next_y < maze->height) {
            if (maze_solve(maze, next_x, next_y)) {
                return 1;
            }
        }
    }

    // If we have tried all possible moves and none of them worked, return false
    return 0;
}

// Main function
int main(void) {
    // Create a new maze
    maze_t *maze = maze_create(MAZE_WIDTH, MAZE_HEIGHT);

    // Generate a random maze
    maze_generate(maze);

    // Print the maze
    maze_print(maze);

    // Find a path through the maze
    int solved = maze_solve(maze, 0, 0);

    // Print the solution
    if (solved) {
        printf("Maze solved!\n");
    } else {
        printf("No solution found.\n");
    }

    // Destroy the maze
    maze_destroy(maze);

    return 0;
}