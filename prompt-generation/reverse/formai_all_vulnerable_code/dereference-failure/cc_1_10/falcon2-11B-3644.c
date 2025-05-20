//Falcon2-11B DATASET v1.0 Category: Poker Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct card {
    char suit;
    char rank;
} card;

typedef struct hand {
    card *cards;
    int size;
} hand;

int compare(const void *a, const void *b) {
    hand *ha = (hand *) a;
    hand *hb = (hand *) b;

    int scorea = 0, scoreb = 0;
    for (int i = 0; i < ha->size; i++) {
        scorea += ha->cards[i].rank;
    }
    for (int i = 0; i < hb->size; i++) {
        scoreb += hb->cards[i].rank;
    }
    return scoreb - scorea;
}

int main() {
    hand *player1 = (hand *) malloc(sizeof(hand));
    hand *player2 = (hand *) malloc(sizeof(hand));

    player1->cards = (card *) malloc(5 * sizeof(card));
    player2->cards = (card *) malloc(5 * sizeof(card));

    for (int i = 0; i < 5; i++) {
        player1->cards[i].suit = 'S';
        player1->cards[i].rank = '9';
        player2->cards[i].suit = 'C';
        player2->cards[i].rank = 'A';
    }

    qsort(player1->cards, 5, sizeof(card), compare);
    qsort(player2->cards, 5, sizeof(card), compare);

    printf("Player 1's hand: ");
    for (int i = 0; i < 5; i++) {
        printf("%c %c\n", player1->cards[i].suit, player1->cards[i].rank);
    }

    printf("Player 2's hand: ");
    for (int i = 0; i < 5; i++) {
        printf("%c %c\n", player2->cards[i].suit, player2->cards[i].rank);
    }

    return 0;
}