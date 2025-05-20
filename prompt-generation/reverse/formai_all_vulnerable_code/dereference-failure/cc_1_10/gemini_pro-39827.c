//GEMINI-pro DATASET v1.0 Category: Procedurally Generated Maze ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Initialize the grid with all walls
char grid[20][20];
int width = 20, height = 20;

// Initialize the visited array with all cells unvisited
int visited[20][20];

// Initialize the stack with the starting cell
struct stack {
    int x, y;
    struct stack *next;
};

struct stack *stack_top = NULL;

// Function to push a cell onto the stack
void stack_push(int x, int y) {
    struct stack *new_cell = malloc(sizeof(struct stack));
    new_cell->x = x;
    new_cell->y = y;
    new_cell->next = stack_top;
    stack_top = new_cell;
}

// Function to pop a cell from the stack
void stack_pop() {
    if (stack_top != NULL) {
        struct stack *temp = stack_top;
        stack_top = stack_top->next;
        free(temp);
    }
}

// Function to check if a cell is valid
int is_valid(int x, int y) {
    return (x >= 0 && x < width && y >= 0 && y < height && !visited[x][y]);
}

// Function to generate the maze
void generate_maze() {
    int x = 0, y = 0;

    // Mark the starting cell as visited and push it onto the stack
    visited[x][y] = 1;
    stack_push(x, y);

    // While there are still cells to visit
    while (stack_top != NULL) {
        // Get the current cell from the stack
        x = stack_top->x;
        y = stack_top->y;

        // Pop the cell from the stack
        stack_pop();

        // Check if the current cell has any unvisited neighbors
        int neighbors[4][2] = {{x, y - 1}, {x, y + 1}, {x - 1, y}, {x + 1, y}};
        int num_neighbors = 4;
        for (int i = 0; i < num_neighbors; i++) {
            int nx = neighbors[i][0];
            int ny = neighbors[i][1];
            if (is_valid(nx, ny)) {
                // Randomly choose a neighbor and mark it as visited
                srand(time(NULL));
                int r = rand() % num_neighbors;
                nx = neighbors[r][0];
                ny = neighbors[r][1];
                visited[nx][ny] = 1;

                // Push the neighbor onto the stack
                stack_push(nx, ny);
            }
        }
    }
}

// Function to print the maze
void print_maze() {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (visited[x][y]) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

int main() {
    // Generate the maze
    generate_maze();

    // Print the maze
    print_maze();

    return 0;
}