//GEMINI-pro DATASET v1.0 Category: Chess AI ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    char piece;
    Position position;
    int value;
} Piece;

typedef struct {
    Piece pieces[BOARD_SIZE][BOARD_SIZE];
    int turn;
    int winner;
} Board;

void printBoard(Board* board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board->pieces[i][j].piece);
        }
        printf("\n");
    }
}

int main() {
    Board* board = malloc(sizeof(Board));

    // Initialize the board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board->pieces[i][j].piece = ' ';
            board->pieces[i][j].position.x = i;
            board->pieces[i][j].position.y = j;
            board->pieces[i][j].value = 0;
        }
    }

    // Place the pieces on the board
    board->pieces[0][0].piece = 'R';
    board->pieces[0][1].piece = 'N';
    board->pieces[0][2].piece = 'B';
    board->pieces[0][3].piece = 'Q';
    board->pieces[0][4].piece = 'K';
    board->pieces[0][5].piece = 'B';
    board->pieces[0][6].piece = 'N';
    board->pieces[0][7].piece = 'R';
    for (int i = 0; i < BOARD_SIZE; i++) {
        board->pieces[1][i].piece = 'P';
        board->pieces[6][i].piece = 'p';
    }

    // Set the turn
    board->turn = 0;

    // Play the game
    while (board->winner == 0) {
        // Get the player's move
        Position from;
        Position to;
        printf("Enter your move: ");
        scanf("%d %d %d %d", &from.x, &from.y, &to.x, &to.y);

        // Make the move
        board->pieces[to.x][to.y] = board->pieces[from.x][from.y];
        board->pieces[from.x][from.y].piece = ' ';

        // Check if the game is over
        if (board->pieces[to.x][to.y].piece == 'K') {
            board->winner = 1;
        }

        // Switch turns
        board->turn = 1 - board->turn;
    }

    // Print the winner
    if (board->winner == 1) {
        printf("White wins!\n");
    } else {
        printf("Black wins!\n");
    }

    return 0;
}