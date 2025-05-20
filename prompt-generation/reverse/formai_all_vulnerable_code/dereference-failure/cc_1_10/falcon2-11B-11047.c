//Falcon2-11B DATASET v1.0 Category: Checkers Game ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define PLAYER_BLACK 1
#define PLAYER_RED 2

typedef struct {
    int x;
    int y;
    int player;
} Move;

typedef struct {
    Move* moves;
    int num_moves;
    bool game_over;
    int winner;
} Board;

void print_board(Board* board) {
    for (int i = 0; i < board->num_moves; i++) {
        printf("%d ", board->moves[i].player);
    }
    printf("\n");
}

void move_piece(Board* board, Move* move) {
    if (board->game_over) {
        printf("Game over!\n");
        return;
    }

    if (board->winner!= 0) {
        printf("Player %d wins!\n", board->winner);
        return;
    }

    if (board->num_moves < 8) {
        if (move->player == PLAYER_BLACK) {
            board->moves[board->num_moves].x = move->x - 1;
            board->moves[board->num_moves].y = move->y;
            board->moves[board->num_moves].player = board->winner;
        } else if (move->player == PLAYER_RED) {
            board->moves[board->num_moves].x = move->x + 1;
            board->moves[board->num_moves].y = move->y;
            board->moves[board->num_moves].player = board->winner;
        }
        board->num_moves++;
    }
}

void clear_board(Board* board) {
    board->num_moves = 0;
    board->game_over = false;
    board->winner = 0;
}

int main() {
    Board board;
    board.moves = NULL;
    board.num_moves = 0;
    board.game_over = false;
    board.winner = 0;

    Move move;
    move.x = 0;
    move.y = 0;
    move.player = PLAYER_RED;

    clear_board(&board);

    while (!board.game_over) {
        printf("Enter the coordinates of the piece you want to move (x,y): ");
        scanf("%d %d", &move.x, &move.y);

        move_piece(&board, &move);

        print_board(&board);
    }

    return 0;
}