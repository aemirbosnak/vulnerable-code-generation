//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

// Forward declarations
void maze_print();
int  maze_solve(int x, int y);
int* maze_init();

// The maze
int maze[6][6] = {
    {1, 1, 1, 1, 0, 1},
    {1, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 0, 1},
    {0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1}
};

// Main function
int main() {
    // Initialize the maze
    int *maze_ptr = maze_init();

    // Print the maze
    maze_print();

    // Solve the maze
    if (maze_solve(1, 1)) {
        printf("Found a solution!\n");
    } else {
        printf("No solution found.\n");
    }

    // Free the maze
    free(maze_ptr);

    return 0;
}

// Initialize the maze
int *maze_init() {
    // Allocate memory for the maze
    int *maze_ptr = malloc(sizeof(maze));

    // Copy the maze data into the allocated memory
    memcpy(maze_ptr, maze, sizeof(maze));

    // Return the pointer to the maze
    return maze_ptr;
}

// Print the maze
void maze_print() {
    // Loop through the maze and print each row
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            // Print the wall or the space
            printf("%c", maze[i][j] ? '#' : ' ');
        }
        printf("\n");
    }
}

// Solve the maze
int maze_solve(int x, int y) {
    // Check if the current position is the exit
    if (x == 5 && y == 5) {
        return 1;
    }

    // Check if the current position is a wall
    if (maze[y][x]) {
        return 0;
    }

    // Mark the current position as visited
    maze[y][x] = 1;

    // Try to solve the maze from the current position
    // Try to move up
    if (maze_solve(x, y - 1)) {
        return 1;
    }
    // Try to move right
    if (maze_solve(x + 1, y)) {
        return 1;
    }
    // Try to move down
    if (maze_solve(x, y + 1)) {
        return 1;
    }
    // Try to move left
    if (maze_solve(x - 1, y)) {
        return 1;
    }

    // Unmark the current position as visited
    maze[y][x] = 0;

    // No solution found from the current position
    return 0;
}