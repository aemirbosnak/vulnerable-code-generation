//LLAMA2-13B DATASET v1.0 Category: Table Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define PIECES 6

// Structure to represent a table game piece
typedef struct {
    int row;
    int col;
} piece_t;

// Function to print the game board
void print_board(piece_t pieces[]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (pieces[i * COLS + j].row != -1) {
                printf("%d", pieces[i * COLS + j].row + 1);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

// Function to move a piece to a new location
void move_piece(piece_t *pieces, int row, int col) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (pieces[i * COLS + j].row == row && pieces[i * COLS + j].col == col) {
                pieces[i * COLS + j].row = -1;
                break;
            }
        }
        if (pieces[i * COLS + j].row == -1) {
            break;
        }
    }
    pieces[row * COLS + col].row = i + 1;
}

// Function to generate a random move
int random_move(piece_t *pieces) {
    int i, j;
    int row = -1, col = -1;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (pieces[i * COLS + j].row != -1) {
                row = i;
                col = j;
                break;
            }
        }
        if (row != -1) {
            break;
        }
    }
    return row * COLS + col;
}

// Main game loop
int main() {
    srand(time(NULL));

    piece_t pieces[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            pieces[i][j].row = -1;
        }
    }

    while (1) {
        print_board(pieces);

        // Get a move from the player
        int move = getchar();
        if (move == EOF) {
            break;
        }

        // Move the piece to the new location
        move_piece(pieces, move / COLS, move % COLS);

        // Check if the game is over
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (pieces[i][j].row == -1) {
                    break;
                }
            }
            if (i == ROWS - 1) {
                break;
            }
        }

        // If the game is over, print the winner
        if (pieces[ROWS - 1][COLS - 1].row == -1) {
            printf("Game over! No more moves left.\n");
            break;
        }

        // Generate a random move if the player did not make a move
        if (move == -1) {
            move = random_move(pieces);
        }
    }

    return 0;
}