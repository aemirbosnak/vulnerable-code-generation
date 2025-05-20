//FormAI DATASET v1.0 Category: Chess AI ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 8

typedef struct _piece {
    char symbol;    // symbol of the piece, e.g. 'K', 'Q', 'R'
    char color;     // color of the piece, 'W' or 'B'
} Piece;

typedef struct _square {
    Piece *piece;   // pointer to the piece that is on the square, NULL if empty
    char color;     // color of the square, 'W' or 'B'
} Square;

Square **board;

bool isOnBoard(int x, int y) {
    return (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE);
}

bool canCapture(int x, int y, char color) {
    // check if there is an opponent piece on the square
    if (isOnBoard(x, y) && board[x][y].piece != NULL && board[x][y].piece->color != color) {
        return true;
    }
    return false;
}

bool canMoveTo(int x, int y, char color) {
    // check if the square is empty or has an opponent piece
    if (isOnBoard(x, y) && board[x][y].piece == NULL) {
        return true;
    }
    if (isOnBoard(x, y) && board[x][y].piece != NULL && board[x][y].piece->color != color) {
        return true;
    }
    return false;
}

bool isKingInCheck(char color) {
    // define the king's symbol based on the color
    char kingSymbol = (color == 'W') ? 'K' : 'k';

    // find the king's square
    int kingX = 0, kingY = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].piece != NULL && board[i][j].piece->color == color && board[i][j].piece->symbol == kingSymbol) {
                kingX = i;
                kingY = j;
            }
        }
    }

    // check if any opponent piece can capture the king
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for (int i = 0; i < 8; i++) {
        if (canCapture(kingX+dx[i], kingY+dy[i], color)) {
            return true;
        }
    }

    // check if any opponent pawn can capture the king
    int pawnY = (color == 'W') ? kingY-1 : kingY+1;
    if (isOnBoard(kingX-1, pawnY) && board[kingX-1][pawnY].piece != NULL && board[kingX-1][pawnY].piece->color != color && board[kingX-1][pawnY].piece->symbol == 'P') {
        return true;
    }
    if (isOnBoard(kingX+1, pawnY) && board[kingX+1][pawnY].piece != NULL && board[kingX+1][pawnY].piece->color != color && board[kingX+1][pawnY].piece->symbol == 'P') {
        return true;
    }

    return false;
}

bool isValidMove(int fromX, int fromY, int toX, int toY, char color) {
    // check if the piece is on the from square and the to square is within the board
    if (!isOnBoard(fromX, fromY) || !isOnBoard(toX, toY)) {
        return false;
    }
    if (board[fromX][fromY].piece == NULL || board[fromX][fromY].piece->color != color) {
        return false;
    }

    // move the piece to the to square temporarily
    Piece *tempPiece = board[toX][toY].piece;
    board[toX][toY].piece = board[fromX][fromY].piece;
    board[fromX][fromY].piece = NULL;

    // check if the move puts the king in check
    bool inCheck = isKingInCheck(color);

    // move the piece back
    board[fromX][fromY].piece = board[toX][toY].piece;
    board[toX][toY].piece = tempPiece;

    // return true if the move is valid and does not put the king in check
    if ((canMoveTo(toX, toY, color) || canCapture(toX, toY, color)) && !inCheck) {
        return true;
    }

    return false;
}

void printBoard() {
    printf("  a b c d e f g h\n");
    printf("  ----------------\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d|", i+1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].piece == NULL) {
                printf("  ");
            } else {
                printf("%c%c", board[i][j].piece->color, board[i][j].piece->symbol);
            }
            printf("|");
        }
        printf("%d\n", i+1);
        printf("  ----------------\n");
    }
    printf("  a b c d e f g h\n");
}

void initializeBoard() {
    board = (Square**) malloc(BOARD_SIZE * sizeof(Square*));
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i] = (Square*) malloc(BOARD_SIZE * sizeof(Square));
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j].piece = NULL;
            if ((i+j) % 2 == 0) {
                board[i][j].color = 'W';
            } else {
                board[i][j].color = 'B';
            }
        }
    }

    // initialize white pieces
    board[0][0].piece = (Piece*) malloc(sizeof(Piece));
    board[0][0].piece->symbol = 'R';
    board[0][0].piece->color = 'W';
    board[0][1].piece = (Piece*) malloc(sizeof(Piece));
    board[0][1].piece->symbol = 'N';
    board[0][1].piece->color = 'W';
    board[0][2].piece = (Piece*) malloc(sizeof(Piece));
    board[0][2].piece->symbol = 'B';
    board[0][2].piece->color = 'W';
    board[0][3].piece = (Piece*) malloc(sizeof(Piece));
    board[0][3].piece->symbol = 'Q';
    board[0][3].piece->color = 'W';
    board[0][4].piece = (Piece*) malloc(sizeof(Piece));
    board[0][4].piece->symbol = 'K';
    board[0][4].piece->color = 'W';
    board[0][5].piece = (Piece*) malloc(sizeof(Piece));
    board[0][5].piece->symbol = 'B';
    board[0][5].piece->color = 'W';
    board[0][6].piece = (Piece*) malloc(sizeof(Piece));
    board[0][6].piece->symbol = 'N';
    board[0][6].piece->color = 'W';
    board[0][7].piece = (Piece*) malloc(sizeof(Piece));
    board[0][7].piece->symbol = 'R';
    board[0][7].piece->color = 'W';
    for (int j = 0; j < BOARD_SIZE; j++) {
        board[1][j].piece = (Piece*) malloc(sizeof(Piece));
        board[1][j].piece->symbol = 'P';
        board[1][j].piece->color = 'W';
    }

    // initialize black pieces
    board[7][0].piece = (Piece*) malloc(sizeof(Piece));
    board[7][0].piece->symbol = 'r';
    board[7][0].piece->color = 'B';
    board[7][1].piece = (Piece*) malloc(sizeof(Piece));
    board[7][1].piece->symbol = 'n';
    board[7][1].piece->color = 'B';
    board[7][2].piece = (Piece*) malloc(sizeof(Piece));
    board[7][2].piece->symbol = 'b';
    board[7][2].piece->color = 'B';
    board[7][3].piece = (Piece*) malloc(sizeof(Piece));
    board[7][3].piece->symbol = 'q';
    board[7][3].piece->color = 'B';
    board[7][4].piece = (Piece*) malloc(sizeof(Piece));
    board[7][4].piece->symbol = 'k';
    board[7][4].piece->color = 'B';
    board[7][5].piece = (Piece*) malloc(sizeof(Piece));
    board[7][5].piece->symbol = 'b';
    board[7][5].piece->color = 'B';
    board[7][6].piece = (Piece*) malloc(sizeof(Piece));
    board[7][6].piece->symbol = 'n';
    board[7][6].piece->color = 'B';
    board[7][7].piece = (Piece*) malloc(sizeof(Piece));
    board[7][7].piece->symbol = 'r';
    board[7][7].piece->color = 'B';
    for (int j = 0; j < BOARD_SIZE; j++) {
        board[6][j].piece = (Piece*) malloc(sizeof(Piece));
        board[6][j].piece->symbol = 'p';
        board[6][j].piece->color = 'B';
    }
}

int main() {
    initializeBoard();
    printBoard();
    return 0;
}