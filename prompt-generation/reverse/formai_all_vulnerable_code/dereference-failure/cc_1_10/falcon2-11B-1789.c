//Falcon2-11B DATASET v1.0 Category: Checkers Game ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BOARD_SIZE 8
#define MAX_MORIARTY 8
#define MAX_WATSON 8

typedef struct {
    int row;
    int col;
    char player;
} board_t;

void print_board(board_t *board, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%c", board[i].player);
    }
    printf("\n");
}

int is_legal_move(board_t *board, int move) {
    int row = move / BOARD_SIZE;
    int col = move % BOARD_SIZE;
    if (board[row].player == 'W' && board[row + 1].player == 'W') {
        if (col < BOARD_SIZE && board[row + 1].col!= col && board[row + 1].player == 'M') {
            return 1;
        }
    } else if (board[row].player == 'M' && board[row + 1].player == 'M') {
        if (col > 0 && board[row + 1].col!= col && board[row + 1].player == 'W') {
            return 1;
        }
    }
    return 0;
}

int main() {
    board_t board[BOARD_SIZE];
    int size = BOARD_SIZE;
    int move;
    int moriarty = 0;
    int watson = 0;
    int i;

    // Initialize board
    for (i = 0; i < size; i++) {
        board[i].player = 'M';
        board[i].row = i;
        board[i].col = 0;
    }

    while (1) {
        // Print board
        print_board(board, size);

        // Get move from user
        printf("Enter a move (row, col): ");
        scanf("%d", &move);

        // Check if move is legal
        if (is_legal_move(board, move)) {
            // Make move
            board[move].player = 'W';

            // Check for win
            for (i = 0; i < size; i++) {
                if (board[i].player == 'W') {
                    watson++;
                    break;
                } else if (board[i].player == 'M') {
                    moriarty++;
                    break;
                }
            }

            // Check for stalemate
            if (watson == size || moriarty == size) {
                break;
            }
        } else {
            printf("Illegal move!\n");
        }
    }

    // Print result
    printf("Game over!\n");
    printf("Watson: %d\n", watson);
    printf("Moriarty: %d\n", moriarty);
    return 0;
}