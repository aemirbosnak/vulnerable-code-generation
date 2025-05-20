//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: shape shifting
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 20

typedef struct Cell {
    int x;
    int y;
    int state;
} Cell;

Cell** createBoard(int size) {
    Cell** board = (Cell**)malloc(size * sizeof(Cell*));
    for (int i = 0; i < size; i++) {
        board[i] = (Cell*)malloc(size * sizeof(Cell));
        for (int j = 0; j < size; j++) {
            board[i][j].x = i;
            board[i][j].y = j;
            board[i][j].state = 0;
        }
    }
    return board;
}

void updateBoard(Cell** board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            int neighbors = 0;
            if (board[i][j].state == 1) {
                neighbors++;
            }
            if (board[i][j].state == 2) {
                neighbors--;
            }
            if (neighbors < 2 || neighbors > 3) {
                board[i][j].state = 0;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    Cell** board = createBoard(BOARD_SIZE);

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j].state = rand() % 2;
        }
    }

    updateBoard(board);

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j].state);
        }
        printf("\n");
    }

    return 0;
}