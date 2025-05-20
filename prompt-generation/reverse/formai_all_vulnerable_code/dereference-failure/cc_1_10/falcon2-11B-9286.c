//Falcon2-11B DATASET v1.0 Category: Memory Game ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Function to initialize the game board
void initialize_board(int** board, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        board[i] = (int*)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

// Function to print the game board
void print_board(int** board, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a tile is matched
bool is_match(int** board, int size, int row, int col) {
    int matched = true;
    for (int i = 0; i < size; i++) {
        if (board[i][col]!= board[row][i]) {
            matched = false;
        }
    }
    return matched;
}

// Function to check if a tile is free
bool is_free(int** board, int size, int row, int col) {
    return board[row][col] == 0;
}

// Function to play a turn
void play_turn(int** board, int size, int* turn_count, int* free_count, int* match_count) {
    printf("Turn %d\n", *turn_count);
    print_board(board, size);
    printf("Free tiles: %d\n", *free_count);
    printf("Matched tiles: %d\n", *match_count);

    int row, col;
    printf("Enter row and column of the tile to flip:\n");
    scanf("%d %d", &row, &col);

    if (is_free(board, size, row, col)) {
        board[row][col] =!board[row][col];
        (*turn_count)++;
    } else if (is_match(board, size, row, col)) {
        board[row][col] =!board[row][col];
        (*match_count)++;
    } else {
        printf("Invalid move!\n");
    }

    if (is_match(board, size, row, col)) {
        (*free_count) -= 2;
    } else {
        (*free_count)--;
    }
}

// Main function
int main() {
    int size = 4;
    int** board = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        board[i] = (int*)malloc(size * sizeof(int));
    }
    initialize_board(board, size);

    int turn_count = 1;
    int free_count = size * size;
    int match_count = 0;

    while (true) {
        play_turn(board, size, &turn_count, &free_count, &match_count);
        if (free_count == 0 && match_count == size * size) {
            printf("Congratulations, you win!\n");
            break;
        }
    }

    for (int i = 0; i < size; i++) {
        free(board[i]);
    }
    free(board);

    return 0;
}