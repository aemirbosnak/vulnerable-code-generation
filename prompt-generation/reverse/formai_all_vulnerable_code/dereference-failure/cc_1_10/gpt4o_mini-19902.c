//GPT-4o-mini DATASET v1.0 Category: Chess AI ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8
#define WHITE_PAWN 'P'
#define BLACK_PAWN 'p'
#define EMPTY ' '
#define WHITE_KING 'K'
#define BLACK_KING 'k'
#define WHITE_QUEEN 'Q'
#define BLACK_QUEEN 'q'
#define WHITE_ROOK 'R'
#define BLACK_ROOK 'r'
#define WHITE_BISHOP 'B'
#define BLACK_BISHOP 'b'
#define WHITE_KNIGHT 'N'
#define BLACK_KNIGHT 'n'

typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
    int whiteToMove;
} GameState;

void initBoard(GameState *game);
void printBoard(const GameState *game);
int movePiece(GameState *game, int startX, int startY, int endX, int endY);
int isMoveValid(const GameState *game, int startX, int startY, int endX, int endY);
void getUserMove(int *startX, int *startY, int *endX, int *endY);

int main() {
    GameState game;
    initBoard(&game);
    int startX, startY, endX, endY;

    while (1) {
        printBoard(&game);
        printf("Player %s, enter your move (startX startY endX endY): ",
               game.whiteToMove ? "White" : "Black");
        getUserMove(&startX, &startY, &endX, &endY);

        if (movePiece(&game, startX, startY, endX, endY) == 1) {
            game.whiteToMove = !game.whiteToMove;
        } else {
            printf("Invalid move!\n");
        }
    }
    return 0;
}

void initBoard(GameState *game) {
    char initial[BOARD_SIZE][BOARD_SIZE] = {
        {BLACK_ROOK, BLACK_KNIGHT, BLACK_BISHOP, BLACK_QUEEN, BLACK_KING, BLACK_BISHOP, BLACK_KNIGHT, BLACK_ROOK},
        {BLACK_PAWN, BLACK_PAWN, BLACK_PAWN, BLACK_PAWN, BLACK_PAWN, BLACK_PAWN, BLACK_PAWN, BLACK_PAWN},
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {WHITE_PAWN, WHITE_PAWN, WHITE_PAWN, WHITE_PAWN, WHITE_PAWN, WHITE_PAWN, WHITE_PAWN, WHITE_PAWN},
        {WHITE_ROOK, WHITE_KNIGHT, WHITE_BISHOP, WHITE_QUEEN, WHITE_KING, WHITE_BISHOP, WHITE_KNIGHT, WHITE_ROOK}
    };
    
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            game->board[i][j] = initial[i][j];
        }
    }
    game->whiteToMove = 1; // White starts first
}

void printBoard(const GameState *game) {
    printf("\n  a b c d e f g h\n");
    printf(" +----------------+\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d|", 8 - i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", game->board[i][j]);
        }
        printf("|\n");
    }
    printf(" +----------------+\n");
}

int movePiece(GameState *game, int startX, int startY, int endX, int endY) {
    if (isMoveValid(game, startX, startY, endX, endY)) {
        game->board[endX][endY] = game->board[startX][startY];
        game->board[startX][startY] = EMPTY;
        return 1; // Move successful
    }
    return 0; // Move failed
}

int isMoveValid(const GameState *game, int startX, int startY, int endX, int endY) {
    char piece = game->board[startX][startY];
    char target = game->board[endX][endY];

    if (piece == EMPTY) return 0; // No piece to move
    if ((game->whiteToMove && piece >= 'a') || (!game->whiteToMove && piece <= 'Z')) return 0; // Wrong player's piece
    if ((target != EMPTY) && ((game->whiteToMove && target >= 'a') || (!game->whiteToMove && target <= 'Z'))) return 0; // Can't capture your own piece

    // Basic boundary checks
    if (endX < 0 || endX >= BOARD_SIZE || endY < 0 || endY >= BOARD_SIZE) return 0;

    // Additional logic for each piece type can be added here
    return 1;  // Allow for now
}

void getUserMove(int *startX, int *startY, int *endX, int *endY) {
    char startCol, endCol;
    int startRow, endRow;
    scanf(" %c%d %c%d", &startCol, &startRow, &endCol, &endRow);
    *startX = 8 - startRow; // Convert to array index
    *startY = startCol - 'a'; // Convert letter to index
    *endX = 8 - endRow; // Convert to array index
    *endY = endCol - 'a'; // Convert letter to index
}