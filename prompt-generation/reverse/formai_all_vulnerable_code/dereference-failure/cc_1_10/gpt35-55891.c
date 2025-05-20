//FormAI DATASET v1.0 Category: Game of Life ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to print the board
void print_board(int **board, int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (board[i][j] == 1) {
                printf(" * ");
            } else {
                printf(" . ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

// function to initialize the board with random values
void initialize_board(int **board, int height, int width) {
    srand(time(NULL));
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

// function to count the number of live neighbors for a given cell
int count_live_neighbors(int **board, int height, int width, int i, int j) {
    int live_neighbors = 0;
    for (int x = -1; x <= 1; x++) {
        for (int y = -1; y <= 1; y++) {
            // skip the current cell
            if (x == 0 && y == 0) {
                continue;
            }
            // check if neighbor is valid and alive
            if (i+x >= 0 && i+x < height && j+y >= 0 && j+y < width && board[i+x][j+y] == 1) {
                live_neighbors++;
            }
        }
    }
    return live_neighbors;
}

// function to update the board based on the Game of Life rules
void update_board(int **board, int height, int width) {
    int **new_board = (int **)malloc(height * sizeof(int *));
    for (int i = 0; i < height; i++) {
        new_board[i] = (int *)malloc(width * sizeof(int));
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int live_neighbors = count_live_neighbors(board, height, width, i, j);
            // update based on live neighbor count
            if (board[i][j] == 1) {
                if (live_neighbors < 2 || live_neighbors > 3) {
                    new_board[i][j] = 0;
                } else {
                    new_board[i][j] = 1;
                }
            } else {
                if (live_neighbors == 3) {
                    new_board[i][j] = 1;
                } else {
                    new_board[i][j] = 0;
                }
            }
        }
    }
    // copy the new board to the old board
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            board[i][j] = new_board[i][j];
        }
    }
    // free the new board
    for (int i = 0; i < height; i++) {
        free(new_board[i]);
    }
    free(new_board);
}

int main() {
    int height, width, generations;

    printf("Enter the height of the board: ");
    scanf("%d", &height);

    printf("Enter the width of the board: ");
    scanf("%d", &width);

    printf("Enter the number of generations: ");
    scanf("%d", &generations);

    // allocate memory for the board
    int **board = (int **)malloc(height * sizeof(int *));
    for (int i = 0; i < height; i++) {
        board[i] = (int *)malloc(width * sizeof(int));
    }

    // initialize the board
    initialize_board(board, height, width);

    // run the game for the specified number of generations
    for (int i = 0; i < generations; i++) {
        printf("Generation %d:\n", i+1);
        print_board(board, height, width);
        update_board(board, height, width);
    }

    // free memory used for the board
    for (int i = 0; i < height; i++) {
        free(board[i]);
    }
    free(board);

    return 0;
}