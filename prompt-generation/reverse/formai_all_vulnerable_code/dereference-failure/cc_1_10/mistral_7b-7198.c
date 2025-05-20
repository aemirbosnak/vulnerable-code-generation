//MISTRAL-7B DATASET v1.0 Category: Percolation Simulator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SIZE 10

bool is_valid(int x, int y) {
    return x >= 0 && x < SIZE && y >= 0 && y < SIZE;
}

void print_board(bool **board) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            printf("%c ", board[i][j] ? 'O' : '.');
        }
        printf("\n");
    }
}

void simulate_percolation(bool **board) {
    srand(time(NULL));
    int num_open_sites = 0;

    // Open initial sites
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (is_valid(i, j) && !board[i][j]) {
                board[i][j] = true;
                ++num_open_sites;

                if (i == 0) {
                    for (int j = 0; j < SIZE; ++j) {
                        if (is_valid(i, j) && !board[i][j]) {
                            board[i][j] = true;
                            ++num_open_sites;
                        }
                    }
                }

                if (i < SIZE - 1 && rand() % 2 == 0) {
                    board[i + 1][j] = true;
                    ++num_open_sites;
                }

                if (j > 0 && rand() % 2 == 0) {
                    board[i][j - 1] = true;
                    ++num_open_sites;
                }

                if (j < SIZE - 1 && rand() % 2 == 0) {
                    board[i][j + 1] = true;
                    ++num_open_sites;
                }
            }
        }
    }

    print_board(board);
    printf("Number of open sites: %d\n", num_open_sites);
}

int main() {
    bool **board = malloc(SIZE * sizeof(bool *));
    for (int i = 0; i < SIZE; ++i) {
        board[i] = calloc(SIZE, sizeof(bool));
    }

    simulate_percolation(board);

    for (int i = 0; i < SIZE; ++i) {
        free(board[i]);
    }
    free(board);

    return 0;
}