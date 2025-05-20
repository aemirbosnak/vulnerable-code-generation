//Falcon2-11B DATASET v1.0 Category: Poker Game ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Card {
    int suit;
    int value;
};

typedef struct Card Card;

struct Deck {
    Card *cards;
    int size;
};

typedef struct Deck Deck;

int deal_cards(Deck *deck, int num_players, Card **hands) {
    int i;
    for (i = 0; i < num_players; i++) {
        hands[i] = malloc(deck->size * sizeof(Card));
        for (int j = 0; j < deck->size; j++) {
            hands[i][j] = deck->cards[j];
            deck->cards[j] = deck->cards[deck->size - 1];
            deck->cards[deck->size - 1] = hands[i][j];
        }
    }
    return 1;
}

int compare_cards(Card *card1, Card *card2) {
    if (card1->value == card2->value) {
        return card1->suit - card2->suit;
    } else {
        return card1->value - card2->value;
    }
}

int main() {
    srand(time(NULL));
    Deck deck;
    deck.size = 52;
    Card *cards = malloc(deck.size * sizeof(Card));
    for (int i = 0; i < deck.size; i++) {
        cards[i].suit = rand() % 4 + 1;
        cards[i].value = rand() % 13 + 1;
    }
    deck.cards = cards;
    Card **hands = malloc(2 * sizeof(Card *));
    int num_players = 2;
    if (deal_cards(&deck, num_players, hands) == 0) {
        printf("Error: not enough cards in the deck.\n");
        return 1;
    }
    printf("Player 1 hand:\n");
    for (int i = 0; i < num_players; i++) {
        printf("%d of %d\n", hands[i][0].value, hands[i][0].suit);
    }
    printf("Player 2 hand:\n");
    for (int i = 0; i < num_players; i++) {
        printf("%d of %d\n", hands[i][1].value, hands[i][1].suit);
    }
    return 0;
}