//GEMINI-pro DATASET v1.0 Category: Pathfinding algorithms ; Style: brave
#include <stdio.h>
#include <stdlib.h>

// Define the grid size
#define GRID_SIZE 10

// Define the start and end positions
#define START_X 0
#define START_Y 0
#define END_X 9
#define END_Y 9

// Define the grid
int grid[GRID_SIZE][GRID_SIZE] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

// Define the directions
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

// Define the queue
struct Node {
    int x;
    int y;
    int distance;
};

struct Queue {
    struct Node *items[GRID_SIZE * GRID_SIZE];
    int front;
    int rear;
};

// Create a new queue
struct Queue *createQueue() {
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Check if the queue is empty
int isEmpty(struct Queue *queue) {
    return queue->front == -1;
}

// Enqueue an item
void enqueue(struct Queue *queue, int x, int y, int distance) {
    if (queue->rear == GRID_SIZE * GRID_SIZE - 1) {
        printf("Queue is full!\n");
        return;
    }

    queue->rear++;
    queue->items[queue->rear] = (struct Node *)malloc(sizeof(struct Node));
    queue->items[queue->rear]->x = x;
    queue->items[queue->rear]->y = y;
    queue->items[queue->rear]->distance = distance;
}

// Dequeue an item
struct Node *dequeue(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return NULL;
    }

    queue->front++;
    return queue->items[queue->front];
}

// Find the path from the start to the end
int findPath(int grid[GRID_SIZE][GRID_SIZE], int start_x, int start_y, int end_x, int end_y) {
    // Create a queue
    struct Queue *queue = createQueue();

    // Enqueue the start position
    enqueue(queue, start_x, start_y, 0);

    // While the queue is not empty
    while (!isEmpty(queue)) {
        // Dequeue the next item
        struct Node *node = dequeue(queue);

        // Check if the current position is the end position
        if (node->x == end_x && node->y == end_y) {
            // Return the distance
            return node->distance;
        }

        // Visit the current position
        grid[node->x][node->y] = 1;

        // Enqueue the neighbors of the current position
        for (int i = 0; i < 4; i++) {
            int x = node->x + dx[i];
            int y = node->y + dy[i];

            // Check if the neighbor is valid
            if (x >= 0 && x < GRID_SIZE && y >= 0 && y < GRID_SIZE && grid[x][y] == 0) {
                // Enqueue the neighbor
                enqueue(queue, x, y, node->distance + 1);
            }
        }
    }

    // Return -1 if no path is found
    return -1;
}

// Print the grid
void printGrid(int grid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    // Find the path from the start to the end
    int distance = findPath(grid, START_X, START_Y, END_X, END_Y);

    // Print the distance
    if (distance == -1) {
        printf("No path found!\n");
    } else {
        printf("Distance: %d\n", distance);
    }

    // Print the grid
    printGrid(grid);

    return 0;
}