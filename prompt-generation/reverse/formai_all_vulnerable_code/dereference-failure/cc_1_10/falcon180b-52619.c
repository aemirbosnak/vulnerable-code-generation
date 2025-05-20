//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_PLAYERS 100
#define MAX_NAME_LENGTH 20
#define MAX_MSG_LENGTH 200

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
    bool is_playing;
} Player;

Player players[MAX_PLAYERS];
int num_players;

void init_players() {
    num_players = 0;
    for (int i = 0; i < MAX_PLAYERS; i++) {
        players[i].is_playing = false;
        players[i].score = 0;
        strcpy(players[i].name, "");
    }
}

void print_players() {
    printf("Players:\n");
    for (int i = 0; i < num_players; i++) {
        printf("%d. %s - %d points\n", i + 1, players[i].name, players[i].score);
    }
}

void add_player(char* name) {
    for (int i = 0; i < num_players; i++) {
        if (strcmp(players[i].name, name) == 0) {
            printf("Player %s is already in the game.\n", name);
            return;
        }
    }

    strcpy(players[num_players].name, name);
    players[num_players].is_playing = true;
    players[num_players].score = 0;
    num_players++;

    printf("Player %s added to the game.\n", name);
}

void remove_player(char* name) {
    for (int i = 0; i < num_players; i++) {
        if (strcmp(players[i].name, name) == 0) {
            players[i].is_playing = false;
            printf("Player %s removed from the game.\n", name);
            return;
        }
    }

    printf("Player %s not found in the game.\n", name);
}

void send_message(int player_id, char* msg) {
    printf("Player %d: %s\n", player_id, msg);
}

int main() {
    init_players();

    while (true) {
        printf("Enter your name: ");
        char name[MAX_NAME_LENGTH];
        scanf("%s", name);

        add_player(name);

        while (true) {
            printf("Enter a message to send: ");
            char msg[MAX_MSG_LENGTH];
            scanf("%[^\n]", msg);

            send_message(num_players - 1, msg);
        }
    }

    return 0;
}