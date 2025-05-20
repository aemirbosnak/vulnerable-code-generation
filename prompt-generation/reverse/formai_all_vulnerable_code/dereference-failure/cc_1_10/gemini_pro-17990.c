//GEMINI-pro DATASET v1.0 Category: Game of Life ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

// Game of Life rules
#define BIRTH 3
#define SURVIVE 2
#define DIE 1

// Cell states
#define ALIVE 1
#define DEAD 0

// Board dimensions
#define WIDTH 80
#define HEIGHT 24

// Board data structure
typedef struct {
    int cells[WIDTH][HEIGHT];
} Board;

// Create a new board
Board* create_board() {
    Board* board = malloc(sizeof(Board));
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            board->cells[i][j] = DEAD;
        }
    }
    return board;
}

// Free the board
void free_board(Board* board) {
    free(board);
}

// Copy the board
Board* copy_board(Board* board) {
    Board* new_board = create_board();
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            new_board->cells[i][j] = board->cells[i][j];
        }
    }
    return new_board;
}

// Print the board
void print_board(Board* board) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", board->cells[j][i] ? '#' : '.');
        }
        printf("\n");
    }
}

// Get the number of living neighbors of a cell
int get_neighbors(Board* board, int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            if (x + i >= 0 && x + i < WIDTH && y + j >= 0 && y + j < HEIGHT) {
                count += board->cells[x + i][y + j];
            }
        }
    }
    return count;
}

// Update the board
void update_board(Board* board) {
    Board* new_board = copy_board(board);
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            int neighbors = get_neighbors(board, i, j);
            if (board->cells[i][j] == ALIVE) {
                if (neighbors == SURVIVE) {
                    new_board->cells[i][j] = ALIVE;
                } else {
                    new_board->cells[i][j] = DEAD;
                }
            } else {
                if (neighbors == BIRTH) {
                    new_board->cells[i][j] = ALIVE;
                } else {
                    new_board->cells[i][j] = DEAD;
                }
            }
        }
    }
    free_board(board);
    board = new_board;
}

// Main function
int main() {
    Board* board = create_board();

    // Set initial conditions
    board->cells[20][10] = ALIVE;
    board->cells[21][10] = ALIVE;
    board->cells[22][10] = ALIVE;
    board->cells[20][11] = ALIVE;
    board->cells[22][11] = ALIVE;

    // Run the simulation
    for (int i = 0; i < 100; i++) {
        print_board(board);
        update_board(board);
        printf("\n");
    }

    free_board(board);
    return 0;
}