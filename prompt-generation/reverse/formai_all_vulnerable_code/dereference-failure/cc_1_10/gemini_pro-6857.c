//GEMINI-pro DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PLAYERS 4

typedef struct {
    char name[20];
    int score;
} player_t;

void print_usage() {
    printf("Usage: alien_invasion_probability_calculator <num_players>\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage();
        return 1;
    }

    int num_players = atoi(argv[1]);
    if (num_players < 1 || num_players > MAX_PLAYERS) {
        printf("Error: Invalid number of players. Must be between 1 and %d.\n", MAX_PLAYERS);
        return 1;
    }

    srand(time(NULL));

    player_t players[MAX_PLAYERS];
    for (int i = 0; i < num_players; i++) {
        printf("Enter the name of player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }

    int num_rounds = 10;
    for (int i = 0; i < num_rounds; i++) {
        printf("Round %d\n", i + 1);

        for (int j = 0; j < num_players; j++) {
            int roll = rand() % 100;
            if (roll < 10) {
                printf("%s has been abducted by aliens!\n", players[j].name);
            } else {
                printf("%s has successfully avoided the aliens.\n", players[j].name);
                players[j].score++;
            }
        }

        printf("\n");
    }

    printf("Final scores:\n");
    for (int i = 0; i < num_players; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }

    return 0;
}