//Falcon2-11B DATASET v1.0 Category: Memory Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// A struct to hold the cards
struct Card {
    int number;
    int face;
};

// Function to initialize a deck of cards
void init_deck(struct Card *deck, int num_cards) {
    // Initialize all cards to face down
    for (int i = 0; i < num_cards; i++) {
        deck[i].number = i + 1;
        deck[i].face = 0;
    }
}

// Function to print the current state of the deck
void print_deck(struct Card *deck, int num_cards) {
    for (int i = 0; i < num_cards; i++) {
        if (deck[i].face == 0) {
            printf(" ");
        } else {
            printf("%d", deck[i].number);
        }
    }
    printf("\n");
}

// Function to flip a card
void flip_card(struct Card *deck, int index) {
    deck[index].face = 1 - deck[index].face;
}

// Function to play the memory game
void play_memory(struct Card *deck, int num_cards) {
    printf("Welcome to the Memory Game!\n");

    // Print the initial state of the deck
    print_deck(deck, num_cards);

    // Shuffle the deck
    for (int i = 0; i < num_cards; i++) {
        int j = rand() % (num_cards - i);
        struct Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }

    // Print the shuffled state of the deck
    print_deck(deck, num_cards);

    // Keep playing until the deck is empty
    while (num_cards > 0) {
        printf("Turn: ");
        int index1, index2;
        scanf("%d %d", &index1, &index2);

        // Check if both indices are valid
        if (index1 < num_cards && index2 < num_cards && index1!= index2) {
            // Flip the cards
            flip_card(deck, index1);
            flip_card(deck, index2);

            // Check if the cards match
            if (deck[index1].face == deck[index2].face) {
                printf("You win!\n");
                exit(0);
            } else {
                printf("You lose...\n");
                exit(0);
            }
        } else {
            printf("Invalid move, try again.\n");
        }
    }
}

int main() {
    int num_cards = 10;
    struct Card deck[num_cards];
    init_deck(deck, num_cards);
    play_memory(deck, num_cards);
    return 0;
}