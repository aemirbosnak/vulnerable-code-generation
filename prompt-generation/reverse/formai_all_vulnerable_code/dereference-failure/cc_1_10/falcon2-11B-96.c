//Falcon2-11B DATASET v1.0 Category: Bingo Simulator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PLAYERS 20
#define MAX_BINGO_CARD 10

typedef struct {
    char *name;
    int *card;
    int num;
} Player;

typedef struct {
    char *name;
    int *card;
    int num;
} Bingo;

Player players[MAX_PLAYERS];
Bingo bingos[MAX_BINGO_CARD];

void display_bingo_cards() {
    printf("Bingo Cards:\n");
    for (int i = 0; i < MAX_BINGO_CARD; i++) {
        printf("%s: ", bingos[i].name);
        for (int j = 0; j < MAX_BINGO_CARD; j++) {
            printf("%d ", bingos[i].card[j]);
        }
        printf("\n");
    }
}

void display_player_cards() {
    printf("Player Cards:\n");
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("%s: ", players[i].name);
        for (int j = 0; j < MAX_BINGO_CARD; j++) {
            printf("%d ", players[i].card[j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < MAX_BINGO_CARD; i++) {
        bingos[i].name = (char*) malloc(sizeof(char) * 10);
        strcpy(bingos[i].name, "Card ");
        bingos[i].card = (int*) malloc(sizeof(int) * MAX_BINGO_CARD);
        for (int j = 0; j < MAX_BINGO_CARD; j++) {
            bingos[i].card[j] = rand() % 75 + 1;
        }
        bingos[i].num = rand() % 100;
    }

    for (int i = 0; i < MAX_PLAYERS; i++) {
        players[i].name = (char*) malloc(sizeof(char) * 10);
        strcpy(players[i].name, "Player ");
        players[i].card = (int*) malloc(sizeof(int) * MAX_BINGO_CARD);
        for (int j = 0; j < MAX_BINGO_CARD; j++) {
            players[i].card[j] = rand() % 75 + 1;
        }
        players[i].num = rand() % 100;
    }

    int player_num;
    printf("Welcome to C Bingo Simulator!\n");
    printf("How many players would you like to play? ");
    scanf("%d", &player_num);

    for (int i = 0; i < player_num; i++) {
        printf("Player %d: ", i + 1);
        scanf("%s", players[i].name);
    }

    display_bingo_cards();
    display_player_cards();

    int player_turn;
    printf("Who would like to go first? ");
    scanf("%d", &player_turn);

    for (int i = 0; i < player_num; i++) {
        for (int j = 0; j < MAX_BINGO_CARD; j++) {
            if (bingos[j].card[j] == players[i].card[j]) {
                printf("%s wins!\n", players[i].name);
                break;
            }
        }
        if (i == player_turn) {
            printf("%s's turn!\n", players[i].name);
            display_bingo_cards();
            display_player_cards();
        } else {
            printf("%s's turn!\n", players[i].name);
        }
    }

    return 0;
}