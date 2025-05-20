//LLAMA2-13B DATASET v1.0 Category: Table Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TABLE_ROWS 10
#define TABLE_COLS 10

// Structure to store the game state
typedef struct {
    int *board;
    int turn;
    int score[2];
} game_state_t;

// Function to initialize the game state
void init_game(game_state_t *state) {
    state->board = malloc(sizeof(int) * TABLE_ROWS * TABLE_COLS);
    for (int i = 0; i < TABLE_ROWS; i++) {
        for (int j = 0; j < TABLE_COLS; j++) {
            state->board[i * TABLE_COLS + j] = 0;
        }
    }
    state->turn = 1;
    state->score[0] = 0;
    state->score[1] = 0;
}

// Function to print the game board
void print_board(game_state_t *state) {
    for (int i = 0; i < TABLE_ROWS; i++) {
        for (int j = 0; j < TABLE_COLS; j++) {
            printf("%d ", state->board[i * TABLE_COLS + j]);
        }
        printf("\n");
    }
}

// Function to make a move
void make_move(game_state_t *state, int row, int col) {
    if (state->board[row * TABLE_COLS + col] == 0) {
        state->board[row * TABLE_COLS + col] = state->turn;
        state->turn *= -1;
        state->score[state->turn]++;
    }
}

// Function to check for a win
int check_win(game_state_t *state) {
    for (int i = 0; i < TABLE_ROWS; i++) {
        if (state->board[i * TABLE_COLS] == state->turn &&
                state->board[(i * TABLE_COLS) + 1] == state->turn &&
                state->board[(i * TABLE_COLS) + 2] == state->turn) {
            return 1;
        }
        if (state->board[i * TABLE_COLS + TABLE_COLS - 1] == state->turn &&
                state->board[(i * TABLE_COLS) + TABLE_COLS - 2] == state->turn &&
                state->board[(i * TABLE_COLS) + TABLE_COLS - 3] == state->turn) {
            return 1;
        }
    }
    for (int i = 0; i < TABLE_COLS; i++) {
        if (state->board[i] == state->turn &&
                state->board[i + TABLE_COLS] == state->turn &&
                state->board[i + 2 * TABLE_COLS] == state->turn) {
            return 1;
        }
    }
    return 0;
}

int main() {
    srand(time(NULL));

    game_state_t state;
    init_game(&state);

    while (1) {
        print_board(&state);
        int row, col;
        printf("Enter row and column (0-9) to place X: ");
        scanf("%d%d", &row, &col);
        make_move(&state, row, col);

        if (check_win(&state)) {
            printf("Game over! %d won!\n", state.turn);
            break;
        }
    }

    return 0;
}