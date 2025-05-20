//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define MAZE_WIDTH 10
#define MAZE_HEIGHT 10

typedef struct Node {
    int x;
    int y;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
    int size;
} Stack;

// Method declarations
void push(Stack* stack, int x, int y);
void pop(Stack* stack);
Node* peek(Stack* stack);
int isEmpty(Stack* stack);
void printPath(Stack* stack);
int inBounds(int x, int y);
int isWall(int maze[][MAZE_WIDTH], int x, int y);
void solveMaze(int maze[][MAZE_WIDTH], int startX, int startY, int endX, int endY);

int main() {
    int maze[MAZE_HEIGHT][MAZE_WIDTH] = { // Example maze
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1, 1, 0, 0, 0, 1},
        {1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 1, 0, 1, 0, 1},
        {1, 0, 0, 0, 1, 1, 0, 0, 0, 1},
        {1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

    int startX = 1;
    int startY = 1;
    int endX = 8;
    int endY = 8;

    solveMaze(maze, startX, startY, endX, endY);
    return 0;
}

// Adds a new node to the top of the stack
void push(Stack* stack, int x, int y) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->next = stack->top;
    stack->top = node;
    stack->size++;
}

// Removes the top node from the stack
void pop(Stack* stack) {
    if (!isEmpty(stack)) {
        Node* node = stack->top;
        stack->top = node->next;
        free(node);
        stack->size--;
    }
}

// Returns the top node without removing it
Node* peek(Stack* stack) {
    return stack->top;
}

// Returns 1 if the stack is empty, 0 otherwise
int isEmpty(Stack* stack) {
    return stack->size == 0;
}

// Prints the path stored in the stack
void printPath(Stack* stack) {
    Node* node = stack->top;
    printf("Path: ");
    while (node != NULL) {
        printf("(%d,%d) ", node->x, node->y);
        node = node->next;
    }
    printf("\n");
}

// Returns 1 if the given coordinates are in bounds, 0 otherwise
int inBounds(int x, int y) {
    return (x >= 0 && x < MAZE_WIDTH && y >= 0 && y < MAZE_HEIGHT);
}

// Returns 1 if the given coordinates are a wall, 0 otherwise
int isWall(int maze[][MAZE_WIDTH], int x, int y) {
    return maze[y][x] == 1;
}

// Solves the maze using depth-first search and a stack to keep track of the path
void solveMaze(int maze[][MAZE_WIDTH], int startX, int startY, int endX, int endY) {
    int visited[MAZE_HEIGHT][MAZE_WIDTH] = {0}; // Initialize all cells as unvisited
    Stack stack = {NULL, 0}; // Initialize the stack
    push(&stack, startX, startY); // push the starting node onto the stack
    visited[startY][startX] = 1; // Mark the starting node as visited

    while (!isEmpty(&stack)) {
        Node* currNode = peek(&stack); // Get the node at the top of the stack
        int x = currNode->x;
        int y = currNode->y;

        if (x == endX && y == endY) { // We have reached the end, print the path and return
            printPath(&stack);
            return;
        }

        // Try moving to each adjacent node in turn (up, down, left, right)
        if (inBounds(x, y-1) && !visited[y-1][x] && !isWall(maze, x, y-1)) { // up
            push(&stack, x, y-1);
            visited[y-1][x] = 1;
        } else if (inBounds(x, y+1) && !visited[y+1][x] && !isWall(maze, x, y+1)) { // down
            push(&stack, x, y+1);
            visited[y+1][x] = 1;
        } else if (inBounds(x-1, y) && !visited[y][x-1] && !isWall(maze, x-1, y)) { // left
            push(&stack, x-1, y);
            visited[y][x-1] = 1;
        } else if (inBounds(x+1, y) && !visited[y][x+1] && !isWall(maze, x+1, y)) { // right
            push(&stack, x+1, y);
            visited[y][x+1] = 1;
        } else { // No unvisited neighbors, backtrack
            pop(&stack);
        }
    }

    printf("No path found!\n");
}