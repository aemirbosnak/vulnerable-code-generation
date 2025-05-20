//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAZE_WIDTH 10
#define MAZE_HEIGHT 10

// The maze is represented as a 2D array of characters.
// Each character represents a different type of cell:
//   '.' - open cell
//   '#' - wall
//   'S' - start cell
//   'E' - end cell
char maze[MAZE_HEIGHT][MAZE_WIDTH] = {
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '#', '#', '#', '#', '#', '#', '#', '#', '.'},
    {'.', '#', 'S', '.', '.', '.', '.', '.', '#', '.'},
    {'.', '#', '.', '#', '#', '#', '#', '.', '#', '.'},
    {'.', '#', '.', '.', '.', '.', '.', '.', '#', '.'},
    {'.', '#', '#', '#', '#', '#', '#', '#', '#', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '#', '#', '#', '#', '#', '#', '#', '#', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.', 'E', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
};

// The following data structures are used to implement a stack.
struct StackNode {
    int x;
    int y;
    struct StackNode *next;
};

struct Stack {
    struct StackNode *top;
};

// Create a new stack.
struct Stack *createStack() {
    struct Stack *stack = malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

// Push a new element onto the stack.
void push(struct Stack *stack, int x, int y) {
    struct StackNode *new_node = malloc(sizeof(struct StackNode));
    new_node->x = x;
    new_node->y = y;
    new_node->next = stack->top;
    stack->top = new_node;
}

// Pop the top element from the stack.
void pop(struct Stack *stack) {
    assert(stack->top != NULL);

    struct StackNode *old_top = stack->top;
    stack->top = stack->top->next;
    free(old_top);
}

// Return the top element of the stack without removing it.
int peek(struct Stack *stack) {
    assert(stack->top != NULL);

    return stack->top->x;
}

// Find the shortest path from the start cell to the end cell in the maze.
int findShortestPath(char maze[][MAZE_WIDTH], int start_x, int start_y, int end_x, int end_y) {
    // Create a stack to store the cells that have been visited.
    struct Stack *stack = createStack();

    // Push the start cell onto the stack.
    push(stack, start_x, start_y);

    // While the stack is not empty, continue searching for the end cell.
    while (stack->top != NULL) {
        // Pop the top cell from the stack.
        int x = peek(stack);
        int y = stack->top->y;
        pop(stack);

        // If the current cell is the end cell, return the number of steps taken to reach it.
        if (x == end_x && y == end_y) {
            return 1;
        }

        // If the current cell is not the end cell, push its neighbors onto the stack.
        if (maze[x - 1][y] == '.' || maze[x - 1][y] == 'E') {
            push(stack, x - 1, y);
        }
        if (maze[x + 1][y] == '.' || maze[x + 1][y] == 'E') {
            push(stack, x + 1, y);
        }
        if (maze[x][y - 1] == '.' || maze[x][y - 1] == 'E') {
            push(stack, x, y - 1);
        }
        if (maze[x][y + 1] == '.' || maze[x][y + 1] == 'E') {
            push(stack, x, y + 1);
        }
    }

    // If the stack is empty, then the end cell was not found.
    return -1;
}

// Print the maze to the console.
void printMaze(char maze[][MAZE_WIDTH]) {
    for (int i = 0; i < MAZE_HEIGHT; i++) {
        for (int j = 0; j < MAZE_WIDTH; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Find the start and end cells in the maze.
    int start_x, start_y, end_x, end_y;
    for (int i = 0; i < MAZE_HEIGHT; i++) {
        for (int j = 0; j < MAZE_WIDTH; j++) {
            if (maze[i][j] == 'S') {
                start_x = i;
                start_y = j;
            }
            if (maze[i][j] == 'E') {
                end_x = i;
                end_y = j;
            }
        }
    }

    // Find the shortest path from the start cell to the end cell.
    int shortest_path = findShortestPath(maze, start_x, start_y, end_x, end_y);

    // Print the maze to the console.
    printMaze(maze);

    // If the end cell was found, print the shortest path.
    if (shortest_path != -1) {
        printf("Shortest path: %d steps\n", shortest_path);
    } else {
        printf("No path found.\n");
    }

    return 0;
}