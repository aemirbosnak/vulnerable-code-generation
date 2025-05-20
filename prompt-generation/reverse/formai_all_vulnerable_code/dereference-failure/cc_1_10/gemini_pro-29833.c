//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Tile types
#define COVERED 0
#define UNCOVERED 1
#define BOMB -1

// Game state
#define RUNNING 0
#define WON 1
#define LOST 2

// Board dimensions
#define WIDTH 10
#define HEIGHT 10

// Number of bombs
#define NUM_BOMBS 10

// Create a new game board
int** create_board() {
    int** board = malloc(sizeof(int*) * HEIGHT);
    for (int i = 0; i < HEIGHT; i++) {
        board[i] = malloc(sizeof(int) * WIDTH);
        memset(board[i], COVERED, sizeof(int) * WIDTH);
    }
    return board;
}

// Free the game board
void free_board(int** board) {
    for (int i = 0; i < HEIGHT; i++) {
        free(board[i]);
    }
    free(board);
}

// Place bombs on the game board
void place_bombs(int** board) {
    for (int i = 0; i < NUM_BOMBS; i++) {
        int x = rand() % WIDTH;
        int y = rand() % HEIGHT;
        while (board[y][x] == BOMB) {
            x = rand() % WIDTH;
            y = rand() % HEIGHT;
        }
        board[y][x] = BOMB;
    }
}

// Count the number of bombs adjacent to a tile
int count_adjacent_bombs(int** board, int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (x + i >= 0 && x + i < WIDTH && y + j >= 0 && y + j < HEIGHT && board[y + j][x + i] == BOMB) {
                count++;
            }
        }
    }
    return count;
}

// Uncover a tile
void uncover_tile(int** board, int x, int y) {
    if (board[y][x] == COVERED) {
        board[y][x] = UNCOVERED;
        if (board[y][x] == BOMB) {
            printf("You lose!\n");
            exit(0);
        } else {
            int count = count_adjacent_bombs(board, x, y);
            if (count == 0) {
                // Uncover all adjacent tiles
                for (int i = -1; i <= 1; i++) {
                    for (int j = -1; j <= 1; j++) {
                        if (x + i >= 0 && x + i < WIDTH && y + j >= 0 && y + j < HEIGHT && board[y + j][x + i] == COVERED) {
                            uncover_tile(board, x + i, y + j);
                        }
                    }
                }
            }
        }
    }
}

// Print the game board
void print_board(int** board) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (board[i][j] == COVERED) {
                printf("?");
            } else if (board[i][j] == UNCOVERED) {
                int count = count_adjacent_bombs(board, j, i);
                if (count == 0) {
                    printf(" ");
                } else {
                    printf("%d", count);
                }
            } else if (board[i][j] == BOMB) {
                printf("*");
            }
        }
        printf("\n");
    }
}

// Main game loop
int main() {
    // Create a new game board
    int** board = create_board();

    // Place bombs on the game board
    place_bombs(board);

    // Game loop
    int state = RUNNING;
    while (state == RUNNING) {
        // Print the game board
        print_board(board);

        // Get the player's input
        int x, y;
        printf("Enter the coordinates of the tile you want to uncover (x, y): ");
        scanf("%d %d", &x, &y);

        // Uncover the tile
        uncover_tile(board, x, y);

        // Check if the player has won or lost
        int uncovered_tiles = 0;
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                if (board[i][j] == UNCOVERED) {
                    uncovered_tiles++;
                }
            }
        }
        if (uncovered_tiles == WIDTH * HEIGHT - NUM_BOMBS) {
            state = WON;
        }
    }

    // Print the final game board
    print_board(board);

    // Free the game board
    free_board(board);

    return 0;
}