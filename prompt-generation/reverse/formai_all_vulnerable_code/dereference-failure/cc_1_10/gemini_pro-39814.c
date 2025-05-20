//GEMINI-pro DATASET v1.0 Category: Pathfinding algorithms ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point *points;
    int size;
} Path;

typedef struct {
    char **grid;
    Point start;
    Point end;
} Maze;

Maze *create_maze() {
    Maze *maze = malloc(sizeof(Maze));
    maze->grid = malloc(sizeof(char *) * ROWS);
    for (int i = 0; i < ROWS; i++) {
        maze->grid[i] = malloc(sizeof(char) * COLS);
    }
    return maze;
}

void free_maze(Maze *maze) {
    for (int i = 0; i < ROWS; i++) {
        free(maze->grid[i]);
    }
    free(maze->grid);
    free(maze);
}

void print_maze(Maze *maze) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", maze->grid[i][j]);
        }
        printf("\n");
    }
}

Path *create_path() {
    Path *path = malloc(sizeof(Path));
    path->points = malloc(sizeof(Point) * 100);
    path->size = 0;
    return path;
}

void free_path(Path *path) {
    free(path->points);
    free(path);
}

void add_point_to_path(Path *path, Point point) {
    path->points[path->size] = point;
    path->size++;
}

int is_valid_point(Maze *maze, Point point) {
    return point.x >= 0 && point.x < ROWS && point.y >= 0 && point.y < COLS && maze->grid[point.x][point.y] != 'X';
}

Path *find_path(Maze *maze) {
    Path *path = create_path();
    Point current = maze->start;
    while (current.x != maze->end.x || current.y != maze->end.y) {
        // Check if we can move up
        if (is_valid_point(maze, (Point){current.x - 1, current.y})) {
            current.x--;
            add_point_to_path(path, current);
            continue;
        }
        // Check if we can move down
        if (is_valid_point(maze, (Point){current.x + 1, current.y})) {
            current.x++;
            add_point_to_path(path, current);
            continue;
        }
        // Check if we can move left
        if (is_valid_point(maze, (Point){current.x, current.y - 1})) {
            current.y--;
            add_point_to_path(path, current);
            continue;
        }
        // Check if we can move right
        if (is_valid_point(maze, (Point){current.x, current.y + 1})) {
            current.y++;
            add_point_to_path(path, current);
            continue;
        }
        // If we can't move in any direction, we're stuck
        break;
    }
    if (current.x == maze->end.x && current.y == maze->end.y) {
        return path;
    } else {
        free_path(path);
        return NULL;
    }
}

int main() {
    Maze *maze = create_maze();
    maze->grid[0][0] = 'S';
    maze->grid[0][9] = 'E';
    for (int i = 1; i < ROWS - 1; i++) {
        for (int j = 1; j < COLS - 1; j++) {
            maze->grid[i][j] = rand() % 2 == 0 ? ' ' : 'X';
        }
    }
    maze->start.x = 0;
    maze->start.y = 0;
    maze->end.x = ROWS - 1;
    maze->end.y = COLS - 1;
    print_maze(maze);
    Path *path = find_path(maze);
    if (path) {
        printf("Found a path!\n");
        for (int i = 0; i < path->size; i++) {
            printf("(%d, %d)\n", path->points[i].x, path->points[i].y);
        }
        free_path(path);
    } else {
        printf("No path found.\n");
    }
    free_maze(maze);
    return 0;
}