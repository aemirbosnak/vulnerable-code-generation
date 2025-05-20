//GEMINI-pro DATASET v1.0 Category: Pathfinding algorithms ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 5
#define COLS 5

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point start;
    Point end;
    int **grid;
} Maze;

typedef struct {
    Point *points;
    int size;
} Path;

bool is_valid_move(Maze *maze, Point *point) {
    return point->x >= 0 && point->x < ROWS && point->y >= 0 && point->y < COLS && maze->grid[point->x][point->y] != 1;
}

void add_point_to_path(Path *path, Point *point) {
    path->points = realloc(path->points, (path->size + 1) * sizeof(Point));
    path->points[path->size] = *point;
    path->size++;
}

void remove_point_from_path(Path *path, Point *point) {
    int i;
    for (i = 0; i < path->size; i++) {
        if (path->points[i].x == point->x && path->points[i].y == point->y) {
            break;
        }
    }
    if (i < path->size) {
        for (; i < path->size - 1; i++) {
            path->points[i] = path->points[i + 1];
        }
        path->size--;
    }
}

bool is_path_valid(Maze *maze, Path *path) {
    int i;
    for (i = 0; i < path->size; i++) {
        if (!is_valid_move(maze, &path->points[i])) {
            return false;
        }
    }
    return true;
}

void print_path(Path *path) {
    int i;
    for (i = 0; i < path->size; i++) {
        printf("(%d, %d) ", path->points[i].x, path->points[i].y);
    }
    printf("\n");
}

void free_path(Path *path) {
    free(path->points);
    free(path);
}

bool find_path(Maze *maze, Path *path) {
    if (path->size > 0 && path->points[path->size - 1].x == maze->end.x && path->points[path->size - 1].y == maze->end.y) {
        return true;
    }

    Point *current_point = &path->points[path->size - 1];
    Point *next_point;

    // Try moving up
    next_point = malloc(sizeof(Point));
    next_point->x = current_point->x - 1;
    next_point->y = current_point->y;
    if (is_valid_move(maze, next_point)) {
        add_point_to_path(path, next_point);
        if (find_path(maze, path)) {
            return true;
        }
        remove_point_from_path(path, next_point);
    }
    free(next_point);

    // Try moving down
    next_point = malloc(sizeof(Point));
    next_point->x = current_point->x + 1;
    next_point->y = current_point->y;
    if (is_valid_move(maze, next_point)) {
        add_point_to_path(path, next_point);
        if (find_path(maze, path)) {
            return true;
        }
        remove_point_from_path(path, next_point);
    }
    free(next_point);

    // Try moving left
    next_point = malloc(sizeof(Point));
    next_point->x = current_point->x;
    next_point->y = current_point->y - 1;
    if (is_valid_move(maze, next_point)) {
        add_point_to_path(path, next_point);
        if (find_path(maze, path)) {
            return true;
        }
        remove_point_from_path(path, next_point);
    }
    free(next_point);

    // Try moving right
    next_point = malloc(sizeof(Point));
    next_point->x = current_point->x;
    next_point->y = current_point->y + 1;
    if (is_valid_move(maze, next_point)) {
        add_point_to_path(path, next_point);
        if (find_path(maze, path)) {
            return true;
        }
        remove_point_from_path(path, next_point);
    }
    free(next_point);

    return false;
}

int main() {
    Maze maze;
    maze.start.x = 0;
    maze.start.y = 0;
    maze.end.x = 4;
    maze.end.y = 4;
    maze.grid = malloc(ROWS * sizeof(int *));
    for (int i = 0; i < ROWS; i++) {
        maze.grid[i] = malloc(COLS * sizeof(int));
    }
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            maze.grid[i][j] = 0;
        }
    }
    maze.grid[1][1] = 1;
    maze.grid[3][3] = 1;

    Path path;
    path.points = malloc(sizeof(Point));
    path.points[0] = maze.start;
    path.size = 1;

    if (find_path(&maze, &path)) {
        printf("Found a path: ");
        print_path(&path);
    } else {
        printf("No path found.\n");
    }

    free_path(&path);
    for (int i = 0; i < ROWS; i++) {
        free(maze.grid[i]);
    }
    free(maze.grid);

    return 0;
}