//GEMINI-pro DATASET v1.0 Category: Chess AI ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8
#define PIECES     16

typedef struct {
    int x, y;
} Pos;

typedef struct {
    char type;
    Pos pos;
} Piece;

typedef struct {
    Piece pieces[PIECES];
    int turn;
} Board;

void initBoard(Board *board) {
    int i, j;

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board->pieces[i * BOARD_SIZE + j].type = ' ';
            board->pieces[i * BOARD_SIZE + j].pos.x = i;
            board->pieces[i * BOARD_SIZE + j].pos.y = j;
        }
    }

    // White pieces
    board->pieces[0].type = 'R';
    board->pieces[1].type = 'N';
    board->pieces[2].type = 'B';
    board->pieces[3].type = 'Q';
    board->pieces[4].type = 'K';
    board->pieces[5].type = 'B';
    board->pieces[6].type = 'N';
    board->pieces[7].type = 'R';
    for (i = 0; i < 8; i++) {
        board->pieces[i].pos.x = 1;
        board->pieces[i].pos.y = i;
    }

    // Black pieces
    board->pieces[8].type = 'r';
    board->pieces[9].type = 'n';
    board->pieces[10].type = 'b';
    board->pieces[11].type = 'q';
    board->pieces[12].type = 'k';
    board->pieces[13].type = 'b';
    board->pieces[14].type = 'n';
    board->pieces[15].type = 'r';
    for (i = 0; i < 8; i++) {
        board->pieces[i + 8].pos.x = 6;
        board->pieces[i + 8].pos.y = i;
    }

    board->turn = 0;
}

void printBoard(Board *board) {
    int i, j;

    printf("  a b c d e f g h\n");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", 8 - i);
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board->pieces[i * BOARD_SIZE + j].type);
        }
        printf("\n");
    }
    printf("\n");
}

int main(void) {
    Board board;
    char input[4];

    initBoard(&board);
    printBoard(&board);

    while (1) {
        printf("Enter your move (e.g. e2e4): ");
        fgets(input, sizeof(input), stdin);

        if (strlen(input) != 4) {
            printf("Invalid input. Please try again.\n");
            continue;
        }

        // Parse the input
        int fromX = input[0] - 'a';
        int fromY = 8 - (input[1] - '0');
        int toX = input[2] - 'a';
        int toY = 8 - (input[3] - '0');

        // Check if the move is valid
        if (!isValidMove(&board, fromX, fromY, toX, toY)) {
            printf("Invalid move. Please try again.\n");
            continue;
        }

        // Make the move
        makeMove(&board, fromX, fromY, toX, toY);

        // Print the board
        printBoard(&board);

        // Check if the game is over
        if (isGameOver(&board)) {
            printf("Game over. %s wins!\n", board.turn == 0 ? "White" : "Black");
            break;
        }

        // Switch turns
        board.turn = !board.turn;
    }

    return 0;
}