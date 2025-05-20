//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent a card
typedef struct {
    int value;
    int is_matched;
} Card;

// Function to create a new deck of cards
Card* create_deck(int num_cards) {
    Card* deck = malloc(sizeof(Card) * num_cards);
    for (int i = 0; i < num_cards; i++) {
        deck[i].value = i % (num_cards / 2);
        deck[i].is_matched = 0;
    }
    return deck;
}

// Function to shuffle the deck of cards
void shuffle_deck(Card* deck, int num_cards) {
    for (int i = 0; i < num_cards; i++) {
        int j = rand() % num_cards;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// Function to print the deck of cards
void print_deck(Card* deck, int num_cards) {
    for (int i = 0; i < num_cards; i++) {
        printf("%d ", deck[i].value);
    }
    printf("\n");
}

// Function to get the player's guess
int get_guess(Card* deck, int num_cards) {
    int guess;
    printf("Enter your guess (0-%d): ", num_cards - 1);
    scanf("%d", &guess);
    return guess;
}

// Function to check if the guess is correct
int check_guess(Card* deck, int guess) {
    if (deck[guess].is_matched == 1) {
        printf("You already matched that card!\n");
        return 0;
    } else if (deck[guess].value == deck[guess].value) {
        deck[guess].is_matched = 1;
        printf("You matched a pair!\n");
        return 1;
    } else {
        printf("Sorry, that's not a match.\n");
        return 0;
    }
}

// Function to check if the game is over
int is_game_over(Card* deck, int num_cards) {
    for (int i = 0; i < num_cards; i++) {
        if (deck[i].is_matched == 0) {
            return 0;
        }
    }
    return 1;
}

// Main function
int main() {
    srand(time(NULL));
    int num_cards = 10;
    Card* deck = create_deck(num_cards);
    shuffle_deck(deck, num_cards);

    int guesses = 0;
    int matches = 0;

    while (!is_game_over(deck, num_cards)) {
        print_deck(deck, num_cards);
        int guess = get_guess(deck, num_cards);
        if (check_guess(deck, guess)) {
            matches++;
        }
        guesses++;
    }

    printf("You matched all the pairs in %d guesses!\n", guesses);

    free(deck);
    return 0;
}