//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 5
#define COL 5

typedef struct {
    int row, col;
} Point;

Point newPoint(int row, int col) {
    Point p = { row, col };
    return p;
}

bool isSafe(int grid[ROW][COL], bool visited[ROW][COL], int row, int col) {
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL) && (grid[row][col] && !visited[row][col]);
}

void printPath(Point path[], int len) {
    for (int i = 0; i < len; i++) {
        printf("(%d, %d) ", path[i].row, path[i].col);
    }
    printf("\n");
}

bool solveMazeUtil(int grid[ROW][COL], bool visited[ROW][COL], Point start, Point end, Point path[], int *len) {
    if (start.row == end.row && start.col == end.col) {
        path[*len++] = start;
        printPath(path, *len);
        return true;
    }
    if (isSafe(grid, visited, start.row, start.col)) {
        visited[start.row][start.col] = true;
        path[*len++] = start;
        if (solveMazeUtil(grid, visited, newPoint(start.row + 1, start.col), end, path, len))
            return true;
        if (solveMazeUtil(grid, visited, newPoint(start.row, start.col + 1), end, path, len))
            return true;
        if (solveMazeUtil(grid, visited, newPoint(start.row - 1, start.col), end, path, len))
            return true;
        if (solveMazeUtil(grid, visited, newPoint(start.row, start.col - 1), end, path, len))
            return true;
        path[--*len] = (Point) {0, 0};
        visited[start.row][start.col] = false;
    }
    return false;
}

void solveMaze(int grid[ROW][COL], Point start, Point end) {
    bool visited[ROW][COL] = {{ false }};
    Point path[ROW * COL];
    int len = 0;
    if (!solveMazeUtil(grid, visited, start, end, path, &len)) {
        printf("No solution found.\n");
    }
}

int main() {
    int grid[ROW][COL] = {
        {1, 0, 0, 0, 1},
        {1, 1, 0, 1, 1},
        {1, 1, 1, 1, 0},
        {0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1}
    };
    Point start = {0, 0};
    Point end = {4, 4};
    solveMaze(grid, start, end);
    return 0;
}