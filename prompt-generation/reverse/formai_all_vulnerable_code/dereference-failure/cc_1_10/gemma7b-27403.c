//Gemma-7B DATASET v1.0 Category: Table Game ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARDS 52

typedef struct Card {
    char suit;
    int number;
} Card;

void deal_cards(Card **hand, int num_cards);
void print_cards(Card **hand, int num_cards);

int main() {
    Card **hands[2];
    int num_cards = 5;

    hands[0] = malloc(num_cards * sizeof(Card));
    hands[1] = malloc(num_cards * sizeof(Card));

    deal_cards(hands[0], num_cards);
    deal_cards(hands[1], num_cards);

    print_cards(hands[0], num_cards);
    print_cards(hands[1], num_cards);

    free(hands[0]);
    free(hands[1]);

    return 0;
}

void deal_cards(Card **hand, int num_cards) {
    int i;
    time_t t;
    srand(time(NULL));

    for (i = 0; i < num_cards; i++) {
        hand[i] = malloc(sizeof(Card));
        hand[i]->suit = 'H' + rand() % 4;
        hand[i]->number = rand() % 13 + 1;
    }
}

void print_cards(Card **hand, int num_cards) {
    int i;

    for (i = 0; i < num_cards; i++) {
        printf("%c%d ", hand[i]->suit, hand[i]->number);
    }
    printf("\n");
}