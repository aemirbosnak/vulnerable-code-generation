//FormAI DATASET v1.0 Category: Memory Game ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * This is a simple memory game where the user needs to match pairs of numbers.
 * The game board is 4x4 with numbers ranging from 1 to 8.
 */

// Function declarations
void print_board(int **board);
void shuffle(int *array, int n);
void play_game(int **board, int *guess_board);
void reveal_tile(int **board, int *guess_board, int row, int col);

int main() {
    // Seed random number generator
    srand(time(NULL));

    // Initialize game board
    int **board = malloc(4 * sizeof(int *));
    for (int i = 0; i < 4; i++) {
        board[i] = malloc(4 * sizeof(int));
        for (int j = 0; j < 4; j++) {
            // Fill board with numbers 1 to 8 in pairs
            board[i][j] = (j + 1) / 2;
        }
    }

    // Shuffle each row of the board
    for (int i = 0; i < 4; i++) {
        shuffle(board[i], 4);
    }

    // Initialize guess board
    int *guess_board = malloc(4 * 4 * sizeof(int));
    for (int i = 0; i < 4 * 4; i++) {
        guess_board[i] = -1;
    }

    // Play the game
    play_game(board, guess_board);

    // Free memory
    for (int i = 0; i < 4; i++) {
        free(board[i]);
    }
    free(board);
    free(guess_board);

    return 0;
}

/**
 * Prints the game board to the console.
 * Empty tiles are represented by a hyphen (-).
 */
void print_board(int **board) {
    printf("\n");
    printf("      1 | 2 | 3 | 4 |\n");
    printf("      ---------\n");
    for (int i = 0; i < 4; i++) {
        printf("%d |", i + 1);
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == -1) {
                printf(" - ");
            } else {
                printf(" %d ", board[i][j]);
            }
            printf("|");
        }
        printf("\n");
    }
    printf("\n");
}

/**
 * Fisher-Yates shuffle algorithm for shuffling an array.
 */
void shuffle(int *array, int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

/**
 * Main game loop.
 */
void play_game(int **board, int *guess_board) {
    int num_pairs = 0;
    while (num_pairs < 8) {
        // Print current board
        print_board(board);

        // Ask user for row and column to reveal
        int row, col;
        printf("Enter row and column to reveal (e.g. 2 3): ");
        scanf("%d %d", &row, &col);

        // Check if selected tile has already been matched
        if (guess_board[(row-1)*4 + (col-1)] != -1) {
            printf("Tile already matched.\n");
            continue;
        }

        // Reveal selected tile
        reveal_tile(board, guess_board, row-1, col-1);

        // Check if two tiles have been revealed
        int guess1_row, guess1_col, guess2_row, guess2_col;
        printf("Enter first guess and second guess (e.g. 1 2 3 4): ");
        scanf("%d %d %d %d", &guess1_row, &guess1_col, &guess2_row, &guess2_col);

        // Reveal the two guessed tiles
        reveal_tile(board, guess_board, guess1_row-1, guess1_col-1);
        reveal_tile(board, guess_board, guess2_row-1, guess2_col-1);

        // Check if the guessed tiles match
        int guess1 = board[guess1_row-1][guess1_col-1];
        int guess2 = board[guess2_row-1][guess2_col-1];
        if (guess1 == guess2) {
            printf("Matched!\n");
            num_pairs++;
        } else {
            printf("Not a match.\n");
            // Hide the non-matching tiles
            guess_board[(guess1_row-1)*4 + (guess1_col-1)] = -1;
            guess_board[(guess2_row-1)*4 + (guess2_col-1)] = -1;
        }
    }
    printf("Congratulations, you won!\n");
}

/**
 * Reveals the tile at the given row and column by updating the guess board.
 */
void reveal_tile(int **board, int *guess_board, int row, int col) {
    guess_board[row*4 + col] = board[row][col];
}