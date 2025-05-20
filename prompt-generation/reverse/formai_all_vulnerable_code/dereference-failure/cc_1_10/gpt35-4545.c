//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define OPEN 0
#define BLOCKED 1

int grid[SIZE][SIZE];
int opened[SIZE][SIZE];

int parent(int i, int j) {
    int p = i - 1;
    return (p >= 0 && grid[p][j] == OPEN) ? p * SIZE + j : -1;
}

int left(int i, int j) {
    int l = j - 1;
    return (l >= 0 && grid[i][l] == OPEN) ? i * SIZE + l : -1;
}

int right(int i, int j) {
    int r = j + 1;
    return (r < SIZE && grid[i][r] == OPEN) ? i * SIZE + r : -1;
}

int bottom(int i, int j) {
    int b = i + 1;
    return (b < SIZE && grid[b][j] == OPEN) ? b * SIZE + j : -1;
}

int find(int *list, int x) {
    while (list[x] != x)
        x = list[x];
    return x;
}

void union_find(int a, int b, int *list) {
    int root_a = find(list, a);
    int root_b = find(list, b);
    list[root_b] = root_a;
}

void percolation() {
    int *list = (int *)malloc(SIZE * SIZE * sizeof(int));
    for (int i = 0; i < SIZE * SIZE; i++)
        list[i] = i;

    // create a random grid with some blocked cells
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            double p = (double)rand() / RAND_MAX;
            if (p < 0.5)
                grid[i][j] = OPEN;
            else
                grid[i][j] = BLOCKED;
        }
    }

    // open the top row
    for (int j = 0; j < SIZE; j++) {
        if (grid[0][j] == OPEN)
            opened[0][j] = 1;
    }

    // open cells until we reach the bottom row
    int percolates = 0;
    while (!percolates) {
        int i = rand() % SIZE;
        int j = rand() % SIZE;
        if (grid[i][j] == BLOCKED) {
            grid[i][j] = OPEN;
            opened[i][j] = 1;
            if (opened[SIZE - 1][j] == 1) {
                percolates = 1;
                break;
            }
            int p = parent(i, j);
            int l = left(i, j);
            int r = right(i, j);
            int b = bottom(i, j);
            if (p != -1 && opened[p/SIZE][p%SIZE] == 1)
                union_find(i * SIZE + j, p, list);
            if (l != -1 && opened[l/SIZE][l%SIZE] == 1)
                union_find(i * SIZE + j, l, list);
            if (r != -1 && opened[r/SIZE][r%SIZE] == 1)
                union_find(i * SIZE + j, r, list);
            if (b != -1 && opened[b/SIZE][b%SIZE] == 1)
                union_find(i * SIZE + j, b, list);
        }
    }

    // print the result
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    if (percolates)
        printf("The grid percolates!\n");
    else
        printf("The grid does not percolate.\n");
}

int main() {
    percolation();
    return 0;
}