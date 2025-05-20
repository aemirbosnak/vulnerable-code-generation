//Gemma-7B DATASET v1.0 Category: Checkers Game ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX_BOARD_SIZE 8

typedef struct Board {
    int **board;
    int turn;
    int winner;
} Board;

void initializeBoard(Board *board) {
    board->board = (int **)malloc(MAX_BOARD_SIZE * sizeof(int *));
    for (int i = 0; i < MAX_BOARD_SIZE; i++) {
        board->board[i] = (int *)malloc(MAX_BOARD_SIZE * sizeof(int));
    }
    board->turn = 0;
    board->winner = -1;
}

void displayBoard(Board *board) {
    for (int i = 0; i < MAX_BOARD_SIZE; i++) {
        for (int j = 0; j < MAX_BOARD_SIZE; j++) {
            printf("%d ", board->board[i][j]);
        }
        printf("\n");
    }
}

int movePiece(Board *board, int x, int y, int direction) {
    if (board->board[x][y] == 0 || board->board[x][y] != board->turn) {
        return 0;
    }

    switch (direction) {
        case 0:
            board->board[x][y] = 0;
            break;
        case 1:
            if (board->board[x + 1][y] == 0) {
                board->board[x + 1][y] = board->turn;
                board->board[x][y] = 0;
            }
            break;
        case 2:
            if (board->board[x - 1][y] == 0) {
                board->board[x - 1][y] = board->turn;
                board->board[x][y] = 0;
            }
            break;
        case 3:
            if (board->board[x][y + 1] == 0) {
                board->board[x][y + 1] = board->turn;
                board->board[x][y] = 0;
            }
            break;
        case 4:
            if (board->board[x][y - 1] == 0) {
                board->board[x][y - 1] = board->turn;
                board->board[x][y] = 0;
            }
            break;
    }

    board->turn = (board->turn == 0) ? 1 : 0;

    return 1;
}

int main() {
    Board board;
    initializeBoard(&board);

    // Game loop
    while (board.winner == -1) {
        displayBoard(&board);

        // Get move from player
        int x, y, direction;
        printf("Enter move (x, y, direction): ");
        scanf("%d %d %d", &x, &y, &direction);

        // Move piece
        if (movePiece(&board, x, y, direction) == 0) {
            printf("Invalid move.\n");
        }
    }

    displayBoard(&board);

    printf("Winner: %d\n", board.winner);

    return 0;
}