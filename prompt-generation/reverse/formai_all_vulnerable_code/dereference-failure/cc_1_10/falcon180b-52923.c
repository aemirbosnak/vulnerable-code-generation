//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_PLAYERS 4
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Player;

Player players[MAX_PLAYERS];
int num_players;

void init_players() {
    for (int i = 0; i < MAX_PLAYERS; i++) {
        strcpy(players[i].name, "");
        players[i].score = 0;
    }
    num_players = 0;
}

void add_player(char* name) {
    if (num_players >= MAX_PLAYERS) {
        printf("Maximum number of players reached.\n");
        return;
    }
    strcpy(players[num_players].name, name);
    num_players++;
}

void display_scoreboard() {
    printf("Scoreboard:\n");
    for (int i = 0; i < num_players; i++) {
        printf("%d. %s - %d points\n", i+1, players[i].name, players[i].score);
    }
}

int main() {
    init_players();

    char input[100];
    while (1) {
        printf("Enter command: ");
        fgets(input, 100, stdin);
        char* command = strtok(input, " ");

        if (strcmp(command, "add_player") == 0) {
            char* name = strtok(NULL, " ");
            add_player(name);
        } else if (strcmp(command, "display_scoreboard") == 0) {
            display_scoreboard();
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}