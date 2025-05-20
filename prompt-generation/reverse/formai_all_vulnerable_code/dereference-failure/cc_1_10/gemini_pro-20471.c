//GEMINI-pro DATASET v1.0 Category: Tic Tac Toe AI ; Style: Dennis Ritchie
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct TTTBoard {
    char board[9];
    char turn;
} TTTBoard;

#define TTTPrintBoard(board) {\
    printf(" %c | %c | %c\n", (board)->board[0], (board)->board[1], (board)->board[2]);\
    printf("---+---+---\n");\
    printf(" %c | %c | %c\n", (board)->board[3], (board)->board[4], (board)->board[5]);\
    printf("---+---+---\n");\
    printf(" %c | %c | %c\n", (board)->board[6], (board)->board[7], (board)->board[8]);\
}

TTTBoard *TTTNewBoard() {
    TTTBoard *board = malloc(sizeof(TTTBoard));
    memcpy(board->board, "         ", 9);
    board->turn = 'X';
    return board;
}

void TTTFreeBoard(TTTBoard *board) {
    free(board);
}

int TTTGetWinner(TTTBoard *board) {
    // Check rows
    for (int i = 0; i < 9; i += 3) {
        if (board->board[i] != ' ' && board->board[i] == board->board[i + 1] && board->board[i] == board->board[i + 2]) {
            return board->board[i];
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board->board[i] != ' ' && board->board[i] == board->board[i + 3] && board->board[i] == board->board[i + 6]) {
            return board->board[i];
        }
    }

    // Check diagonals
    if (board->board[0] != ' ' && board->board[0] == board->board[4] && board->board[0] == board->board[8]) {
        return board->board[0];
    }

    if (board->board[2] != ' ' && board->board[2] == board->board[4] && board->board[2] == board->board[6]) {
        return board->board[2];
    }

    return ' ';
}

int TTTIsFull(TTTBoard *board) {
    for (int i = 0; i < 9; i++) {
        if (board->board[i] == ' ') {
            return 0;
        }
    }

    return 1;
}

int TTTCheckMove(TTTBoard *board, int move) {
    if (move < 0 || move > 8) {
        return 0;
    }

    if (board->board[move] != ' ') {
        return 0;
    }

    return 1;
}

void TTTMakeMove(TTTBoard *board, int move) {
    board->board[move] = board->turn;
    board->turn = (board->turn == 'X' ? 'O' : 'X');
}

int TTTMinimax(TTTBoard *board, int depth, int maximizingPlayer) {
    int winner = TTTGetWinner(board);

    if (winner != ' ') {
        if (winner == 'X') {
            return -1;
        } else if (winner == 'O') {
            return 1;
        } else {
            return 0;
        }
    }

    if (TTTIsFull(board)) {
        return 0;
    }

    int bestScore;
    if (maximizingPlayer) {
        bestScore = -1000;
        for (int i = 0; i < 9; i++) {
            if (TTTCheckMove(board, i)) {
                TTTMakeMove(board, i);
                int score = TTTMinimax(board, depth + 1, 0);
                TTTMakeMove(board, i);
                bestScore = fmax(bestScore, score);
            }
        }
    } else {
        bestScore = 1000;
        for (int i = 0; i < 9; i++) {
            if (TTTCheckMove(board, i)) {
                TTTMakeMove(board, i);
                int score = TTTMinimax(board, depth + 1, 1);
                TTTMakeMove(board, i);
                bestScore = fmin(bestScore, score);
            }
        }
    }

    return bestScore;
}

int TTTGetBestMove(TTTBoard *board) {
    int bestScore = -1000;
    int bestMove = -1;
    for (int i = 0; i < 9; i++) {
        if (TTTCheckMove(board, i)) {
            TTTMakeMove(board, i);
            int score = TTTMinimax(board, 0, 0);
            TTTMakeMove(board, i);
            if (score > bestScore) {
                bestScore = score;
                bestMove = i;
            }
        }
    }

    return bestMove;
}

int main() {
    srand(time(NULL));

    TTTBoard *board = TTTNewBoard();

    printf("Let's play tic-tac-toe!\n");
    printf("You are 'X' and the computer is 'O'.\n");

    while (!TTTGetWinner(board)) {
        if (board->turn == 'X') {
            int move;
            do {
                printf("Your move (1-9): ");
                scanf("%d", &move);
            } while (!TTTCheckMove(board, move - 1));

            TTTMakeMove(board, move - 1);
            TTTPrintBoard(board);
        } else {
            int move = TTTGetBestMove(board);
            TTTMakeMove(board, move);
            printf("Computer's move:\n");
            TTTPrintBoard(board);
        }
    }

    char winner = TTTGetWinner(board);
    if (winner == 'X') {
        printf("You win!\n");
    } else if (winner == 'O') {
        printf("Computer wins!\n");
    } else {
        printf("Tie!\n");
    }

    TTTFreeBoard(board);

    return 0;
}