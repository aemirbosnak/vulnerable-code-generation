//FormAI DATASET v1.0 Category: Data structures visualization ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a structure representing a card
typedef struct {
    int value;
    char suit;
} Card;

// Define a function to generate a shuffled deck of cards
Card* generate_deck() {
    Card* deck = (Card*)malloc(52*sizeof(Card)); // Allocate memory for 52 cards
    char suits[4] = {'H', 'D', 'S', 'C'}; // Define the four suits
    int values[13] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14}; // Define the thirteen card values
    int index = 0;
    // Loop through all combinations of suits and values, adding each card to the deck
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            deck[index].value = values[j];
            deck[index].suit = suits[i];
            index++;
        }
    }
    // Shuffle the deck using the Fisher-Yates algorithm
    for (int i = 51; i > 0; i--) {
        int j = rand() % (i+1);
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
    return deck;
}

// Define a function to print a card in a visually appealing way
void print_card(Card card) {
    if (card.value == 10) {
        printf(" %c10", card.suit);
    }
    else {
        printf(" %c%d ", card.suit, card.value);
    }
}

// Define a function to print a visual representation of a hand of cards
void print_hand(Card* hand, int size) {
    for (int i = 0; i < size; i++) {
        print_card(hand[i]);
        printf("|");
    }
    printf("\n");
}

// Define the main function
int main() {
    srand(time(NULL)); // Seed the random number generator
    Card* deck = generate_deck(); // Generate a shuffled deck of cards
    printf("Here is a shuffled deck of cards:\n");
    print_hand(deck, 52); // Print the deck
    int i = 0;
    int j = 0;
    Card temp;
    // Sort the cards using a modified bubble sort algorithm
    for (i = 0; i < 52; i++) {
        for (j = 0; j < 52-i-1; j++) {
            if (deck[j].value > deck[j+1].value) {
                temp = deck[j];
                deck[j] = deck[j+1];
                deck[j+1] = temp;
                printf("Swapping:");
                print_hand(&deck[j], 2); // Print the two cards being swapped
            }
        }
    }
    printf("Here is the sorted deck of cards:\n");
    print_hand(deck, 52); // Print the sorted deck
    free(deck); // Free the heap memory occupied by the deck
    return 0;
}