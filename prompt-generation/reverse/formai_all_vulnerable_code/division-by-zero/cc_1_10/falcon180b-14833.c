//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 10
#define MAX_CARDS 100
#define MAX_BINGO 30

typedef struct {
    char name[20];
    int card[MAX_CARDS];
    int bingo[MAX_BINGO];
} Player;

void init_card(Player *player) {
    int i;
    for (i = 0; i < MAX_CARDS; i++) {
        player->card[i] = rand() % 100;
    }
}

void init_bingo(Player *player) {
    int i;
    for (i = 0; i < MAX_BINGO; i++) {
        player->bingo[i] = 0;
    }
}

void print_card(Player *player) {
    int i;
    for (i = 0; i < MAX_CARDS; i++) {
        printf("%d ", player->card[i]);
    }
    printf("\n");
}

void print_bingo(Player *player) {
    int i;
    for (i = 0; i < MAX_BINGO; i++) {
        printf("%d ", player->bingo[i]);
    }
    printf("\n");
}

int is_bingo(Player *player) {
    int i, j, count = 0;
    for (i = 0; i < MAX_BINGO; i++) {
        count = 0;
        for (j = 0; j < MAX_CARDS; j++) {
            if (player->card[j] == player->bingo[i]) {
                count++;
            }
        }
        if (count == 5) {
            return 1;
        }
    }
    return 0;
}

int main() {
    srand(time(NULL));
    Player players[MAX_PLAYERS];
    int num_players, i;
    printf("Enter number of players: ");
    scanf("%d", &num_players);
    for (i = 0; i < num_players; i++) {
        printf("Enter player %d name: ", i + 1);
        scanf("%s", players[i].name);
        init_card(&players[i]);
        init_bingo(&players[i]);
    }
    int num_cards = 0;
    while (num_cards < 75) {
        int card = rand() % 100;
        int found = 0;
        for (i = 0; i < num_cards; i++) {
            if (card == players[i % num_players].card[i]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("Card %d\n", card);
            players[i % num_players].card[num_cards] = card;
            num_cards++;
        }
    }
    int num_bingos = 0;
    while (num_bingos < num_players) {
        for (i = 0; i < num_players; i++) {
            if (is_bingo(&players[i])) {
                printf("Player %s wins!\n", players[i].name);
                num_bingos++;
                break;
            }
        }
    }
    return 0;
}