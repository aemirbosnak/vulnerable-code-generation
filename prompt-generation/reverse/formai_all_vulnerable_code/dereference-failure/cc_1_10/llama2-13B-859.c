//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: recursive
#include <stdio.h>

// Structure to represent the game board
typedef struct {
    int rows;
    int cols;
    int** cells;
} game_board;

// Function to create a new game board
game_board* new_board(int rows, int cols) {
    game_board* board = malloc(sizeof(game_board));
    board->rows = rows;
    board->cols = cols;
    board->cells = malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        board->cells[i] = malloc(cols * sizeof(int));
    }
    return board;
}

// Function to draw the game board
void draw_board(game_board* board) {
    for (int i = 0; i < board->rows; i++) {
        for (int j = 0; j < board->cols; j++) {
            printf("%d ", board->cells[i][j]);
        }
        printf("\n");
    }
}

// Function to apply the game of life rules
void apply_rules(game_board* board) {
    for (int i = 0; i < board->rows; i++) {
        for (int j = 0; j < board->cols; j++) {
            int alive_neighbors = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 || l == 0) {
                        continue;
                    }
                    int cell_index = i * board->cols + j + k * board->cols + l;
                    if (cell_index < 0 || cell_index >= board->rows * board->cols) {
                        continue;
                    }
                    if (board->cells[i][j] == 1 && board->cells[i][cell_index] == 1) {
                        alive_neighbors++;
                    }
                }
            }
            if (alive_neighbors < 2 || alive_neighbors > 3) {
                board->cells[i][j] = 0;
            }
        }
    }
}

// Function to simulate the game of life
void simulate(game_board* board, int generations) {
    for (int i = 0; i < generations; i++) {
        apply_rules(board);
    }
}

int main() {
    // Create a new game board
    game_board* board = new_board(10, 10);

    // Initialize the board with random values
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            board->cells[i][j] = rand() % 2;
        }
    }

    // Draw the board
    draw_board(board);

    // Simulate the game of life for 10 generations
    simulate(board, 10);

    // Free the board memory
    free(board->cells);
    free(board);

    return 0;
}