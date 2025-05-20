//Falcon2-11B DATASET v1.0 Category: Poker Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Card {
    char suit;
    int value;
} Card;

typedef struct Hand {
    Card* cards;
    int numCards;
} Hand;

int compareCards(const void* a, const void* b) {
    Card* cardA = (Card*)a;
    Card* cardB = (Card*)b;
    if (cardA->value == cardB->value) {
        if (cardA->suit == 'H' && cardB->suit == 'S')
            return -1;
        else if (cardA->suit == 'S' && cardB->suit == 'H')
            return 1;
        else
            return 0;
    } else {
        return cardA->value - cardB->value;
    }
}

void dealHand(Hand* hand) {
    int numCards = rand() % 7 + 1;
    for (int i = 0; i < numCards; i++) {
        Card card;
        card.suit = 'S' + (rand() % 3);
        card.value = (rand() % 13) + 1;
        hand->cards[i] = card;
    }
    hand->numCards = numCards;
}

int main() {
    srand(time(NULL));
    Hand hand1, hand2;
    dealHand(&hand1);
    dealHand(&hand2);

    qsort(hand1.cards, hand1.numCards, sizeof(Card), compareCards);
    qsort(hand2.cards, hand2.numCards, sizeof(Card), compareCards);

    printf("Hand 1: ");
    for (int i = 0; i < hand1.numCards; i++) {
        printf("%c %d ", hand1.cards[i].suit, hand1.cards[i].value);
    }
    printf("\n");

    printf("Hand 2: ");
    for (int i = 0; i < hand2.numCards; i++) {
        printf("%c %d ", hand2.cards[i].suit, hand2.cards[i].value);
    }
    printf("\n");

    if (strcmp(hand1.cards[0].suit, hand2.cards[0].suit) == 0 &&
        hand1.cards[0].value == hand2.cards[0].value) {
        printf("It's a tie!\n");
    } else if (strcmp(hand1.cards[0].suit, hand2.cards[0].suit)!= 0 ||
               hand1.cards[0].value < hand2.cards[0].value) {
        printf("Hand 1 wins!\n");
    } else {
        printf("Hand 2 wins!\n");
    }

    return 0;
}