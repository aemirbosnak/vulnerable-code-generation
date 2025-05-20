//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 5
#define COLS 5

// Struct for each grid cell
struct Cell {
    int row;
    int col;
    bool visited;
};

// Struct to represent queue
struct Queue {
    int size;
    int front;
    int rear;
    struct Cell *array;
};

// Create a queue
struct Queue *createQueue(int size) {
    struct Queue *queue = (struct Queue *) malloc(sizeof(struct Queue));
    queue->size = size;
    queue->front = -1;
    queue->rear = -1;
    queue->array = (struct Cell *) malloc(size * sizeof(struct Cell));
    return queue;
}

// Check if the queue is empty
bool isQueueEmpty(struct Queue *queue) {
    return queue->front == -1;
}

// Check if queue is full
bool isQueueFull(struct Queue *queue) {
    return queue->rear == queue->size - 1;
}

// Add item to queue
void enqueue(struct Queue *queue, struct Cell cell) {
    if (isQueueFull(queue)) {
        return;
    }
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->rear++;
    queue->array[queue->rear] = cell;
}

// Remove item from queue
struct Cell dequeue(struct Queue *queue) {
    if (isQueueEmpty(queue)) {
        struct Cell empty;
        empty.row = -1;
        empty.col = -1;
        return empty;
    }
    struct Cell temp = queue->array[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front++;
    }
    return temp;
}

// Check if the given cell is a valid cell
bool isValid(int row, int col) {
    return (row >= 0) && (row < ROWS) && (col >= 0) && (col < COLS);
}

// Check if the given cell is not blocked
bool isUnblocked(int grid[][COLS], int row, int col) {
    return grid[row][col] == 1;
}

// Check if the given cell has not visited before
bool isNotVisited(int row, int col, bool visited[][COLS]) {
    return !visited[row][col];
}

// Find the shortest path between two given points using Breadth First Search
int BFS(int grid[][COLS], int row1, int col1, int row2, int col2) {
    // Create a queue for BFS
    struct Queue *queue = createQueue(ROWS * COLS);
    // Mark the starting cell as visited
    bool visited[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            visited[i][j] = false;
        }
    }
    visited[row1][col1] = true;
    // Enqueue the starting cell
    struct Cell start;
    start.row = row1;
    start.col = col1;
    start.visited = true;
    enqueue(queue, start);
    // Keep searching until queue is empty
    while (!isQueueEmpty(queue)) {
        // Dequeue the front cell and process it
        struct Cell current = dequeue(queue);
        if (current.row == row2 && current.col == col2) {
            return -1;
        }
        // Visit adjacent cells
        int row = current.row;
        int col = current.col - 1;
        if (isValid(row, col) && isUnblocked(grid, row, col) && isNotVisited(row, col, visited)) {
            visited[row][col] = true;
            struct Cell adjacent;
            adjacent.row = row;
            adjacent.col = col;
            adjacent.visited = true;
            enqueue(queue, adjacent);
        }
        row = current.row - 1;
        col = current.col;
        if (isValid(row, col) && isUnblocked(grid, row, col) && isNotVisited(row, col, visited)) {
            visited[row][col] = true;
            struct Cell adjacent;
            adjacent.row = row;
            adjacent.col = col;
            adjacent.visited = true;
            enqueue(queue, adjacent);
        }
        row = current.row;
        col = current.col + 1;
        if (isValid(row, col) && isUnblocked(grid, row, col) && isNotVisited(row, col, visited)) {
            visited[row][col] = true;
            struct Cell adjacent;
            adjacent.row = row;
            adjacent.col = col;
            adjacent.visited = true;
            enqueue(queue, adjacent);
        }
        row = current.row + 1;
        col = current.col;
        if (isValid(row, col) && isUnblocked(grid, row, col) && isNotVisited(row, col, visited)) {
            visited[row][col] = true;
            struct Cell adjacent;
            adjacent.row = row;
            adjacent.col = col;
            adjacent.visited = true;
            enqueue(queue, adjacent);
        }
    }
    // No path found
    return -2;
}

// Driver program to test the algorithm
int main() {
    int grid[ROWS][COLS] =
    {
        {1, 0, 1, 1, 1},
        {1, 1, 1, 0, 1},
        {0, 0, 1, 0, 1},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 0, 1}
    };
    int shortestPath = BFS(grid, 0, 0, 0, 4);
    if (shortestPath == -1) {
        printf("Destination cannot be reached");
    } else if (shortestPath == -2) {
        printf("No path found");
    } else {
        printf("Shortest path is: %d", shortestPath);
    }
    return 0;
}