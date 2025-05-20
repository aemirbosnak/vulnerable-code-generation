//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define EMPTY_SPOT -1

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

void playGame() {
    Cell* head = createCell(EMPTY_SPOT);
    head->next = createCell(EMPTY_SPOT);
    head->next->next = createCell(EMPTY_SPOT);

    for (int i = 0; i < 9; i++) {
        int move = rand() % 3;
        Cell* currentCell = head;
        for (int j = 0; j < move; j++) {
            currentCell = currentCell->next;
        }
        if (currentCell->state == EMPTY_SPOT) {
            currentCell->state = 2;
        }
    }

    int winner = checkWinner(head);
    if (winner == 1) {
        printf("You win!\n");
    } else if (winner == 2) {
        printf("AI wins!\n");
    } else {
        printf("It's a draw!\n");
    }
}

int checkWinner(Cell* head) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        Cell* currentCell = head;
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (currentCell->state == head->state && currentCell->next->state == head->state && currentCell->next->next->state == head->state) {
                return head->state;
            }
            currentCell = currentCell->next;
        }
    }

    // Check columns
    for (int i = 0; i < BOARD_SIZE; i++) {
        Cell* currentCell = head;
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (currentCell->state == head->state && currentCell->next->state == head->state && currentCell->next->next->state == head->state) {
                return head->state;
            }
            currentCell = currentCell->next;
        }
    }

    // Check diagonals
    Cell* currentCell = head;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (currentCell->state == head->state && currentCell->next->state == head->state && currentCell->next->next->state == head->state) {
                return head->state;
            }
            currentCell = currentCell->next;
        }
    }

    // No winner
    return 0;
}

int main() {
    playGame();
    return 0;
}