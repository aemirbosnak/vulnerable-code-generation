//FormAI DATASET v1.0 Category: Poker Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define HAND_SIZE 5

enum Suit { CLUBS, DIAMONDS, HEARTS, SPADES };

typedef struct Card {
    enum Suit suit;
    int value;
} Card;

void shuffle(Card **deck) {
    srand(time(NULL));
    for (int i = 0; i < DECK_SIZE; i++) {
        int j = rand() % DECK_SIZE;
        Card *temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void printCard(const Card *card) {
    char value;
    switch (card->value) {
        case 1:
            value = 'A';
            break;
        case 10:
            value = 'T';
            break;
        case 11:
            value = 'J';
            break;
        case 12:
            value = 'Q';
            break;
        case 13:
            value = 'K';
            break;
        default:
            value = card->value + '0';
    }
    char suit;
    switch (card->suit) {
        case CLUBS:
            suit = 'C';
            break;
        case DIAMONDS:
            suit = 'D';
            break;
        case HEARTS:
            suit = 'H';
            break;
        case SPADES:
            suit = 'S';
            break;
    }
    printf("%c%c ", value, suit);
}

void printDeck(const Card **deck, int deckSize) {
    for (int i = 0; i < deckSize; i++) {
        printCard(deck[i]);
    }
    printf("\n");
}

Card **createDeck() {
    Card **deck = (Card **) malloc(DECK_SIZE * sizeof(Card *));
    for (int suit = 0; suit < 4; suit++) {
        for (int value = 1; value <= 13; value++) {
            Card *card = (Card *) malloc(sizeof(Card));
            card->suit = suit;
            card->value = value;
            deck[suit * 13 + value - 1] = card;
        }
    }
    return deck;
}

void destroyDeck(Card **deck, int deckSize) {
    for (int i = 0; i < deckSize; i++) {
        free(deck[i]);
    }
    free(deck);
}

int compareCards(const void *card1, const void *card2) {
    return (*(Card **) card1)->value - (*(Card **) card2)->value;
}

int isStraight(const Card **hand) {
    if (hand[0]->value == 1 && hand[1]->value == 10 && hand[2]->value == 11 &&
        hand[3]->value == 12 && hand[4]->value == 13) {
        return 1;
    }
    for (int i = 1; i < HAND_SIZE; i++) {
        if (hand[i]->value != hand[i - 1]->value + 1) {
            return 0;
        }
    }
    return 1;
}

int hasFlush(const Card **hand) {
    enum Suit suit = hand[0]->suit;
    for (int i = 1; i < HAND_SIZE; i++) {
        if (hand[i]->suit != suit) {
            return 0;
        }
    }
    return 1;
}

int hasStraightFlush(const Card **hand) {
    return hasFlush(hand) && isStraight(hand);
}

int hasFourOfAKind(const Card **hand) {
    int count = 1;
    for (int i = 1; i < HAND_SIZE; i++) {
        if (hand[i]->value == hand[i - 1]->value) {
            count++;
            if (count == 4) {
                return 1;
            }
        } else {
            count = 1;
        }
    }
    return 0;
}

int hasFullHouse(const Card **hand) {
    if (hand[0]->value == hand[1]->value && hand[2]->value == hand[3]->value &&
        hand[3]->value == hand[4]->value) {
        return 1;
    }
    if (hand[0]->value == hand[1]->value && hand[1]->value == hand[2]->value &&
        hand[3]->value == hand[4]->value) {
        return 1;
    }
    return 0;
}

int hasThreeOfAKind(const Card **hand) {
    int count = 1;
    for (int i = 1; i < HAND_SIZE; i++) {
        if (hand[i]->value == hand[i - 1]->value) {
            count++;
            if (count == 3) {
                return 1;
            }
        } else {
            count = 1;
        }
    }
    return 0;
}

int hasTwoPairs(const Card **hand) {
    if (hand[0]->value == hand[1]->value && hand[2]->value == hand[3]->value) {
        return 1;
    }
    if (hand[0]->value == hand[1]->value && hand[3]->value == hand[4]->value) {
        return 1;
    }
    if (hand[1]->value == hand[2]->value && hand[3]->value == hand[4]->value) {
        return 1;
    }
    return 0;
}

int hasPair(const Card **hand) {
    for (int i = 1; i < HAND_SIZE; i++) {
        if (hand[i]->value == hand[i - 1]->value) {
            return 1;
        }
    }
    return 0;
}

int getScore(const Card **hand) {
    if (hasStraightFlush(hand)) {
        return 8000000 + hand[0]->value;
    }
    if (hasFourOfAKind(hand)) {
        return 7000000 + hand[2]->value;
    }
    if (hasFullHouse(hand)) {
        return 6000000 + hand[2]->value;
    }
    if (hasFlush(hand)) {
        return 5000000 + hand[0]->value;
    }
    if (isStraight(hand)) {
        return 4000000 + hand[4]->value;
    }
    if (hasThreeOfAKind(hand)) {
        return 3000000 + hand[2]->value;
    }
    if (hasTwoPairs(hand)) {
        if (hand[0]->value == hand[1]->value) {
            return 2000000 + hand[3]->value * 100 + hand[1]->value;
        } else if (hand[1]->value == hand[2]->value) {
            return 2000000 + hand[3]->value * 100 + hand[1]->value;
        } else {
            return 2000000 + hand[3]->value * 100 + hand[2]->value;
        }
    }
    if (hasPair(hand)) {
        for (int i = 1; i < HAND_SIZE; i++) {
            if (hand[i]->value == hand[i - 1]->value) {
                return 1000000 + hand[i]->value * 10000 + hand[4]->value * 100 + hand[3]->value;
            }
        }
    }
    return hand[4]->value * 10000 + hand[3]->value * 100 + hand[2]->value;
}

int compareHands(const void *hand1, const void *hand2) {
    int score1 = getScore((const Card **) hand1);
    int score2 = getScore((const Card **) hand2);
    return score2 - score1;
}

void printHand(const Card **hand) {
    for (int i = 0; i < HAND_SIZE; i++) {
        printCard(hand[i]);
    }
    printf("\n");
}

void drawHand(Card **deck, Card **hand) {
    for (int i = 0; i < HAND_SIZE; i++) {
        hand[i] = deck[i];
    }
    qsort(hand, HAND_SIZE, sizeof(Card *), compareCards);
}

int main() {
    Card **deck = createDeck();
    Card **hand1 = (Card **) malloc(HAND_SIZE * sizeof(Card *));
    Card **hand2 = (Card **) malloc(HAND_SIZE * sizeof(Card *));
    shuffle(deck);
    drawHand(deck, hand1);
    drawHand(deck + HAND_SIZE, hand2);
    printf("Hand 1: ");
    printHand(hand1);
    printf("Hand 2: ");
    printHand(hand2);
    printf("Winner: ");
    if (compareHands(hand1, hand2) > 0) {
        printf("Hand 1\n");
    } else {
        printf("Hand 2\n");
    }
    destroyDeck(deck, DECK_SIZE);
    free(hand1);
    free(hand2);
    return 0;
}