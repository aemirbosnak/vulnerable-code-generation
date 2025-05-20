//Gemma-7B DATASET v1.0 Category: Poker Game ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4

typedef struct Player {
    char name[20];
    int chips;
    int bet;
    int hand[5];
} Player;

void dealCards(Player *players) {
    // Shuffle the deck
    srand(time(NULL));
    for (int i = 0; i < 52; i++) {
        int r = rand() % 52;
        int tmp = players[0].hand[r];
        players[0].hand[r] = players[1].hand[r];
        players[1].hand[r] = tmp;
    }

    // Deal two cards to each player
    for (int i = 0; i < MAX_PLAYERS; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%c ", players[i].hand[j]);
        }
        printf("\n");
    }
}

int main() {
    Player players[MAX_PLAYERS];

    // Initialize players
    for (int i = 0; i < MAX_PLAYERS; i++) {
        players[i].name[0] = 'A' + i;
        players[i].chips = 100;
        players[i].bet = 0;
        players[i].hand[0] = -1;
        players[i].hand[1] = -1;
        players[i].hand[2] = -1;
        players[i].hand[3] = -1;
        players[i].hand[4] = -1;
    }

    // Deal cards
    dealCards(players);

    return 0;
}