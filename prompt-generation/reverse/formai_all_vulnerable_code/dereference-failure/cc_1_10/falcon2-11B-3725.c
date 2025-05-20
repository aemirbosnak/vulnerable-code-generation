//Falcon2-11B DATASET v1.0 Category: Checkers Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a checker piece
struct Piece {
    int x;
    int y;
    int team;
};

// Define a struct to represent a game board
struct Board {
    int size;
    struct Piece** pieces;
};

// Define a function to initialize a game board
struct Board* initializeBoard(int size) {
    struct Board* board = (struct Board*)malloc(sizeof(struct Board));
    board->size = size;
    board->pieces = (struct Piece**)malloc(sizeof(struct Piece*) * size);
    for (int i = 0; i < size; i++) {
        board->pieces[i] = (struct Piece*)malloc(sizeof(struct Piece) * size);
    }
    return board;
}

// Define a function to print the game board
void printBoard(struct Board* board) {
    for (int i = 0; i < board->size; i++) {
        for (int j = 0; j < board->size; j++) {
            if (board->pieces[i][j].team == 1) {
                printf("X ");
            } else if (board->pieces[i][j].team == 2) {
                printf("O ");
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }
}

// Define a function to make a move on the game board
void makeMove(struct Board* board, int x, int y, int team) {
    board->pieces[x][y].team = team;
}

// Define a function to check if a move is valid on the game board
int isValidMove(struct Board* board, int x, int y, int team) {
    if (board->pieces[x][y].team!= 0) {
        return 0;
    }
    if (x < 0 || y < 0 || x >= board->size || y >= board->size) {
        return 0;
    }
    if (board->pieces[x][y].team!= 0) {
        return 0;
    }
    return 1;
}

// Define a function to check if a player has won the game
int hasWon(struct Board* board, int team) {
    int won = 0;
    for (int i = 0; i < board->size; i++) {
        for (int j = 0; j < board->size; j++) {
            if (board->pieces[i][j].team == team) {
                if ((i!= board->size - 1 && j!= board->size - 1) || (i!= 0 && j!= 0)) {
                    if (board->pieces[i + 1][j].team == team && board->pieces[i - 1][j].team == team &&
                            board->pieces[i][j + 1].team == team && board->pieces[i][j - 1].team == team) {
                        won = 1;
                        break;
                    }
                } else if (i!= 0) {
                    if (board->pieces[i - 1][j].team == team && board->pieces[i][j].team == team) {
                        won = 1;
                        break;
                    }
                } else if (j!= 0) {
                    if (board->pieces[i][j - 1].team == team && board->pieces[i][j].team == team) {
                        won = 1;
                        break;
                    }
                }
            }
        }
        if (won == 1) {
            break;
        }
    }
    return won;
}

// Define a function to play a game of checkers
void playCheckers(int size) {
    struct Board* board = initializeBoard(size);
    int turn = 1;
    while (!hasWon(board, turn)) {
        int x, y;
        printf("Player %d's turn.\n", turn);
        printf("Enter coordinates (x y): ");
        scanf("%d %d", &x, &y);
        if (!isValidMove(board, x, y, turn)) {
            printf("Invalid move.\n");
        } else {
            makeMove(board, x, y, turn);
            turn = (turn + 1) % 2;
            printf("Player %d's turn.\n", turn);
        }
        printf("Board:\n");
        printBoard(board);
    }
    if (hasWon(board, turn)) {
        printf("%d wins!\n", turn + 1);
    } else {
        printf("It's a draw.\n");
    }
}

int main() {
    playCheckers(8);
    return 0;
}