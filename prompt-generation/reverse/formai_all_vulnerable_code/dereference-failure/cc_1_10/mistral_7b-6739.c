//MISTRAL-7B DATASET v1.0 Category: Percolation Simulator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define N 10
#define M 10

bool **grid;
int openSites;
int totalSites;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

void printGrid() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

bool isValid(int r, int c) {
    return r >= 0 && r < N && c >= 0 && c < M;
}

void openSite(int r, int c) {
    grid[r][c] = 1;
    openSites++;
}

bool siteIsOpen(int r, int c) {
    return grid[r][c] == 1;
}

void connectToNeighbors(int r, int c) {
    for (int i = 0; i < 4; ++i) {
        int newR = r + dr[i];
        int newC = c + dc[i];
        if (isValid(newR, newC) && siteIsOpen(newR, newC)) {
            openSite(r, c);
            connectToNeighbors(newR, newC);
        }
    }
}

int main() {
    srand(time(NULL));

    totalSites = N * M;
    grid = calloc(N, sizeof(bool *));
    for (int i = 0; i < N; ++i) {
        grid[i] = calloc(M, sizeof(bool));
    }

    while (openSites < totalSites) {
        int r = rand() % N;
        int c = rand() % M;
        if (!siteIsOpen(r, c)) {
            openSite(r, c);
            connectToNeighbors(r, c);
        }
    }

    printGrid();

    for (int i = 0; i < N; ++i) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}