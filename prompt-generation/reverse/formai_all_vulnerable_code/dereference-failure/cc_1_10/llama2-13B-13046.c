//LLAMA2-13B DATASET v1.0 Category: Poker Game ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 5
#define DECK_SIZE 52
#define HAND_SIZE 5

typedef struct {
    char *name;
    int bet;
    int hand[HAND_SIZE];
} player_t;

player_t players[MAX_PLAYERS];
int num_players = 0;

void init_players(void);
void deal_cards(void);
void bet(void);
void show_hands(void);
void winner(void);

int main(void) {
    srand(time(NULL));

    init_players();
    deal_cards();
    bet();
    show_hands();
    winner();

    return 0;
}

void init_players(void) {
    int i;

    for (i = 0; i < MAX_PLAYERS; i++) {
        players[i].name = malloc(20);
        printf("Player %d, enter your name: ", i + 1);
        fgets(players[i].name, 20, stdin);
        players[i].bet = 0;
        for (int j = 0; j < HAND_SIZE; j++) {
            players[i].hand[j] = rand() % DECK_SIZE;
        }
    }
    num_players = MAX_PLAYERS;
}

void deal_cards(void) {
    int i, j;

    for (i = 0; i < num_players; i++) {
        for (j = 0; j < HAND_SIZE; j++) {
            players[i].hand[j] = rand() % DECK_SIZE;
        }
    }
}

void bet(void) {
    int i;

    for (i = 0; i < num_players; i++) {
        printf("Player %d, bet: ", i + 1);
        scanf("%d", &players[i].bet);
    }
}

void show_hands(void) {
    int i;

    for (i = 0; i < num_players; i++) {
        printf("Player %d's hand: ", i + 1);
        for (int j = 0; j < HAND_SIZE; j++) {
            printf("%d ", players[i].hand[j]);
        }
        printf("\n");
    }
}

void winner(void) {
    int i, j;
    int highest_hand = 0;
    int highest_bet = 0;

    for (i = 0; i < num_players; i++) {
        if (players[i].bet > highest_bet) {
            highest_bet = players[i].bet;
            highest_hand = i;
        }
    }

    for (i = 0; i < num_players; i++) {
        if (players[i].hand[0] == highest_hand) {
            printf("Player %d wins! Their hand was: ", i + 1);
            for (int j = 0; j < HAND_SIZE; j++) {
                printf("%d ", players[i].hand[j]);
            }
            printf("\n");
            break;
        }
    }
}