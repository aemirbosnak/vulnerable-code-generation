//Falcon2-11B DATASET v1.0 Category: Poker Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>

typedef struct Card{
    int rank;
    char suit;
} Card;

typedef struct Deck{
    Card* cards;
    int size;
} Deck;

int main() {
    int n, i, j;
    char c;

    Deck* deck = (Deck*) malloc(sizeof(Deck));
    deck->size = 52;
    deck->cards = (Card*) malloc(deck->size * sizeof(Card));

    // fill deck with card values
    for(i = 0; i < deck->size; i++){
        deck->cards[i].rank = (i % 13) + 1;
        deck->cards[i].suit = 'S';
    }

    // shuffle deck
    for(i = 0; i < deck->size; i++){
        j = rand() % i;
        c = deck->cards[i].suit;
        deck->cards[i].suit = deck->cards[j].suit;
        deck->cards[j].suit = c;
    }

    // deal cards
    n = 5;
    printf("Player 1: ");
    for(i = 0; i < n; i++){
        printf("%c ", deck->cards[i].suit);
    }
    printf("\n");

    n = 5;
    printf("Player 2: ");
    for(i = 0; i < n; i++){
        printf("%c ", deck->cards[i].suit);
    }
    printf("\n");

    return 0;
}