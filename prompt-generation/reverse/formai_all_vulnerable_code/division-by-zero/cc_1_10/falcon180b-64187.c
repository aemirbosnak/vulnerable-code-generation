//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 10
#define MAX_PLAYER_NAME_LENGTH 20

typedef struct player {
    char name[MAX_PLAYER_NAME_LENGTH];
    int score;
    int is_active;
} Player;

void init_player(Player* player, char* name) {
    strncpy(player->name, name, MAX_PLAYER_NAME_LENGTH);
    player->score = 0;
    player->is_active = 1;
}

void print_player(Player player) {
    printf("%s: %d\n", player.name, player.score);
}

int main() {
    srand(time(NULL));

    int num_players;
    printf("Enter the number of players (max %d): ", MAX_PLAYERS);
    scanf("%d", &num_players);

    Player players[MAX_PLAYERS];
    for (int i = 0; i < num_players; i++) {
        char name[MAX_PLAYER_NAME_LENGTH];
        printf("Enter player %d's name: ", i+1);
        scanf("%s", name);
        init_player(&players[i], name);
    }

    int current_player = 0;
    int round_number = 0;

    while (1) {
        printf("\nRound %d\n", round_number);

        for (int i = 0; i < num_players; i++) {
            if (players[i].is_active) {
                printf("%s's turn\n", players[i].name);
                int choice;
                printf("1. Roll dice\n2. Pass turn\n");
                scanf("%d", &choice);

                if (choice == 1) {
                    int dice_roll = rand() % 6 + 1;
                    printf("%s rolled a %d\n", players[i].name, dice_roll);
                    players[i].score += dice_roll;
                } else {
                    printf("%s passed their turn\n", players[i].name);
                }
            }
        }

        round_number++;

        int num_eliminated = 0;
        for (int i = 0; i < num_players; i++) {
            if (players[i].score >= 100) {
                printf("%s has reached 100 points and is eliminated!\n", players[i].name);
                players[i].is_active = 0;
                num_eliminated++;
            }
        }

        if (num_eliminated == num_players - 1) {
            printf("Only %s remains, they win!\n", players[num_eliminated].name);
            break;
        }

        current_player = (current_player + 1) % num_players;
    }

    return 0;
}