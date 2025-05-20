//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define ROW 10
#define COL 10

// Node structure
struct Node {
    int row, col, distance;
};

// Stack structure for DFS algorithm
struct Stack {
    int top, capacity;
    struct Node *array;
};

// Function to create a node
struct Node *createNode(int row, int col, int distance) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->row = row;
    newNode->col = col;
    newNode->distance = distance;
    return newNode;
}

// Function to create a stack
struct Stack *createStack(int capacity) {
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (struct Node *)malloc(capacity * sizeof(struct Node));
    return stack;
}

// Function to check if a node is valid
int isValid(int row, int col) {
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL);
}

// Function to check if a node is not blocked
int isUnblocked(int maze[][COL], int row, int col) {
    return (maze[row][col] == 1);
}

// Function to check if a node is the destination
int isDestination(int row, int col, struct Node *dest) {
    return (row == dest->row) && (col == dest->col);
}

// Function to calculate the Manhattan distance between two nodes
int calculateDistance(int row, int col, struct Node *dest) {
    return abs(row - dest->row) + abs(col - dest->col);
}

// Function to push a node into the stack
void push(struct Stack *stack, struct Node *node) {
    stack->array[++stack->top] = *node;
}

// Function to pop a node from the stack
struct Node *pop(struct Stack *stack) {
    return &(stack->array[stack->top--]);
}

// Function to perform the Depth-First Search algorithm
int DFS(int maze[][COL], struct Node *src, struct Node *dest) {
    if (!isValid(src->row, src->col) || !isValid(dest->row, dest->col)) {
        printf("Invalid source or destination\n");
        return -1;
    }
    if (!isUnblocked(maze, src->row, src->col) || !isUnblocked(maze, dest->row, dest->col)) {
        printf("Source or destination is blocked\n");
        return -1;
    }
    if (isDestination(src->row, src->col, dest)) {
        printf("Source is same as destination\n");
        return 0;
    }
    struct Stack *stack = createStack(ROW * COL);
    int visited[ROW][COL], i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            visited[i][j] = 0;
        }
    }
    visited[src->row][src->col] = 1;
    push(stack, src);
    while (stack->top != -1) {
        struct Node *currentNode = pop(stack);
        if (isDestination(currentNode->row, currentNode->col, dest)) {
            return currentNode->distance;
        }
        int row = currentNode->row;
        int col = currentNode->col;
        if (isValid(row + 1, col) && isUnblocked(maze, row + 1, col) && !visited[row + 1][col]) {
            visited[row + 1][col] = 1;
            struct Node *newNode = createNode(row + 1, col, currentNode->distance + 1);
            push(stack, newNode);
        }
        if (isValid(row, col + 1) && isUnblocked(maze, row, col + 1) && !visited[row][col + 1]) {
            visited[row][col + 1] = 1;
            struct Node *newNode = createNode(row, col + 1, currentNode->distance + 1);
            push(stack, newNode);
        }
        if (isValid(row - 1, col) && isUnblocked(maze, row - 1, col) && !visited[row - 1][col]) {
            visited[row - 1][col] = 1;
            struct Node *newNode = createNode(row - 1, col, currentNode->distance + 1);
            push(stack, newNode);
        }
        if (isValid(row, col - 1) && isUnblocked(maze, row, col - 1) && !visited[row][col - 1]) {
            visited[row][col - 1] = 1;
            struct Node *newNode = createNode(row, col - 1, currentNode->distance + 1);
            push(stack, newNode);
        }
    }
    printf("No path found\n");
    return -1;
}

int main() {
    int maze[ROW][COL] = {
        {1, 0, 1, 1, 1, 0, 1, 1, 1, 1},
        {1, 1, 1, 0, 1, 1, 1, 0, 1, 1},
        {0, 1, 1, 0, 1, 0, 1, 0, 0, 1},
        {1, 1, 0, 0, 0, 1, 1, 0, 1, 1},
        {0, 0, 1, 1, 1, 1, 1, 0, 0, 1},
        {1, 0, 1, 0, 0, 0, 1, 1, 0, 1},
        {1, 0, 0, 1, 1, 1, 0, 0, 1, 1},
        {1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 0, 0, 0, 1, 0, 0, 1}
    };
    struct Node *src = createNode(0, 0, 0);
    struct Node *dest = createNode(7, 5, 0);
    int distance = DFS(maze, src, dest);
    printf("Shortest Path Distance: %d\n", distance);
    return 0;
}