//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PAIRS 8
#define NUM_CARDS 2 * NUM_PAIRS

// Card struct
typedef struct {
    int value;
    int matched;
} Card;

// Function to create a new deck of cards
Card* create_deck() {
    Card* deck = malloc(sizeof(Card) * NUM_CARDS);

    // Initialize the deck
    for (int i = 0; i < NUM_PAIRS; i++) {
        deck[2 * i].value = i;
        deck[2 * i + 1].value = i;
    }

    return deck;
}

// Function to shuffle the deck of cards
void shuffle_deck(Card* deck) {
    for (int i = 0; i < NUM_CARDS; i++) {
        // Get a random index to swap with
        int j = rand() % NUM_CARDS;

        // Swap the cards
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// Function to print the deck of cards
void print_deck(Card* deck) {
    for (int i = 0; i < NUM_CARDS; i++) {
        printf("%d ", deck[i].value);
    }
    printf("\n");
}

// Function to get a user's guess
int get_guess() {
    int guess;
    printf("Enter your guess (1-%d): ", NUM_CARDS);
    scanf("%d", &guess);
    return guess - 1;
}

// Function to check if a guess is correct
int is_correct_guess(Card* deck, int guess1, int guess2) {
    return deck[guess1].value == deck[guess2].value;
}

// Function to mark a pair of cards as matched
void mark_cards_as_matched(Card* deck, int guess1, int guess2) {
    deck[guess1].matched = 1;
    deck[guess2].matched = 1;
}

// Function to check if all cards have been matched
int all_cards_matched(Card* deck) {
    for (int i = 0; i < NUM_CARDS; i++) {
        if (!deck[i].matched) {
            return 0;
        }
    }
    return 1;
}

// Function to play the game
void play_game(Card* deck) {
    int guesses = 0;
    int matches = 0;
    shuffle_deck(deck);

    while (!all_cards_matched(deck)) {
        // Get the user's first guess
        int guess1 = get_guess();

        // Get the user's second guess
        int guess2 = get_guess();

        // Check if the guesses are correct
        if (is_correct_guess(deck, guess1, guess2)) {
            matches++;
            mark_cards_as_matched(deck, guess1, guess2);
            printf("Correct guess!\n");
        } else {
            printf("Incorrect guess.\n");
        }

        guesses++;
    }

    // Print the number of guesses and matches
    printf("You won in %d guesses with %d matches!\n", guesses, matches);
}

int main() {
    srand(time(NULL));
    Card* deck = create_deck();
    play_game(deck);
    free(deck);
    return 0;
}