//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARDS 100
#define MAX_PLAYERS 10

typedef struct {
    int id;
    char name[30];
    int cards[MAX_CARDS];
} Player;

void shuffle(int deck[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        int j = rand() % n;
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void print_deck(int deck[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", deck[i]);
    }
    printf("\n");
}

int main() {
    int num_players;
    printf("Enter the number of players: ");
    scanf("%d", &num_players);

    if (num_players > MAX_PLAYERS) {
        printf("Error: Maximum number of players is %d\n", MAX_PLAYERS);
        return 1;
    }

    Player players[num_players];
    for (int i = 0; i < num_players; i++) {
        printf("Enter player %d's name: ", i + 1);
        scanf("%s", players[i].name);
        players[i].id = i + 1;
    }

    int num_cards;
    printf("Enter the number of cards: ");
    scanf("%d", &num_cards);

    if (num_cards > MAX_CARDS) {
        printf("Error: Maximum number of cards is %d\n", MAX_CARDS);
        return 1;
    }

    int deck[num_cards];
    for (int i = 1; i <= num_cards; i++) {
        deck[i - 1] = i;
    }

    shuffle(deck, num_cards);

    for (int i = 0; i < num_players; i++) {
        for (int j = 0; j < num_cards / num_players; j++) {
            players[i].cards[j] = deck[i * num_cards / num_players + j];
        }
    }

    printf("Bingo cards:\n");
    for (int i = 0; i < num_players; i++) {
        printf("Player %d's cards: ", players[i].id);
        print_deck(players[i].cards, num_cards / num_players);
    }

    return 0;
}