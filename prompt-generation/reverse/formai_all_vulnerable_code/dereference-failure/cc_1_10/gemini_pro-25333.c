//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define MAZE_WIDTH 10
#define MAZE_HEIGHT 10

// The maze represented as a 2D array of integers:
// 0 - open space
// 1 - wall
int maze[MAZE_HEIGHT][MAZE_WIDTH] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 0, 1, 1, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 1, 1, 0, 1, 1, 1, 0, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

// A stack to store the visited positions:
struct Stack {
    int x;
    int y;
    struct Stack *next;
};

// Create a new stack:
struct Stack *createStack() {
    return NULL;
}

// Push a new position onto the stack:
void push(struct Stack **stack, int x, int y) {
    struct Stack *newStack = malloc(sizeof(struct Stack));
    newStack->x = x;
    newStack->y = y;
    newStack->next = *stack;
    *stack = newStack;
}

// Pop the top position from the stack:
int pop(struct Stack **stack, int *x, int *y) {
    if (*stack == NULL) {
        return 0;
    }
    struct Stack *temp = *stack;
    *x = temp->x;
    *y = temp->y;
    *stack = temp->next;
    free(temp);
    return 1;
}

// Find a path from the start position to the end position using depth-first search:
int findPath(int startX, int startY, int endX, int endY) {
    // Create a stack to store the visited positions:
    struct Stack *stack = createStack();

    // Push the start position onto the stack:
    push(&stack, startX, startY);

    // While the stack is not empty:
    while (stack != NULL) {
        // Pop the top position from the stack:
        int x, y;
        if (!pop(&stack, &x, &y)) {
            return 0;
        }

        // Check if the current position is the end position:
        if (x == endX && y == endY) {
            return 1;
        }

        // Check if the current position is a valid move:
        if (x >= 0 && x < MAZE_WIDTH && y >= 0 && y < MAZE_HEIGHT && maze[y][x] == 0) {
            // Mark the current position as visited:
            maze[y][x] = 2;

            // Push the adjacent positions onto the stack:
            push(&stack, x + 1, y);
            push(&stack, x - 1, y);
            push(&stack, x, y + 1);
            push(&stack, x, y - 1);
        }
    }

    // No path found
    return 0;
}

// Print the maze to the console:
void printMaze() {
    for (int y = 0; y < MAZE_HEIGHT; y++) {
        for (int x = 0; x < MAZE_WIDTH; x++) {
            switch (maze[y][x]) {
            case 0:
                printf("  ");
                break;
            case 1:
                printf("██");
                break;
            case 2:
                printf("**");
                break;
            }
        }
        printf("\n");
    }
}

int main() {
    // Find a path from the start position to the end position:
    int startX = 1;
    int startY = 1;
    int endX = 8;
    int endY = 8;

    if (findPath(startX, startY, endX, endY)) {
        printf("Path found!\n");
        printMaze();
    } else {
        printf("No path found.\n");
    }
}