//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

int create_board(int board[ROWS][COLS]) {
    int i, j;
    srand(time(NULL));
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = rand() % 10;
        }
    }
    return 0;
}

int print_board(int board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int check_match(int board[ROWS][COLS], int row, int col) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (board[i][j] == board[row][col]) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int board[ROWS][COLS];
    int choice, flag = 0, count = 0;
    create_board(board);
    while (1) {
        system("clear");
        printf("Welcome to the Memory Game!\n");
        printf("Press 1 to start a new game\n");
        printf("Press 2 to quit\n");
        scanf("%d", &choice);
        if (choice == 1) {
            flag = 0;
            count = 0;
            int player_row = 0, player_col = 0;
            while (flag == 0) {
                system("clear");
                print_board(board);
                printf("Player's turn. Enter your row and column: ");
                scanf("%d %d", &player_row, &player_col);
                if (check_match(board, player_row, player_col)) {
                    printf("Correct match! Try again.\n");
                    count++;
                } else {
                    printf("Incorrect match. Game over.\n");
                    flag = 1;
                }
            }
            if (count == ROWS * COLS) {
                printf("Congratulations! You win.\n");
            }
        } else if (choice == 2) {
            exit(0);
        }
    }
    return 0;
}