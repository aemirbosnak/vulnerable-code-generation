//FormAI DATASET v1.0 Category: Memory Game ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void fill_board(int board[ROWS][COLS]) {
    int i, j;
    int nums[] = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8};
    srand(time(NULL));
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            int idx = rand() % 16;
            if (nums[idx] != 0)
                board[i][j] = nums[idx];
            else
                j--; 
            nums[idx] = 0;
        }
    }
}

void display_board(int board[ROWS][COLS], int rows, int cols, int game_over) {
    int i, j;
    printf("   ");
    for (i = 0; i < cols; i++) {
        printf("%d  ", i+1);
    }
    printf("\n");
    for (i = 0; i < rows; i++) {
        printf("%d  ", i+1);
        for (j = 0; j < cols; j++) {
            if (board[i][j] == 0 || game_over == 0) 
                printf(".  ");
            else
                printf("%d  ", board[i][j]);
        }
        printf("\n");
    }
}

int check_match(int board[ROWS][COLS], int row1, int col1, int row2, int col2) {
    if (board[row1][col1] == board[row2][col2]) {
        board[row1][col1] = 0;
        board[row2][col2] = 0;
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int board[ROWS][COLS];
    fill_board(board);
    int game_over = 0, num_moves = 0;
    display_board(board, ROWS, COLS, game_over);
    while (game_over == 0) {
        int row1, col1, row2, col2;
        printf("Enter the row and column of your first choice: ");
        scanf("%d %d", &row1, &col1);
        printf("Enter the row and column of your second choice: ");
        scanf("%d %d", &row2, &col2);
        row1--;
        col1--;
        row2--;
        col2--;
        if (board[row1][col1]==0 || board[row2][col2]==0 || (row1==row2 && col1==col2)) {
            printf("Invalid input.\n");
        } else {
            num_moves++;
            if (check_match(board, row1, col1, row2, col2) == 1) {
                printf("Match found!\n");
            } else {
                printf("No match found.\n");
            }
        }
        display_board(board, ROWS, COLS, game_over);
        game_over = 1;
        int i,j;
        for(i=0; i<ROWS; i++) {
            for(j=0; j<COLS; j++) {
                if(board[i][j] != 0) {
                    game_over = 0;
                }
            }
        }
    }
    printf("Game over! Number of moves = %d\n", num_moves);
    return 0;
}