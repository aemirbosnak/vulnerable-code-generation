//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 4
#define MAX_LIGHTS 10

typedef struct {
    char name[20];
    int score;
    int lights[MAX_LIGHTS];
} player;

player players[MAX_PLAYERS];
int lights[MAX_LIGHTS];

void init_game() {
    for (int i = 0; i < MAX_PLAYERS; i++) {
        strcpy(players[i].name, "Player ");
        char num[2];
        sprintf(num, "%d", i + 1);
        strcat(players[i].name, num);
        players[i].score = 0;
        for (int j = 0; j < MAX_LIGHTS; j++) {
            players[i].lights[j] = 0;
        }
    }

    for (int i = 0; i < MAX_LIGHTS; i++) {
        lights[i] = 0;
    }
}

void print_game() {
    printf("Players:\n");
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }

    printf("Lights:\n");
    for (int i = 0; i < MAX_LIGHTS; i++) {
        printf("Light %d: %d\n", i + 1, lights[i]);
    }
}

void player_turn(player *p) {
    char input[10];
    int light;

    printf("%s's turn:\n", p->name);
    printf("Enter a light number (1-%d): ", MAX_LIGHTS);
    fgets(input, sizeof(input), stdin);
    light = atoi(input) - 1;

    if (light < 0 || light >= MAX_LIGHTS) {
        printf("Invalid light number!\n");
        return;
    }

    if (lights[light] == 0) {
        lights[light] = 1;
        p->score++;
        printf("Light %d turned on!\n", light + 1);
    } else {
        printf("Light %d is already on!\n", light + 1);
    }
}

int main() {
    init_game();
    print_game();

    while (1) {
        for (int i = 0; i < MAX_PLAYERS; i++) {
            player_turn(&players[i]);
            print_game();
        }

        int all_lights_on = 1;
        for (int i = 0; i < MAX_LIGHTS; i++) {
            if (lights[i] == 0) {
                all_lights_on = 0;
                break;
            }
        }

        if (all_lights_on) {
            printf("All lights are on! Game over!\n");
            break;
        }
    }

    int winner = 0;
    int max_score = 0;
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (players[i].score > max_score) {
            winner = i;
            max_score = players[i].score;
        }
    }

    printf("%s wins with a score of %d!\n", players[winner].name, players[winner].score);

    return 0;
}