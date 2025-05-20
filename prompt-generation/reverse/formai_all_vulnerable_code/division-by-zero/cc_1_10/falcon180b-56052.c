//Falcon-180B DATASET v1.0 Category: Sudoku solver ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MAX_ROWS 9
#define MAX_COLS 9
#define MAX_VAL 9

typedef struct {
    int row;
    int col;
    int val;
} Cell;

int board[MAX_ROWS][MAX_COLS];
int num_cells;

void *solver(void *arg) {
    int start_row = 0;
    int start_col = 0;
    int end_row = MAX_ROWS - 1;
    int end_col = MAX_COLS - 1;

    srand(time(NULL));
    for (int i = start_row; i <= end_row; i++) {
        for (int j = start_col; j <= end_col; j++) {
            if (board[i][j] == 0) {
                int val = rand() % MAX_VAL + 1;
                board[i][j] = val;
                num_cells++;
            }
        }
    }
    pthread_exit(NULL);
}

void print_board() {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    pthread_t thread_id;
    int thread_num = 0;
    int rows = MAX_ROWS / thread_num;

    srand(time(NULL));
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            board[i][j] = 0;
        }
    }

    num_cells = 0;

    for (int i = 0; i < thread_num; i++) {
        pthread_create(&thread_id, NULL, solver, NULL);
        thread_num++;
    }

    for (int i = 0; i < thread_num; i++) {
        pthread_join(thread_id, NULL);
    }

    print_board();

    return 0;
}