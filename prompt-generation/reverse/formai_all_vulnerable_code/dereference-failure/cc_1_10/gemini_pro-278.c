//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: complete
#include <stdio.h>
#include <stdlib.h>

/* Constants */
#define SIZE 10
#define START 0
#define END 99

/* Data structures */
typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point *points;
    int length;
} Path;

/* Function prototypes */
Path * find_path(int maze[][SIZE], Point start, Point end);
void print_path(Path *path);
void free_path(Path *path);

/* Main function */
int main() {
    /* Create the maze */
    int maze[SIZE][SIZE] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
        {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

    /* Find the path */
    Point start = {1, 1};
    Point end = {8, 8};
    Path *path = find_path(maze, start, end);

    /* Print the path */
    if (path != NULL) {
        print_path(path);
    } else {
        printf("No path found.\n");
    }

    /* Free the path */
    free_path(path);

    return 0;
}

/* Find the path */
Path * find_path(int maze[][SIZE], Point start, Point end) {
    /* Create the queue */
    Path *queue = malloc(sizeof(Path));
    queue->points = malloc(sizeof(Point) * SIZE * SIZE);
    queue->length = 0;

    /* Add the start point to the queue */
    queue->points[queue->length++] = start;

    /* While the queue is not empty */
    while (queue->length > 0) {
        /* Get the next point from the queue */
        Point point = queue->points[queue->length--];

        /* If the point is the end point */
        if (point.x == end.x && point.y == end.y) {
            /* Return the path */
            return queue;
        }

        /* Add the adjacent points to the queue */
        if (point.x > 0 && maze[point.x - 1][point.y] == 0) {
            Point adjacent_point = {point.x - 1, point.y};
            queue->points[queue->length++] = adjacent_point;
        }
        if (point.y > 0 && maze[point.x][point.y - 1] == 0) {
            Point adjacent_point = {point.x, point.y - 1};
            queue->points[queue->length++] = adjacent_point;
        }
        if (point.x < SIZE - 1 && maze[point.x + 1][point.y] == 0) {
            Point adjacent_point = {point.x + 1, point.y};
            queue->points[queue->length++] = adjacent_point;
        }
        if (point.y < SIZE - 1 && maze[point.x][point.y + 1] == 0) {
            Point adjacent_point = {point.x, point.y + 1};
            queue->points[queue->length++] = adjacent_point;
        }
    }

    /* No path found */
    return NULL;
}

/* Print the path */
void print_path(Path *path) {
    for (int i = 0; i < path->length; i++) {
        printf("(%d, %d)\n", path->points[i].x, path->points[i].y);
    }
}

/* Free the path */
void free_path(Path *path) {
    free(path->points);
    free(path);
}