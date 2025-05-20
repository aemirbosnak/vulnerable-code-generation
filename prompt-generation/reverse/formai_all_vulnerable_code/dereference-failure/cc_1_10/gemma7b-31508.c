//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Cell {
    int state;
    struct Cell* next;
} Cell;

Cell* createCell(int state) {
    Cell* cell = (Cell*)malloc(sizeof(Cell));
    cell->state = state;
    cell->next = NULL;
    return cell;
}

void placeMark(Cell* cell, int mark) {
    cell->state = mark;
}

int isWinner(Cell* cell, int mark) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (cell->next->state == mark && cell->next->next->state == mark) {
            return 1;
        }
    }

    // Check columns
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (cell->state == mark && cell->next->state == mark && cell->next->next->state == mark) {
            return 1;
        }
    }

    // Check diagonals
    if (cell->state == mark && cell->next->state == mark && cell->next->next->state == mark) {
        return 1;
    }

    return 0;
}

int main() {
    srand(time(NULL));

    Cell* board = createCell(0);
    board->next = createCell(0);
    board->next->next = createCell(0);

    int player1 = 1;
    int player2 = 2;

    // Game loop
    while (!isWinner(board, player1) && !isWinner(board, player2)) {
        // Get the next move
        int move = rand() % 9;

        // Place the mark
        placeMark(board->next->next->next, player1);

        // Check if the player won
        if (isWinner(board, player1)) {
            printf("Player 1 won!");
            break;
        }

        // Switch to the next player
        player1 = player2;
        player2 = 1 - player1;
    }

    // Game over
    if (isWinner(board, player1)) {
        printf("Player 1 won!");
    } else if (isWinner(board, player2)) {
        printf("Player 2 won!");
    } else {
        printf("It's a draw!");
    }

    return 0;
}