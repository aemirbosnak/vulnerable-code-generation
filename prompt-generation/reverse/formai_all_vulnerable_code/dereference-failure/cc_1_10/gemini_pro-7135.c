//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4
#define NUM_PAIRS 8
#define MAX_TURNS 20

// Card struct
typedef struct {
    int value;
    int flipped;
} Card;

// Board struct
typedef struct {
    Card cards[BOARD_SIZE][BOARD_SIZE];
} Board;

// Function to create a new board
Board* create_board() {
    // Allocate memory for the board
    Board* board = malloc(sizeof(Board));

    // Initialize the board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board->cards[i][j].value = -1;
            board->cards[i][j].flipped = 0;
        }
    }

    return board;
}

// Function to destroy a board
void destroy_board(Board* board) {
    // Free the memory allocated for the board
    free(board);
}

// Function to shuffle the cards on the board
void shuffle_cards(Board* board) {
    // Create an array to store the values of the cards
    int values[BOARD_SIZE * BOARD_SIZE];

    // Initialize the array
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {
        values[i] = i / 2;
    }

    // Shuffle the array
    srand(time(NULL));
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {
        int j = rand() % (BOARD_SIZE * BOARD_SIZE);
        int temp = values[i];
        values[i] = values[j];
        values[j] = temp;
    }

    // Copy the values back to the board
    int index = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board->cards[i][j].value = values[index++];
        }
    }
}

// Function to print the board
void print_board(Board* board) {
    printf("  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i + 1);
    }
    printf("\n");

    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board->cards[i][j].flipped) {
                printf("%d ", board->cards[i][j].value + 1);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

// Function to get the input from the user
int get_input() {
    int input;
    printf("Enter the row and column of the card you want to flip (e.g. 1 2): ");
    scanf("%d %d", &input, &input);
    return input;
}

// Function to check if the game is over
int is_game_over(Board* board) {
    // Check if all the cards are flipped
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (!board->cards[i][j].flipped) {
                return 0;
            }
        }
    }

    return 1;
}

// Main function
int main() {
    // Create a new board
    Board* board = create_board();

    // Shuffle the cards on the board
    shuffle_cards(board);

    // Print the board
    print_board(board);

    // Get the input from the user
    int input = get_input();

    // Flip the card
    board->cards[input - 1][input - 1].flipped = 1;

    // Print the board
    print_board(board);

    // Check if the game is over
    if (is_game_over(board)) {
        printf("You win!\n");
    } else {
        printf("Keep playing!\n");
    }

    // Destroy the board
    destroy_board(board);

    return 0;
}