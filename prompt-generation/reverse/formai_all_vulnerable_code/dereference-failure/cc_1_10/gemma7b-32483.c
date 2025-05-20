//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: accurate
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define PLAYER_X 1
#define PLAYER_O 2

#define EMPTY_SPACE 0

typedef struct Board {
    int **board;
    int current_player;
    int game_status;
} Board;

Board *initialize_board() {
    Board *board = malloc(sizeof(Board));
    board->board = malloc(sizeof(int *) * BOARD_SIZE);
    for (int i = 0; i < BOARD_SIZE; i++) {
        board->board[i] = malloc(sizeof(int) * BOARD_SIZE);
        for (int j = 0; j < BOARD_SIZE; j++) {
            board->board[i][j] = EMPTY_SPACE;
        }
    }
    board->current_player = PLAYER_X;
    board->game_status = 0;
    return board;
}

void play_turn(Board *board, int x, int y) {
    if (board->board[x][y] != EMPTY_SPACE) {
        return;
    }
    board->board[x][y] = board->current_player;
    board->current_player = (board->current_player == PLAYER_X) ? PLAYER_O : PLAYER_X;
}

int check_win(Board *board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        // Check rows
        if (board->board[0][i] == board->board[1][i] && board->board[0][i] == board->board[2][i] && board->board[0][i] != EMPTY_SPACE) {
            return board->board[0][i];
        }
        // Check columns
        if (board->board[i][0] == board->board[i][1] && board->board[i][0] == board->board[i][2] && board->board[i][0] != EMPTY_SPACE) {
            return board->board[i][0];
        }
    }
    // Check diagonals
    if (board->board[0][0] == board->board[1][1] && board->board[0][0] == board->board[2][2] && board->board[0][0] != EMPTY_SPACE) {
        return board->board[0][0];
    }
    // No winner, draw
    return EMPTY_SPACE;
}

int main() {
    Board *board = initialize_board();
    play_turn(board, 1, 1);
    play_turn(board, 0, 0);
    play_turn(board, 2, 2);
    int winner = check_win(board);
    if (winner != EMPTY_SPACE) {
        printf("Winner: Player %d\n", winner);
    } else {
        printf("Draw\n");
    }
    return 0;
}