//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 5
#define MAX_COLS 5
#define MAX_NUMBERS 25

typedef struct {
    int row;
    int col;
    int value;
} Cell;

void generate_board(Cell board[MAX_ROWS][MAX_COLS]) {
    srand(time(NULL));

    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            board[i][j].value = rand() % MAX_NUMBERS + 1;
        }
    }
}

void print_board(Cell board[MAX_ROWS][MAX_COLS]) {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            printf("%d ", board[i][j].value);
        }
        printf("\n");
    }
}

int check_row(Cell board[MAX_ROWS][MAX_COLS], int row) {
    for (int i = 0; i < MAX_COLS; i++) {
        if (board[row][i].value == 0) {
            return 0;
        }
    }
    return 1;
}

int check_col(Cell board[MAX_ROWS][MAX_COLS], int col) {
    for (int i = 0; i < MAX_ROWS; i++) {
        if (board[i][col].value == 0) {
            return 0;
        }
    }
    return 1;
}

int check_diag(Cell board[MAX_ROWS][MAX_COLS]) {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            if (i == j && board[i][j].value == 0) {
                return 0;
            }
            if (i + j == MAX_ROWS - 1 && board[i][j].value == 0) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    Cell board[MAX_ROWS][MAX_COLS];
    generate_board(board);

    int player_row, player_col;
    int choice;

    do {
        print_board(board);

        printf("Enter your choice (row col): ");
        scanf("%d %d", &player_row, &player_col);

        if (player_row >= 0 && player_row < MAX_ROWS && player_col >= 0 && player_col < MAX_COLS) {
            if (board[player_row][player_col].value == 0) {
                board[player_row][player_col].value = 1;
            } else {
                printf("Invalid move\n");
            }
        } else {
            printf("Invalid move\n");
        }

        if (check_row(board, player_row) || check_col(board, player_col) || check_diag(board)) {
            printf("Congratulations! You won\n");
            break;
        }
    } while (1);

    return 0;
}