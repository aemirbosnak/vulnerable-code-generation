//Gemma-7B DATASET v1.0 Category: Poker Game ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_HAND_SIZE 5

typedef struct Card {
    int number;
    char suit;
} Card;

void deal_cards(Card **hand, int hand_size) {
    srand(time(NULL));
    for (int i = 0; i < hand_size; i++) {
        hand[i] = malloc(sizeof(Card));
        hand[i]->number = rand() % 13 + 1;
        hand[i]->suit = 'H' + rand() % 4;
    }
}

int compare_cards(Card *card1, Card *card2) {
    if (card1->number > card2->number) {
        return 1;
    } else if (card1->number < card2->number) {
        return -1;
    } else {
        return 0;
    }
}

int main() {
    Card **hand = NULL;
    int hand_size = MAX_HAND_SIZE;

    deal_cards(&hand, hand_size);

    for (int i = 0; i < hand_size; i++) {
        printf("%d of %c ", hand[i]->number, hand[i]->suit);
    }

    printf("\n");

    int winner = compare_cards(hand[0], hand[1]);

    if (winner == 1) {
        printf("The first player won.");
    } else if (winner == -1) {
        printf("The second player won.");
    } else {
        printf("It's a draw.");
    }

    return 0;
}