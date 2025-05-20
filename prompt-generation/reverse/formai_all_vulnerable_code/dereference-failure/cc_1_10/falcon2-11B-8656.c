//Falcon2-11B DATASET v1.0 Category: Game of Life ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to initialize the Game of Life board
void initialize_board(int** board, int size) {
    for (int i = 0; i < size; i++) {
        board[i] = (int*)malloc(sizeof(int) * size);
        for (int j = 0; j < size; j++) {
            board[i][j] = 0;
        }
    }
}

// Function to update the Game of Life board
void update_board(int** board, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            // Count the number of live neighbors
            int live_neighbors = 0;
            int x = i - 1;
            int y = j - 1;
            while (x >= 0 && y >= 0) {
                if (board[x][y]) {
                    live_neighbors++;
                }
                x--;
                y--;
            }
            x = i - 1;
            y = j;
            while (x >= 0) {
                if (board[x][y]) {
                    live_neighbors++;
                }
                x--;
            }
            x = i;
            y = j + 1;
            while (y < size) {
                if (board[x][y]) {
                    live_neighbors++;
                }
                y++;
            }
            x = i + 1;
            y = j - 1;
            while (x < size && y >= 0) {
                if (board[x][y]) {
                    live_neighbors++;
                }
                x++;
                y--;
            }
            x = i + 1;
            y = j;
            while (x < size) {
                if (board[x][y]) {
                    live_neighbors++;
                }
                x++;
            }
            x = i + 1;
            y = j + 1;
            while (y < size) {
                if (board[x][y]) {
                    live_neighbors++;
                }
                y++;
            }
            // Update the cell based on the number of live neighbors
            if (board[i][j] == 1 && live_neighbors < 2) {
                board[i][j] = 0;
            } else if (board[i][j] == 1 && (live_neighbors == 2 || live_neighbors == 3)) {
                board[i][j] = 1;
            } else if (board[i][j] == 0 && live_neighbors == 3) {
                board[i][j] = 1;
            }
        }
    }
}

// Function to print the Game of Life board
void print_board(int** board, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Initialize the Game of Life board
    int** board = (int**)malloc(sizeof(int*) * 10);
    for (int i = 0; i < 10; i++) {
        board[i] = (int*)malloc(sizeof(int) * 10);
        for (int j = 0; j < 10; j++) {
            board[i][j] = 0;
        }
    }
    // Initialize the board with random cells
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            board[i][j] = rand() % 2;
        }
    }
    // Print the initial board
    printf("Initial board:\n");
    print_board(board, 10);
    // Update the board for 20 generations
    for (int i = 0; i < 20; i++) {
        update_board(board, 10);
        // Print the updated board
        printf("Generation %d:\n", i + 1);
        print_board(board, 10);
    }
    // Free the memory allocated for the board
    for (int i = 0; i < 10; i++) {
        free(board[i]);
    }
    free(board);
    return 0;
}