//GEMINI-pro DATASET v1.0 Category: Pathfinding algorithms ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point *array;
    int size;
} Path;

typedef struct {
    Point *array;
    int size;
    int capacity;
} Queue;

void initQueue(Queue *queue, int capacity) {
    queue->array = malloc(sizeof(Point) * capacity);
    queue->size = 0;
    queue->capacity = capacity;
}

void enqueue(Queue *queue, Point point) {
    if (queue->size == queue->capacity) {
        queue->capacity *= 2;
        queue->array = realloc(queue->array, sizeof(Point) * queue->capacity);
    }
    queue->array[queue->size++] = point;
}

Point dequeue(Queue *queue) {
    if (queue->size == 0) {
        printf("Queue is empty\n");
        exit(1);
    }
    return queue->array[--queue->size];
}

bool isEmpty(Queue *queue) {
    return queue->size == 0;
}

void initPath(Path *path) {
    path->array = malloc(sizeof(Point) * MAX_SIZE);
    path->size = 0;
}

void addPoint(Path *path, Point point) {
    if (path->size == MAX_SIZE) {
        printf("Path is full\n");
        exit(1);
    }
    path->array[path->size++] = point;
}

int main() {
    // Initialize the grid
    int grid[10][10] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
        {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
        {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 0, 0, 1, 1, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

    // Initialize the start and end points
    Point start = {1, 1};
    Point end = {8, 8};

    // Initialize the queue and path
    Queue queue;
    initQueue(&queue, 100);
    Path path;
    initPath(&path);

    // Add the start point to the queue
    enqueue(&queue, start);

    // While the queue is not empty
    while (!isEmpty(&queue)) {
        // Get the current point from the queue
        Point current = dequeue(&queue);

        // Check if the current point is the end point
        if (current.x == end.x && current.y == end.y) {
            // Add the current point to the path
            addPoint(&path, current);

            // Print the path
            for (int i = 0; i < path.size; i++) {
                printf("(%d, %d)\n", path.array[i].x, path.array[i].y);
            }

            // Exit the loop
            break;
        }

        // Add the neighbors of the current point to the queue
        if (current.x > 0 && grid[current.x - 1][current.y] == 0) {
            enqueue(&queue, (Point){.x = current.x - 1, .y = current.y});
        }
        if (current.y > 0 && grid[current.x][current.y - 1] == 0) {
            enqueue(&queue, (Point){.x = current.x, .y = current.y - 1});
        }
        if (current.x < 9 && grid[current.x + 1][current.y] == 0) {
            enqueue(&queue, (Point){.x = current.x + 1, .y = current.y});
        }
        if (current.y < 9 && grid[current.x][current.y + 1] == 0) {
            enqueue(&queue, (Point){.x = current.x, .y = current.y + 1});
        }

        // Mark the current point as visited
        grid[current.x][current.y] = 1;

        // Add the current point to the path
        addPoint(&path, current);
    }

    return 0;
}