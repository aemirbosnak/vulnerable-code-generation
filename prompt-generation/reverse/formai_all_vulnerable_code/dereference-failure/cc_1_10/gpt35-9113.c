//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define ROW 5
#define COL 5

int isValid(int row, int col) {
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL);
}

int isUnblocked(int grid[ROW][COL], int row, int col) {
    return grid[row][col] == 1;
}

int isDestination(int row, int col, int dest_row, int dest_col) {
    return row == dest_row && col == dest_col;
}

int calculateDistance(int row, int col, int dest_row, int dest_col) {
    return abs(row - dest_row) + abs(col - dest_col);
}

void printPath(int** path, int row, int col) {
    if (path[row][col] != -1) {
        printPath(path, path[row][col] / COL, path[row][col] % COL);
    }
    printf("(%d,%d) -> ", row, col);
}

void aStarSearch(int grid[ROW][COL], int src_row, int src_col, int dest_row, int dest_col) {
    if (!isValid(src_row, src_col) || !isValid(dest_row, dest_col)) {
        printf("Invalid input\n");
        return;
    }

    if (!isUnblocked(grid, src_row, src_col) || !isUnblocked(grid, dest_row, dest_col)) {
        printf("Source or destination is blocked\n");
        return;
    }

    if (isDestination(src_row, src_col, dest_row, dest_col)) {
        printf("Source is destination\n");
        return;
    }

    int** f = malloc(sizeof(int*) * ROW);
    for (int i = 0; i < ROW; i++) {
        f[i] = malloc(sizeof(int) * COL);
        for (int j = 0; j < COL; j++) {
            f[i][j] = INT_MAX;
        }
    }

    int** g = malloc(sizeof(int*) * ROW);
    for (int i = 0; i < ROW; i++) {
        g[i] = malloc(sizeof(int) * COL);
        for (int j = 0; j < COL; j++) {
            g[i][j] = INT_MAX;
        }
    }

    int** h = malloc(sizeof(int*) * ROW);
    for (int i = 0; i < ROW; i++) {
        h[i] = malloc(sizeof(int) * COL);
        for (int j = 0; j < COL; j++) {
            h[i][j] = INT_MAX;
        }
    }

    int** path = malloc(sizeof(int*) * ROW);
    for (int i = 0; i < ROW; i++) {
        path[i] = malloc(sizeof(int) * COL);
        for (int j = 0; j < COL; j++) {
            path[i][j] = -1;
        }
    }

    int openList[ROW * COL];
    int openListSize = 0;
    int closedList[ROW][COL];
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            closedList[i][j] = 0;
        }
    }

    openList[0] = src_row * COL + src_col;
    openListSize++;

    g[src_row][src_col] = 0;
    h[src_row][src_col] = calculateDistance(src_row, src_col, dest_row, dest_col);
    f[src_row][src_col] = g[src_row][src_col] + h[src_row][src_col];

    while (openListSize > 0) {
        int current = openList[0];
        for (int i = 1; i < openListSize; i++) {
            if (f[openList[i] / COL][openList[i] % COL] < f[current / COL][current % COL]) {
                current = openList[i];
            }
        }

        openListSize--;

        int current_row = current / COL;
        int current_col = current % COL;

        closedList[current_row][current_col] = 1;

        if (isDestination(current_row, current_col, dest_row, dest_col)) {
            printPath(path, dest_row, dest_col);
            return;
        }

        int neighbour_rows[4] = {-1, 0, 0, 1};
        int neighbour_cols[4] = {0, -1, 1, 0};

        for (int i = 0; i < 4; i++) {
            int neighbour_row = current_row + neighbour_rows[i];
            int neighbour_col = current_col + neighbour_cols[i];

            if (isValid(neighbour_row, neighbour_col) && isUnblocked(grid, neighbour_row, neighbour_col) && !closedList[neighbour_row][neighbour_col]) {
                int new_g = g[current_row][current_col] + 1;
                int new_h = calculateDistance(neighbour_row, neighbour_col, dest_row, dest_col);
                int new_f = new_g + new_h;

                if (f[neighbour_row][neighbour_col] == INT_MAX || f[neighbour_row][neighbour_col] > new_f) {
                    openList[openListSize] = neighbour_row * COL + neighbour_col;
                    openListSize++;

                    path[neighbour_row][neighbour_col] = current_row * COL + current_col;

                    g[neighbour_row][neighbour_col] = new_g;
                    h[neighbour_row][neighbour_col] = new_h;
                    f[neighbour_row][neighbour_col] = new_f;
                }
            }
        }
    }

    printf("No path found\n");
}

int main() {
    int grid[ROW][COL] = {
        {1, 1, 1, 1, 1},
        {0, 1, 1, 0, 1},
        {0, 0, 0, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 1}
    };

    int src_row = 0, src_col = 0;
    int dest_row = 4, dest_col = 4;

    aStarSearch(grid, src_row, src_col, dest_row, dest_col);

    return 0;
}