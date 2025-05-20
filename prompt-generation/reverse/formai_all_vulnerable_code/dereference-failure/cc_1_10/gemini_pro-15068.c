//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define BOARD_SIZE 4
#define NUM_PAIRS 8

// Card states
#define CARD_HIDDEN 0
#define CARD_SHOWN 1
#define CARD_MATCHED 2

// Game state
typedef struct {
    int board[BOARD_SIZE][BOARD_SIZE];
    int num_shown;
    int num_matched;
} game_state;

// Initialize the game state
void init_game(game_state *state) {
    // Generate a random sequence of numbers
    int *numbers = malloc(NUM_PAIRS * 2 * sizeof(int));
    for (int i = 0; i < NUM_PAIRS * 2; i++) {
        numbers[i] = i % NUM_PAIRS;
    }
    for (int i = 0; i < NUM_PAIRS * 2; i++) {
        int j = rand() % (NUM_PAIRS * 2);
        int temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }

    // Fill the board with the numbers
    int index = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            state->board[i][j] = numbers[index++];
        }
    }

    // Initialize the other game state variables
    state->num_shown = 0;
    state->num_matched = 0;
}

// Print the game board
void print_board(game_state *state) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            switch (state->board[i][j]) {
                case CARD_HIDDEN:
                    printf("[] ");
                    break;
                case CARD_SHOWN:
                    printf("[%d] ", state->board[i][j]);
                    break;
                case CARD_MATCHED:
                    printf("[ ] ");
                    break;
            }
        }
        printf("\n");
    }
}

// Flip a card over
void flip_card(game_state *state, int row, int col) {
    if (state->board[row][col] == CARD_HIDDEN) {
        state->board[row][col] = CARD_SHOWN;
        state->num_shown++;
    }
}

// Check if two cards match
int cards_match(game_state *state, int row1, int col1, int row2, int col2) {
    return state->board[row1][col1] == state->board[row2][col2];
}

// Check if the game is over
int is_game_over(game_state *state) {
    return state->num_matched == NUM_PAIRS;
}

// Main game loop
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Initialize the game state
    game_state state;
    init_game(&state);

    // Main game loop
    while (!is_game_over(&state)) {
        // Print the game board
        print_board(&state);

        // Get the user's input
        int row1, col1, row2, col2;
        printf("Enter the coordinates of two cards to flip (e.g. 1 2 3 4): ");
        scanf("%d %d %d %d", &row1, &col1, &row2, &col2);

        // Flip the cards over
        flip_card(&state, row1 - 1, col1 - 1);
        flip_card(&state, row2 - 1, col2 - 1);

        // Check if the cards match
        if (cards_match(&state, row1 - 1, col1 - 1, row2 - 1, col2 - 1)) {
            printf("Match!\n");
            state.board[row1 - 1][col1 - 1] = CARD_MATCHED;
            state.board[row2 - 1][col2 - 1] = CARD_MATCHED;
            state.num_matched++;
        } else {
            printf("No match.\n");
            flip_card(&state, row1 - 1, col1 - 1);
            flip_card(&state, row2 - 1, col2 - 1);
        }
    }

    // Print the final game board
    print_board(&state);

    // Congratulate the player
    printf("Congratulations! You won the game!\n");

    return 0;
}