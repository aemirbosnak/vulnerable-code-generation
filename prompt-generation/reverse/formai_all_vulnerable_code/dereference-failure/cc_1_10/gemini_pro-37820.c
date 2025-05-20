//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maze structure
typedef struct {
    int width;
    int height;
    int **maze;
} Maze;

// Create a new maze
Maze *create_maze(int width, int height) {
    Maze *maze = (Maze *)malloc(sizeof(Maze));
    maze->width = width;
    maze->height = height;
    maze->maze = (int **)malloc(sizeof(int *) * height);
    for (int i = 0; i < height; i++) {
        maze->maze[i] = (int *)malloc(sizeof(int) * width);
    }
    return maze;
}

// Free the memory allocated for the maze
void free_maze(Maze *maze) {
    for (int i = 0; i < maze->height; i++) {
        free(maze->maze[i]);
    }
    free(maze->maze);
    free(maze);
}

// Print the maze to the console
void print_maze(Maze *maze) {
    for (int i = 0; i < maze->height; i++) {
        for (int j = 0; j < maze->width; j++) {
            printf("%d ", maze->maze[i][j]);
        }
        printf("\n");
    }
}

// Find the path from the start to the end of the maze
int find_path(Maze *maze, int start_x, int start_y, int end_x, int end_y) {
    // Create a stack to store the path
    int **stack = (int **)malloc(sizeof(int *) * maze->height);
    for (int i = 0; i < maze->height; i++) {
        stack[i] = (int *)malloc(sizeof(int) * maze->width);
    }

    // Push the start position onto the stack
    stack[0][0] = start_x;
    stack[0][1] = start_y;

    // While the stack is not empty
    while (stack[0][0] != -1) {
        // Pop the top position from the stack
        int x = stack[0][0];
        int y = stack[0][1];
        stack[0][0] = -1;
        stack[0][1] = -1;

        // If the current position is the end position, return true
        if (x == end_x && y == end_y) {
            free(stack);
            return 1;
        }

        // If the current position is valid, push the adjacent positions onto the stack
        if (x > 0 && maze->maze[y][x - 1] == 0) {
            stack[0][0] = x - 1;
            stack[0][1] = y;
        }
        if (y > 0 && maze->maze[y - 1][x] == 0) {
            stack[0][0] = x;
            stack[0][1] = y - 1;
        }
        if (x < maze->width - 1 && maze->maze[y][x + 1] == 0) {
            stack[0][0] = x + 1;
            stack[0][1] = y;
        }
        if (y < maze->height - 1 && maze->maze[y + 1][x] == 0) {
            stack[0][0] = x;
            stack[0][1] = y + 1;
        }
    }

    // If the stack is empty, return false
    free(stack);
    return 0;
}

// Main function
int main() {
    // Create a maze
    Maze *maze = create_maze(10, 10);

    // Set the walls of the maze
    for (int i = 0; i < maze->height; i++) {
        for (int j = 0; j < maze->width; j++) {
            if (i == 0 || i == maze->height - 1 || j == 0 || j == maze->width - 1) {
                maze->maze[i][j] = 1;
            }
        }
    }

    // Print the maze
    print_maze(maze);

    // Find the path from the start to the end of the maze
    int start_x = 1;
    int start_y = 1;
    int end_x = 8;
    int end_y = 8;
    int path_found = find_path(maze, start_x, start_y, end_x, end_y);

    // Print the result
    if (path_found) {
        printf("Path found!\n");
    } else {
        printf("No path found.\n");
    }

    // Free the memory allocated for the maze
    free_maze(maze);

    return 0;
}