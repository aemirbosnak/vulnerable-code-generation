//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 50
#define CELL_SIZE 10

// Structure to represent the game board
typedef struct {
    int width;
    int height;
    int cells[WIDTH][HEIGHT];
} game_board;

// Function to create a new game board
game_board* create_board() {
    game_board* board = (game_board*) malloc(sizeof(game_board));
    board->width = WIDTH;
    board->height = HEIGHT;
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            board->cells[i][j] = 0;
        }
    }
    return board;
}

// Function to draw the game board
void draw_board(game_board* board) {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            printf("%d ", board->cells[i][j]);
        }
        printf("\n");
    }
}

// Function to apply the game of life rules
void apply_rules(game_board* board) {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            // Check if the cell is alive
            if (board->cells[i][j] == 1) {
                // If the cell is alive and has two or three alive neighbors, leave it alive
                if (board->cells[i][j - 1] == 1 && board->cells[i][j + 1] == 1 && board->cells[i][j - CELL_SIZE] == 1) {
                    board->cells[i][j] = 1;
                } else {
                    // If the cell is alive and has less than two alive neighbors, die
                    if (board->cells[i][j - 1] == 1 && board->cells[i][j + 1] == 1) {
                        board->cells[i][j] = 0;
                    }
                }
            } else {
                // If the cell is dead and has three alive neighbors, come to life
                if (board->cells[i][j - 1] == 1 && board->cells[i][j + 1] == 1 && board->cells[i][j - CELL_SIZE] == 1) {
                    board->cells[i][j] = 1;
                }
            }
        }
    }
}

// Main game loop
void game_loop(game_board* board) {
    // Apply the game of life rules
    apply_rules(board);

    // Draw the game board
    draw_board(board);

    // Wait for user input
    printf("Press any key to continue...");
    getchar();
}

int main() {
    game_board* board = create_board();
    game_loop(board);
    free(board);
    return 0;
}