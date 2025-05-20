//GPT-4o-mini DATASET v1.0 Category: Chess engine ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 8

// Enum to represent pieces
typedef enum { EMPTY, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING } Piece;

// Struct to represent a square on the board
typedef struct {
    Piece piece;
    int color; // 0 for white, 1 for black
} Square;

// Function prototypes
void initializeBoard(Square board[SIZE][SIZE]);
void printBoard(Square board[SIZE][SIZE]);
int movePiece(Square board[SIZE][SIZE], const char *from, const char *to);
int isValidMove(Square board[SIZE][SIZE], const char *from, const char *to);
void convertToChessNotation(int x, int y, char *notation);
void getPositionInput(char *input);

int main() {
    Square board[SIZE][SIZE];
    char moveFrom[3], moveTo[3];

    initializeBoard(board);
    printBoard(board);

    while (1) {
        printf("Enter your move (from to): ");
        getPositionInput(moveFrom);
        getPositionInput(moveTo);

        if (movePiece(board, moveFrom, moveTo)) {
            printBoard(board);
        } else {
            printf("Invalid Move. Try Again.\n");
        }
    }
    
    return 0;
}

// Function to initialize the chess board
void initializeBoard(Square board[SIZE][SIZE]) {
    // Initialize all squares to empty
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j].piece = EMPTY;
            board[i][j].color = -1; // -1 means no color (empty)
        }
    }

    // Place pieces for both players
    board[0][0].piece = ROOK;    board[0][0].color = 1;
    board[0][1].piece = KNIGHT;  board[0][1].color = 1;
    board[0][2].piece = BISHOP;  board[0][2].color = 1;
    board[0][3].piece = QUEEN;   board[0][3].color = 1;
    board[0][4].piece = KING;    board[0][4].color = 1;
    board[0][5].piece = BISHOP;  board[0][5].color = 1;
    board[0][6].piece = KNIGHT;  board[0][6].color = 1;
    board[0][7].piece = ROOK;    board[0][7].color = 1;

    for (int j = 0; j < SIZE; j++) {
        board[1][j].piece = PAWN;
        board[1][j].color = 1; // All white pawns
        board[6][j].piece = PAWN;
        board[6][j].color = 0; // All black pawns
    }

    board[7][0].piece = ROOK;    board[7][0].color = 0;
    board[7][1].piece = KNIGHT;  board[7][1].color = 0;
    board[7][2].piece = BISHOP;  board[7][2].color = 0;
    board[7][3].piece = QUEEN;   board[7][3].color = 0;
    board[7][4].piece = KING;    board[7][4].color = 0;
    board[7][5].piece = BISHOP;  board[7][5].color = 0;
    board[7][6].piece = KNIGHT;  board[7][6].color = 0;
    board[7][7].piece = ROOK;    board[7][7].color = 0;
}

// Function to print the chess board
void printBoard(Square board[SIZE][SIZE]) {
    for (int i = SIZE - 1; i >= 0; i--) {
        for (int j = 0; j < SIZE; j++) {
            switch (board[i][j].piece) {
                case PAWN:   printf("P "); break;
                case KNIGHT: printf("N "); break;
                case BISHOP: printf("B "); break;
                case ROOK:   printf("R "); break;
                case QUEEN:  printf("Q "); break;
                case KING:   printf("K "); break;
                default:     printf(". "); break; // Empty square
            }
        }
        printf("%d\n", i + 1); // Print row number
    }
    printf(" a b c d e f g h\n"); // Print column letters
}

// Function to move a piece from one square to another
int movePiece(Square board[SIZE][SIZE], const char *from, const char *to) {
    int fromX = from[0] - 'a';
    int fromY = from[1] - '1';
    int toX = to[0] - 'a';
    int toY = to[1] - '1';

    // Check for valid move
    if (isValidMove(board, from, to)) {
        board[toY][toX] = board[fromY][fromX]; // Move piece
        board[fromY][fromX].piece = EMPTY; // Empty original square
        return 1; // Move successful
    }
    return 0; // Move unsuccessful
}

// Function to check if a move is valid
int isValidMove(Square board[SIZE][SIZE], const char *from, const char *to) {
    // Implementation of specific rules can be added here
    return 1; // Placeholder: all moves are valid for simplicity
}

// Function to convert board coordinates to chess notation
void convertToChessNotation(int x, int y, char *notation) {
    notation[0] = 'a' + x;
    notation[1] = '1' + y;
    notation[2] = '\0';
}

// Function to get move position input
void getPositionInput(char *input) {
    fgets(input, 3, stdin);
    while (getchar() != '\n'); // Clear newline
}