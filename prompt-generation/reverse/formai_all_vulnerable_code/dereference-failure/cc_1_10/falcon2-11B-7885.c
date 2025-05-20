//Falcon2-11B DATASET v1.0 Category: Tic Tac Toe AI ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_SIZE 3

typedef struct {
    int size;
    int board[MAX_SIZE][MAX_SIZE];
    char player;
    int winner;
} TicTacToe;

TicTacToe *create_board() {
    TicTacToe *board = (TicTacToe*)malloc(sizeof(TicTacToe));
    board->size = MAX_SIZE;
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            board->board[i][j] = 0;
        }
    }
    board->player = 'X';
    board->winner = 0;
    return board;
}

void print_board(TicTacToe *board) {
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            printf("%c ", board->board[i][j] == 'X'? 'X' : 'O');
        }
        printf("\n");
    }
}

void update_board(TicTacToe *board, int row, int col, char player) {
    board->board[row][col] = player;
    if (row == col && board->board[row][col] == board->player) {
        board->winner = 1;
        board->player = 'O';
    } else if (row + col == MAX_SIZE - 1 && board->board[row][col] == board->player) {
        board->winner = 1;
        board->player = 'O';
    } else if (row + col == MAX_SIZE - 1 && board->board[row][col] == 'O') {
        board->winner = 2;
        board->player = 'X';
    } else if (row + col == MAX_SIZE - 1 && board->board[row][col] == 0) {
        board->winner = 0;
    }
}

void check_winner(TicTacToe *board) {
    int row_winner = 0, col_winner = 0, diag_winner = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            if (board->board[i][j] == board->player) {
                row_winner = 1;
                break;
            }
        }
        if (row_winner == 1) {
            break;
        }
    }
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            if (board->board[j][i] == board->player) {
                col_winner = 1;
                break;
            }
        }
        if (col_winner == 1) {
            break;
        }
    }
    if (board->board[MAX_SIZE - 1][MAX_SIZE - 1] == board->player) {
        diag_winner = 1;
    }
    if (board->board[MAX_SIZE - 1][0] == board->player) {
        diag_winner = 1;
    }
    if (diag_winner == 1) {
        board->winner = 1;
    } else if (row_winner == 1 || col_winner == 1) {
        board->winner = 2;
    } else if (board->board[0][0] == board->board[1][1] && board->board[1][1] == board->board[2][2]) {
        board->winner = 3;
    } else if (board->board[0][2] == board->board[1][1] && board->board[1][1] == board->board[2][0]) {
        board->winner = 3;
    } else if (board->board[0][2] == board->board[1][1] && board->board[1][1] == board->board[2][1]) {
        board->winner = 3;
    } else {
        board->winner = 0;
    }
}

void *player_thread(void *arg) {
    TicTacToe *board = (TicTacToe*)arg;
    int row = rand() % MAX_SIZE, col = rand() % MAX_SIZE;
    while (board->winner == 0) {
        update_board(board, row, col, board->player);
        check_winner(board);
        if (board->winner!= 0) {
            break;
        }
        row = rand() % MAX_SIZE, col = rand() % MAX_SIZE;
    }
    return NULL;
}

int main() {
    TicTacToe *board = create_board();
    pthread_t thread[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++) {
        pthread_create(&thread[i], NULL, player_thread, board);
    }
    for (int i = 0; i < MAX_SIZE; i++) {
        pthread_join(thread[i], NULL);
    }
    printf("Game over\n");
    print_board(board);
    return 0;
}