//FormAI DATASET v1.0 Category: Checkers Game ; Style: irregular
#include <stdio.h>

#define ROW 8
#define COL 8

// Function to initialize the board
void initialize_board(char board[ROW][COL]) {
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            board[i][j] = '.';
        }
    }
    board[0][1] = 'b';
    board[0][3] = 'b';
    board[0][5] = 'b';
    board[0][7] = 'b';
    board[1][0] = 'b';
    board[1][2] = 'b';
    board[1][4] = 'b';
    board[1][6] = 'b';
    board[2][1] = 'b';
    board[2][3] = 'b';
    board[2][5] = 'b';
    board[2][7] = 'b';
    board[5][0] = 'w';
    board[5][2] = 'w';
    board[5][4] = 'w';
    board[5][6] = 'w';
    board[6][1] = 'w';
    board[6][3] = 'w';
    board[6][5] = 'w';
    board[6][7] = 'w';
    board[7][0] = 'w';
    board[7][2] = 'w';
    board[7][4] = 'w';
    board[7][6] = 'w';
}

// Function to print the board
void print_board(char board[ROW][COL]) {
    int i, j;
    printf("  0 1 2 3 4 5 6 7\n");
    for (i = 0; i < ROW; i++) {
        printf("%d ", i);
        for (j = 0; j < COL; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to get the current player's move
void get_move(int *src_row, int *src_col, int *dst_row, int *dst_col) {
    printf("Enter your move (source row, source column, destination row, destination column): ");
    scanf("%d %d %d %d", src_row, src_col, dst_row, dst_col);
}

// Function to check if the move is valid
int is_valid_move(char board[ROW][COL], int src_row, int src_col, int dst_row, int dst_col) {
    // Check if destination is empty
    if (board[dst_row][dst_col] != '.') {
        return 0;
    }
    // Check if destination is a diagonal of the current position
    if ((abs(dst_row - src_row) == 1) && (abs(dst_col - src_col) == 1)) {
        return 1;
    }
    return 0;
}

// Function to perform the move
void perform_move(char board[ROW][COL], int src_row, int src_col, int dst_row, int dst_col) {
    board[dst_row][dst_col] = board[src_row][src_col];
    board[src_row][src_col] = '.';
}

int main() {
    char board[ROW][COL];
    int src_row, src_col, dst_row, dst_col;
    char current_player = 'w';
    initialize_board(board);
    print_board(board);
    while (1) {
        get_move(&src_row, &src_col, &dst_row, &dst_col);
        if (is_valid_move(board, src_row, src_col, dst_row, dst_col)) {
            perform_move(board, src_row, src_col, dst_row, dst_col);
            print_board(board);
            if (current_player == 'w') {
                current_player = 'b';
            } else {
                current_player = 'w';
            }
        } else {
            printf("Invalid move.\n");
        }
    }
    return 0;
}