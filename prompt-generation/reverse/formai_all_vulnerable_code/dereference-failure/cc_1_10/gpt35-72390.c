//FormAI DATASET v1.0 Category: Poker Game ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DECK_SIZE 52
#define HAND_SIZE 5

// Card struct
typedef struct {
    char *rank;
    char *suit;
} Card;

// Deck struct
typedef struct {
    int top; // Index of the top card in the deck
    Card *cards[DECK_SIZE]; // Array of pointers to Card structs
} Deck;

// Hand struct
typedef struct {
    Card *cards[HAND_SIZE]; // Array of pointers to Card structs
} Hand;

// Function to create a new deck of cards
Deck* NewDeck() {
    Deck *d = malloc(sizeof(Deck)); // Allocate memory for the new deck
    d->top = 0; // Initialize the top of the deck
    char *ranks[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"}; // Array of possible ranks
    char *suits[4] = {"♠️", "♥️", "♦️", "♣️"}; // Array of possible suits
    for(int i = 0; i < DECK_SIZE; i++) {
        Card *c = malloc(sizeof(Card)); // Allocate memory for a new card
        c->rank = ranks[i % 13]; // Set the rank of the card based on index
        c->suit = suits[i / 13]; // Set the suit of the card based on index
        d->cards[i] = c; // Set the i-th element of the deck to the new card
    }
    return d;
}

// Function to shuffle a deck of cards
void ShuffleDeck(Deck *d) {
    srand(time(NULL)); // Seed the random number generator
    for(int i = 0; i < DECK_SIZE; i++) {
        int j = rand() % DECK_SIZE; // Generate a random index
        // Swap the i-th and j-th elements of the deck
        Card *temp = d->cards[i];
        d->cards[i] = d->cards[j];
        d->cards[j] = temp;
    }
}

// Function to create a new hand of cards
Hand* NewHand() {
    Hand *h = malloc(sizeof(Hand)); // Allocate memory for the new hand
    for(int i = 0; i < HAND_SIZE; i++) {
        h->cards[i] = NULL; // Set all elements of the hand to NULL
    }
    return h;
}

// Function to deal cards from a deck into a hand
void DealCards(Deck *d, Hand *h) {
    for(int i = 0; i < HAND_SIZE; i++) {
        h->cards[i] = d->cards[d->top]; // Add the top card of the deck to the hand
        d->top++; // Increment the top of the deck
    }
}

// Function to print a card
void PrintCard(Card *c) {
    printf("%s%s ", c->rank, c->suit);
}

// Function to print a hand
void PrintHand(Hand *h) {
    for(int i = 0; i < HAND_SIZE; i++) {
        PrintCard(h->cards[i]); // Print each card in the hand
    }
    printf("\n");
}

// Function to determine if a hand contains a flush
int HasFlush(Hand *h) {
    char *suit = h->cards[0]->suit; // Get the suit of the first card
    for(int i = 1; i < HAND_SIZE; i++) {
        if(strcmp(h->cards[i]->suit, suit) != 0) { // If any other card has a different suit
            return 0; // Return false
        }
    }
    return 1; // If all cards have the same suit, return true
}

// Function to determine if a hand contains a straight
int HasStraight(Hand *h) {
    int ranks[HAND_SIZE]; // Array to hold the numeric values of the ranks
    // Convert each rank to a numeric value and store in the ranks array
    for(int i = 0; i < HAND_SIZE; i++) {
        switch(h->cards[i]->rank[0]) { // Switch on the first character of the rank string
            case '2': ranks[i] = 2; break;
            case '3': ranks[i] = 3; break;
            case '4': ranks[i] = 4; break;
            case '5': ranks[i] = 5; break;
            case '6': ranks[i] = 6; break;
            case '7': ranks[i] = 7; break;
            case '8': ranks[i] = 8; break;
            case '9': ranks[i] = 9; break;
            case '1': ranks[i] = 10; break; // Handle the "10" rank
            case 'J': ranks[i] = 11; break;
            case 'Q': ranks[i] = 12; break;
            case 'K': ranks[i] = 13; break;
            case 'A': ranks[i] = 14; break;
        }
    }
    // Sort the ranks array in ascending order
    for(int i = 0; i < HAND_SIZE - 1; i++) {
        for(int j = i + 1; j < HAND_SIZE; j++) {
            if(ranks[i] > ranks[j]) { // Swap elements if the first is greater than the second
                int temp = ranks[i];
                ranks[i] = ranks[j];
                ranks[j] = temp;
            }
        }
    }
    int expected_rank = ranks[0]; // The expected rank is the lowest rank in the hand
    for(int i = 1; i < HAND_SIZE; i++) {
        if(ranks[i] != expected_rank + 1) { // If the next rank is not one greater than the expected rank
            return 0; // Return false
        }
        expected_rank++; // Increment the expected rank
    }
    return 1; // If all ranks are consecutive, return true
}

// Main function
int main() {
    Deck *d = NewDeck(); // Create a new deck of cards
    printf("New deck:\n");
    for(int i = 0; i < DECK_SIZE; i++) {
        PrintCard(d->cards[i]); // Print each card in the deck
    }
    printf("\n\n");
    ShuffleDeck(d); // Shuffle the deck
    printf("Shuffled deck:\n");
    for(int i = 0; i < DECK_SIZE; i++) {
        PrintCard(d->cards[i]); // Print each card in the deck
    }
    printf("\n\n");
    Hand *h = NewHand(); // Create a new hand of cards
    DealCards(d, h); // Deal cards from the deck into the hand
    printf("Your hand:\n");
    PrintHand(h); // Print the hand
    if(HasFlush(h)) { // Check for a flush
        printf("You have a flush!\n");
    } else if(HasStraight(h)) { // Check for a straight
        printf("You have a straight!\n");
    }
    return 0;
}