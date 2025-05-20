//Falcon2-11B DATASET v1.0 Category: Chess AI ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WHITE 1
#define BLACK 2
#define EMPTY 0

typedef struct board {
    int **board;
    int height;
    int width;
    int turn;
} Board;

Board createBoard(int height, int width) {
    Board board;
    board.height = height;
    board.width = width;
    board.board = (int **)malloc(height * sizeof(int *));
    for (int i = 0; i < height; i++) {
        board.board[i] = (int *)malloc(width * sizeof(int));
        for (int j = 0; j < width; j++) {
            board.board[i][j] = EMPTY;
        }
    }
    board.turn = WHITE;
    return board;
}

void printBoard(Board board) {
    for (int i = 0; i < board.height; i++) {
        for (int j = 0; j < board.width; j++) {
            if (board.board[i][j] == WHITE) {
                printf(" W ");
            } else if (board.board[i][j] == BLACK) {
                printf(" B ");
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }
}

void movePiece(Board *board, int fromRow, int fromCol, int toRow, int toCol) {
    if (board->board[fromRow][fromCol] == EMPTY) {
        printf("Invalid move, piece not found at (%d, %d).\n", fromRow, fromCol);
        return;
    }

    if (board->board[toRow][toCol]!= EMPTY) {
        printf("Invalid move, space (%d, %d) is occupied.\n", toRow, toCol);
        return;
    }

    int **tempBoard = (int **)malloc((board->height + 1) * sizeof(int *));
    for (int i = 0; i < board->height + 1; i++) {
        tempBoard[i] = (int *)malloc(board->width * sizeof(int));
        for (int j = 0; j < board->width; j++) {
            tempBoard[i][j] = board->board[i][j];
        }
    }

    tempBoard[toRow][toCol] = board->board[fromRow][fromCol];

    for (int i = board->height; i > toRow; i--) {
        tempBoard[i][toCol] = tempBoard[i - 1][toCol];
    }

    for (int i = board->height; i > fromRow; i--) {
        tempBoard[fromRow][toCol] = tempBoard[fromRow + 1][toCol];
    }

    for (int i = board->height - 1; i >= toRow; i--) {
        tempBoard[i][fromCol] = tempBoard[i + 1][fromCol];
    }

    for (int i = board->height - 1; i > toRow; i--) {
        tempBoard[toRow][fromCol] = tempBoard[toRow + 1][fromCol];
    }

    free(board->board);
    board->board = tempBoard;

    board->turn = board->turn == WHITE? BLACK : WHITE;

    printf("Piece moved from (%d, %d) to (%d, %d).\n", fromRow, fromCol, toRow, toCol);
}

int main() {
    srand(time(0));
    int height = 8;
    int width = 8;
    Board board = createBoard(height, width);

    printBoard(board);
    printf("White to move.\n");

    int fromRow, fromCol, toRow, toCol;
    while (1) {
        printf("Enter row (1-%d) and column (1-%d): ", board.height - 1, board.width - 1);
        scanf("%d%d", &fromRow, &fromCol);

        if (fromRow < 1 || fromRow > board.height || fromCol < 1 || fromCol > board.width) {
            printf("Invalid move, please try again.\n");
            continue;
        }

        printf("Enter row (1-%d) and column (1-%d): ", board.height - 1, board.width - 1);
        scanf("%d%d", &toRow, &toCol);

        if (toRow < 1 || toRow > board.height || toCol < 1 || toCol > board.width) {
            printf("Invalid move, please try again.\n");
            continue;
        }

        movePiece(&board, fromRow, fromCol, toRow, toCol);

        printBoard(board);
        if (board.turn == WHITE) {
            printf("White's turn\n");
        } else {
            printf("Black's turn\n");
        }
    }

    return 0;
}