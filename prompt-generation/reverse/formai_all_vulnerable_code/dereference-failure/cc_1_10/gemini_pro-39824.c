//GEMINI-pro DATASET v1.0 Category: Pathfinding algorithms ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Grid Dimensions
#define WIDTH  10
#define HEIGHT 10

// Directions
enum {
    NORTH,
    EAST,
    SOUTH,
    WEST
};

// Cell
typedef struct {
    uint8_t visited;
    uint8_t direction;
} cell;

// Grid
cell grid[WIDTH][HEIGHT];

// Queue
struct queue {
    int size;
    int head;
    int tail;
    int *data;
};

// Create Queue
struct queue *newQueue(int size) {
    struct queue *newqueue = malloc(sizeof(struct queue));
    newqueue->size = size;
    newqueue->head = 0;
    newqueue->tail = 0;
    newqueue->data = malloc(sizeof(int) * size);
    return newqueue;
}

// Destroy Queue
void destroyQueue(struct queue *queue) {
    free(queue->data);
    free(queue);
}

// Is Queue Empty
int isQueueEmpty(struct queue *queue) {
    return queue->head == queue->tail;
}

// Enqueue
void enqueue(struct queue *queue, int value) {
    queue->data[(queue->tail++) % queue->size] = value;
}

// Dequeue
int dequeue(struct queue *queue) {
    return queue->data[(queue->head++) % queue->size];
}

// Find Path
int findPath(int start_x, int start_y, int end_x, int end_y) {
    // Queue
    struct queue *queue = newQueue(WIDTH * HEIGHT);

    // Set Start Cell
    grid[start_x][start_y].visited = 1;
    grid[start_x][start_y].direction = -1;
    enqueue(queue, start_x * WIDTH + start_y);

    // Path Found
    if (start_x == end_x && start_y == end_y) {
        return 1;
    }

    // While Queue Not Empty
    while (!isQueueEmpty(queue)) {
        int cell = dequeue(queue);
        int x = cell / WIDTH;
        int y = cell % WIDTH;

        // Check North Cell
        if (x > 0 && grid[x - 1][y].visited == 0) {
            grid[x - 1][y].visited = 1;
            grid[x - 1][y].direction = NORTH;
            enqueue(queue, (x - 1) * WIDTH + y);

            // Path Found
            if (x - 1 == end_x && y == end_y) {
                destroyQueue(queue);
                return 1;
            }
        }

        // Check East Cell
        if (y < WIDTH - 1 && grid[x][y + 1].visited == 0) {
            grid[x][y + 1].visited = 1;
            grid[x][y + 1].direction = EAST;
            enqueue(queue, x * WIDTH + (y + 1));

            // Path Found
            if (x == end_x && y + 1 == end_y) {
                destroyQueue(queue);
                return 1;
            }
        }

        // Check South Cell
        if (x < HEIGHT - 1 && grid[x + 1][y].visited == 0) {
            grid[x + 1][y].visited = 1;
            grid[x + 1][y].direction = SOUTH;
            enqueue(queue, (x + 1) * WIDTH + y);

            // Path Found
            if (x + 1 == end_x && y == end_y) {
                destroyQueue(queue);
                return 1;
            }
        }

        // Check West Cell
        if (y > 0 && grid[x][y - 1].visited == 0) {
            grid[x][y - 1].visited = 1;
            grid[x][y - 1].direction = WEST;
            enqueue(queue, x * WIDTH + (y - 1));

            // Path Found
            if (x == end_x && y - 1 == end_y) {
                destroyQueue(queue);
                return 1;
            }
        }
    }

    // Path Not Found
    destroyQueue(queue);
    return 0;
}

// Print Path
void printPath(int start_x, int start_y, int end_x, int end_y) {
    int x = end_x;
    int y = end_y;

    // Print Start and End Positions
    printf("Start: (%d, %d)\n", start_x, start_y);
    printf("End: (%d, %d)\n", end_x, end_y);

    // Path Not Found
    if (!findPath(start_x, start_y, end_x, end_y)) {
        printf("Path Not Found!\n");
        return;
    }

    // Print Path
    while (x != start_x || y != start_y) {
        switch (grid[x][y].direction) {
            case NORTH:
                printf("N");
                x++;
                break;
            case EAST:
                printf("E");
                y--;
                break;
            case SOUTH:
                printf("S");
                x--;
                break;
            case WEST:
                printf("W");
                y++;
                break;
        }
    }

    printf("\n");
}

int main() {
    // Start and End Positions
    int start_x = 0;
    int start_y = 0;
    int end_x = 9;
    int end_y = 9;

    // Print Path
    printPath(start_x, start_y, end_x, end_y);

    return 0;
}