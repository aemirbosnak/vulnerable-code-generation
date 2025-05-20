//GEMINI-pro DATASET v1.0 Category: Procedurally Generated Maze ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

// Constants
#define WIDTH 10
#define HEIGHT 10

// Data structures
typedef struct {
    int x;
    int y;
} Point;

// Function declarations
Point* find_start_point(int** maze);
void print_maze(int** maze);
void generate_maze(int** maze);
void solve_maze(int** maze, Point* start);

// Main function
int main() {
    // Create a new maze
    int** maze = (int**)malloc(WIDTH * sizeof(int*));
    for (int i = 0; i < WIDTH; i++) {
        maze[i] = (int*)malloc(HEIGHT * sizeof(int));
    }

    // Generate the maze
    generate_maze(maze);

    // Find the start point
    Point* start = find_start_point(maze);

    // Solve the maze
    solve_maze(maze, start);

    // Print the maze
    print_maze(maze);

    // Free the memory
    for (int i = 0; i < WIDTH; i++) {
        free(maze[i]);
    }
    free(maze);

    return 0;
}

// Function definitions

// Find the start point of the maze
Point* find_start_point(int** maze) {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            if (maze[i][j] == 0) {
                Point* start = (Point*)malloc(sizeof(Point));
                start->x = i;
                start->y = j;
                return start;
            }
        }
    }

    return NULL;
}

// Print the maze
void print_maze(int** maze) {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            if (maze[i][j] == 0) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

// Generate a maze using the Eller's algorithm
void generate_maze(int** maze) {
    // Initialize the maze
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            maze[i][j] = 1;
        }
    }

    // Create a set of disjoint sets
    int* sets = (int*)malloc(WIDTH * HEIGHT * sizeof(int));
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        sets[i] = i;
    }

    // Iterate over the cells in the maze
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            // Get the current cell and its neighbors
            int cell = i * WIDTH + j;
            int left = (i - 1) * WIDTH + j;
            int right = (i + 1) * WIDTH + j;
            int up = i * WIDTH + (j - 1);
            int down = i * WIDTH + (j + 1);

            // Check if the cell is on the left edge of the maze
            if (i == 0) {
                // Remove the left wall
                maze[cell][left] = 0;
            }

            // Check if the cell is on the right edge of the maze
            if (i == WIDTH - 1) {
                // Remove the right wall
                maze[cell][right] = 0;
            }

            // Check if the cell is on the top edge of the maze
            if (j == 0) {
                // Remove the up wall
                maze[cell][up] = 0;
            }

            // Check if the cell is on the bottom edge of the maze
            if (j == HEIGHT - 1) {
                // Remove the down wall
                maze[cell][down] = 0;
            }

            // Check if the cell has any neighbors in the same set
            if (sets[cell] != sets[left] && sets[cell] != sets[right] && sets[cell] != sets[up] && sets[cell] != sets[down]) {
                // Remove a random wall
                int walls[4] = {left, right, up, down};
                int random_wall = walls[rand() % 4];
                maze[cell][random_wall] = 0;

                // Union the sets of the cell and its neighbor
                int set_cell = sets[cell];
                int set_neighbor = sets[random_wall];
                for (int k = 0; k < WIDTH * HEIGHT; k++) {
                    if (sets[k] == set_neighbor) {
                        sets[k] = set_cell;
                    }
                }
            }
        }
    }

    // Free the memory
    free(sets);
}

// Solve the maze using a depth-first search
void solve_maze(int** maze, Point* start) {
    // Create a stack to store the path
    int* stack = (int*)malloc(WIDTH * HEIGHT * sizeof(int));
    int top = 0;

    // Push the start point onto the stack
    stack[top++] = start->x * WIDTH + start->y;

    // While the stack is not empty
    while (top > 0) {
        // Pop the top point from the stack
        int cell = stack[--top];
        int x = cell / WIDTH;
        int y = cell % WIDTH;

        // Check if the cell is the exit
        if (x == WIDTH - 1 && y == HEIGHT - 1) {
            // Print the path
            for (int i = 0; i < top; i++) {
                int cell = stack[i];
                int x = cell / WIDTH;
                int y = cell % WIDTH;
                maze[x][y] = 2;
            }

            break;
        }

        // Mark the cell as visited
        maze[x][y] = 2;

        // Push the unvisited neighbors onto the stack
        int left = (x - 1) * WIDTH + y;
        int right = (x + 1) * WIDTH + y;
        int up = x * WIDTH + (y - 1);
        int down = x * WIDTH + (y + 1);

        if (maze[x - 1][y] == 0) {
            stack[top++] = left;
        }
        if (maze[x + 1][y] == 0) {
            stack[top++] = right;
        }
        if (maze[x][y - 1] == 0) {
            stack[top++] = up;
        }
        if (maze[x][y + 1] == 0) {
            stack[top++] = down;
        }
    }

    // Free the memory
    free(stack);
}