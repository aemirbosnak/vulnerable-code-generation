//FormAI DATASET v1.0 Category: Chess AI ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct Move {
    int source[2];
    int dest[2];
} Move;

typedef struct ChessBoard {
    char board[8][8];
    char player;
    int kings[2][2];
} ChessBoard;

int getSquareValue(char piece) {
    if (piece == 'P')
        return 1;
    else if (piece == 'N')
        return 3;
    else if (piece == 'B')
        return 3;
    else if (piece == 'R')
        return 5;
    else if (piece == 'Q')
        return 9;
    else if (piece == 'K')
        return 100;
    else if (piece == 'p')
        return -1;
    else if (piece == 'n')
        return -3;
    else if (piece == 'b')
        return -3;
    else if (piece == 'r')
        return -5;
    else if (piece == 'q')
        return -9;
    else if (piece == 'k')
        return -100;
    else
        return 0;
}

int evaluateBoard(ChessBoard *board) {
    int evaluation = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            evaluation += getSquareValue(board->board[i][j]);
        }
    }
    return evaluation;
}

Move *getRandomMove(ChessBoard *board) {
    int sourceRow, sourceCol, destRow, destCol;
    int validMove = 0;
    char piece = board->board[0][0];
    Move *move = malloc(sizeof(Move));
    do {
        sourceRow = rand() % 8;
        sourceCol = rand() % 8;
        destRow = rand() % 8;
        destCol = rand() % 8;
        if (board->board[sourceRow][sourceCol] != '.' &&
                board->player == (isupper(board->board[sourceRow][sourceCol]) ? 'w' : 'b')) {
            piece = board->board[sourceRow][sourceCol];
            if (abs(sourceCol - destCol) <= 1 && abs(sourceRow - destRow) <= 1 &&
                    board->board[destRow][destCol] == '.') {
                validMove = 1;
            }
        }
    } while (!validMove);

    move->source[0] = sourceRow;
    move->source[1] = sourceCol;
    move->dest[0] = destRow;
    move->dest[1] = destCol;

    return move;
}

void makeMove(ChessBoard *board, Move *move) {
    char piece = board->board[move->source[0]][move->source[1]];
    board->board[move->dest[0]][move->dest[1]] = piece;
    board->board[move->source[0]][move->source[1]] = '.';

    if (piece == 'K') {
        board->kings[0][0] = move->dest[0];
        board->kings[0][1] = move->dest[1];
    } else if (piece == 'k') {
        board->kings[1][0] = move->dest[0];
        board->kings[1][1] = move->dest[1];
    }

    board->player = (board->player == 'w') ? 'b' : 'w';
}

int isGameOver(ChessBoard *board) {
    int whiteKingRow = board->kings[0][0];
    int whiteKingCol = board->kings[0][1];
    int blackKingRow = board->kings[1][0];
    int blackKingCol = board->kings[1][1];

    if (board->board[whiteKingRow][whiteKingCol] == '.') {
        printf("Black wins!\n");
        return 1;
    } else if (board->board[blackKingRow][blackKingCol] == '.') {
        printf("White wins!\n");
        return 1;
    }

    return 0;
}

Move *getBestMove(ChessBoard *board) {
    Move *move = getRandomMove(board);
    int bestValue = evaluateBoard(board);
    for (int i = 0; i < 1000; i++) {
        ChessBoard *tempBoard = malloc(sizeof(ChessBoard));
        memcpy(tempBoard, board, sizeof(ChessBoard));

        Move *tempMove = getRandomMove(tempBoard);
        makeMove(tempBoard, tempMove);

        int tempValue = evaluateBoard(tempBoard);
        if (tempValue > bestValue) {
            bestValue = tempValue;
            memcpy(move, tempMove, sizeof(Move));
        }

        free(tempMove);
        free(tempBoard);
    }
    return move;
}

int main() {
    srand(time(NULL));

    ChessBoard *board = malloc(sizeof(ChessBoard));
    board->player = 'w';
    board->kings[0][0] = 0;
    board->kings[0][1] = 4;
    board->kings[1][0] = 7;
    board->kings[1][1] = 4;

    char startingBoard[8][8] = {
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
    };
    memcpy(board->board, startingBoard, sizeof(startingBoard));

    while (!isGameOver(board)) {
        if (board->player == 'w') {
            printf("White's turn\n");
            Move *move = getBestMove(board);
            printf("Moved %c from %c%d to %c%d\n", board->board[move->source[0]][move->source[1]],
                move->source[1] + 'a', move->source[0] + 1,
                move->dest[1] + 'a', move->dest[0] + 1);
            makeMove(board, move);
            free(move);
        } else {
            printf("Black's turn\n");
            Move *move = getBestMove(board);
            printf("Moved %c from %c%d to %c%d\n", board->board[move->source[0]][move->source[1]],
                move->source[1] + 'a', move->source[0] + 1,
                move->dest[1] + 'a', move->dest[0] + 1);
            makeMove(board, move);
            free(move);
        }
    }

    free(board);
    return 0;
}