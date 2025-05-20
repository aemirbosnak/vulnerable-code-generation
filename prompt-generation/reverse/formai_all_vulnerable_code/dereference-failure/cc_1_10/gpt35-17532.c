//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define ROWS 7
#define COLS 8

// Maze matrix
char maze[ROWS][COLS] = {
    {'S', 'X', 'O', 'O', 'O', 'O', 'O', 'O'},
    {'O', 'X', 'O', 'O', 'O', 'X', 'O', 'O'},
    {'O', 'X', 'O', 'O', 'O', 'X', 'O', 'O'},
    {'O', 'X', 'O', 'X', 'O', 'X', 'O', 'O'},
    {'O', 'O', 'O', 'X', 'O', 'X', 'O', 'O'},
    {'O', 'X', 'X', 'X', 'O', 'X', 'O', 'E'},
    {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'}
};

// Maze coordinate struct
typedef struct Coord {
    int x;
    int y;
} Coord;

// Stack struct for backtracking
typedef struct Stack {
    int top;
    Coord items[ROWS * COLS];
} Stack;

Stack* createStack() {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->top = -1;
    return stack;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

Coord peek(Stack* stack) {
    return stack->items[stack->top];
}

Coord pop(Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->items[stack->top--];
    }
}

void push(Stack* stack, Coord item) {
    stack->items[++stack->top] = item;
}

void printMaze() {
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

int isSafe(int x, int y) {
    return (x >= 0 && x < ROWS && y >= 0 && y < COLS && maze[x][y] != 'X');
}

void markVisited(int x, int y) {
    maze[x][y] = '.';
}

void* findRoute(void* arg) {
    Coord start = *(Coord*) arg;

    Stack* stack = createStack();
    push(stack, start);

    while (!isEmpty(stack)) {
        Coord current = peek(stack);
        int x = current.x;
        int y = current.y;

        // Check if we have reached the end point
        if (maze[x][y] == 'E') {
            printf("Route Found\n");

            while (!isEmpty(stack)) {
                Coord point = pop(stack);
                printf("(%d, %d)\n", point.x, point.y);
            }

            return 0;
        }

        // Mark as visited
        markVisited(x, y);
        printMaze();

        // Add adjacent points to stack
        // Top
        if (isSafe(x - 1, y)) {
            Coord top = {x - 1, y};
            push(stack, top);
        }
        // Right
        if (isSafe(x, y + 1)) {
            Coord right = {x, y + 1};
            push(stack, right);
        }
        // Bottom
        if (isSafe(x + 1, y)) {
            Coord bottom = {x + 1, y};
            push(stack, bottom);
        }
        // Left
        if (isSafe(x, y - 1)) {
            Coord left = {x, y - 1};
            push(stack, left);
        }
    }

    printf("Route Not Found\n");
}

int main() {
    Coord start = {0, 0};
    pthread_t thread;

    // Create multi-threaded maze route finding program
    if (pthread_create(&thread, NULL, findRoute, (void*) &start)) {
        printf("Error creating thread\n");
        return 1;
    }

    pthread_join(thread, NULL);

    return 0;
}