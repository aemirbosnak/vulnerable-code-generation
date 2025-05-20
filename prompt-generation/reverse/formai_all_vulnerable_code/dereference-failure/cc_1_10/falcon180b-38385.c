//Falcon-180B DATASET v1.0 Category: Game of Life ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 30
#define NEIGHBORS 8

// Define the initial state of the game
void init(int **board) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            *board = rand() % 2;
        }
    }
}

// Print the state of the game
void print(int **board) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (*board == 0) {
                printf("  ");
            } else {
                printf("* ");
            }
        }
        printf("\n");
    }
}

// Count the number of live neighbors
int count_neighbors(int **board, int x, int y) {
    int count = 0;
    int i, j;
    for (i = -1; i <= 1; i++) {
        for (j = -1; j <= 1; j++) {
            if ((i!= 0 || j!= 0) && (x + i >= 0 && x + i < HEIGHT && y + j >= 0 && y + j < WIDTH)) {
                count += *board;
            }
        }
    }
    return count;
}

// Update the state of the game
void update(int **board) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            int count = count_neighbors(board, i, j);
            if (*board == 1) {
                if (count < 2) {
                    *board = 0;
                } else if (count > 3) {
                    *board = 0;
                } else {
                    *board = 1;
                }
            } else {
                if (count == 3) {
                    *board = 1;
                }
            }
        }
    }
}

// Main function
int main() {
    int **board;
    int i, j;
    srand(time(NULL));
    board = (int **) malloc(HEIGHT * sizeof(int *));
    for (i = 0; i < HEIGHT; i++) {
        board[i] = (int *) malloc(WIDTH * sizeof(int));
    }
    init(board);
    while (1) {
        print(board);
        update(board);
    }
    return 0;
}