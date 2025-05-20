//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point *points;
    int size;
} Maze;

Maze *create_maze(int size) {
    Maze *maze = malloc(sizeof(Maze));
    maze->size = size;
    maze->points = malloc(sizeof(Point) * size * size);
    return maze;
}

void destroy_maze(Maze *maze) {
    free(maze->points);
    free(maze);
}

void print_maze(Maze *maze) {
    for (int i = 0; i < maze->size; i++) {
        for (int j = 0; j < maze->size; j++) {
            Point point = maze->points[i * maze->size + j];
            if (point.x == -1 && point.y == -1) {
                printf("X");
            } else {
                printf("O");
            }
        }
        printf("\n");
    }
}

int find_path(Maze *maze, Point start, Point end) {
    if (start.x == end.x && start.y == end.y) {
        return 1;
    }

    maze->points[start.x * maze->size + start.y].x = -1;
    maze->points[start.x * maze->size + start.y].y = -1;

    if (start.x > 0 && maze->points[(start.x - 1) * maze->size + start.y].x != -1) {
        if (find_path(maze, (Point){start.x - 1, start.y}, end)) {
            return 1;
        }
    }

    if (start.y > 0 && maze->points[start.x * maze->size + start.y - 1].x != -1) {
        if (find_path(maze, (Point){start.x, start.y - 1}, end)) {
            return 1;
        }
    }

    if (start.x < maze->size - 1 && maze->points[(start.x + 1) * maze->size + start.y].x != -1) {
        if (find_path(maze, (Point){start.x + 1, start.y}, end)) {
            return 1;
        }
    }

    if (start.y < maze->size - 1 && maze->points[start.x * maze->size + start.y + 1].x != -1) {
        if (find_path(maze, (Point){start.x, start.y + 1}, end)) {
            return 1;
        }
    }

    return 0;
}

int main() {
    Maze *maze = create_maze(10);

    // Set the starting and ending points.
    Point start = {0, 0};
    Point end = {9, 9};

    // Find the path from the starting point to the ending point.
    int found = find_path(maze, start, end);

    // Print the maze.
    print_maze(maze);

    // Destroy the maze.
    destroy_maze(maze);

    return 0;
}