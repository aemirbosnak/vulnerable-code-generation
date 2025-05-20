//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: funny
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point *points;
    int num_points;
} Path;

Path *path_new() {
    Path *path = malloc(sizeof(Path));
    path->points = NULL;
    path->num_points = 0;
    return path;
}

void path_free(Path *path) {
    free(path->points);
    free(path);
}

void path_add_point(Path *path, int x, int y) {
    path->points = realloc(path->points, sizeof(Point) * (path->num_points + 1));
    path->points[path->num_points].x = x;
    path->points[path->num_points].y = y;
    path->num_points++;
}

int **maze_new(int width, int height) {
    int **maze = malloc(sizeof(int *) * height);
    for (int i = 0; i < height; i++) {
        maze[i] = malloc(sizeof(int) * width);
    }
    return maze;
}

void maze_free(int **maze, int height) {
    for (int i = 0; i < height; i++) {
        free(maze[i]);
    }
    free(maze);
}

void maze_print(int **maze, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

int maze_solve(int **maze, int width, int height, Path *path) {
    if (maze[path->points[path->num_points - 1].y][path->points[path->num_points - 1].x] == 2) {
        return TRUE;
    }

    if (path->num_points > 0 && maze[path->points[path->num_points - 1].y][path->points[path->num_points - 1].x] == 0) {
        return FALSE;
    }

    // Try north
    if (path->num_points == 0 || path->points[path->num_points - 1].y > 0 && maze[path->points[path->num_points - 1].y - 1][path->points[path->num_points - 1].x] != 0) {
        path_add_point(path, path->points[path->num_points - 1].x, path->points[path->num_points - 1].y - 1);
        if (maze_solve(maze, width, height, path)) {
            return TRUE;
        }
        path->num_points--;
    }

    // Try east
    if (path->num_points == 0 || path->points[path->num_points - 1].x < width - 1 && maze[path->points[path->num_points - 1].y][path->points[path->num_points - 1].x + 1] != 0) {
        path_add_point(path, path->points[path->num_points - 1].x + 1, path->points[path->num_points - 1].y);
        if (maze_solve(maze, width, height, path)) {
            return TRUE;
        }
        path->num_points--;
    }

    // Try south
    if (path->num_points == 0 || path->points[path->num_points - 1].y < height - 1 && maze[path->points[path->num_points - 1].y + 1][path->points[path->num_points - 1].x] != 0) {
        path_add_point(path, path->points[path->num_points - 1].x, path->points[path->num_points - 1].y + 1);
        if (maze_solve(maze, width, height, path)) {
            return TRUE;
        }
        path->num_points--;
    }

    // Try west
    if (path->num_points == 0 || path->points[path->num_points - 1].x > 0 && maze[path->points[path->num_points - 1].y][path->points[path->num_points - 1].x - 1] != 0) {
        path_add_point(path, path->points[path->num_points - 1].x - 1, path->points[path->num_points - 1].y);
        if (maze_solve(maze, width, height, path)) {
            return TRUE;
        }
        path->num_points--;
    }

    return FALSE;
}

int main() {
    int width, height;
    printf("Enter the width and height of the maze: ");
    scanf("%d %d", &width, &height);

    int **maze = maze_new(width, height);
    printf("Enter the maze: ");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            scanf("%d", &maze[i][j]);
        }
    }

    Path *path = path_new();
    path_add_point(path, 0, 0);

    if (maze_solve(maze, width, height, path)) {
        printf("The maze has been solved!\n");
        maze_print(maze, width, height);
        printf("The path is: ");
        for (int i = 0; i < path->num_points; i++) {
            printf("(%d, %d) ", path->points[i].x, path->points[i].y);
        }
        printf("\n");
    } else {
        printf("The maze has no solution.\n");
    }

    maze_free(maze, height);
    path_free(path);
    return 0;
}