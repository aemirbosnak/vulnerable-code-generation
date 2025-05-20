//FormAI DATASET v1.0 Category: Memory Game ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int *arr, int size) {
    if (size < 2) {
        return;
    }
    int i, temp, index;
    for (i = 0; i < size - 1; i++) {
        index = rand() % (size - i) + i;
        temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
    }
    shuffle(arr, size - 1);
}

void print_board(int *board, int size) {
    int i, j, index;
    printf("---------------------\n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            index = i * size + j;
            if (board[index] < 0) {
                printf("  ");
            } else {
                printf("%2d", board[index]);
            }
            printf("|");
        }
        printf("\n---------------------\n");
    }
}

int is_win(int *board, int size) {
    int i, j, index, temp;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            index = i * size + j;
            if (board[index] < 0) {
                continue;
            }
            temp = 1 + (i > 0 && board[index - size] > 0) + (i < size - 1 && board[index + size] > 0) + (j > 0 && board[index - 1] > 0) + (j < size - 1 && board[index + 1] > 0);
            if (board[index] != temp) {
                return 0;
            }
        }
    }
    return 1;
}

int solve(int *board, int size, int moves_left) {
    if (is_win(board, size)) {
        return 1;
    }
    if (moves_left == 0) {
        return 0;
    }
    int i, j, index, temp, temp_index;
    int *valid_moves = (int *)calloc(size * size, sizeof(int));
    int moves_count = 0;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            index = i * size + j;
            if (board[index] < 0) {
                continue;
            }
            temp = 1 + (i > 0 && board[index - size] > 0) + (i < size - 1 && board[index + size] > 0) + (j > 0 && board[index - 1] > 0) + (j < size - 1 && board[index + 1] > 0);
            if (board[index] == temp) {
                valid_moves[moves_count] = index;
                moves_count++;
            }
        }
    }
    shuffle(valid_moves, moves_count);
    int result;
    for (i = 0; i < moves_count; i++) {
        temp_index = valid_moves[i];
        board[temp_index] = -1;
        result = solve(board, size, moves_left - 1);
        if (result == 1) {
            free(valid_moves);
            return 1;
        }
        board[temp_index] = 0;
    }
    free(valid_moves);
    return 0;
}

int main() {
    srand(time(NULL));
    int size = 5;
    int *board = (int *)calloc(size * size, sizeof(int));
    int i, j, index, temp;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            index = i * size + j;
            temp = (i > 0) + (i < size - 1) + (j > 0) + (j < size - 1);
            if (temp == 4) {
                board[index] = -1;
            } else {
                board[index] = temp;
            }
        }
    }
    shuffle(board, size * size);
    int moves = 10;
    print_board(board, size);
    if (solve(board, size, moves)) {
        printf("Congratulations! You have won the game.\n");
    } else {
        printf("Sorry, you have lost the game.\n");
    }
    print_board(board, size);
    free(board);
    return 0;
}