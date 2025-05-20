//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#define WIDTH 640
#define HEIGHT 480
#define CELL_SIZE 20
#define BORDER_SIZE 10

// Structure to represent a cell in the game board
typedef struct {
    int alive;    // Whether the cell is alive or not
    int next;    // The next state of the cell (based on the current state and the neighbors)
} Cell;

// Function to generate a randomly-shaped game board
void generate_board(Cell **board, int width, int height) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            // Generate a random state for the cell
            int random_state = rand() % 2;

            // Create a new cell and store its state
            Cell *cell = malloc(sizeof(Cell));
            cell->alive = random_state;
            cell->next = random_state;

            // Add the cell to the game board
            board[i * height + j] = cell;
        }
    }
}

// Function to update the game state based on the current state and the neighbors
void update_state(Cell **board, int width, int height) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            // Get the current state and the neighbors of the cell
            int alive = board[i * height + j]->alive;
            int north = board[i * height + j - 1]->alive;
            int south = board[i * height + j + 1]->alive;
            int west = board[i - 1 * height + j]->alive;
            int east = board[i + 1 * height + j]->alive;

            // Calculate the next state based on the current state and the neighbors
            int next = alive;
            if (north && south) {
                // If the cell is surrounded by alive cells, it stays alive
                next = alive;
            } else if (north && !south) {
                // If the cell is surrounded by dead cells, it dies
                next = 0;
            } else if (!north && south) {
                // If the cell is surrounded by alive cells, it dies
                next = 0;
            } else if (west && east) {
                // If the cell is surrounded by alive cells, it stays alive
                next = alive;
            } else {
                // If the cell is not surrounded by alive cells, it dies
                next = 0;
            }

            // Update the cell's state and next state
            board[i * height + j]->alive = next;
            board[i * height + j]->next = next;
        }
    }
}

// Function to draw the game board and the current state
void draw_board(Cell **board, int width, int height) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            // Calculate the x and y coordinates of the cell
            int x = i * CELL_SIZE;
            int y = j * CELL_SIZE;

            // Draw the cell based on its state
            if (board[i * height + j]->alive) {
                // Draw a living cell in green
                printf(" \033[32m");
            } else {
                // Draw a dead cell in red
                printf(" \033[31m");
            }

            // Print the cell's state and next state
            printf("Cell %d, %d: alive %d, next %d\n", i, j, board[i * height + j]->alive, board[i * height + j]->next);
        }
    }
}

int main() {
    // Generate a randomly-shaped game board
    Cell **board = malloc(sizeof(Cell *) * WIDTH * HEIGHT);
    generate_board(board, WIDTH, HEIGHT);

    // Update the game state based on the current state and the neighbors
    update_state(board, WIDTH, HEIGHT);

    // Draw the game board and the current state
    draw_board(board, WIDTH, HEIGHT);

    // Wait for user input
    printf("Press any key to continue...");
    getchar();

    // Free the game board memory
    free(board);

    return 0;
}