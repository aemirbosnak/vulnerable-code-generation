//GEMINI-pro DATASET v1.0 Category: Pathfinding algorithms ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

// Define the grid size
#define GRID_WIDTH 10
#define GRID_HEIGHT 10

// Define the start and end positions
#define START_X 0
#define START_Y 0
#define END_X 9
#define END_Y 9

// Define the obstacles
int obstacles[GRID_WIDTH][GRID_HEIGHT] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

// Define the directions
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

// Define the queue
struct Queue {
    int x, y;
    struct Queue *next;
};

// Create a new queue
struct Queue *createQueue() {
    struct Queue *queue = malloc(sizeof(struct Queue));
    queue->x = 0;
    queue->y = 0;
    queue->next = NULL;
    return queue;
}

// Enqueue an item
void enqueue(struct Queue **queue, int x, int y) {
    struct Queue *new = malloc(sizeof(struct Queue));
    new->x = x;
    new->y = y;
    new->next = NULL;

    if (*queue == NULL) {
        *queue = new;
    } else {
        struct Queue *last = *queue;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = new;
    }
}

// Dequeue an item
void dequeue(struct Queue **queue) {
    if (*queue != NULL) {
        struct Queue *next = (*queue)->next;
        free(*queue);
        *queue = next;
    }
}

// Is the queue empty?
bool isEmpty(struct Queue *queue) {
    return queue == NULL;
}

// Find the path from the start to the end
int findPath(int grid[GRID_WIDTH][GRID_HEIGHT], int start_x, int start_y, int end_x, int end_y) {
    // Create a queue
    struct Queue *queue = createQueue();

    // Enqueue the start position
    enqueue(&queue, start_x, start_y);

    // While the queue is not empty
    while (!isEmpty(queue)) {
        // Dequeue the next position
        int x = queue->x;
        int y = queue->y;
        dequeue(&queue);

        // Check if the position is the end position
        if (x == end_x && y == end_y) {
            return 1;
        }

        // Check if the position is a valid position
        if (x >= 0 && x < GRID_WIDTH && y >= 0 && y < GRID_HEIGHT && grid[x][y] != 1) {
            // Enqueue the adjacent positions
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                enqueue(&queue, nx, ny);
            }
        }
    }

    // No path found
    return 0;
}

int main() {
    // Find the path
    int pathFound = findPath(obstacles, START_X, START_Y, END_X, END_Y);

    // Print the result
    if (pathFound) {
        printf("Path found!\n");
    } else {
        printf("No path found.\n");
    }

    return 0;
}