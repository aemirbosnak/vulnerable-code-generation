//Falcon2-11B DATASET v1.0 Category: Game of Life ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_board(int** board, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

void generate_random_board(int** board, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            board[i][j] = rand() % 2; // 0 represents dead cells, 1 represents alive cells
        }
    }
}

void update_board(int** board, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int live_neighbors = count_live_neighbors(board, rows, cols, i, j);
            if (board[i][j] == 1 && (live_neighbors < 2 || live_neighbors > 3)) {
                board[i][j] = 0; // Cell dies
            } else if (board[i][j] == 0 && live_neighbors == 3) {
                board[i][j] = 1; // Cell is born
            }
        }
    }
}

int count_live_neighbors(int** board, int rows, int cols, int i, int j) {
    int count = 0;
    for (int delta_i = -1; delta_i <= 1; delta_i++) {
        for (int delta_j = -1; delta_j <= 1; delta_j++) {
            if (i + delta_i >= 0 && i + delta_i < rows &&
                j + delta_j >= 0 && j + delta_j < cols) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    srand(time(NULL)); // Seed random number generator

    int rows = 10;
    int cols = 10;
    int** board = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        board[i] = (int*)malloc(cols * sizeof(int));
    }

    generate_random_board(board, rows, cols);

    printf("Initial board:\n");
    print_board(board, rows, cols);

    for (int i = 0; i < 100; i++) {
        update_board(board, rows, cols);

        printf("Board after %d steps:\n", i + 1);
        print_board(board, rows, cols);

        printf("\n");
    }

    free(board[0]);
    for (int i = 1; i < rows; i++) {
        free(board[i]);
    }
    free(board);

    return 0;
}