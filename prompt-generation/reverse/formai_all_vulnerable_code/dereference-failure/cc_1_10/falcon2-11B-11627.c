//Falcon2-11B DATASET v1.0 Category: Bingo Simulator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_board(int *board, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", board[i * size + j]);
        }
        printf("\n");
    }
}

int main() {
    int size = 5;
    int *board = (int *)malloc(size * size * sizeof(int));
    srand(time(NULL));

    for (int i = 0; i < size * size; i++) {
        board[i] = rand() % 100 + 1;
    }

    print_board(board, size);
    printf("\n\n");

    int winning_pattern[5][5] = {
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5}
    };

    int num_win = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (board[i * size + j] == winning_pattern[i][j]) {
                num_win++;
                printf("WINNER!\n");
                print_board(board, size);
                printf("\n\n");
            }
        }
    }

    if (num_win == 0) {
        printf("No one won this round.\n");
    }

    free(board);
    return 0;
}