//Falcon2-11B DATASET v1.0 Category: Poker Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Structure for a card
struct Card {
    char suit;
    char rank;
};

// Structure for a hand
struct Hand {
    int handValue;
    int numCards;
    struct Card* cards;
};

// Function to compare two hands
int compareHand(struct Hand* a, struct Hand* b) {
    if (a->numCards == b->numCards) {
        if (a->handValue == b->handValue) {
            return 0;
        }
        return (a->handValue > b->handValue)? 1 : -1;
    }
    return (a->numCards > b->numCards)? 1 : -1;
}

// Function to print the hand
void printHand(struct Hand* hand) {
    int i;
    printf("Hand has %d cards:\n", hand->numCards);
    for (i = 0; i < hand->numCards; i++) {
        printf("%c %c\n", hand->cards[i].suit, hand->cards[i].rank);
    }
}

// Function to add a card to the hand
void addCard(struct Hand* hand, char suit, char rank) {
    hand->cards = (struct Card*)realloc(hand->cards, (hand->numCards + 1) * sizeof(struct Card));
    hand->cards[hand->numCards].suit = suit;
    hand->cards[hand->numCards].rank = rank;
    hand->numCards++;
}

// Function to calculate the hand value
int calculateHandValue(struct Hand* hand) {
    int handValue = 0;
    int i;
    for (i = 0; i < hand->numCards; i++) {
        if (hand->cards[i].rank == 'A') {
            handValue += 14;
        } else if (hand->cards[i].rank == 'K') {
            handValue += 13;
        } else if (hand->cards[i].rank == 'Q') {
            handValue += 12;
        } else if (hand->cards[i].rank == 'J') {
            handValue += 11;
        } else if (hand->cards[i].rank == 'T') {
            handValue += 10;
        } else if (hand->cards[i].rank == '9') {
            handValue += 9;
        } else if (hand->cards[i].rank == '8') {
            handValue += 8;
        } else if (hand->cards[i].rank == '7') {
            handValue += 7;
        } else if (hand->cards[i].rank == '6') {
            handValue += 6;
        } else if (hand->cards[i].rank == '5') {
            handValue += 5;
        } else if (hand->cards[i].rank == '4') {
            handValue += 4;
        } else if (hand->cards[i].rank == '3') {
            handValue += 3;
        } else if (hand->cards[i].rank == '2') {
            handValue += 2;
        }
    }
    return handValue;
}

// Main function
int main() {
    struct Hand* myHand = (struct Hand*)malloc(sizeof(struct Hand));
    myHand->numCards = 0;
    myHand->handValue = 0;

    addCard(myHand, 'S', 'A');
    addCard(myHand, 'C', 'K');
    addCard(myHand, 'H', 'Q');
    addCard(myHand, 'D', 'J');
    addCard(myHand, 'S', 'T');

    printHand(myHand);
    myHand->handValue = calculateHandValue(myHand);
    printf("Hand value: %d\n", myHand->handValue);

    struct Hand* computerHand = (struct Hand*)malloc(sizeof(struct Hand));
    computerHand->numCards = 0;
    computerHand->handValue = 0;

    addCard(computerHand, 'D', 'A');
    addCard(computerHand, 'S', 'K');
    addCard(computerHand, 'C', 'Q');
    addCard(computerHand, 'H', 'J');
    addCard(computerHand, 'D', 'T');

    printHand(computerHand);
    computerHand->handValue = calculateHandValue(computerHand);
    printf("Computer hand value: %d\n", computerHand->handValue);

    return 0;
}