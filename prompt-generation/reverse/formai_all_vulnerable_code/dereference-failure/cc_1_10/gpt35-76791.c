//FormAI DATASET v1.0 Category: Chess engine ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define KNIGHT 1
#define BISHOP 2
#define ROOK 3
#define QUEEN 4
#define KING 5
#define PAWN 6

#define BLACK 0
#define WHITE 1

#define ROWS 8
#define COLS 8

typedef struct {
    int row;
    int col;
} Position;

typedef struct {
    int type;
    int color;
    char symbol;
} Piece;

typedef struct {
    Piece* board[ROWS][COLS];
} ChessBoard;

void init_board(ChessBoard* board);
void print_board(ChessBoard* board);

void init_board(ChessBoard* board) 
{
    Piece* white_pieces[COLS];
    Piece* black_pieces[COLS];

    //initialize white pieces
    white_pieces[0] = malloc(sizeof(Piece)); white_pieces[0]->type = ROOK; white_pieces[0]->color = WHITE; white_pieces[0]->symbol = 'R';
    white_pieces[1] = malloc(sizeof(Piece)); white_pieces[1]->type = KNIGHT; white_pieces[1]->color = WHITE; white_pieces[1]->symbol = 'N';
    white_pieces[2] = malloc(sizeof(Piece)); white_pieces[2]->type = BISHOP; white_pieces[2]->color = WHITE; white_pieces[2]->symbol = 'B';
    white_pieces[3] = malloc(sizeof(Piece)); white_pieces[3]->type = QUEEN; white_pieces[3]->color = WHITE; white_pieces[3]->symbol = 'Q';
    white_pieces[4] = malloc(sizeof(Piece)); white_pieces[4]->type = KING; white_pieces[4]->color = WHITE; white_pieces[4]->symbol = 'K';
    white_pieces[5] = malloc(sizeof(Piece)); white_pieces[5]->type = BISHOP; white_pieces[5]->color = WHITE; white_pieces[5]->symbol = 'B';
    white_pieces[6] = malloc(sizeof(Piece)); white_pieces[6]->type = KNIGHT; white_pieces[6]->color = WHITE; white_pieces[6]->symbol = 'N';
    white_pieces[7] = malloc(sizeof(Piece)); white_pieces[7]->type = ROOK; white_pieces[7]->color = WHITE; white_pieces[7]->symbol = 'R';

    //initialize black pieces
    black_pieces[0] = malloc(sizeof(Piece)); black_pieces[0]->type = ROOK; black_pieces[0]->color = BLACK; black_pieces[0]->symbol = 'r';
    black_pieces[1] = malloc(sizeof(Piece)); black_pieces[1]->type = KNIGHT; black_pieces[1]->color = BLACK; black_pieces[1]->symbol = 'n';
    black_pieces[2] = malloc(sizeof(Piece)); black_pieces[2]->type = BISHOP; black_pieces[2]->color = BLACK; black_pieces[2]->symbol = 'b';
    black_pieces[3] = malloc(sizeof(Piece)); black_pieces[3]->type = QUEEN; black_pieces[3]->color = BLACK; black_pieces[3]->symbol = 'q';
    black_pieces[4] = malloc(sizeof(Piece)); black_pieces[4]->type = KING; black_pieces[4]->color = BLACK; black_pieces[4]->symbol = 'k';
    black_pieces[5] = malloc(sizeof(Piece)); black_pieces[5]->type = BISHOP; black_pieces[5]->color = BLACK; black_pieces[5]->symbol = 'b';
    black_pieces[6] = malloc(sizeof(Piece)); black_pieces[6]->type = KNIGHT; black_pieces[6]->color = BLACK; black_pieces[6]->symbol = 'n';
    black_pieces[7] = malloc(sizeof(Piece)); black_pieces[7]->type = ROOK; black_pieces[7]->color = BLACK; black_pieces[7]->symbol = 'r';

    //initialize remaining pieces with nulls
    for(int row=2; row<=5; row++) {
        for(int col=0; col<COLS; col++) {
            board->board[row][col] = NULL;
        }
    }

    //place white pawns
    for(int col=0; col<COLS; col++) {
        Piece* pawn = malloc(sizeof(Piece));
        pawn->type = PAWN; pawn->color = WHITE; pawn->symbol = 'P';
        board->board[1][col] = pawn;
    }

    //place black pawns
    for(int col=0; col<COLS; col++) {
        Piece* pawn = malloc(sizeof(Piece));
        pawn->type = PAWN; pawn->color = BLACK; pawn->symbol = 'p';
        board->board[6][col] = pawn;
    }

    //place remaining pieces
    for(int col=0; col<COLS; col++) {
        board->board[0][col] = white_pieces[col];
        board->board[7][col] = black_pieces[col];
    }
}

void print_board(ChessBoard* board) 
{
    printf("\n     A  B  C  D  E  F  G  H");
    for(int r=0; r<ROWS; r++) {
        printf("\n   -------------------------\n%d |", (ROWS - r));
        for(int c=0; c<COLS; c++) {
            if(board->board[r][c] != NULL) {
                printf(" %c ", board->board[r][c]->symbol);
            } else {
                printf("   ");
            }
            printf("|");
        }
    }
    printf("\n   -------------------------\n");
}

int main() 
{
    ChessBoard board;
    init_board(&board);
    print_board(&board);
    return 0;
}