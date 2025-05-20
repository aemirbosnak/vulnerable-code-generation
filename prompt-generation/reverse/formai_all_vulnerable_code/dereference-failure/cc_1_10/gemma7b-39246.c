//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: sophisticated
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 20

typedef struct Cell {
    int state;
    struct Cell* neighbors[4];
} Cell;

void initializeBoard(Cell** board) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        board[i] = malloc(sizeof(Cell));
        board[i]->state = 0;
        for (j = 0; j < 4; j++) {
            board[i]->neighbors[j] = NULL;
        }
    }
}

void updateBoard(Cell** board) {
    int i, j, count, alive = 0;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            count = 0;
            if (board[i]->neighbors[0] && board[i]->neighbors[0]->state == 1) count++;
            if (board[i]->neighbors[1] && board[i]->neighbors[1]->state == 1) count++;
            if (board[i]->neighbors[2] && board[i]->neighbors[2]->state == 1) count++;
            if (board[i]->neighbors[3] && board[i]->neighbors[3]->state == 1) count++;

            if (board[i]->state == 1) {
                if (count < 2) board[i]->state = 0;
            } else if (count == 3) {
                board[i]->state = 1;
            }
        }
    }
}

int main() {
    Cell** board = NULL;
    initializeBoard(&board);

    // Simulate game of life
    for (int t = 0; t < 10; t++) {
        updateBoard(board);
    }

    // Print final board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i]->state);
        }
        printf("\n");
    }

    return 0;
}