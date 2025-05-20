//Falcon2-11B DATASET v1.0 Category: Poker Game ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int card[5];
    int rank;
} Card;

typedef struct {
    int player[5];
    int score;
} Player;

typedef struct {
    int deck[52];
    int top;
} Deck;

int compare(const void* a, const void* b) {
    Card* c = (Card*)a;
    Card* d = (Card*)b;
    if (c->rank < d->rank) {
        return -1;
    } else if (c->rank > d->rank) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    Deck deck;
    Deck* deck_ptr = &deck;

    srand(time(NULL));
    for (int i = 0; i < 52; i++) {
        deck_ptr->deck[i] = i + 1;
    }
    deck_ptr->top = 0;

    Card* cards[52];
    Player players[5];
    int num_players = 5;

    for (int i = 0; i < num_players; i++) {
        for (int j = 0; j < 5; j++) {
            cards[j] = (Card*)malloc(sizeof(Card));
            players[i].player[j] = cards[j]->card[0];
        }
        players[i].score = 0;
    }

    qsort(cards, 52, sizeof(Card), compare);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("Player %d's hand: ", i + 1);
            for (int k = 0; k < 5; k++) {
                printf("%d ", players[i].player[k]);
            }
            printf("\n");
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("Player %d draws a card: ", i + 1);
            int card_index = deck_ptr->deck[deck_ptr->top++];
            Card* new_card = (Card*)malloc(sizeof(Card));
            new_card->card[0] = card_index;
            new_card->rank = card_index / 13;
            cards[j] = new_card;
            players[i].score += new_card->rank;
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("Player %d's score: %d\n", i + 1, players[i].score);
        }
    }

    for (int i = 0; i < 5; i++) {
        free(cards[i]);
    }

    return 0;
}