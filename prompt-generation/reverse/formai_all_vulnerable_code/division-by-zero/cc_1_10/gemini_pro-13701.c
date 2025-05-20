//GEMINI-pro DATASET v1.0 Category: Procedurally Generated Maze ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

// Maze structure
typedef struct {
    int width;
    int height;
    char **maze;
} Maze;

// Function to create a new maze
Maze *create_maze(int width, int height) {
    // Allocate memory for the maze
    Maze *maze = malloc(sizeof(Maze));
    if (maze == NULL) {
        return NULL;
    }

    // Initialize the maze
    maze->width = width;
    maze->height = height;
    maze->maze = malloc(sizeof(char *) * height);
    for (int i = 0; i < height; i++) {
        maze->maze[i] = malloc(sizeof(char) * width);
        for (int j = 0; j < width; j++) {
            maze->maze[i][j] = '#';
        }
    }

    // Return the maze
    return maze;
}

// Function to free the memory allocated for the maze
void free_maze(Maze *maze) {
    // Free the maze structure
    free(maze);

    // Free the maze data
    for (int i = 0; i < maze->height; i++) {
        free(maze->maze[i]);
    }
    free(maze->maze);
}

// Function to generate a random maze
void generate_maze(Maze *maze) {
    // Initialize the maze
    for (int i = 0; i < maze->height; i++) {
        for (int j = 0; j < maze->width; j++) {
            maze->maze[i][j] = '#';
        }
    }

    // Create a stack to store the cells that have been visited
    int stack_size = maze->width * maze->height;
    int *stack = malloc(sizeof(int) * stack_size);
    int stack_top = 0;

    // Select a random starting cell
    int x = rand() % maze->width;
    int y = rand() % maze->height;

    // Push the starting cell onto the stack
    stack[stack_top++] = x + y * maze->width;

    // While the stack is not empty, continue generating the maze
    while (stack_top > 0) {
        // Pop the top cell from the stack
        int cell = stack[--stack_top];

        // Get the coordinates of the cell
        int x = cell % maze->width;
        int y = cell / maze->width;

        // Mark the cell as visited
        maze->maze[y][x] = '.';

        // Get the neighbors of the cell
        int neighbors[4];
        int num_neighbors = 0;
        if (x > 0) { neighbors[num_neighbors++] = x - 1 + y * maze->width; }
        if (y > 0) { neighbors[num_neighbors++] = x + (y - 1) * maze->width; }
        if (x < maze->width - 1) { neighbors[num_neighbors++] = x + 1 + y * maze->width; }
        if (y < maze->height - 1) { neighbors[num_neighbors++] = x + (y + 1) * maze->width; }

        // Shuffle the neighbors
        for (int i = 0; i < num_neighbors; i++) {
            int j = rand() % num_neighbors;
            int temp = neighbors[i];
            neighbors[i] = neighbors[j];
            neighbors[j] = temp;
        }

        // Push the unvisited neighbors onto the stack
        for (int i = 0; i < num_neighbors; i++) {
            int neighbor = neighbors[i];
            if (maze->maze[neighbor / maze->width][neighbor % maze->width] == '#') {
                stack[stack_top++] = neighbor;
            }
        }
    }

    // Free the stack
    free(stack);
}

// Function to print the maze
void print_maze(Maze *maze) {
    for (int i = 0; i < maze->height; i++) {
        for (int j = 0; j < maze->width; j++) {
            printf("%c", maze->maze[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    // Create a new maze
    Maze *maze = create_maze(WIDTH, HEIGHT);

    // Generate the maze
    generate_maze(maze);

    // Print the maze
    print_maze(maze);

    // Free the memory allocated for the maze
    free_maze(maze);

    return 0;
}