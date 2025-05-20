//GEMINI-pro DATASET v1.0 Category: Checkers Game ; Style: ephemeral
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BOARD_WIDTH 8
#define BOARD_HEIGHT 8

// Board squares
#define SQUARE_EMPTY 0
#define SQUARE_BLACK 1
#define SQUARE_WHITE 2

// Piece types
#define PIECE_PAWN 0
#define PIECE_KING 1

// Constants
#define INVALID_MOVE -1

// Types
typedef struct Piece {
    int type;
    int color;
    int x;
    int y;
} Piece;

typedef struct Board {
    Piece pieces[BOARD_WIDTH][BOARD_HEIGHT];
} Board;

// Functions
int is_valid_move(Board *board, Piece *piece, int new_x, int new_y);
void make_move(Board *board, Piece *piece, int new_x, int new_y);
void print_board(Board *board);

int main() {
    // Initialize the board
    Board board;
    memset(&board, 0, sizeof(Board));

    // Set up the initial board position
    for (int x = 0; x < BOARD_WIDTH; x++) {
        for (int y = 0; y < BOARD_HEIGHT; y++) {
            if ((x % 2 == 0 && y % 2 == 1) || (x % 2 == 1 && y % 2 == 0)) {
                if (y < 3) {
                    board.pieces[x][y].type = PIECE_PAWN;
                    board.pieces[x][y].color = SQUARE_BLACK;
                } else if (y > 4) {
                    board.pieces[x][y].type = PIECE_PAWN;
                    board.pieces[x][y].color = SQUARE_WHITE;
                }
            }
        }
    }

    // Print the initial board position
    print_board(&board);

    // Get the player's move
    int x1, y1, x2, y2;
    printf("Enter the coordinates of the piece you want to move (x1, y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter the coordinates of the square you want to move to (x2, y2): ");
    scanf("%d %d", &x2, &y2);

    // Validate the move
    Piece *piece = &board.pieces[x1][y1];
    int valid_move = is_valid_move(&board, piece, x2, y2);

    // Make the move
    if (valid_move) {
        make_move(&board, piece, x2, y2);
    } else {
        printf("Invalid move.\n");
    }

    // Print the board after the move
    print_board(&board);

    return 0;
}

int is_valid_move(Board *board, Piece *piece, int new_x, int new_y) {
    // Check if the new square is on the board
    if (new_x < 0 || new_x >= BOARD_WIDTH || new_y < 0 || new_y >= BOARD_HEIGHT) {
        return INVALID_MOVE;
    }

    // Check if the new square is empty
    if (board->pieces[new_x][new_y].color != SQUARE_EMPTY) {
        return INVALID_MOVE;
    }

    // Check if the move is diagonal
    if (abs(new_x - piece->x) != abs(new_y - piece->y)) {
        return INVALID_MOVE;
    }

    // Check if the move is forward for the piece's color
    if (piece->color == SQUARE_BLACK && new_y < piece->y) {
        return INVALID_MOVE;
    } else if (piece->color == SQUARE_WHITE && new_y > piece->y) {
        return INVALID_MOVE;
    }

    // Check if the move is a king move
    if (piece->type == PIECE_KING) {
        return 1;
    }

    // Check if the move is a double jump
    if (abs(new_x - piece->x) == 2 && abs(new_y - piece->y) == 2) {
        int jump_x = (new_x + piece->x) / 2;
        int jump_y = (new_y + piece->y) / 2;
        if (board->pieces[jump_x][jump_y].color == piece->color) {
            return INVALID_MOVE;
        }
    }

    return 1;
}

void make_move(Board *board, Piece *piece, int new_x, int new_y) {
    // Move the piece to the new square
    board->pieces[new_x][new_y] = *piece;

    // Remove the piece from its old square
    board->pieces[piece->x][piece->y].color = SQUARE_EMPTY;

    // Check if the piece has reached the opposite side of the board
    if (piece->color == SQUARE_BLACK && new_y == 0) {
        piece->type = PIECE_KING;
    } else if (piece->color == SQUARE_WHITE && new_y == BOARD_HEIGHT - 1) {
        piece->type = PIECE_KING;
    }

    // Update the piece's coordinates
    piece->x = new_x;
    piece->y = new_y;
}

void print_board(Board *board) {
    printf("  ");
    for (int x = 0; x < BOARD_WIDTH; x++) {
        printf("%d ", x);
    }
    printf("\n");

    for (int y = 0; y < BOARD_HEIGHT; y++) {
        printf("%d ", y);
        for (int x = 0; x < BOARD_WIDTH; x++) {
            switch (board->pieces[x][y].color) {
                case SQUARE_EMPTY:
                    printf("  ");
                    break;
                case SQUARE_BLACK:
                    printf("b ");
                    break;
                case SQUARE_WHITE:
                    printf("w ");
                    break;
            }
        }
        printf("\n");
    }
}