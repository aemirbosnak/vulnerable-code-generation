//GEMINI-pro DATASET v1.0 Category: Pathfinding algorithms ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maze structure
typedef struct maze {
    int width;
    int height;
    int **cells;
} maze;

// Create a new maze
maze* create_maze(int width, int height) {
    maze* m = malloc(sizeof(maze));
    m->width = width;
    m->height = height;
    m->cells = malloc(sizeof(int*) * height);
    for (int i = 0; i < height; i++) {
        m->cells[i] = malloc(sizeof(int) * width);
    }
    return m;
}

// Free the memory allocated for the maze
void free_maze(maze* m) {
    for (int i = 0; i < m->height; i++) {
        free(m->cells[i]);
    }
    free(m->cells);
    free(m);
}

// Print the maze to the console
void print_maze(maze* m) {
    for (int i = 0; i < m->height; i++) {
        for (int j = 0; j < m->width; j++) {
            printf("%d ", m->cells[i][j]);
        }
        printf("\n");
    }
}

// Solve the maze using a depth-first search algorithm
bool solve_maze(maze* m, int x, int y) {
    // Check if the current cell is the goal cell
    if (x == m->width - 1 && y == m->height - 1) {
        return true;
    }

    // Check if the current cell is a wall
    if (m->cells[y][x] == 1) {
        return false;
    }

    // Mark the current cell as visited
    m->cells[y][x] = 2;

    // Recursively solve the maze from the current cell
    bool north = solve_maze(m, x, y - 1);
    bool east = solve_maze(m, x + 1, y);
    bool south = solve_maze(m, x, y + 1);
    bool west = solve_maze(m, x - 1, y);

    // If any of the recursive calls returned true, then the maze is solvable
    return north || east || south || west;
}

// Main function
int main() {
    // Create a maze
    maze* m = create_maze(10, 10);

    // Set the walls of the maze
    m->cells[0][0] = 1;
    m->cells[0][1] = 1;
    m->cells[0][2] = 1;
    m->cells[0][3] = 1;
    m->cells[1][3] = 1;
    m->cells[2][3] = 1;
    m->cells[3][3] = 1;
    m->cells[4][3] = 1;
    m->cells[5][3] = 1;
    m->cells[5][2] = 1;
    m->cells[5][1] = 1;
    m->cells[5][0] = 1;

    // Print the maze
    printf("Maze before solving:\n");
    print_maze(m);

    // Solve the maze
    bool solved = solve_maze(m, 0, 0);

    // Print the maze after solving
    printf("\nMaze after solving:\n");
    print_maze(m);

    // Free the memory allocated for the maze
    free_maze(m);

    return 0;
}