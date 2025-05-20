//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent the game board
typedef struct {
    int width;
    int height;
    int **grid;
} game_board_t;

// Function to create a new game board
game_board_t* new_game_board(int width, int height) {
    game_board_t* board = malloc(sizeof(game_board_t));
    board->width = width;
    board->height = height;
    board->grid = malloc(width * sizeof(int*) * height);
    for (int i = 0; i < width; i++) {
        board->grid[i] = malloc(height * sizeof(int));
    }
    return board;
}

// Function to print the game board
void print_board(game_board_t* board) {
    for (int i = 0; i < board->width; i++) {
        for (int j = 0; j < board->height; j++) {
            printf("%d ", board->grid[i][j]);
        }
        printf("\n");
    }
}

// Function to apply the game of life rules
void apply_rules(game_board_t* board) {
    for (int i = 0; i < board->width; i++) {
        for (int j = 0; j < board->height; j++) {
            int alive_neighbors = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 && l == 0) {
                        // If we are on the border, consider the cell alive
                        alive_neighbors++;
                    } else if (board->grid[i + k][j + l] != 0) {
                        // If we have a living neighbor, consider the cell alive
                        alive_neighbors++;
                    }
                }
            }
            // If the cell is alive and has 2 or 3 alive neighbors, leave it alive
            if (board->grid[i][j] != 0 && alive_neighbors >= 2 && alive_neighbors <= 3) {
                board->grid[i][j] = 1;
            } else {
                // If the cell is alive and has less than 2 alive neighbors, or is dead and has 3 alive neighbors, die
                if (board->grid[i][j] != 0 && alive_neighbors < 2) {
                    board->grid[i][j] = 0;
                } else if (board->grid[i][j] == 0 && alive_neighbors == 3) {
                    board->grid[i][j] = 1;
                }
            }
        }
    }
}

int main() {
    srand(time(NULL));
    int width = 10;
    int height = 10;
    game_board_t* board = new_game_board(width, height);
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            board->grid[i][j] = rand() % 2;
        }
    }
    print_board(board);
    for (int generation = 0; generation < 100; generation++) {
        apply_rules(board);
        print_board(board);
    }
    free(board->grid);
    free(board);
    return 0;
}