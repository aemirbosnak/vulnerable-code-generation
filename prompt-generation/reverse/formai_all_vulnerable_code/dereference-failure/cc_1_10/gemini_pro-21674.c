//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: single-threaded
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Card struct
typedef struct card {
    int value;
    int matched;
} card;

// Function to create a new deck of cards
card *createDeck() {
    // Allocate memory for the deck
    card *deck = malloc(sizeof(card) * 16);
    
    // Initialize the deck
    int values[] = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8};
    for (int i = 0; i < 16; i++) {
        deck[i].value = values[i];
        deck[i].matched = 0;
    }
    
    // Return the deck
    return deck;
}

// Function to shuffle the deck of cards
void shuffleDeck(card *deck) {
    // Seed the random number generator
    srand(time(NULL));
    
    // Shuffle the deck
    for (int i = 0; i < 16; i++) {
        int j = rand() % 16;
        card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// Function to print the deck of cards
void printDeck(card *deck) {
    for (int i = 0; i < 16; i++) {
        printf("%d ", deck[i].value);
    }
    printf("\n");
}

// Function to get the user's input
int getInput() {
    int input;
    printf("Enter the number of the card you want to flip: ");
    scanf("%d", &input);
    return input;
}

// Function to flip a card
void flipCard(card *deck, int index) {
    deck[index].matched = 1;
}

// Function to check if the game is over
int isGameOver(card *deck) {
    for (int i = 0; i < 16; i++) {
        if (deck[i].matched == 0) {
            return 0;
        }
    }
    return 1;
}

// Main function
int main() {
    // Create a new deck of cards
    card *deck = createDeck();
    
    // Shuffle the deck
    shuffleDeck(deck);
    
    // Print the deck
    printDeck(deck);
    
    // Get the user's input
    int input1 = getInput();
    int input2 = getInput();
    
    // Flip the cards
    flipCard(deck, input1 - 1);
    flipCard(deck, input2 - 1);
    
    // Print the deck
    printDeck(deck);
    
    // Check if the cards match
    if (deck[input1 - 1].value == deck[input2 - 1].value) {
        printf("Match!\n");
    } else {
        printf("No match!\n");
    }
    
    // Check if the game is over
    if (isGameOver(deck)) {
        printf("Game over!\n");
    }
    
    // Free the memory allocated for the deck
    free(deck);
    
    return 0;
}