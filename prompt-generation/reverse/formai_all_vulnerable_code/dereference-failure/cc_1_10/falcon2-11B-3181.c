//Falcon2-11B DATASET v1.0 Category: Poker Game ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

struct card {
    char suit;
    char rank;
};

typedef struct card card;

struct deck {
    int n_cards;
    card *cards;
};

typedef struct deck deck;

deck *new_deck(void) {
    deck *d = malloc(sizeof(deck));
    d->n_cards = 52;
    d->cards = malloc(sizeof(card) * d->n_cards);
    for (int i = 0; i < d->n_cards; i++) {
        d->cards[i].suit = 'S';
        d->cards[i].rank = 'A';
    }
    return d;
}

void shuffle_deck(deck *d) {
    for (int i = d->n_cards - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        card temp = d->cards[i];
        d->cards[i] = d->cards[j];
        d->cards[j] = temp;
    }
}

card *deal_card(deck *d) {
    card *c = d->cards;
    d->cards = d->cards + 1;
    d->n_cards--;
    return c;
}

void show_card(card c) {
    printf("%c%c\n", c.suit, c.rank);
}

int main(void) {
    deck *d = new_deck();
    shuffle_deck(d);
    card *hand = deal_card(d);
    show_card(*hand);
    card *comparator = deal_card(d);
    show_card(*comparator);
    return 0;
}