//FormAI DATASET v1.0 Category: Game of Life ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 40

// function to print the board
void print_board(int **board) {
    printf("\n");
    for (int y=0; y<HEIGHT; y++) {
        for (int x=0; x<WIDTH; x++) {
            if (board[y][x] == 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// function to count live neighbours
int count_live_neighbours(int **board, int x, int y) {
    int count = 0;
    for (int i=-1; i<2; i++) {
        for (int j=-1; j<2; j++) {
            int neighbour_x = x + i;
            int neighbour_y = y + j;
            // check for edge cases
            if (neighbour_x < 0 || neighbour_x >= WIDTH || neighbour_y < 0 || neighbour_y >= HEIGHT) {
                continue;
            }
            if (i == 0 && j == 0) {
                continue;
            }
            if (board[neighbour_y][neighbour_x] == 1) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    srand(time(NULL)); // seed the random number generator

    // allocate memory for the starting board
    int **board = (int **)malloc(HEIGHT * sizeof(int *));
    for (int y=0; y<HEIGHT; y++) {
        board[y] = (int *)malloc(WIDTH * sizeof(int));
    }

    // initialize the board randomly
    for (int y=0; y<HEIGHT; y++) {
        for (int x=0; x<WIDTH; x++) {
            board[y][x] = rand() % 2;
        }
    }

    print_board(board);

    // iterate over generations
    for (int gen=0; gen<50; gen++) {
        // allocate memory for the next generation board
        int **next_board = (int **)malloc(HEIGHT * sizeof(int *));
        for (int y=0; y<HEIGHT; y++) {
            next_board[y] = (int *)malloc(WIDTH * sizeof(int));
        }

        for (int y=0; y<HEIGHT; y++) {
            for (int x=0; x<WIDTH; x++) {
                int live_neighbours = count_live_neighbours(board, x, y);
                if (board[y][x] == 1 && (live_neighbours == 2 || live_neighbours == 3)) {
                    next_board[y][x] = 1; // cell survives
                } else if (board[y][x] == 0 && live_neighbours == 3) {
                    next_board[y][x] = 1; // cell is born
                } else {
                    next_board[y][x] = 0; // cell dies
                }
            }
        }

        // free memory of the previous board
        for (int y=0; y<HEIGHT; y++) {
            free(board[y]);
        }
        free(board);

        // update the board to the next generation
        board = next_board;

        printf("Generation %d:\n", gen+1);
        print_board(board);
    }

    // free memory of the last board
    for (int y=0; y<HEIGHT; y++) {
        free(board[y]);
    }
    free(board);

    return 0;
}