//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Card struct representing a single card in the game
typedef struct Card {
    char suit;
    int value;
    int is_flipped;
} Card;

// Game state struct representing the entire game state
typedef struct GameState {
    Card** board;
    int num_rows;
    int num_cols;
    int num_matches;
    int num_flips;
} GameState;

// Function to create a new game state
GameState* create_game_state(int num_rows, int num_cols) {
    // Allocate memory for the game state
    GameState* state = malloc(sizeof(GameState));
    
    // Set the dimensions of the board
    state->num_rows = num_rows;
    state->num_cols = num_cols;

    // Set the number of matches to 0
    state->num_matches = 0;
    
    // Set the number of flips to 0
    state->num_flips = 0;
    
    // Allocate memory for the board
    state->board = malloc(num_rows * sizeof(Card*));
    for (int i = 0; i < num_rows; i++) {
        state->board[i] = malloc(num_cols * sizeof(Card));
    }
    
    // Initialize the board with random cards
    srand(time(NULL));
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            state->board[i][j].suit = 'A' + rand() % 4;
            state->board[i][j].value = rand() % 13 + 1;
            state->board[i][j].is_flipped = 0;
        }
    }

    // Return the game state
    return state;
}

// Function to free the memory allocated for the game state
void free_game_state(GameState* state) {
    // Free the memory allocated for the board
    for (int i = 0; i < state->num_rows; i++) {
        free(state->board[i]);
    }
    free(state->board);
    
    // Free the memory allocated for the game state
    free(state);
}

// Function to print the game state
void print_game_state(GameState* state) {
    // Print the board
    for (int i = 0; i < state->num_rows; i++) {
        for (int j = 0; j < state->num_cols; j++) {
            if (state->board[i][j].is_flipped) {
                printf("%c%d ", state->board[i][j].suit, state->board[i][j].value);
            } else {
                printf("XX ");
            }
        }
        printf("\n");
    }
    
    // Print the number of matches and flips
    printf("Matches: %d\n", state->num_matches);
    printf("Flips: %d\n", state->num_flips);
}

// Function to flip a card at the given row and column
void flip_card(GameState* state, int row, int col) {
    // Check if the card is already flipped
    if (state->board[row][col].is_flipped) {
        return;
    }
    
    // Flip the card
    state->board[row][col].is_flipped = 1;
    
    // Increment the number of flips
    state->num_flips++;
}

// Function to check if the game is over
int is_game_over(GameState* state) {
    // Check if all the cards have been matched
    for (int i = 0; i < state->num_rows; i++) {
        for (int j = 0; j < state->num_cols; j++) {
            if (!state->board[i][j].is_flipped) {
                return 0;
            }
        }
    }
    
    // Return 1 if the game is over
    return 1;
}

// Function to play the game
void play_game(GameState* state) {
    // Print the game state
    print_game_state(state);
    
    // Get the user's input
    int row1, col1, row2, col2;
    printf("Enter the row and column of the first card: ");
    scanf("%d %d", &row1, &col1);
    printf("Enter the row and column of the second card: ");
    scanf("%d %d", &row2, &col2);
    
    // Flip the first card
    flip_card(state, row1, col1);

    // Flip the second card
    flip_card(state, row2, col2);

    // Check if the cards match
    if (state->board[row1][col1].suit == state->board[row2][col2].suit &&
        state->board[row1][col1].value == state->board[row2][col2].value) {
        // The cards match, so increment the number of matches
        state->num_matches++;
    } else {
        // The cards do not match, so flip them back over
        flip_card(state, row1, col1);
        flip_card(state, row2, col2);
    }

    // Print the game state
    print_game_state(state);
    
    // Check if the game is over
    if (is_game_over(state)) {
        printf("Game over!\n");
    } else {
        // The game is not over, so play again
        play_game(state);
    }
}

// Main function
int main() {
    // Create the game state
    GameState* state = create_game_state(4, 4);
    
    // Play the game
    play_game(state);
    
    // Free the memory allocated for the game state
    free_game_state(state);
    
    return 0;
}