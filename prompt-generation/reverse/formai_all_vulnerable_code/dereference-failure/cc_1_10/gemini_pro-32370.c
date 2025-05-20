//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to represent a card
typedef struct {
    char *front;
    char *back;
} Card;

// Function to create a new deck of cards
Card *create_deck() {
    // Allocate memory for the deck
    Card *deck = malloc(sizeof(Card) * 52);

    // Initialize the deck
    for (int i = 0; i < 52; i++) {
        deck[i].front = malloc(sizeof(char) * 3);
        deck[i].back = malloc(sizeof(char) * 3);

        // Set the front of the card
        deck[i].front[0] = (i / 13) + '2';
        deck[i].front[1] = (i % 13) + 'A';
        deck[i].front[2] = '\0';

        // Set the back of the card
        strcpy(deck[i].back, "##");
    }

    return deck;
}

// Function to shuffle the deck of cards
void shuffle_deck(Card *deck) {
    // Seed the random number generator
    srand(time(NULL));

    // Shuffle the deck
    for (int i = 0; i < 52; i++) {
        int r = rand() % 52;

        // Swap the cards
        Card temp = deck[i];
        deck[i] = deck[r];
        deck[r] = temp;
    }
}

// Function to deal a hand of cards to a player
Card **deal_hand(Card *deck, int num_cards) {
    // Allocate memory for the hand
    Card **hand = malloc(sizeof(Card *) * num_cards);

    // Deal the cards
    for (int i = 0; i < num_cards; i++) {
        hand[i] = &deck[i];
    }

    return hand;
}

// Function to play the game
void play_game(Card **hand1, Card **hand2) {
    // Get the number of cards in each hand
    int num_cards1 = sizeof(hand1) / sizeof(Card *);
    int num_cards2 = sizeof(hand2) / sizeof(Card *);

    // Compare the cards in the two hands
    for (int i = 0; i < num_cards1; i++) {
        for (int j = 0; j < num_cards2; j++) {
            // If the cards match, print the cards and remove them from the hands
            if (strcmp(hand1[i]->front, hand2[j]->front) == 0) {
                printf("Match: %s\n", hand1[i]->front);
                hand1[i] = NULL;
                hand2[j] = NULL;
            }
        }
    }

    // Check if either player has won
    int won1 = 1;
    int won2 = 1;
    for (int i = 0; i < num_cards1; i++) {
        if (hand1[i] != NULL) {
            won1 = 0;
        }
    }

    for (int i = 0; i < num_cards2; i++) {
        if (hand2[i] != NULL) {
            won2 = 0;
        }
    }
    
    if (won1) {
        printf("Player 1 wins!\n");
    } else if (won2) {
        printf("Player 2 wins!\n");
    } else {
        printf("Tie!\n");
    }
}

// Free the memory used by the game
void free_memory(Card *deck, Card **hand1, Card **hand2) {
    // Free the deck
    for (int i = 0; i < 52; i++) {
        free(deck[i].front);
        free(deck[i].back);
    }
    free(deck);

    // Free the hands
    free(hand1);
    free(hand2);
}

// Main function
int main() {
    // Create the deck of cards
    Card *deck = create_deck();

    // Shuffle the deck
    shuffle_deck(deck);

    // Deal the hands
    Card **hand1 = deal_hand(deck, 26);
    Card **hand2 = deal_hand(deck, 26);

    // Play the game
    play_game(hand1, hand2);

    // Free the memory used by the game
    free_memory(deck, hand1, hand2);

    return 0;
}