//GPT-4o-mini DATASET v1.0 Category: Chess engine ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8
#define EMPTY '.'

// Enum for pieces
typedef enum { PAWN, ROOK, KNIGHT, BISHOP, QUEEN, KING, NONE } PieceType;
typedef enum { WHITE, BLACK } Color;

// Struct for a piece
typedef struct {
    PieceType type;
    Color color;
} Piece;

// Board representation
typedef struct {
    Piece *squares[BOARD_SIZE][BOARD_SIZE];
} Board;

// Function to initialize the chess board
void initialize_board(Board *board) {
    const char *initial_setup[8] = {
        "rnbqkbnr",
        "pppppppp",
        "........",
        "........",
        "........",
        "........",
        "PPPPPPPP",
        "RNBQKBNR"
    };

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board->squares[i][j] = NULL;
            char piece = initial_setup[i][j];
            if (piece != '.') {
                Piece *new_piece = (Piece *)malloc(sizeof(Piece));
                new_piece->color = (piece >= 'a') ? BLACK : WHITE;
                new_piece->type = (piece >= 'a') ? (piece - 'a') : (piece - 'A');
                board->squares[i][j] = new_piece;
            }
        }
    }
}

// Function to display the chess board
void display_board(Board *board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board->squares[i][j] != NULL) {
                char piece_char = (board->squares[i][j]->color == WHITE) ?
                                  (board->squares[i][j]->type + 'A') :
                                  (board->squares[i][j]->type + 'a');
                printf("%c ", piece_char);
            } else {
                printf("%c ", EMPTY);
            }
        }
        printf("\n");
    }
}

// Function to free the board
void free_board(Board *board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            free(board->squares[i][j]);
        }
    }
}

// Main game loop
int main() {
    Board board;
    initialize_board(&board);
    
    char command[100];
    while (1) {
        display_board(&board);
        printf("Enter your command (e.g., 'move e2 e4' or 'quit'): ");
        fgets(command, sizeof(command), stdin);

        if (strncmp(command, "quit", 4) == 0) {
            break;
        }
        // Here we can later parse the command to move pieces
    }

    free_board(&board);
    return 0;
}