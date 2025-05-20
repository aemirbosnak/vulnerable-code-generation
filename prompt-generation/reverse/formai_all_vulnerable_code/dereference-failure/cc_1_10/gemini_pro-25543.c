//GEMINI-pro DATASET v1.0 Category: Procedurally Generated Maze ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point *points;
    int size;
} Maze;

Maze *create_maze(int width, int height) {
    Maze *maze = malloc(sizeof(Maze));
    maze->size = width * height;
    maze->points = malloc(sizeof(Point) * maze->size);

    for (int i = 0; i < maze->size; i++) {
        maze->points[i].x = i % width;
        maze->points[i].y = i / width;
    }

    return maze;
}

void destroy_maze(Maze *maze) {
    free(maze->points);
    free(maze);
}

void print_maze(Maze *maze) {
    for (int i = 0; i < maze->size; i++) {
        printf("%d %d\n", maze->points[i].x, maze->points[i].y);
    }
}

int main() {
    srand(time(NULL));

    int width = 10;
    int height = 10;

    Maze *maze = create_maze(width, height);

    print_maze(maze);

    destroy_maze(maze);

    return 0;
}