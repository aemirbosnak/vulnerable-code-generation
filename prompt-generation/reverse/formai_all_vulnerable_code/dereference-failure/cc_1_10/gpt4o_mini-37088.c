//GPT-4o-mini DATASET v1.0 Category: Maze Route Finder ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define PATH ' '
#define WALL '#'
#define START 'S'
#define EXIT 'E'
#define VISITED '.'

typedef struct Position {
    int x;
    int y;
} Position;

typedef struct Stack {
    Position *positions;
    int top;
    int maxSize;
} Stack;

void initializeStack(Stack *stack, int size) {
    stack->positions = (Position *)malloc(size * sizeof(Position));
    stack->top = -1;
    stack->maxSize = size;
}

int isFull(Stack *stack) {
    return stack->top == stack->maxSize - 1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, Position pos) {
    if (!isFull(stack)) {
        stack->positions[++stack->top] = pos;
    }
}

Position pop(Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->positions[stack->top--];
    }
    return (Position){-1, -1}; // Return an invalid position
}

void freeStack(Stack *stack) {
    free(stack->positions);
}

void printMaze(char **maze, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            putchar(maze[i][j]);
        }
        putchar('\n');
    }
}

int isSafe(char **maze, int x, int y, int rows, int cols) {
    return (x >= 0 && x < rows && y >= 0 && y < cols && (maze[x][y] == PATH || maze[x][y] == EXIT));
}

int findPath(char **maze, Position start, Position exit, int rows, int cols) {
    Stack stack;
    initializeStack(&stack, rows * cols);
    push(&stack, start);

    while (!isEmpty(&stack)) {
        Position current = pop(&stack);
        int x = current.x;
        int y = current.y;

        if (x == exit.x && y == exit.y) {
            maze[x][y] = VISITED; // Path found
            printMaze(maze, rows, cols);
            freeStack(&stack);
            return 1;
        }

        if (isSafe(maze, x, y, rows, cols)) {
            maze[x][y] = VISITED; // Mark as visited

            // Explore neighbors (up, down, left, right)
            push(&stack, (Position){x + 1, y}); // Down
            push(&stack, (Position){x - 1, y}); // Up
            push(&stack, (Position){x, y + 1}); // Right
            push(&stack, (Position){x, y - 1}); // Left
        }
    }

    freeStack(&stack);
    return 0; // No path found
}

int main() {
    int rows = 5, cols = 5;
    char **maze = (char **)malloc(rows * sizeof(char *));
    
    maze[0] = "#S###";
    maze[1] = "#  #E";
    maze[2] = "# ## ";
    maze[3] = "#    ";
    maze[4] = "#####";
    
    printf("Initial Maze:\n");
    printMaze(maze, rows, cols);
    
    Position start = {0, 1}; // Starting point (row 0, col 1)
    Position exit = {1, 4};   // Ending point (row 1, col 4)

    if (findPath(maze, start, exit, rows, cols)) {
        printf("Path exists from 'S' to 'E'.\n");
    } else {
        printf("No path found from 'S' to 'E'.\n");
    }

    // Free allocated memory
    for (int i = 0; i < rows; i++) {
        free(maze[i]);
    }
    free(maze);

    return 0;
}