//LLAMA2-13B DATASET v1.0 Category: Poker Game ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define HAND_SIZE 5

typedef struct hand {
    int cards[HAND_SIZE];
} hand_t;

typedef struct deck {
    int cards[DECK_SIZE];
} deck_t;

void shuffle_deck(deck_t *deck);
void deal_hands(hand_t **hands, int num_players, deck_t *deck);
void print_hand(hand_t *hand);
int compare_hands(hand_t *hand1, hand_t *hand2);

int main() {
    srand(time(NULL));

    deck_t *deck = malloc(DECK_SIZE * sizeof(int));
    for (int i = 0; i < DECK_SIZE; i++) {
        deck->cards[i] = i % 13 + 1; // assign card values from 1 to 13
    }

    hand_t *hands[5]; // initialize hands for 5 players
    for (int i = 0; i < 5; i++) {
        hands[i] = malloc(HAND_SIZE * sizeof(int));
        for (int j = 0; j < HAND_SIZE; j++) {
            hands[i]->cards[j] = deck->cards[i * HAND_SIZE + j];
        }
    }

    shuffle_deck(deck);
    deal_hands(hands, 5, deck);

    for (int i = 0; i < 5; i++) {
        print_hand(hands[i]);
    }

    int winner = compare_hands(hands[0], hands[1]);
    if (winner == -1) {
        printf("No winner, tied!\n");
    } else {
        printf("Winner is player %d with hand %d\n", winner + 1, hands[winner]->cards[0]);
    }

    return 0;
}

void shuffle_deck(deck_t *deck) {
    for (int i = 0; i < DECK_SIZE; i++) {
        int j = rand() % DECK_SIZE;
        int temp = deck->cards[i];
        deck->cards[i] = deck->cards[j];
        deck->cards[j] = temp;
    }
}

void deal_hands(hand_t **hands, int num_players, deck_t *deck) {
    for (int i = 0; i < num_players; i++) {
        for (int j = 0; j < HAND_SIZE; j++) {
            hands[i]->cards[j] = deck->cards[i * HAND_SIZE + j];
        }
    }
}

void print_hand(hand_t *hand) {
    for (int i = 0; i < HAND_SIZE; i++) {
        printf("%d ", hand->cards[i]);
    }
    printf("\n");
}

int compare_hands(hand_t *hand1, hand_t *hand2) {
    int compare = 0;
    for (int i = 0; i < HAND_SIZE; i++) {
        if (hand1->cards[i] > hand2->cards[i]) {
            compare = 1;
            break;
        } else if (hand1->cards[i] < hand2->cards[i]) {
            compare = -1;
            break;
        }
    }
    if (compare == 0) {
        compare = -1; // tied
    }
    return compare;
}