//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point start;
    Point end;
    char maze[SIZE][SIZE];
} Maze;

bool is_valid_move(Maze *maze, Point *point) {
    return point->x >= 0 && point->x < SIZE && point->y >= 0 && point->y < SIZE && maze->maze[point->x][point->y] != '#';
}

bool find_path(Maze *maze, Point *current, Point *end, bool **visited) {
    if (current->x == end->x && current->y == end->y) {
        return true;
    }

    if (!is_valid_move(maze, current)) {
        return false;
    }

    if (visited[current->x][current->y]) {
        return false;
    }

    visited[current->x][current->y] = true;

    if (find_path(maze, &(Point){current->x + 1, current->y}, end, visited)) {
        return true;
    }

    if (find_path(maze, &(Point){current->x - 1, current->y}, end, visited)) {
        return true;
    }

    if (find_path(maze, &(Point){current->x, current->y + 1}, end, visited)) {
        return true;
    }

    if (find_path(maze, &(Point){current->x, current->y - 1}, end, visited)) {
        return true;
    }

    visited[current->x][current->y] = false;

    return false;
}

void print_maze(Maze *maze) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c", maze->maze[i][j]);
        }

        printf("\n");
    }
}

int main() {
    Maze maze = {
        .start = {0, 0},
        .end = {SIZE - 1, SIZE - 1},
        .maze = {
            {'#', '#', '#', '#', '#'},
            {'#', '.', '.', '.', '#'},
            {'.', '.', '#', '.', '.'},
            {'.', '#', '.', '#', '.'},
            {'#', '#', '#', '#', '#'}
        }
    };

    bool **visited = malloc(sizeof(bool *) * SIZE);

    for (int i = 0; i < SIZE; i++) {
        visited[i] = malloc(sizeof(bool) * SIZE);

        for (int j = 0; j < SIZE; j++) {
            visited[i][j] = false;
        }
    }

    if (find_path(&maze, &maze.start, &maze.end, visited)) {
        printf("Path found:\n");

        print_maze(&maze);
    } else {
        printf("No path found.\n");
    }

    for (int i = 0; i < SIZE; i++) {
        free(visited[i]);
    }

    free(visited);

    return 0;
}