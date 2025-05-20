//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: Donald Knuth
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#define MAX_MOVES 9

typedef struct Move {
    int row;
    int col;
    struct Move* next;
} Move;

Move* createMove(int row, int col) {
    Move* move = malloc(sizeof(Move));
    move->row = row;
    move->col = col;
    move->next = NULL;
    return move;
}

Move* insertMove(Move* head, int row, int col) {
    Move* move = createMove(row, col);
    if (head == NULL) {
        head = move;
    } else {
        move->next = head;
        head = move;
    }
    return head;
}

int evaluateBoard(Move* moves) {
    // Check for win
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            int count = 0;
            for (Move* m = moves; m != NULL; m++) {
                if (m->row == r && m->col == c) {
                    count++;
                }
            }
            if (count == 3) {
                return 1;
            }
        }
    }

    // Check for draw
    if (moves->next == NULL) {
        return 0;
    }

    // No win or draw, so it's still ongoing
    return -1;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create the game board
    int board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

    // Create the move list
    Move* moves = NULL;

    // Play the game
    while (1) {
        // Get the player's move
        int row = rand() % 3;
        int col = rand() % 3;

        // Check if the move is valid
        if (board[row][col] != 0) {
            continue;
        }

        // Make the move
        board[row][col] = 1;
        insertMove(moves, row, col);

        // Evaluate the board
        int result = evaluateBoard(moves);

        // Check if the player has won or drawn
        if (result == 1) {
            printf("You win!");
            break;
        } else if (result == 0) {
            printf("Draw!");
            break;
        }
    }

    return 0;
}