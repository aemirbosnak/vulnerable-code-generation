//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARDS 100
#define MAX_PLAYERS 10

typedef struct {
    int *numbers;
    int size;
} Card;

typedef struct {
    Card **cards;
    int num_cards;
    int current_card;
} Deck;

void generate_card(Card *card) {
    card->size = rand() % 16 + 1;
    card->numbers = (int *)malloc(card->size * sizeof(int));
    for (int i = 0; i < card->size; i++) {
        card->numbers[i] = rand() % 75 + 1;
    }
}

void generate_deck(Deck *deck) {
    deck->cards = (Card **)malloc(MAX_CARDS * sizeof(Card *));
    deck->num_cards = 0;
    deck->current_card = 0;

    for (int i = 0; i < MAX_CARDS; i++) {
        Card *card = (Card *)malloc(sizeof(Card));
        generate_card(card);
        deck->cards[i] = card;
        deck->num_cards++;
    }
}

void shuffle_deck(Deck *deck) {
    srand(time(NULL));

    for (int i = 0; i < deck->num_cards; i++) {
        int j = rand() % deck->num_cards;
        Card *temp = deck->cards[i];
        deck->cards[i] = deck->cards[j];
        deck->cards[j] = temp;
    }

    deck->current_card = 0;
}

int get_number(Card *card, int index) {
    return card->numbers[index];
}

int main() {
    srand(time(NULL));

    Deck deck;
    generate_deck(&deck);
    shuffle_deck(&deck);

    int num_players = 2;
    int *cards = (int *)malloc(num_players * MAX_CARDS * sizeof(int));

    for (int i = 0; i < num_players; i++) {
        for (int j = 0; j < MAX_CARDS; j++) {
            cards[i * MAX_CARDS + j] = get_number(deck.cards[deck.current_card], 0);
            deck.current_card++;
        }
    }

    for (int i = 0; i < num_players; i++) {
        for (int j = 0; j < MAX_CARDS; j++) {
            printf("%d ", cards[i * MAX_CARDS + j]);
        }
        printf("\n");
    }

    return 0;
}