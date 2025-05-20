//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

// Define the maze array
char maze[ROWS][COLS] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', '#', '#', ' ', '#', '#', '#', ' ', '#'},
    {'#', ' ', '#', '#', ' ', ' ', ' ', '#', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#'},
    {'#', ' ', '#', '#', ' ', '#', '#', '#', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', '#', '#', ' ', '#', '#', '#', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
};

// Define the directions
enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

// Define the stack
struct Stack {
    int top;
    int capacity;
    int* array;
};

// Create a new stack
struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
    return stack;
}

// Push an element onto the stack
void push(struct Stack* stack, int element) {
    if (stack->top == stack->capacity - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack->array[++stack->top] = element;
}

// Pop an element from the stack
int pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->array[stack->top--];
}

// Check if the stack is empty
bool isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Print the maze
void printMaze() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

// Check if the position is valid
bool isValidPosition(int row, int col) {
    return row >= 0 && row < ROWS && col >= 0 && col < COLS && maze[row][col] != '#';
}

// Find the path using DFS
bool findPath(int startRow, int startCol, struct Stack* stack) {
    // Push the starting position onto the stack
    push(stack, startRow);
    push(stack, startCol);

    // While the stack is not empty
    while (!isEmpty(stack)) {
        // Pop the current position from the stack
        int row = pop(stack);
        int col = pop(stack);

        // Mark the current position as visited
        maze[row][col] = '*';

        // Check if we have reached the destination
        if (row == ROWS - 1 && col == COLS - 1) {
            return true;
        }

        // Try all possible moves
        if (isValidPosition(row - 1, col)) {
            push(stack, row - 1);
            push(stack, col);
        }
        if (isValidPosition(row + 1, col)) {
            push(stack, row + 1);
            push(stack, col);
        }
        if (isValidPosition(row, col - 1)) {
            push(stack, row);
            push(stack, col - 1);
        }
        if (isValidPosition(row, col + 1)) {
            push(stack, row);
            push(stack, col + 1);
        }
    }

    // No path found
    return false;
}

// Main function
int main() {
    // Create a stack
    struct Stack* stack = createStack(ROWS * COLS);

    // Find the path
    bool foundPath = findPath(0, 0, stack);

    // Print the maze
    printMaze();

    // Free the stack
    free(stack->array);
    free(stack);

    return 0;
}