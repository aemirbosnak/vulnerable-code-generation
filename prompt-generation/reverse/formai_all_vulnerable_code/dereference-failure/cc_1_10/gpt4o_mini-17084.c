//GPT-4o-mini DATASET v1.0 Category: Maze Route Finder ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define N 5 // Define the size of the maze (NxN)
#define PATH ' ' // Define a path in the maze
#define WALL '#' // Define a wall in the maze

typedef struct Point {
    int x, y;
} Point;

typedef struct Stack {
    Point* points;
    int top;
    int capacity;
} Stack;

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->points = (Point*)malloc(stack->capacity * sizeof(Point));
    return stack;
}

void push(Stack* stack, Point p) {
    if (stack->top < stack->capacity - 1) {
        stack->points[++stack->top] = p;
    }
}

Point pop(Stack* stack) {
    if (stack->top != -1) {
        return stack->points[stack->top--];
    }
    Point invalid = {-1, -1}; // Indicate stack is empty
    return invalid;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

int isValidMove(char maze[N][N], int visited[N][N], int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == PATH && !visited[x][y]);
}

void printMaze(char maze[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

void findRoute(char maze[N][N], int startX, int startY, int exitX, int exitY) {
    Stack* stack = createStack(N*N);
    int visited[N][N] = {0}; // Keep track of visited locations

    Point start = {startX, startY};
    push(stack, start);
    visited[startX][startY] = 1;

    int found = 0;

    // Define movements in four possible directions: down, up, right, left
    int directionX[] = {1, -1, 0, 0};
    int directionY[] = {0, 0, 1, -1};

    while (!isEmpty(stack)) {
        Point current = pop(stack);
        int x = current.x;
        int y = current.y;

        // If the exit is found
        if (x == exitX && y == exitY) {
            found = 1;
            break;
        }

        // Explore in all four directions
        for (int i = 0; i < 4; i++) {
            int newX = x + directionX[i];
            int newY = y + directionY[i];
            if (isValidMove(maze, visited, newX, newY)) {
                visited[newX][newY] = 1;
                Point nextMove = {newX, newY};
                push(stack, nextMove);
            }
        }
    }

    if (found) {
        printf("Route to exit found!\n");
    } else {
        printf("No route to exit!\n");
    }

    free(stack->points);
    free(stack);
}

int main() {
    char maze[N][N] = {
        {PATH, WALL, PATH, PATH, PATH},
        {PATH, WALL, WALL, WALL, PATH},
        {PATH, PATH, PATH, WALL, PATH},
        {WALL, WALL, PATH, PATH, PATH},
        {PATH, PATH, WALL, WALL, WALL}
    };

    printf("Maze Layout:\n");
    printMaze(maze);

    int startX = 0, startY = 0; // Entry Point
    int exitX = 4, exitY = 4; // Exit Point

    findRoute(maze, startX, startY, exitX, exitY);

    return 0;
}