//Falcon-180B DATASET v1.0 Category: Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PLAYERS 10
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Player;

void init_player(Player* player) {
    strcpy(player->name, "Player");
    player->score = 0;
}

void print_player(Player player) {
    printf("%s: %d\n", player.name, player.score);
}

int main() {
    srand(time(NULL));

    char game_name[MAX_NAME_LENGTH];
    printf("Enter the name of the game: ");
    scanf("%s", game_name);

    int num_players;
    printf("Enter the number of players (maximum %d): ", MAX_PLAYERS);
    scanf("%d", &num_players);

    Player players[MAX_PLAYERS];
    for (int i = 0; i < num_players; i++) {
        init_player(&players[i]);
    }

    int current_player = 0;

    while (1) {
        printf("\n%s's turn\n", players[current_player].name);

        int choice;
        printf("1. Roll the dice\n2. Pass the turn\n");
        scanf("%d", &choice);

        if (choice == 1) {
            int dice_roll = rand() % 6 + 1;
            printf("%s rolled %d\n", players[current_player].name, dice_roll);

            if (dice_roll == 6) {
                printf("%s gets an extra turn!\n", players[current_player].name);
            } else {
                current_player = (current_player + 1) % num_players;
            }
        } else {
            current_player = (current_player + 1) % num_players;
        }
    }

    return 0;
}