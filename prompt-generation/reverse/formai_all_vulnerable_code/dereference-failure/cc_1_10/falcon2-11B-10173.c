//Falcon2-11B DATASET v1.0 Category: Table Game ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

struct Card {
    int rank;
    int suit;
};

int compare_cards(const void* a, const void* b) {
    struct Card* card_a = (struct Card*)a;
    struct Card* card_b = (struct Card*)b;
    
    if (card_a->rank < card_b->rank) {
        return -1;
    } else if (card_a->rank > card_b->rank) {
        return 1;
    } else if (card_a->suit < card_b->suit) {
        return -1;
    } else if (card_a->suit > card_b->suit) {
        return 1;
    } else {
        return 0;
    }
}

void deal_cards(struct Card** cards, int num_cards) {
    for (int i = 0; i < num_cards; i++) {
        cards[i] = (struct Card*)malloc(sizeof(struct Card));
        cards[i]->rank = rand() % 13 + 1;
        cards[i]->suit = rand() % 4;
    }
}

void sort_cards(struct Card** cards, int num_cards) {
    qsort(cards, num_cards, sizeof(struct Card), compare_cards);
}

void print_cards(struct Card** cards, int num_cards) {
    for (int i = 0; i < num_cards; i++) {
        printf("Card %d: Rank: %d, Suit: %d\n", i+1, cards[i]->rank, cards[i]->suit);
    }
}

int main() {
    struct Card** cards = (struct Card**)malloc(10 * sizeof(struct Card*));
    deal_cards(cards, 10);
    sort_cards(cards, 10);
    print_cards(cards, 10);
    return 0;
}