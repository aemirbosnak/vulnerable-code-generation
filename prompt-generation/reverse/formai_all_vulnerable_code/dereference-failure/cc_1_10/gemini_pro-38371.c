//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4
#define NUM_PAIRS (BOARD_SIZE * BOARD_SIZE / 2)

// Structure to store a card
typedef struct card {
    int value;
    int flipped;
} card;

// Function to create a new game board
card** create_board() {
    // Allocate memory for the board
    card** board = malloc(sizeof(card*) * BOARD_SIZE);
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i] = malloc(sizeof(card) * BOARD_SIZE);
    }

    // Initialize the board with random values
    srand(time(NULL));
    int values[NUM_PAIRS];
    for (int i = 0; i < NUM_PAIRS; i++) {
        values[i] = rand() % 10;
    }

    int index = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j].value = values[index];
            board[i][j].flipped = 0;
            index++;
        }
    }

    return board;
}

// Function to print the game board
void print_board(card** board) {
    printf("  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].flipped) {
                printf("%d ", board[i][j].value);
            } else {
                printf("X ");
            }
        }
        printf("\n");
    }
}

// Function to get a valid move from the user
int get_move(card** board) {
    int row, col;

    do {
        printf("Enter the row and column of the card you want to flip (e.g. 0 0): ");
        scanf("%d %d", &row, &col);
    } while (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE || board[row][col].flipped);

    return row * BOARD_SIZE + col;
}

// Function to check if the game is over
int is_game_over(card** board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (!board[i][j].flipped) {
                return 0;
            }
        }
    }

    return 1;
}

// Function to play the game
void play_game(card** board) {
    int first_card, second_card;

    while (!is_game_over(board)) {
        // Get the first card
        first_card = get_move(board);

        // Flip the first card
        board[first_card / BOARD_SIZE][first_card % BOARD_SIZE].flipped = 1;

        // Print the board
        print_board(board);

        // Get the second card
        second_card = get_move(board);

        // Flip the second card
        board[second_card / BOARD_SIZE][second_card % BOARD_SIZE].flipped = 1;

        // Print the board
        print_board(board);

        // Check if the cards match
        if (board[first_card / BOARD_SIZE][first_card % BOARD_SIZE].value == board[second_card / BOARD_SIZE][second_card % BOARD_SIZE].value) {
            printf("You found a match!\n");
        } else {
            printf("The cards don't match. Try again.\n");

            // Flip the cards back over
            board[first_card / BOARD_SIZE][first_card % BOARD_SIZE].flipped = 0;
            board[second_card / BOARD_SIZE][second_card % BOARD_SIZE].flipped = 0;
        }
    }

    printf("Congratulations! You found all the matches.\n");
}

// Function to free the memory allocated for the game board
void free_board(card** board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        free(board[i]);
    }
    free(board);
}

int main() {
    // Create the game board
    card** board = create_board();

    // Play the game
    play_game(board);

    // Free the memory allocated for the game board
    free_board(board);

    return 0;
}