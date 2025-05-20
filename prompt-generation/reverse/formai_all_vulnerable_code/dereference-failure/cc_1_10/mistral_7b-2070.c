//MISTRAL-7B DATASET v1.0 Category: Percolation Simulator ; Style: protected
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define SITE_PER_SQUARE 1

typedef struct {
    int x, y;
} Site;

bool **board;

bool is_valid_site(int x, int y) {
    return (x >= 0 && x < SIZE && y >= 0 && y < SIZE);
}

void print_board() {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
#pragma GCC diagnostic pop
}

void initialize_board() {
    board = malloc(SIZE * sizeof(bool *));
    for (int i = 0; i < SIZE; i++) {
        board[i] = calloc(SIZE, sizeof(bool));
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = false;
        }
    }
}

void random_site(Site *site) {
    do {
        site->x = rand() % SIZE;
        site->y = rand() % SIZE;
    } while (!is_valid_site(site->x, site->y) || board[site->x][site->y]);
}

bool percolates_left(int x, int y) {
    if (x == 0) {
        return true;
    }
    if (board[x - 1][y]) {
        return true;
    }
    return false;
}

bool percolates_right(int x, int y) {
    if (x == SIZE - 1) {
        return true;
    }
    if (board[x + 1][y]) {
        return true;
    }
    return false;
}

bool site_is_connected(int x, int y) {
    if (!board[x][y]) {
        board[x][y] = true;
        if (percolates_left(x, y)) {
            return true;
        }
        if (percolates_right(x, y)) {
            return true;
        }
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                if (is_valid_site(x + i, y + j) && site_is_connected(x + i, y + j)) {
                    return true;
                }
            }
        }
        board[x][y] = false;
    }
    return false;
}

void simulate_percolation() {
    srand(time(NULL));
    Site site;
    int sites_filled = 0;
    while (sites_filled < SIZE * SIZE) {
        random_site(&site);
        if (site_is_connected(site.x, site.y)) {
            sites_filled++;
        }
    }
    print_board();
}

int main() {
    initialize_board();
    simulate_percolation();
    for (int i = 0; i < SIZE; i++) {
        free(board[i]);
    }
    free(board);
    return 0;
}