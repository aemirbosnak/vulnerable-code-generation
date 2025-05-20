//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: real-life
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Initialize the game board with random numbers
void init_board(int *board, int size) {
    srand(time(NULL));
    for (int i = 0; i < size * size; i++) {
        board[i] = rand() % (size * size);
    }
}

// Shuffle the game board
void shuffle_board(int *board, int size) {
    int temp;
    for (int i = 0; i < size * size; i++) {
        int j = rand() % (size * size);
        temp = board[i];
        board[i] = board[j];
        board[j] = temp;
    }
}

// Print the game board
void print_board(int *board, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", board[i * size + j]);
        }
        printf("\n");
    }
}

// Check if the two cards are a match
int check_match(int a, int b) {
    return a == b;
}

// Get the input from the user
int get_input(int size) {
    int input;
    printf("Enter a number between 1 and %d: ", size * size);
    scanf("%d", &input);
    return input;
}

// Main game loop
int main() {
    int size = 4;
    int *board = malloc(sizeof(int) * size * size);

    init_board(board, size);
    shuffle_board(board, size);
    print_board(board, size);

    int first_card, second_card;
    int attempts = 0;
    int matches = 0;

    while (matches < size * size) {
        first_card = get_input(size);
        second_card = get_input(size);

        if (check_match(board[first_card - 1], board[second_card - 1])) {
            matches++;
            printf("Match found!\n");
        } else {
            printf("No match, try again.\n");
        }
        attempts++;
    }

    printf("You won the game in %d attempts.\n", attempts);
    free(board);
    return 0;
}