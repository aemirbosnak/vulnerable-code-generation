//GPT-4o-mini DATASET v1.0 Category: Pathfinding algorithms ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 10

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point* cells;
    int count;
} Path;

int grid[N][N] = {
    {0, 1, 0, 0, 0, 1, 0, 1, 0, 0},
    {0, 1, 0, 1, 1, 1, 0, 0, 0, 1},
    {0, 0, 0, 0, 1, 0, 1, 1, 0, 0},
    {0, 1, 1, 0, 1, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 1, 1, 0, 1, 0, 0},
    {0, 1, 1, 1, 1, 0, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
    {0, 1, 0, 1, 0, 0, 0, 1, 0, 0}
};

bool isSafe(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && grid[x][y] == 0);
}

Path* createPath() {
    Path* path = (Path*)malloc(sizeof(Path));
    path->cells = (Point*)malloc(N * N * sizeof(Point));
    path->count = 0;
    return path;
}

void printPath(Path* path) {
    printf("Path found: ");
    for (int i = 0; i < path->count; i++) {
        printf("-> (%d, %d) ", path->cells[i].x, path->cells[i].y);
    }
    printf("\n");
}

bool findPath(int x, int y, Path* path) {
    if (x == N - 1 && y == N - 1) {
        path->cells[path->count].x = x;
        path->cells[path->count].y = y;
        path->count++;
        return true;
    }

    if (isSafe(x, y)) {
        path->cells[path->count].x = x;
        path->cells[path->count].y = y;
        path->count++;

        // Move forward in x direction
        if (findPath(x + 1, y, path)) {
            return true;
        }

        // If moving in x direction doesn't give solution
        // then move down in y direction
        if (findPath(x, y + 1, path)) {
            return true;
        }

        // If none of the above movements work then
        // BACKTRACK: remove the current cell from path
        path->count--;
    }
    return false;
}

int main() {
    Path* path = createPath();
    if (findPath(0, 0, path)) {
        printPath(path);
    } else {
        printf("No path found!\n");
    }

    free(path->cells);
    free(path);
    return 0;
}