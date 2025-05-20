//Falcon2-11B DATASET v1.0 Category: Poker Game ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

typedef struct Card {
    int value;
    char suit;
} Card;

typedef struct Deck {
    Card* cards;
    int top;
} Deck;

typedef struct Hand {
    Card* cards;
    int top;
} Hand;

void shuffle(Deck* deck) {
    int i;
    for (i = deck->top - 1; i >= 0; i--) {
        int j = rand() % (i + 1);
        Card temp = deck->cards[i];
        deck->cards[i] = deck->cards[j];
        deck->cards[j] = temp;
    }
}

void deal(Deck* deck, Hand* hand) {
    for (int i = 0; i < 5; i++) {
        hand->cards[i] = deck->cards[deck->top--];
    }
}

void print_hand(Hand* hand) {
    for (int i = 0; i < 5; i++) {
        printf("%d of %c\n", hand->cards[i].value, hand->cards[i].suit);
    }
}

int main() {
    Deck deck;
    Hand hand;
    int i;

    deck.cards = (Card*)malloc(52 * sizeof(Card));
    for (i = 0; i < 52; i++) {
        deck.cards[i].value = i + 1;
        deck.cards[i].suit = 'C';
    }
    deck.top = 52;

    shuffle(&deck);
    deal(&deck, &hand);
    print_hand(&hand);

    return 0;
}