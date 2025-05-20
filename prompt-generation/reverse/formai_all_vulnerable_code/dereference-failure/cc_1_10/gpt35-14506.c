//FormAI DATASET v1.0 Category: Chess engine ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

// struct to store a chess position
typedef struct {
    char board[8][8]; // the chess board
    char curr_player; // current player
} ChessPosition;

// function to initialize the board with starting positions
void init_board(ChessPosition *cp) {
    // initialize the player
    cp->curr_player = 'W';

    // initialize the board with starting positions
    char board[8][8] = {
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
        {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
        {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
        {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
    };

    // copy the board to cp->board
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            cp->board[i][j] = board[i][j];
        }
    }
}

// function to print the board
void print_board(ChessPosition *cp) {
    for(int i=0; i<8; i++) {
        printf("%d ", 8-i); // print the row number
        for(int j=0; j<8; j++) {
            printf("%c ", cp->board[i][j]); // print the piece
        }
        printf("\n");
    }
    printf("  a b c d e f g h\n"); // print the column letters
}

// function to update the board after a move
void make_move(ChessPosition *cp, int srow, int scol, int erow, int ecol) {
    // move the piece
    cp->board[erow][ecol] = cp->board[srow][scol];
    cp->board[srow][scol] = ' ';

    // switch players
    if(cp->curr_player == 'W') {
        cp->curr_player = 'B';
    } else {
        cp->curr_player = 'W';
    }
}

// function to get the move from the player
void get_move(ChessPosition *cp, int *srow, int *scol, int *erow, int *ecol) {
    char start[3];
    char end[3];
    printf("%c's turn to move.\n", cp->curr_player);
    printf("Enter the starting position (e.g. b2): ");
    scanf("%s", start);
    printf("Enter the ending position (e.g. b4): ");
    scanf("%s", end);
    *srow = 8 - (start[1] - '0');
    *scol = start[0] - 'a';
    *erow = 8 - (end[1] - '0');
    *ecol = end[0] - 'a';
}

int main(void) {
    ChessPosition cp;
    init_board(&cp);
    int srow, scol, erow, ecol;
    while(1) {
        print_board(&cp);
        get_move(&cp, &srow, &scol, &erow, &ecol);
        make_move(&cp, srow, scol, erow, ecol);
    }
    return 0;
}