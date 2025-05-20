//FormAI DATASET v1.0 Category: Poker Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Struct for the cards
typedef struct Card {
    int value;
    char *suit;
} Card;

// Function to generate a random number between min and max (inclusive)
int random_number(int min, int max) {
    return min + rand() % (max + 1 - min);
}

// Function to create a new deck of cards
Card* create_deck() {
    Card *deck = malloc(52 * sizeof(Card));
    int i = 0;
    for (int value = 2; value <= 14; value++) {
        char *suit = "spades";
        deck[i].value = value;
        deck[i].suit = suit;
        i++;

        suit = "hearts";
        deck[i].value = value;
        deck[i].suit = suit;
        i++;

        suit = "diamonds";
        deck[i].value = value;
        deck[i].suit = suit;
        i++;

        suit = "clubs";
        deck[i].value = value;
        deck[i].suit = suit;
        i++;
    }
    return deck;
}

// Function to shuffle the deck of cards
void shuffle_deck(Card *deck) {
    srand(time(NULL));
    for (int i = 0; i < 52; i++) {
        int j = random_number(0, 51);
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// Function to print a card
void print_card(Card card) {
    if (card.value == 11) {
        printf("Jack of %s\n", card.suit);
    } else if (card.value == 12) {
        printf("Queen of %s\n", card.suit);
    } else if (card.value == 13) {
        printf("King of %s\n", card.suit);
    } else if (card.value == 14) {
        printf("Ace of %s\n", card.suit);
    } else {
        printf("%d of %s\n", card.value, card.suit);
    }
}

// Function to deal cards to players
void deal_cards(Card *deck, Card **player1, Card **player2) {
    *player1 = malloc(5 * sizeof(Card));
    *player2 = malloc(5 * sizeof(Card));
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            (*player1)[i / 2] = deck[i];
        } else {
            (*player2)[i / 2] = deck[i];
        }
    }
}

int main() {
    Card *deck = create_deck();
    shuffle_deck(deck);

    Card *player1;
    Card *player2;
    deal_cards(deck, &player1, &player2);

    printf("Player 1's cards:\n");
    for (int i = 0; i < 5; i++) {
        print_card(player1[i]);
    }

    printf("\nPlayer 2's cards:\n");
    for (int i = 0; i < 5; i++) {
        print_card(player2[i]);
    }

    free(deck);
    free(player1);
    free(player2);
    return 0;
}