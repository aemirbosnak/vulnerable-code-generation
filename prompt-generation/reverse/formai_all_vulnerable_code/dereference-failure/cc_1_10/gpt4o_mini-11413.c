//GPT-4o-mini DATASET v1.0 Category: Pathfinding algorithms ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100
#define WALL 1
#define PATH 0

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point* points;
    int size;
    int capacity;
} Path;

typedef struct {
    int rows;
    int cols;
    int grid[MAX][MAX];
} Grid;

// Function declarations
Path* createPath(int capacity);
void addToPath(Path* path, Point point);
void freePath(Path* path);
bool isSafe(Grid* grid, int x, int y);
bool findPath(Grid* grid, Point start, Point end, Path* path);
void printGrid(Grid* grid);
void printPath(Path* path);

int main() {
    Grid grid = {
        .rows = 5,
        .cols = 5,
        .grid = {
            {0, 0, 1, 0, 0},
            {0, 0, 1, 0, 1},
            {0, 0, 0, 0, 1},
            {1, 1, 1, 0, 0},
            {0, 0, 0, 0, 0}
        }
    };

    Point start = {0, 0};
    Point end = {4, 4};
    Path* path = createPath(10);

    if (findPath(&grid, start, end, path)) {
        printf("Path found:\n");
        printPath(path);
    } else {
        printf("No path found.\n");
    }

    freePath(path);
    return 0;
}

Path* createPath(int capacity) {
    Path* path = (Path*)malloc(sizeof(Path));
    path->points = (Point*)malloc(sizeof(Point) * capacity);
    path->size = 0;
    path->capacity = capacity;
    return path;
}

void addToPath(Path* path, Point point) {
    if (path->size < path->capacity) {
        path->points[path->size++] = point;
    }
}

void freePath(Path* path) {
    free(path->points);
    free(path);
}

bool isSafe(Grid* grid, int x, int y) {
    return (x >= 0 && x < grid->rows && y >= 0 && y < grid->cols && grid->grid[x][y] == PATH);
}

bool findPath(Grid* grid, Point start, Point end, Path* path) {
    if (start.x == end.x && start.y == end.y) {
        addToPath(path, start);
        return true;
    }

    if (isSafe(grid, start.x, start.y)) {
        addToPath(path, start);
        grid->grid[start.x][start.y] = WALL;  // Mark the cell as visited

        // Move in all four possible directions
        Point directions[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        for (int i = 0; i < 4; i++) {
            Point next = {start.x + directions[i].x, start.y + directions[i].y};
            if (findPath(grid, next, end, path)) {
                return true;
            }
        }

        // Backtrack
        grid->grid[start.x][start.y] = PATH;  // Unmark the cell
        path->size--;  // Remove the last point from path
    }
    return false;
}

void printGrid(Grid* grid) {
    for (int i = 0; i < grid->rows; i++) {
        for (int j = 0; j < grid->cols; j++) {
            printf("%d ", grid->grid[i][j]);
        }
        printf("\n");
    }
}

void printPath(Path* path) {
    for (int i = 0; i < path->size; i++) {
        printf("(%d, %d) ", path->points[i].x, path->points[i].y);
    }
    printf("\n");
}