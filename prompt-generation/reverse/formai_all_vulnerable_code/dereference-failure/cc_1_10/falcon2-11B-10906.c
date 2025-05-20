//Falcon2-11B DATASET v1.0 Category: Tic Tac Toe AI ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 3
#define MAX_COLS 3

typedef struct board {
    int rows;
    int cols;
    int* board;
} Board;

typedef struct player {
    char name[10];
    int* moves;
    int moves_left;
} Player;

int max(int a, int b) {
    return a > b? a : b;
}

int min(int a, int b) {
    return a < b? a : b;
}

int is_valid_move(Board* board, int row, int col) {
    return row >= 0 && row < board->rows && col >= 0 && col < board->cols;
}

void print_board(Board* board) {
    printf("   0 | 1 | 2\n");
    printf("-----+\n");
    printf("   3 | 4 | 5\n");
    printf("-----+\n");
    printf("   6 | 7 | 8\n");
}

int player_choice(Board* board, Player* players) {
    int row, col;
    printf("Player %s's turn. Enter row and column (0-%d): ", players->name, board->rows);
    scanf("%d%d", &row, &col);
    if (!is_valid_move(board, row, col)) {
        printf("Invalid move.\n");
        return 0;
    }
    return 1;
}

int ai_choice(Board* board, Player* players) {
    int row, col;
    int best_move = -1;
    for (int i = 0; i < board->rows; i++) {
        for (int j = 0; j < board->cols; j++) {
            if (board->board[i * board->cols + j] == 0) {
                row = i;
                col = j;
                break;
            }
        }
        if (best_move == -1) {
            best_move = row * board->cols + col;
        }
        else if (board->board[best_move] < board->board[row * board->cols + col]) {
            best_move = row * board->cols + col;
        }
    }
    return best_move;
}

int check_win(Board* board, int move) {
    int row, col;
    for (int i = 0; i < board->rows; i++) {
        row = i;
        col = 0;
        if (board->board[move] == board->board[move + row * board->cols]) {
            return 1;
        }
        col = board->cols - 1;
        if (board->board[move] == board->board[move + row * board->cols]) {
            return 1;
        }
    }
    for (int i = 0; i < board->cols; i++) {
        row = 0;
        col = i;
        if (board->board[move] == board->board[move + col * board->rows]) {
            return 1;
        }
        col = board->cols - 1;
        if (board->board[move] == board->board[move + col * board->rows]) {
            return 1;
        }
    }
    for (int i = 0; i < board->rows; i++) {
        for (int j = 0; j < board->cols; j++) {
            if (board->board[move] == board->board[i * board->cols + j] &&
                board->board[move] == board->board[i * board->cols + j + 1] &&
                board->board[move] == board->board[i * board->cols + j + 2]) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    Board board;
    board.rows = MAX_ROWS;
    board.cols = MAX_COLS;
    board.board = (int*) malloc(board.rows * board.cols * sizeof(int));
    for (int i = 0; i < board.rows * board.cols; i++) {
        board.board[i] = 0;
    }

    Player player1;
    strcpy(player1.name, "Player 1");
    player1.moves = (int*) malloc(sizeof(int));
    player1.moves_left = MAX_ROWS * MAX_COLS;

    Player player2;
    strcpy(player2.name, "Player 2");
    player2.moves = (int*) malloc(sizeof(int));
    player2.moves_left = MAX_ROWS * MAX_COLS;

    int winner = 0;
    int move;
    while (winner == 0) {
        print_board(&board);
        printf("Enter move (0-%d): ", board.rows * board.cols - 1);
        scanf("%d", &move);
        if (move < 0 || move >= board.rows * board.cols) {
            printf("Invalid move.\n");
            continue;
        }
        if (board.board[move] == 0) {
            if (player_choice(&board, &player1) == 1) {
                board.board[move] = 1;
                player1.moves[player1.moves_left++] = move;
            }
            else if (player_choice(&board, &player2) == 1) {
                board.board[move] = 2;
                player2.moves[player2.moves_left++] = move;
            }
            else {
                printf("Invalid move.\n");
                continue;
            }
        }
        else {
            winner = check_win(&board, move);
            if (winner == 1) {
                printf("%s wins!\n", player1.name);
            }
            else if (winner == 2) {
                printf("%s wins!\n", player2.name);
            }
            else {
                printf("It's a tie!\n");
            }
        }
    }
    free(board.board);
    free(player1.moves);
    free(player2.moves);
    return 0;
}