//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the game board size
#define BOARD_SIZE 4

// Define the number of pairs of cards
#define NUM_PAIRS 8

// Define the card values
const char *card_values[] = {
    "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight",
    "Nine", "Ten", "Jack", "Queen", "King"
};

// Define the game state
enum game_state {
    GAME_STATE_PLAYING,
    GAME_STATE_WON,
    GAME_STATE_LOST
};

// Define the card struct
typedef struct card {
    char *value;
    int is_flipped;
    int is_matched;
} card_t;

// Create the game board
card_t **create_board() {
    // Allocate memory for the game board
    card_t **board = malloc(BOARD_SIZE * sizeof(card_t *));
    if (board == NULL) {
        printf("Error: Could not allocate memory for the game board.\n");
        exit(1);
    }

    // Allocate memory for each row of the game board
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i] = malloc(BOARD_SIZE * sizeof(card_t));
        if (board[i] == NULL) {
            printf("Error: Could not allocate memory for row %d of the game board.\n", i);
            exit(1);
        }
    }

    // Initialize the game board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j].value = NULL;
            board[i][j].is_flipped = 0;
            board[i][j].is_matched = 0;
        }
    }

    return board;
}

// Free the game board
void free_board(card_t **board) {
    // Free each row of the game board
    for (int i = 0; i < BOARD_SIZE; i++) {
        free(board[i]);
    }

    // Free the game board
    free(board);
}

// Shuffle the cards
void shuffle_cards(card_t **board) {
    // Seed the random number generator
    srand(time(NULL));

    // Shuffle the cards
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {
        // Get a random index
        int index1 = rand() % (BOARD_SIZE * BOARD_SIZE);

        // Get another random index
        int index2 = rand() % (BOARD_SIZE * BOARD_SIZE);

        // Swap the cards
        card_t temp = board[index1 / BOARD_SIZE][index1 % BOARD_SIZE];
        board[index1 / BOARD_SIZE][index1 % BOARD_SIZE] = board[index2 / BOARD_SIZE][index2 % BOARD_SIZE];
        board[index2 / BOARD_SIZE][index2 % BOARD_SIZE] = temp;
    }
}

// Print the game board
void print_board(card_t **board) {
    printf("  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%2d ", i + 1);
    }
    printf("\n");

    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].is_flipped) {
                printf("%3s ", board[i][j].value);
            } else {
                printf("    ");
            }
        }
        printf("\n");
    }
}

// Get the user's input
void get_input(int *row1, int *col1, int *row2, int *col2) {
    printf("Enter the row and column of the first card: ");
    scanf("%d %d", row1, col1);

    printf("Enter the row and column of the second card: ");
    scanf("%d %d", row2, col2);
}

// Flip the cards
void flip_cards(card_t **board, int row1, int col1, int row2, int col2) {
    // Flip the first card
    board[row1][col1].is_flipped = 1;

    // Flip the second card
    board[row2][col2].is_flipped = 1;
}

// Check if the cards match
int check_match(card_t **board, int row1, int col1, int row2, int col2) {
    // Check if the cards are the same
    if (strcmp(board[row1][col1].value, board[row2][col2].value) == 0) {
        // The cards match
        board[row1][col1].is_matched = 1;
        board[row2][col2].is_matched = 1;
        return 1;
    } else {
        // The cards do not match
        return 0;
    }
}

// Check if the game is won
int check_win(card_t **board) {
    // Check if all of the cards are matched
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (!board[i][j].is_matched) {
                // Not all of the cards are matched
                return 0;
            }
        }
    }

    // All of the cards are matched
    return 1;
}

// Play the game
void play_game() {
    // Create the game board
    card_t **board = create_board();

    // Shuffle the cards
    shuffle_cards(board);

    // Print the game board
    print_board(board);

    // Get the user's input
    int row1, col1, row2, col2;
    get_input(&row1, &col1, &row2, &col2);

    // Flip the cards
    flip_cards(board, row1 - 1, col1 - 1, row2 - 1, col2 - 1);

    // Check if the cards match
    int match = check_match(board, row1 - 1, col1 - 1, row2 - 1, col2 - 1);

    // Print the game board
    print_board(board);

    // Check if the game is won
    int win = check_win(board);

    // Print the game status
    if (win) {
        printf("You won!\n");
    } else if (match) {
        printf("Match!\n");
    } else {
        printf("Try again.\n");
    }

    // Free the game board
    free_board(board);
}

// Main function
int main() {
    // Play the game
    play_game();

    return 0;
}