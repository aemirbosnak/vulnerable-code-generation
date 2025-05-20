//GEMINI-pro DATASET v1.0 Category: Pathfinding algorithms ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>

#define MAX_SIZE 100

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point *points;
    int size;
} Path;

typedef struct {
    int **grid;
    int width;
    int height;
} Grid;

Grid *create_grid(int width, int height) {
    Grid *grid = malloc(sizeof(Grid));
    grid->width = width;
    grid->height = height;
    grid->grid = malloc(sizeof(int *) * height);
    for (int i = 0; i < height; i++) {
        grid->grid[i] = malloc(sizeof(int) * width);
    }
    return grid;
}

void destroy_grid(Grid *grid) {
    for (int i = 0; i < grid->height; i++) {
        free(grid->grid[i]);
    }
    free(grid->grid);
    free(grid);
}

Path *create_path() {
    Path *path = malloc(sizeof(Path));
    path->points = malloc(sizeof(Point) * MAX_SIZE);
    path->size = 0;
    return path;
}

void destroy_path(Path *path) {
    free(path->points);
    free(path);
}

void add_point_to_path(Path *path, Point point) {
    path->points[path->size] = point;
    path->size++;
}

int get_distance(Point point1, Point point2) {
    return abs(point1.x - point2.x) + abs(point1.y - point2.y);
}

int find_path(Grid *grid, Point start, Point end, Path *path) {
    int **distances = malloc(sizeof(int *) * grid->height);
    for (int i = 0; i < grid->height; i++) {
        distances[i] = malloc(sizeof(int) * grid->width);
    }

    for (int i = 0; i < grid->height; i++) {
        for (int j = 0; j < grid->width; j++) {
            distances[i][j] = INT_MAX;
        }
    }

    distances[start.y][start.x] = 0;

    while (1) {
        Point current_point;
        int min_distance = INT_MAX;

        for (int i = 0; i < grid->height; i++) {
            for (int j = 0; j < grid->width; j++) {
                if (distances[i][j] < min_distance && grid->grid[i][j] != -1) {
                    min_distance = distances[i][j];
                    current_point.x = j;
                    current_point.y = i;
                }
            }
        }

        if (current_point.x == end.x && current_point.y == end.y) {
            break;
        }

        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }

                Point neighbor_point;
                neighbor_point.x = current_point.x + j;
                neighbor_point.y = current_point.y + i;

                if (neighbor_point.x >= 0 && neighbor_point.x < grid->width && neighbor_point.y >= 0 && neighbor_point.y < grid->height && grid->grid[neighbor_point.y][neighbor_point.x] != -1) {
                    int new_distance = distances[current_point.y][current_point.x] + get_distance(current_point, neighbor_point);
                    if (new_distance < distances[neighbor_point.y][neighbor_point.x]) {
                        distances[neighbor_point.y][neighbor_point.x] = new_distance;
                    }
                }
            }
        }
    }

    if (distances[end.y][end.x] == INT_MAX) {
        return -1;
    }

    Point current_point = end;
    while (current_point.x != start.x || current_point.y != start.y) {
        add_point_to_path(path, current_point);

        int min_distance = INT_MAX;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }

                Point neighbor_point;
                neighbor_point.x = current_point.x + j;
                neighbor_point.y = current_point.y + i;

                if (neighbor_point.x >= 0 && neighbor_point.x < grid->width && neighbor_point.y >= 0 && neighbor_point.y < grid->height && distances[neighbor_point.y][neighbor_point.x] < min_distance) {
                    min_distance = distances[neighbor_point.y][neighbor_point.x];
                    current_point = neighbor_point;
                }
            }
        }
    }

    add_point_to_path(path, start);

    for (int i = 0; i < grid->height; i++) {
        free(distances[i]);
    }
    free(distances);

    return distances[end.y][end.x];
}

int main() {
    Grid *grid = create_grid(10, 10);

    for (int i = 0; i < grid->height; i++) {
        for (int j = 0; j < grid->width; j++) {
            grid->grid[i][j] = 0;
        }
    }

    grid->grid[5][5] = -1;

    Point start;
    start.x = 0;
    start.y = 0;

    Point end;
    end.x = 9;
    end.y = 9;

    Path *path = create_path();

    int distance = find_path(grid, start, end, path);

    if (distance == -1) {
        printf("No path found.\n");
    } else {
        printf("Path found with distance: %d\n", distance);
        for (int i = 0; i < path->size; i++) {
            printf("(%d, %d)\n", path->points[i].x, path->points[i].y);
        }
    }

    destroy_path(path);
    destroy_grid(grid);

    return 0;
}