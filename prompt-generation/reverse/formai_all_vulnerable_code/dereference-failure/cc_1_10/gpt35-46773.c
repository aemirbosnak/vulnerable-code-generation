//FormAI DATASET v1.0 Category: Chess AI ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define BOARD_LENGTH 8 // Chess board is 8x8
#define WHITE_TURN true
#define BLACK_TURN false

// Struct to represent each piece on the board
typedef struct {
    int x;
    int y;
    bool color; // true for white, false for black
    char type;
} Piece;

// Struct to represent the board
typedef struct {
    Piece *pieces[BOARD_LENGTH][BOARD_LENGTH];
} Board;

// Function to initialize the board with starting configurations
Board *initialize_board() {
    Board *board = malloc(sizeof(Board));
    // Placing all pawns on the board
    for(int i = 0; i < BOARD_LENGTH; i++) {
        board->pieces[1][i] = malloc(sizeof(Piece));
        board->pieces[1][i]->x = i;
        board->pieces[1][i]->y = 1;
        board->pieces[1][i]->color = BLACK_TURN;
        board->pieces[1][i]->type = 'P';
        board->pieces[6][i] = malloc(sizeof(Piece));
        board->pieces[6][i]->x = i;
        board->pieces[6][i]->y = 6;
        board->pieces[6][i]->color = WHITE_TURN;
        board->pieces[6][i]->type = 'P';
    }
    // Placing all other pieces on the board
    board->pieces[0][0] = malloc(sizeof(Piece));
    board->pieces[0][0]->x = 0;
    board->pieces[0][0]->y = 0;
    board->pieces[0][0]->color = BLACK_TURN;
    board->pieces[0][0]->type = 'R';
    board->pieces[0][7] = malloc(sizeof(Piece));
    board->pieces[0][7]->x = 7;
    board->pieces[0][7]->y = 0;
    board->pieces[0][7]->color = BLACK_TURN;
    board->pieces[0][7]->type = 'R';
    board->pieces[7][0] = malloc(sizeof(Piece));
    board->pieces[7][0]->x = 0;
    board->pieces[7][0]->y = 7;
    board->pieces[7][0]->color = WHITE_TURN;
    board->pieces[7][0]->type = 'R';
    board->pieces[7][7] = malloc(sizeof(Piece));
    board->pieces[7][7]->x = 7;
    board->pieces[7][7]->y = 7;
    board->pieces[7][7]->color = WHITE_TURN;
    board->pieces[7][7]->type = 'R';
    board->pieces[0][1] = malloc(sizeof(Piece));
    board->pieces[0][1]->x = 1;
    board->pieces[0][1]->y = 0;
    board->pieces[0][1]->color = BLACK_TURN;
    board->pieces[0][1]->type = 'N';
    board->pieces[0][6] = malloc(sizeof(Piece));
    board->pieces[0][6]->x = 6;
    board->pieces[0][6]->y = 0;
    board->pieces[0][6]->color = BLACK_TURN;
    board->pieces[0][6]->type = 'N';
    board->pieces[7][1] = malloc(sizeof(Piece));
    board->pieces[7][1]->x = 1;
    board->pieces[7][1]->y = 7;
    board->pieces[7][1]->color = WHITE_TURN;
    board->pieces[7][1]->type = 'N';
    board->pieces[7][6] = malloc(sizeof(Piece));
    board->pieces[7][6]->x = 6;
    board->pieces[7][6]->y = 7;
    board->pieces[7][6]->color = WHITE_TURN;
    board->pieces[7][6]->type = 'N';
    board->pieces[0][2] = malloc(sizeof(Piece));
    board->pieces[0][2]->x = 2;
    board->pieces[0][2]->y = 0;
    board->pieces[0][2]->color = BLACK_TURN;
    board->pieces[0][2]->type = 'B';
    board->pieces[0][5] = malloc(sizeof(Piece));
    board->pieces[0][5]->x = 5;
    board->pieces[0][5]->y = 0;
    board->pieces[0][5]->color = BLACK_TURN;
    board->pieces[0][5]->type = 'B';
    board->pieces[7][2] = malloc(sizeof(Piece));
    board->pieces[7][2]->x = 2;
    board->pieces[7][2]->y = 7;
    board->pieces[7][2]->color = WHITE_TURN;
    board->pieces[7][2]->type = 'B';
    board->pieces[7][5] = malloc(sizeof(Piece));
    board->pieces[7][5]->x = 5;
    board->pieces[7][5]->y = 7;
    board->pieces[7][5]->color = WHITE_TURN;
    board->pieces[7][5]->type = 'B';
    board->pieces[0][3] = malloc(sizeof(Piece));
    board->pieces[0][3]->x = 3;
    board->pieces[0][3]->y = 0;
    board->pieces[0][3]->color = BLACK_TURN;
    board->pieces[0][3]->type = 'Q';
    board->pieces[7][3] = malloc(sizeof(Piece));
    board->pieces[7][3]->x = 3;
    board->pieces[7][3]->y = 7;
    board->pieces[7][3]->color = WHITE_TURN;
    board->pieces[7][3]->type = 'Q';
    board->pieces[0][4] = malloc(sizeof(Piece));
    board->pieces[0][4]->x = 4;
    board->pieces[0][4]->y = 0;
    board->pieces[0][4]->color = BLACK_TURN;
    board->pieces[0][4]->type = 'K';
    board->pieces[7][4] = malloc(sizeof(Piece));
    board->pieces[7][4]->x = 4;
    board->pieces[7][4]->y = 7;
    board->pieces[7][4]->color = WHITE_TURN;
    board->pieces[7][4]->type = 'K';
    // Placing empty spaces on the board
    for(int i = 2; i < 6; i++) {
        for(int j = 0; j < BOARD_LENGTH; j++) {
            board->pieces[i][j] = NULL;
        }
    }
    return board;
}

// Function to print the board at any given time
void print_board(Board *board) {
    for(int i = 0; i < BOARD_LENGTH; i++) {
        for(int j = 0; j < BOARD_LENGTH; j++) {
            if(board->pieces[i][j] != NULL) {
                printf("%c ", board->pieces[i][j]->type);
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

int main(void) {
    Board *board = initialize_board();
    print_board(board);
    return 0;
}