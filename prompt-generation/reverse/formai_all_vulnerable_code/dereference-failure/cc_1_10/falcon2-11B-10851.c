//Falcon2-11B DATASET v1.0 Category: Table Game ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent a game board
typedef struct {
    int width;
    int height;
    int **board;
} GameBoard;

// Define a function to initialize a new game board
GameBoard* newGameBoard(int width, int height) {
    GameBoard* board = (GameBoard*) malloc(sizeof(GameBoard));
    board->width = width;
    board->height = height;
    board->board = (int**) malloc(height * sizeof(int*));
    for (int i = 0; i < height; i++) {
        board->board[i] = (int*) malloc(width * sizeof(int));
    }
    return board;
}

// Define a function to print the game board
void printBoard(GameBoard* board) {
    for (int i = 0; i < board->height; i++) {
        for (int j = 0; j < board->width; j++) {
            printf("%d ", board->board[i][j]);
        }
        printf("\n");
    }
}

// Define a function to make a move on the game board
void makeMove(GameBoard* board, int row, int col) {
    if (row < 0 || row >= board->height || col < 0 || col >= board->width) {
        printf("Invalid move\n");
        return;
    }
    board->board[row][col] = 1;
}

// Define a function to check if the game is over
int isGameOver(GameBoard* board) {
    for (int i = 0; i < board->height; i++) {
        for (int j = 0; j < board->width; j++) {
            if (board->board[i][j] == 0) {
                return 0; // Game is not over
            }
            if (board->board[i][j] == 2) {
                return 1; // Game is over
            }
        }
    }
    return 2; // Game is over, but no more moves can be made
}

int main() {
    int width = 5;
    int height = 5;
    GameBoard* board = newGameBoard(width, height);

    while (1) {
        printf("Make a move (row, col): ");
        int row, col;
        scanf("%d %d", &row, &col);
        makeMove(board, row, col);
        if (isGameOver(board) == 1) {
            printf("Congratulations, you win!\n");
            break;
        } else if (isGameOver(board) == 2) {
            printf("Game is over, but no more moves can be made.\n");
            break;
        }
    }

    free(board->board);
    free(board->board);
    free(board);

    return 0;
}