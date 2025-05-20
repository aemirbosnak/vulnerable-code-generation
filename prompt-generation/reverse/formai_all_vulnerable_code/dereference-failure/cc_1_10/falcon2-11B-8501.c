//Falcon2-11B DATASET v1.0 Category: Poker Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 52
#define NUM_PLAYERS 4

typedef struct Card {
    int suit;
    int value;
} Card;

typedef struct Player {
    char name[20];
    Card hand[5];
    int score;
} Player;

void shuffle(Card cards[], int num_cards) {
    srand(time(0));
    for (int i = num_cards - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Card temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
}

void deal(Card cards[], Player players[], int num_players, int num_cards) {
    for (int i = 0; i < num_players; i++) {
        for (int j = 0; j < num_cards; j++) {
            players[i].hand[j] = cards[j];
        }
    }
}

void print_hand(Player players[], int num_players) {
    for (int i = 0; i < num_players; i++) {
        printf("Player %s:\n", players[i].name);
        for (int j = 0; j < 5; j++) {
            printf("Card %d: %d of %d\n", j+1, players[i].hand[j].value, players[i].hand[j].suit);
        }
    }
}

int compare_cards(Card c1, Card c2) {
    if (c1.value > c2.value) {
        return 1;
    } else if (c1.value < c2.value) {
        return -1;
    } else {
        if (c1.suit > c2.suit) {
            return 1;
        } else if (c1.suit < c2.suit) {
            return -1;
        } else {
            return 0;
        }
    }
}

int main() {
    srand(time(0));
    Card cards[NUM_CARDS];
    Player players[NUM_PLAYERS];

    for (int i = 0; i < NUM_CARDS; i++) {
        cards[i].value = (rand() % 13) + 1;
        cards[i].suit = (rand() % 4) + 1;
    }

    shuffle(cards, NUM_CARDS);
    deal(cards, players, NUM_PLAYERS, NUM_CARDS);

    print_hand(players, NUM_PLAYERS);

    // Game logic goes here

    return 0;
}