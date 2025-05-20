//FormAI DATASET v1.0 Category: Game of Life ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define WIDTH 40
#define HEIGHT 20

// define custom game rules
int shouldLive(int neighbors, int alive) {
    if (alive) {
        return (neighbors == 2) || (neighbors == 3);
    } else {
        return (neighbors == 3) || (neighbors == 5);
    }
}

// calculate the number of living neighbors around a cell
int countNeighbors(int x, int y, int** board) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int neighbor_x = x + i;
            int neighbor_y = y + j;
            if (i == 0 && j == 0) {
                // ignore self
            } else if (neighbor_x < 0 || neighbor_y < 0 || neighbor_x >= WIDTH || neighbor_y >= HEIGHT) {
                // out of bounds
            } else if (board[neighbor_x][neighbor_y]) {
                count++;
            }
        }
    }
    return count;
}

// print the board to the screen
void printBoard(int** board) {
    printf("\033[H"); // move cursor to top left of screen
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%c", board[x][y] ? '*' : ' ');
        }
        printf("\n");
    }
    fflush(stdout);
}

int main() {
    // initialize the board
    int** board = (int**) malloc(WIDTH * sizeof(int*));
    for (int x = 0; x < WIDTH; x++) {
        board[x] = (int*) calloc(HEIGHT, sizeof(int));
    }

    // create a glider at the center of the board
    board[WIDTH/2][HEIGHT/2] = 1;
    board[WIDTH/2][HEIGHT/2+1] = 1;
    board[WIDTH/2][HEIGHT/2-1] = 1;
    board[WIDTH/2-1][HEIGHT/2] = 1;
    board[WIDTH/2+1][HEIGHT/2-1] = 1;

    // run the game loop
    while (1) {
        printBoard(board);
        usleep(100000); // sleep for 100ms
        int** newBoard = (int**) malloc(WIDTH * sizeof(int*));
        for (int x = 0; x < WIDTH; x++) {
            newBoard[x] = (int*) calloc(HEIGHT, sizeof(int));
        }
        for (int y = 0; y < HEIGHT; y++) {
            for (int x = 0; x < WIDTH; x++) {
                int neighbors = countNeighbors(x, y, board);
                int alive = board[x][y];
                if (shouldLive(neighbors, alive)) {
                    newBoard[x][y] = 1;
                }
            }
        }
        for (int x = 0; x < WIDTH; x++) {
            free(board[x]);
        }
        free(board);
        board = newBoard;
    }

    return 0;
}