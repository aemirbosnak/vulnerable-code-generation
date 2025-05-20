//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maze structure
typedef struct {
    int width;
    int height;
    char **maze;
} Maze;

// Define the stack structure
typedef struct {
    int *data;
    int top;
    int size;
} Stack;

// Create a new maze
Maze *createMaze(int width, int height) {
    Maze *maze = (Maze *)malloc(sizeof(Maze));
    maze->width = width;
    maze->height = height;
    maze->maze = (char **)malloc(sizeof(char *) * height);
    for (int i = 0; i < height; i++) {
        maze->maze[i] = (char *)malloc(sizeof(char) * width);
    }
    return maze;
}

// Free the maze
void freeMaze(Maze *maze) {
    for (int i = 0; i < maze->height; i++) {
        free(maze->maze[i]);
    }
    free(maze->maze);
    free(maze);
}

// Print the maze
void printMaze(Maze *maze) {
    for (int i = 0; i < maze->height; i++) {
        for (int j = 0; j < maze->width; j++) {
            printf("%c", maze->maze[i][j]);
        }
        printf("\n");
    }
}

// Create a new stack
Stack *createStack(int size) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->data = (int *)malloc(sizeof(int) * size);
    stack->top = -1;
    stack->size = size;
    return stack;
}

// Free the stack
void freeStack(Stack *stack) {
    free(stack->data);
    free(stack);
}

// Push an element onto the stack
void push(Stack *stack, int element) {
    if (stack->top == stack->size - 1) {
        printf("Error: Stack overflow\n");
        return;
    }
    stack->data[++stack->top] = element;
}

// Pop an element from the stack
int pop(Stack *stack) {
    if (stack->top == -1) {
        printf("Error: Stack underflow\n");
        return -1;
    }
    return stack->data[stack->top--];
}

// Check if the stack is empty
bool isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Find the path through the maze using a stack
bool findPath(Maze *maze, int startX, int startY, int endX, int endY) {
    // Create a stack to store the path
    Stack *stack = createStack(maze->width * maze->height);

    // Push the starting position onto the stack
    push(stack, startX);
    push(stack, startY);

    // While the stack is not empty
    while (!isEmpty(stack)) {
        // Pop the current position from the stack
        int x = pop(stack);
        int y = pop(stack);

        // If the current position is the end position
        if (x == endX && y == endY) {
            return true;
        }

        // If the current position is not a wall
        if (maze->maze[y][x] != '#') {
            // Mark the current position as visited
            maze->maze[y][x] = '.';

            // Push the adjacent positions onto the stack
            if (x > 0 && maze->maze[y][x - 1] != '#') {
                push(stack, x - 1);
                push(stack, y);
            }
            if (y > 0 && maze->maze[y - 1][x] != '#') {
                push(stack, x);
                push(stack, y - 1);
            }
            if (x < maze->width - 1 && maze->maze[y][x + 1] != '#') {
                push(stack, x + 1);
                push(stack, y);
            }
            if (y < maze->height - 1 && maze->maze[y + 1][x] != '#') {
                push(stack, x);
                push(stack, y + 1);
            }
        }
    }

    // No path found
    return false;
}

// Main function
int main() {
    // Create a maze
    Maze *maze = createMaze(10, 10);

    // Set the maze walls
    for (int i = 0; i < maze->height; i++) {
        for (int j = 0; j < maze->width; j++) {
            if (i == 0 || i == maze->height - 1 || j == 0 || j == maze->width - 1) {
                maze->maze[i][j] = '#';
            } else {
                maze->maze[i][j] = ' ';
            }
        }
    }

    // Set the starting and ending positions
    int startX = 1;
    int startY = 1;
    int endX = 8;
    int endY = 8;

    // Find the path through the maze
    bool foundPath = findPath(maze, startX, startY, endX, endY);

    // Print the maze
    printMaze(maze);

    // Free the maze
    freeMaze(maze);

    return 0;
}