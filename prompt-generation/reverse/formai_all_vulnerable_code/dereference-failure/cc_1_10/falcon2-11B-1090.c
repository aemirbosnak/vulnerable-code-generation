//Falcon2-11B DATASET v1.0 Category: Game of Life ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_board(int board[][10], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%3d ", board[i][j]);
        }
        printf("\n");
    }
}

void update_neighbors(int board[][10], int size, int x, int y) {
    int n_neighbors = 0;

    int n_x, n_y;
    n_x = x - 1;
    if (n_x < 0) {
        n_x = size - 1;
    }

    n_y = y - 1;
    if (n_y < 0) {
        n_y = size - 1;
    }

    n_x = n_x < size? n_x : 0;
    n_y = n_y < size? n_y : 0;

    n_x = n_x > size - 1? n_x : size - 1;
    n_y = n_y > size - 1? n_y : size - 1;

    for (int i = n_x; i <= n_x + 1; i++) {
        for (int j = n_y; j <= n_y + 1; j++) {
            if (i!= x && j!= y) {
                n_neighbors += board[i][j];
            }
        }
    }

    if (board[x][y] == 1) {
        if (n_neighbors < 2 || n_neighbors > 3) {
            board[x][y] = 0;
        } else {
            board[x][y] = 1;
        }
    } else {
        if (n_neighbors == 3) {
            board[x][y] = 1;
        }
    }
}

void game_of_life(int board[][10], int size, int iterations) {
    srand(time(NULL));

    for (int i = 0; i < iterations; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                update_neighbors(board, size, j, k);
            }
        }

        print_board(board, size);
    }
}

int main() {
    int board[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    int size = 10;
    int iterations = 10;

    game_of_life(board, size, iterations);

    return 0;
}