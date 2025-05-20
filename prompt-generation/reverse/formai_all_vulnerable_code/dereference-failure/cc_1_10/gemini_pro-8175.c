//GEMINI-pro DATASET v1.0 Category: Procedurally Generated Maze ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Dimensions of the maze
#define WIDTH 20
#define HEIGHT 10

// Data structure to store the maze
typedef struct {
    int x;
    int y;
} Cell;

// Function to create a new maze
Cell* create_maze() {
    // Allocate memory for the maze
    Cell* maze = (Cell*)malloc(WIDTH * HEIGHT * sizeof(Cell));

    // Initialize the maze
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            maze[i * HEIGHT + j].x = i;
            maze[i * HEIGHT + j].y = j;
        }
    }

    // Randomly generate the maze
    srand(time(NULL));
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        int x1 = rand() % WIDTH;
        int y1 = rand() % HEIGHT;
        int x2 = rand() % WIDTH;
        int y2 = rand() % HEIGHT;
        if (x1 != x2 || y1 != y2) {
            maze[x1 * HEIGHT + y1].x = x2;
            maze[x1 * HEIGHT + y1].y = y2;
        }
    }

    return maze;
}

// Function to print the maze
void print_maze(Cell* maze) {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            if (maze[i * HEIGHT + j].x == i && maze[i * HEIGHT + j].y == j) {
                printf("O");
            } else {
                printf("X");
            }
        }
        printf("\n");
    }
}

// Function to find the path through the maze
int find_path(Cell* maze, int start_x, int start_y, int end_x, int end_y) {
    // Create a stack to store the path
    Cell* stack = (Cell*)malloc(WIDTH * HEIGHT * sizeof(Cell));
    int top = 0;

    // Push the starting cell onto the stack
    stack[top++] = maze[start_x * HEIGHT + start_y];

    // While the stack is not empty
    while (top > 0) {
        // Pop the top cell from the stack
        Cell cell = stack[--top];

        // If the current cell is the end cell
        if (cell.x == end_x && cell.y == end_y) {
            return 1;
        }

        // Add the neighbors of the current cell to the stack
        if (cell.x > 0 && maze[(cell.x - 1) * HEIGHT + cell.y].x == cell.x - 1 && maze[(cell.x - 1) * HEIGHT + cell.y].y == cell.y) {
            stack[top++] = maze[(cell.x - 1) * HEIGHT + cell.y];
        }
        if (cell.x < WIDTH - 1 && maze[(cell.x + 1) * HEIGHT + cell.y].x == cell.x + 1 && maze[(cell.x + 1) * HEIGHT + cell.y].y == cell.y) {
            stack[top++] = maze[(cell.x + 1) * HEIGHT + cell.y];
        }
        if (cell.y > 0 && maze[cell.x * HEIGHT + (cell.y - 1)].x == cell.x && maze[cell.x * HEIGHT + (cell.y - 1)].y == cell.y - 1) {
            stack[top++] = maze[cell.x * HEIGHT + (cell.y - 1)];
        }
        if (cell.y < HEIGHT - 1 && maze[cell.x * HEIGHT + (cell.y + 1)].x == cell.x && maze[cell.x * HEIGHT + (cell.y + 1)].y == cell.y + 1) {
            stack[top++] = maze[cell.x * HEIGHT + (cell.y + 1)];
        }
    }

    // No path found
    return 0;
}

int main() {
    // Create the maze
    Cell* maze = create_maze();

    // Print the maze
    print_maze(maze);

    // Find the path through the maze
    int path_found = find_path(maze, 0, 0, WIDTH - 1, HEIGHT - 1);

    // Print the result
    if (path_found) {
        printf("Path found!\n");
    } else {
        printf("No path found.\n");
    }

    // Free the memory allocated for the maze
    free(maze);

    return 0;
}