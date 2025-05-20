//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a maze cell
typedef struct {
    int x, y;
    int visited;
} Cell;

// Structure to represent a stack of cells
typedef struct {
    Cell *cells;
    int top;
} Stack;

// Function to create a new maze cell
Cell *newCell(int x, int y) {
    Cell *cell = malloc(sizeof(Cell));
    cell->x = x;
    cell->y = y;
    cell->visited = 0;
    return cell;
}

// Function to create a new stack
Stack *newStack() {
    Stack *stack = malloc(sizeof(Stack));
    stack->cells = malloc(sizeof(Cell) * 100);
    stack->top = -1;
    return stack;
}

// Function to push a cell onto the stack
void push(Stack *stack, Cell *cell) {
    stack->cells[++stack->top] = *cell;
}

// Function to pop a cell from the stack
Cell *pop(Stack *stack) {
    return &stack->cells[stack->top--];
}

// Function to check if a cell is valid
int isValid(Cell *cell, int n, int m) {
    return cell->x >= 0 && cell->x < n && cell->y >= 0 && cell->y < m;
}

// Function to check if a cell is visited
int isVisited(Cell *cell) {
    return cell->visited;
}

// Function to mark a cell as visited
void visit(Cell *cell) {
    cell->visited = 1;
}

// Function to find the next valid cell in a given direction
Cell *nextCell(Cell *cell, int n, int m, int direction) {
    switch (direction) {
    case 0: // North
        return newCell(cell->x, cell->y - 1);
    case 1: // East
        return newCell(cell->x + 1, cell->y);
    case 2: // South
        return newCell(cell->x, cell->y + 1);
    case 3: // West
        return newCell(cell->x - 1, cell->y);
    }
    return NULL;
}

// Function to find a path from the starting cell to the ending cell in a maze
int findPath(Cell *start, Cell *end, int n, int m) {
    // Create a stack to store the cells in the path
    Stack *stack = newStack();

    // Push the starting cell onto the stack
    push(stack, start);

    // While the stack is not empty
    while (stack->top != -1) {
        // Pop the top cell from the stack
        Cell *cell = pop(stack);

        // If the current cell is the ending cell, then we have found a path
        if (cell->x == end->x && cell->y == end->y) {
            return 1;
        }

        // Mark the current cell as visited
        visit(cell);

        // Check all four directions for a valid next cell
        for (int i = 0; i < 4; i++) {
            Cell *next = nextCell(cell, n, m, i);
            if (isValid(next, n, m) && !isVisited(next)) {
                // Push the next cell onto the stack
                push(stack, next);
            }
        }
    }

    // If the stack is empty, then there is no path from the starting cell to the ending cell
    return 0;
}

// Function to print the maze
void printMaze(Cell **maze, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maze[i][j].visited) {
                printf("."); // Visited cell
            } else {
                printf("#"); // Unvisited cell
            }
        }
        printf("\n");
    }
}

int main() {
    // Create a maze with 5 rows and 5 columns
    int n = 5;
    int m = 5;
    Cell **maze = malloc(sizeof(Cell *) * n);
    for (int i = 0; i < n; i++) {
        maze[i] = malloc(sizeof(Cell) * m);
    }

    // Initialize the maze
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            maze[i][j] = *newCell(i, j);
        }
    }

    // Set the starting and ending cells
    Cell *start = &maze[0][0];
    Cell *end = &maze[n - 1][m - 1];

    // Find a path from the starting cell to the ending cell
    int found = findPath(start, end, n, m);

    // Print the maze
    printMaze(maze, n, m);

    // Free the memory allocated for the maze
    for (int i = 0; i < n; i++) {
        free(maze[i]);
    }
    free(maze);

    return 0;
}