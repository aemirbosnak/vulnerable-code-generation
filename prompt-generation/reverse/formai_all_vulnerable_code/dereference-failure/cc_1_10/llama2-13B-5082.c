//LLAMA2-13B DATASET v1.0 Category: Table Game ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent the game state
typedef struct {
    int *grid;  // 2D array representing the game board
    int rows;  // Number of rows in the grid
    int cols;  // Number of columns in the grid
    int score;  // Current player score
    int turn;  // Current player turn (0 for X, 1 for O)
} game_state_t;

// Function to initialize the game state
void init_game_state(game_state_t *state, int rows, int cols) {
    state->grid = calloc(rows * cols, sizeof(int));
    state->rows = rows;
    state->cols = cols;
    state->score = 0;
    state->turn = 0;
}

// Function to print the game board
void print_board(game_state_t *state) {
    printf("  1 | 2 | 3\n");
    for (int i = 1; i <= state->rows; i++) {
        for (int j = 1; j <= state->cols; j++) {
            if (state->grid[i * state->cols + j] == 1) {
                printf(" X ");
            } else if (state->grid[i * state->cols + j] == 0) {
                printf(" O ");
            }
        }
        printf("\n");
    }
}

// Function to make a move
void make_move(game_state_t *state, int row, int col) {
    if (state->grid[row * state->cols + col] == 0) {
        state->grid[row * state->cols + col] = state->turn;
        state->score += state->turn;
        state->turn = (state->turn + 1) % 2;
    }
}

// Function to check for a win
int check_win(game_state_t *state) {
    int rows_win = 1;
    int cols_win = 1;
    int diag_win = 1;

    // Check rows
    for (int i = 1; i <= state->rows; i++) {
        if (state->grid[i * state->cols + 1] != state->grid[i * state->cols + state->cols]) {
            rows_win = 0;
            break;
        }
    }

    // Check cols
    for (int j = 1; j <= state->cols; j++) {
        if (state->grid[1 * state->rows + j] != state->grid[state->rows * state->cols + j]) {
            cols_win = 0;
            break;
        }
    }

    // Check diagonals
    for (int i = 1; i <= state->rows; i++) {
        if (state->grid[i * state->cols + 1] != state->grid[i * state->cols + state->cols]) {
            diag_win = 0;
            break;
        }
    }

    return rows_win || cols_win || diag_win;
}

// Function to play the game
void play_game(game_state_t *state) {
    int move;

    // Print the initial game board
    print_board(state);

    // Get the first player's move
    printf("Enter row and column for X (1-%d, 1-%d): ", state->rows, state->cols);
    scanf("%d%d", &move, &move);

    // Make the move
    make_move(state, move, move);

    // Check for a win
    if (check_win(state)) {
        printf("Game over! %d wins.\n", state->turn);
        return;
    }

    // Print the updated game board
    print_board(state);

    // Get the second player's move
    printf("Enter row and column for O (1-%d, 1-%d): ", state->rows, state->cols);
    scanf("%d%d", &move, &move);

    // Make the move
    make_move(state, move, move);

    // Check for a win
    if (check_win(state)) {
        printf("Game over! %d wins.\n", state->turn);
        return;
    }

    // Print the updated game board
    print_board(state);

    // Repeat the game until a win or a draw
    play_game(state);
}

int main() {
    srand(time(NULL));  // Seed the random number generator

    // Create the game state
    game_state_t state;
    init_game_state(&state, 3, 3);

    // Play the game
    play_game(&state);

    return 0;
}