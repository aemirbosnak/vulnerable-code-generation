//GEMINI-pro DATASET v1.0 Category: Pathfinding algorithms ; Style: decentralized
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point *points;
    int num_points;
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

void free_grid(Grid *grid) {
    for (int i = 0; i < grid->height; i++) {
        free(grid->grid[i]);
    }
    free(grid->grid);
    free(grid);
}

void print_grid(Grid *grid) {
    for (int i = 0; i < grid->height; i++) {
        for (int j = 0; j < grid->width; j++) {
            printf("%d ", grid->grid[i][j]);
        }
        printf("\n");
    }
}

bool is_valid_point(Grid *grid, Point point) {
    return point.x >= 0 && point.x < grid->width && point.y >= 0 && point.y < grid->height && grid->grid[point.y][point.x] == 0;
}

Path *find_path(Grid *grid, Point start, Point end) {
    Path *path = malloc(sizeof(Path));
    path->points = malloc(sizeof(Point) * 100);
    path->num_points = 0;

    Point queue[WIDTH * HEIGHT];
    int head = 0;
    int tail = 0;
    queue[tail++] = start;
    grid->grid[start.y][start.x] = 1;

    while (head != tail) {
        Point current = queue[head++];
        if (current.x == end.x && current.y == end.y) {
            break;
        }

        Point neighbors[4] = {
            {current.x - 1, current.y},
            {current.x + 1, current.y},
            {current.x, current.y - 1},
            {current.x, current.y + 1},
        };

        for (int i = 0; i < 4; i++) {
            Point neighbor = neighbors[i];
            if (is_valid_point(grid, neighbor)) {
                queue[tail++] = neighbor;
                grid->grid[neighbor.y][neighbor.x] = 1;
                path->points[path->num_points++] = neighbor;
            }
        }
    }

    return path;
}

int main() {
    Grid *grid = create_grid(WIDTH, HEIGHT);

    // Initialize the grid with obstacles
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (rand() % 10 == 0) {
                grid->grid[i][j] = 1;
            }
        }
    }

    // Print the grid
    print_grid(grid);

    // Find the path from the start point to the end point
    Point start = {0, 0};
    Point end = {WIDTH - 1, HEIGHT - 1};
    Path *path = find_path(grid, start, end);

    // Print the path
    for (int i = 0; i < path->num_points; i++) {
        printf("(%d, %d)\n", path->points[i].x, path->points[i].y);
    }

    // Free the memory allocated for the path
    free(path->points);
    free(path);

    // Free the memory allocated for the grid
    free_grid(grid);

    return 0;
}