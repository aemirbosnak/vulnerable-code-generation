//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent a card
typedef struct {
    int value;
    int matched;
} Card;

// Function to create a deck of cards
Card* create_deck() {
    // Allocate memory for the deck
    Card* deck = malloc(sizeof(Card) * 16);

    // Initialize the deck with values
    int values[] = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8};
    for (int i = 0; i < 16; i++) {
        deck[i].value = values[i];
        deck[i].matched = 0;
    }

    // Return the deck
    return deck;
}

// Function to shuffle the deck
void shuffle_deck(Card* deck) {
    // Initialize the random number generator
    srand(time(NULL));

    // Shuffle the deck
    for (int i = 0; i < 16; i++) {
        int r = rand() % 16;
        Card temp = deck[i];
        deck[i] = deck[r];
        deck[r] = temp;
    }
}

// Function to print the deck
void print_deck(Card* deck) {
    for (int i = 0; i < 16; i++) {
        printf("%d ", deck[i].value);
    }
    printf("\n");
}

// Function to get the user's guess
int get_guess() {
    int guess;
    printf("Enter your guess (1-16): ");
    scanf("%d", &guess);
    return guess - 1;
}

// Function to check if the guess is correct
int check_guess(Card* deck, int guess1, int guess2) {
    return deck[guess1].value == deck[guess2].value;
}

// Function to mark the cards as matched
void mark_matched(Card* deck, int guess1, int guess2) {
    deck[guess1].matched = 1;
    deck[guess2].matched = 1;
}

// Function to check if all cards are matched
int check_win(Card* deck) {
    for (int i = 0; i < 16; i++) {
        if (!deck[i].matched) {
            return 0;
        }
    }
    return 1;
}

// Function to play the game
void play_game() {
    // Create the deck
    Card* deck = create_deck();

    // Shuffle the deck
    shuffle_deck(deck);

    // Print the deck
    print_deck(deck);

    // Get the user's first guess
    int guess1 = get_guess();

    // Get the user's second guess
    int guess2 = get_guess();

    // Check if the guess is correct
    int correct = check_guess(deck, guess1, guess2);

    // If the guess is correct, mark the cards as matched
    if (correct) {
        mark_matched(deck, guess1, guess2);
    }

    // Print the deck
    print_deck(deck);

    // Check if all cards are matched
    int win = check_win(deck);

    // If all cards are matched, print a winning message
    if (win) {
        printf("You win!\n");
    } else {
        printf("Try again!\n");
    }

    // Free the memory allocated for the deck
    free(deck);
}

// Main function
int main() {
    // Play the game
    play_game();

    return 0;
}