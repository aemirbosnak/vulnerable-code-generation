//Falcon2-11B DATASET v1.0 Category: Percolation Simulator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 100
#define NEIGHBORS 8

// Structure to represent a board
typedef struct {
    int **board;
    int num_occupied;
} Board;

// Function to initialize a board
Board* initialize_board(int size) {
    Board *board = (Board *)malloc(sizeof(Board));
    board->board = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        board->board[i] = (int *)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            board->board[i][j] = 0;
        }
    }
    board->num_occupied = 0;
    return board;
}

// Function to print the board
void print_board(Board *board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board->board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if a cell is occupied
int is_occupied(Board *board, int x, int y) {
    return board->board[x][y] == 1;
}

// Function to set a cell to occupied
void set_occupied(Board *board, int x, int y) {
    board->board[x][y] = 1;
    board->num_occupied++;
}

// Function to set a cell to empty
void set_empty(Board *board, int x, int y) {
    board->board[x][y] = 0;
    board->num_occupied--;
}

// Function to check if a cell is a neighbor of the current cell
int is_neighbor(Board *board, int x, int y, int dx, int dy) {
    int nx = x + dx;
    int ny = y + dy;
    if (nx < 0 || nx >= BOARD_SIZE || ny < 0 || ny >= BOARD_SIZE) {
        return 0;
    }
    return is_occupied(board, nx, ny);
}

// Function to perform percolation simulation
void percolate(Board *board) {
    int num_steps = 0;
    srand(time(NULL));

    while (board->num_occupied > 0) {
        int rnd_x = rand() % BOARD_SIZE;
        int rnd_y = rand() % BOARD_SIZE;
        if (is_occupied(board, rnd_x, rnd_y)) {
            continue;
        }
        set_occupied(board, rnd_x, rnd_y);
        num_steps++;

        for (int i = 0; i < NEIGHBORS; i++) {
            int dx = -1 + 2 * (rand() % 2);
            int dy = -1 + 2 * (rand() % 2);
            if (is_neighbor(board, rnd_x, rnd_y, dx, dy)) {
                set_occupied(board, rnd_x + dx, rnd_y + dy);
            }
        }
    }

    printf("Number of steps: %d\n", num_steps);
}

int main() {
    Board *board = initialize_board(BOARD_SIZE);
    percolate(board);
    print_board(board);
    free(board->board);
    free(board);
    return 0;
}