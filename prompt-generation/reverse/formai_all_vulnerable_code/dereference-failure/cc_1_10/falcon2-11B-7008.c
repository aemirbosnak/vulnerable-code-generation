//Falcon2-11B DATASET v1.0 Category: Poker Game ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define MAX_CARDS 7

typedef struct {
    char suit[3];
    char value[3];
} Card;

typedef struct {
    Card cards[MAX_CARDS];
    int num_cards;
} Deck;

Deck* create_deck() {
    Deck* deck = (Deck*)malloc(sizeof(Deck));
    for (int i = 0; i < MAX_CARDS; i++) {
        deck->cards[i].suit[0] = 'S';
        deck->cards[i].suit[1] = 'C';
        deck->cards[i].suit[2] = '\0';
        deck->cards[i].value[0] = 'A';
        deck->cards[i].value[1] = 'K';
        deck->cards[i].value[2] = '\0';
    }
    deck->num_cards = MAX_CARDS;
    return deck;
}

void shuffle_deck(Deck* deck) {
    for (int i = MAX_CARDS - 1; i > 0; i--) {
        int j = (int)rand() / RAND_MAX * (i + 1);
        Card temp = deck->cards[i];
        deck->cards[i] = deck->cards[j];
        deck->cards[j] = temp;
    }
}

void deal_card(Deck* deck, Card* card) {
    *card = deck->cards[deck->num_cards--];
}

void show_card(Card* card) {
    printf("%c%c%c - %c%c%c\n", card->suit[0], card->suit[1], card->suit[2], card->value[0], card->value[1], card->value[2]);
}

int main() {
    Deck* deck = create_deck();
    shuffle_deck(deck);

    Card card;
    deal_card(deck, &card);
    show_card(&card);

    return 0;
}