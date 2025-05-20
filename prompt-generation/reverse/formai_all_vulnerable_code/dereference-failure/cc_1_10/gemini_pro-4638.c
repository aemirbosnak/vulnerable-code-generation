//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Define the maze dimensions
#define MAZE_WIDTH 10
#define MAZE_HEIGHT 10

// Define the maze data structure
typedef struct Maze {
    int width;
    int height;
    int **data;
} Maze;

// Create a new maze
Maze *create_maze(int width, int height) {
    Maze *maze = malloc(sizeof(Maze));
    maze->width = width;
    maze->height = height;
    maze->data = malloc(sizeof(int *) * height);
    for (int i = 0; i < height; i++) {
        maze->data[i] = malloc(sizeof(int) * width);
    }
    return maze;
}

// Free the memory allocated for the maze
void destroy_maze(Maze *maze) {
    for (int i = 0; i < maze->height; i++) {
        free(maze->data[i]);
    }
    free(maze->data);
    free(maze);
}

// Print the maze to the console
void print_maze(Maze *maze) {
    for (int i = 0; i < maze->height; i++) {
        for (int j = 0; j < maze->width; j++) {
            printf("%d ", maze->data[i][j]);
        }
        printf("\n");
    }
}

// Solve the maze using a depth-first search
int solve_maze(Maze *maze, int start_x, int start_y, int end_x, int end_y) {
    // Check if the starting and ending points are valid
    if (start_x < 0 || start_x >= maze->width || start_y < 0 || start_y >= maze->height ||
        end_x < 0 || end_x >= maze->width || end_y < 0 || end_y >= maze->height) {
        return 0;
    }

    // Check if the starting point is a wall
    if (maze->data[start_y][start_x] == 1) {
        return 0;
    }

    // Check if the starting point is the ending point
    if (start_x == end_x && start_y == end_y) {
        return 1;
    }

    // Mark the starting point as visited
    maze->data[start_y][start_x] = 1;

    // Recursively explore the maze in all four directions
    int result = 0;
    if (start_x > 0 && maze->data[start_y][start_x - 1] == 0) {
        result = solve_maze(maze, start_x - 1, start_y, end_x, end_y);
    }
    if (start_x < maze->width - 1 && maze->data[start_y][start_x + 1] == 0) {
        result = solve_maze(maze, start_x + 1, start_y, end_x, end_y);
    }
    if (start_y > 0 && maze->data[start_y - 1][start_x] == 0) {
        result = solve_maze(maze, start_x, start_y - 1, end_x, end_y);
    }
    if (start_y < maze->height - 1 && maze->data[start_y + 1][start_x] == 0) {
        result = solve_maze(maze, start_x, start_y + 1, end_x, end_y);
    }

    // If a path was found, return 1
    if (result == 1) {
        return 1;
    }

    // Otherwise, unmark the starting point as visited and return 0
    maze->data[start_y][start_x] = 0;
    return 0;
}

// Main function
int main() {
    // Create a new maze
    Maze *maze = create_maze(MAZE_WIDTH, MAZE_HEIGHT);

    // Populate the maze with walls and empty spaces
    for (int i = 0; i < maze->height; i++) {
        for (int j = 0; j < maze->width; j++) {
            maze->data[i][j] = rand() % 2;
        }
    }

    // Print the maze to the console
    print_maze(maze);

    // Solve the maze
    int result = solve_maze(maze, 0, 0, MAZE_WIDTH - 1, MAZE_HEIGHT - 1);

    // Print the result to the console
    if (result == 1) {
        printf("A path was found!\n");
    } else {
        printf("No path was found.\n");
    }

    // Free the memory allocated for the maze
    destroy_maze(maze);

    return 0;
}