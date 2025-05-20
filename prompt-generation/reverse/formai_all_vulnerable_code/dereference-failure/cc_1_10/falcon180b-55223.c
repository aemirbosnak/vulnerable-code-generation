//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 10
#define MAX_CARDS 100
#define MAX_ROUNDS 10

typedef struct {
    char name[50];
    int card[MAX_CARDS];
} Player;

void initCards(int cards[MAX_CARDS]) {
    int i;
    for (i = 0; i < MAX_CARDS; i++) {
        cards[i] = i + 1;
    }
}

void shuffleCards(int cards[MAX_CARDS]) {
    int i, j, temp;
    srand(time(NULL));
    for (i = 0; i < MAX_CARDS; i++) {
        j = rand() % MAX_CARDS;
        temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
}

void printCard(int card) {
    switch (card) {
        case 1:
            printf("Ace\n");
            break;
        case 11:
            printf("Jack\n");
            break;
        case 12:
            printf("Queen\n");
            break;
        case 13:
            printf("King\n");
            break;
        default:
            printf("%d\n", card);
            break;
    }
}

void printCards(int cards[MAX_CARDS]) {
    int i;
    for (i = 0; i < MAX_CARDS; i++) {
        printCard(cards[i]);
    }
}

int main() {
    int i, j, players = 0;
    char name[50];
    Player *player;

    printf("Welcome to Bingo Simulator!\n");

    while (players < MAX_PLAYERS) {
        printf("Enter your name: ");
        scanf("%s", name);
        player = (Player *) malloc(sizeof(Player));
        strcpy(player->name, name);
        players++;
    }

    initCards(player[0].card);
    shuffleCards(player[0].card);
    printf("Round 1\n");
    printCards(player[0].card);

    return 0;
}