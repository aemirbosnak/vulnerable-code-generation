//FormAI DATASET v1.0 Category: Chess AI ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8
#define MAX_DEPTH 4

#define PAWN_VALUE 1
#define KNIGHT_VALUE 3
#define BISHOP_VALUE 3
#define ROOK_VALUE 5
#define QUEEN_VALUE 9
#define KING_VALUE 0

typedef enum { BLACK, WHITE } Color;
typedef enum { PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING } Piece;

typedef struct {
   Piece pieceType;
   Color color;
} ChessPiece;

typedef struct {
   ChessPiece piece;
   int row;
   int col;
} ChessSquare;

typedef struct ChessMove {
   ChessSquare from;
   ChessSquare to;
} ChessMove;

typedef struct {
   ChessPiece board[BOARD_SIZE][BOARD_SIZE];
   Color currentPlayer;
   int moveCount;
} ChessGame;

typedef struct ChessTreeNode {
   ChessGame *game;
   ChessMove *move;
   struct ChessTreeNode *children[MAX_DEPTH];
   int numChildren;
} ChessTreeNode;

ChessPiece createPiece(Piece pieceType, Color color) {
   ChessPiece piece;
   piece.pieceType = pieceType;
   piece.color = color;
   return piece;
}

void initializeBoard(ChessGame *game) {
   // set up pawns
   for (int i = 0; i < BOARD_SIZE; i++) {
      game->board[1][i] = createPiece(PAWN, BLACK);
      game->board[6][i] = createPiece(PAWN, WHITE);
   }

   // set up non-pawns
   game->board[0][0] = createPiece(ROOK, BLACK);
   game->board[0][1] = createPiece(KNIGHT, BLACK);
   game->board[0][2] = createPiece(BISHOP, BLACK);
   game->board[0][3] = createPiece(QUEEN, BLACK);
   game->board[0][4] = createPiece(KING, BLACK);
   game->board[0][5] = createPiece(BISHOP, BLACK);
   game->board[0][6] = createPiece(KNIGHT, BLACK);
   game->board[0][7] = createPiece(ROOK, BLACK);

   game->board[7][0] = createPiece(ROOK, WHITE);
   game->board[7][1] = createPiece(KNIGHT, WHITE);
   game->board[7][2] = createPiece(BISHOP, WHITE);
   game->board[7][3] = createPiece(QUEEN, WHITE);
   game->board[7][4] = createPiece(KING, WHITE);
   game->board[7][5] = createPiece(BISHOP, WHITE);
   game->board[7][6] = createPiece(KNIGHT, WHITE);
   game->board[7][7] = createPiece(ROOK, WHITE);

   // set current player to white
   game->currentPlayer = WHITE;
}

int evaluate(ChessGame *game) {
   int sum = 0;
   for (int i = 0; i < BOARD_SIZE; i++) {
      for (int j = 0; j < BOARD_SIZE; j++) {
         ChessPiece piece = game->board[i][j];
         if (piece.pieceType == PAWN) {
            sum += (piece.color == WHITE ? 1 : -1) * PAWN_VALUE;
         } else if (piece.pieceType == KNIGHT) {
            sum += (piece.color == WHITE ? 1 : -1) * KNIGHT_VALUE;
         } else if (piece.pieceType == BISHOP) {
            sum += (piece.color == WHITE ? 1 : -1) * BISHOP_VALUE;
         } else if (piece.pieceType == ROOK) {
            sum += (piece.color == WHITE ? 1 : -1) * ROOK_VALUE;
         } else if (piece.pieceType == QUEEN) {
            sum += (piece.color == WHITE ? 1 : -1) * QUEEN_VALUE;
         } else if (piece.pieceType == KING) {
            sum += (piece.color == WHITE ? 1 : -1) * KING_VALUE;
         }
      }
   }
   return sum;
}

void printBoard(ChessGame *game) {
   for (int i = 0; i < BOARD_SIZE; i++) {
      for (int j = 0; j < BOARD_SIZE; j++) {
         if (game->board[i][j].pieceType == KING) {
            printf("* ");
         } else {
            printf("%c ", game->board[i][j].color == WHITE ? 'W' : 'B');
         }
      }
      printf("\n");
   }
}

void copyBoard(ChessGame *source, ChessGame *target) {
   memcpy(target, source, sizeof(ChessGame));
}

void getMoves(ChessGame *game, ChessSquare square, ChessMove **moves, int *numMoves) {
   *moves = malloc(sizeof(ChessMove) * BOARD_SIZE * BOARD_SIZE);
   *numMoves = 0;
   // todo: implement move generation
}

ChessTreeNode *createTreeNode(ChessGame *game, ChessMove *move) {
   ChessTreeNode *node = malloc(sizeof(ChessTreeNode));
   node->game = malloc(sizeof(ChessGame));
   copyBoard(game, node->game);
   node->move = move;
   node->numChildren = 0;
   return node;
}

void addChild(ChessTreeNode *parent, ChessTreeNode *child) {
   parent->children[parent->numChildren] = child;
   parent->numChildren++;
}

int main() {
   ChessGame *game = malloc(sizeof(ChessGame));
   ChessMove *moves;
   int numMoves;
   initializeBoard(game);
   printBoard(game);
   getMoves(game, (ChessSquare){.row=1, .col=0}, &moves, &numMoves);
   for (int i = 0; i < numMoves; i++) {
      printf("(%d,%d) -> (%d,%d)\n", moves[i].from.row, moves[i].from.col, moves[i].to.row, moves[i].to.col);
   }
   return 0;
}