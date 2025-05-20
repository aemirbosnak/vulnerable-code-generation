//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const int BOARD_SIZE = 3;
const int MAX_DEPTH = 9;

int* create_board() {
    int* board = (int*)malloc(BOARD_SIZE * BOARD_SIZE * sizeof(int));
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i * BOARD_SIZE + j] = 0;
        }
    }
    return board;
}

void display_board(int* board) {
    printf("-------------\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("| ");
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i * BOARD_SIZE + j] == 1) printf("X");
            else if (board[i * BOARD_SIZE + j] == -1) printf("O");
            else printf(" ");
            printf(" | ");
        }
        printf("\n");
        printf("-------------\n");
    }
}

bool check_win(int* board, int player) {
    // Rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        bool row_win = true;
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i * BOARD_SIZE + j] != player) row_win = false;
        }
        if (row_win) return true;
    }
    // Columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        bool col_win = true;
        for (int i = 0; i < BOARD_SIZE; i++) {
            if (board[i * BOARD_SIZE + j] != player) col_win = false;
        }
        if (col_win) return true;
    }
    // Diagonal
    bool diag_win = true;
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i * BOARD_SIZE + i] != player) diag_win = false;
    }
    if (diag_win) return true;
    diag_win = true;
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i * BOARD_SIZE + (BOARD_SIZE - i - 1)] != player) diag_win = false;
    }
    if (diag_win) return true;
    return false;
}

int evaluate_board(int* board, int player) {
    if (check_win(board, player)) return 1;
    if (check_win(board, -player)) return -1;
    return 0;
}

int minimax(int* board, int player, int depth) {
    if (depth == MAX_DEPTH) return evaluate_board(board, player);
    int best_score;
    if (player == 1) {
        best_score = -1000;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i * BOARD_SIZE + j] == 0) {
                    board[i * BOARD_SIZE + j] = player;
                    int score = minimax(board, -player, depth + 1);
                    board[i * BOARD_SIZE + j] = 0;
                    if (score > best_score) best_score = score;
                }
            }
        }
    }
    else {
        best_score = 1000;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i * BOARD_SIZE + j] == 0) {
                    board[i * BOARD_SIZE + j] = player;
                    int score = minimax(board, -player, depth + 1);
                    board[i * BOARD_SIZE + j] = 0;
                    if (score < best_score) best_score = score;
                }
            }
        }
    }
    return best_score;
}

void perform_move(int* board, int player) {
    int best_score = -1000;
    int move = -1;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i * BOARD_SIZE + j] == 0) {
                board[i * BOARD_SIZE + j] = player;
                int score = minimax(board, -player, 0);
                board[i * BOARD_SIZE + j] = 0;
                if (score > best_score) {
                    best_score = score;
                    move = i * BOARD_SIZE + j;
                }
            }
        }
    }
    board[move] = player;
}

int main() {
    int* board = create_board();
    int player = 1;
    while (true) {
        display_board(board);
        if (check_win(board, player)) {
            printf("Player %d wins!\n", player);
            break;
        }
        if (player == 1) {
            printf("Player X's turn.\n");
            int row, col;
            printf("Enter row: ");
            scanf("%d", &row);
            printf("Enter column: ");
            scanf("%d", &col);
            while (board[row * BOARD_SIZE + col] != 0) {
                printf("Invalid move! Try again.\n");
                printf("Enter row: ");
                scanf("%d", &row);
                printf("Enter column: ");
                scanf("%d", &col);
            }
            board[row * BOARD_SIZE + col] = player;
        }
        else {
            printf("Player O's turn.\n");
            perform_move(board, player);
        }
        player *= -1;
    }
    free(board);
    return 0;
}