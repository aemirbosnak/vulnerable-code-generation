//FormAI DATASET v1.0 Category: Poker Game ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define card structure
struct Card {
    char *rank;
    char *suit;
    int value;
};

// Define deck structure
struct Deck {
    struct Card cards[52];
    int top;
};

// Initialize deck
struct Deck* initDeck() {
    struct Deck *deck = malloc(sizeof(struct Deck));

    char *ranks[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
    char *suits[4] = {"Clubs", "Diamonds", "Hearts", "Spades"};

    int count = 0;
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 4; j++) {
            struct Card newCard = {ranks[i], suits[j], i+2};
            deck->cards[count] = newCard;
            count++;
        }
    }

    deck->top = 51;

    return deck;
}

// Shuffle deck
void shuffleDeck(struct Deck *deck) {
    srand(time(NULL));

    for (int i = 0; i < 52; i++) {
        int randomIndex = rand() % 52;
        struct Card tempCard = deck->cards[i];
        deck->cards[i] = deck->cards[randomIndex];
        deck->cards[randomIndex] = tempCard;
    }
}

// Deal cards
struct Card dealCard(struct Deck *deck) {
    struct Card dealtCard = deck->cards[deck->top];
    deck->top--;
    return dealtCard;
}

// Calculate hand value
int calculateHandValue(struct Card *hand, int numCards) {
    int handValue = 0;
    int numAces = 0;

    for (int i = 0; i < numCards; i++) {
        handValue += hand[i].value;

        if (hand[i].value == 14) {
            numAces++;
        }
    }

    while (handValue > 21 && numAces > 0) {
        handValue -= 10;
        numAces--;
    }

    return handValue;
}

// Print card
void printCard(struct Card card) {
    printf("%s of %s\n", card.rank, card.suit);
}

// Print hand
void printHand(struct Card *hand, int numCards) {
    for (int i = 0; i < numCards; i++) {
        printCard(hand[i]);
    }
}

int main() {
    struct Deck *deck = initDeck();
    shuffleDeck(deck);

    // Deal player hand
    struct Card playerHand[2];
    playerHand[0] = dealCard(deck);
    playerHand[1] = dealCard(deck);

    printf("Player hand:\n");
    printHand(playerHand, 2);
    printf("Hand value: %d\n\n", calculateHandValue(playerHand, 2));

    // Deal dealer hand
    struct Card dealerHand[2];
    dealerHand[0] = dealCard(deck);
    dealerHand[1] = dealCard(deck);

    printf("Dealer upcard:\n");
    printCard(dealerHand[0]);
    printf("\n");

    // Player turn
    char playerAction = 'h';
    while (playerAction != 's' && calculateHandValue(playerHand, 2) < 21) {
        printf("Enter 'h' to hit or 's' to stand: ");
        scanf(" %c", &playerAction);

        if (playerAction == 'h') {
            struct Card newCard = dealCard(deck);
            printf("Dealt card:\n");
            printCard(newCard);
            printf("\n");

            playerHand[2] = newCard;
            printf("Player hand:\n");
            printHand(playerHand, 3);
            printf("Hand value: %d\n\n", calculateHandValue(playerHand, 3));
        }
    }

    // Dealer turn
    int dealerValue = calculateHandValue(dealerHand, 2);
    while (dealerValue < 16) {
        struct Card newCard = dealCard(deck);
        dealerHand[2] = newCard;
        dealerValue = calculateHandValue(dealerHand, 3);
    }

    // Determine winner
    int playerValue = calculateHandValue(playerHand, 3);
    dealerValue = calculateHandValue(dealerHand, 3);

    printf("Player hand value: %d\n", playerValue);
    printf("Dealer hand value: %d\n", dealerValue);

    if ((playerValue > dealerValue && playerValue <= 21) || dealerValue > 21) {
        printf("Player wins!\n");
    } else if (playerValue == dealerValue) {
        printf("Push!\n");
    } else {
        printf("Dealer wins!\n");
    }

    free(deck);

    return 0;
}