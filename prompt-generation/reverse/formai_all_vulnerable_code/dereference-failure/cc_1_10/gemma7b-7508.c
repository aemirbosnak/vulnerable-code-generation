//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Players 2

typedef struct Player {
    char name[20];
    int heartRate;
    int stepsTaken;
    int pointsEarned;
} Player;

void initializePlayers(Player *players, int numPlayers) {
    for (int i = 0; i < numPlayers; i++) {
        players[i].name[0] = '\0';
        players[i].heartRate = 0;
        players[i].stepsTaken = 0;
        players[i].pointsEarned = 0;
    }
}

void updatePlayerStatus(Player *player) {
    player->heartRate++;
    player->stepsTaken++;
    player->pointsEarned++;
}

void displayPlayerStatus(Player *player) {
    printf("Name: %s\n", player->name);
    printf("Heart Rate: %d\n", player->heartRate);
    printf("Steps Taken: %d\n", player->stepsTaken);
    printf("Points Earned: %d\n", player->pointsEarned);
}

int main() {
    Player players[MAX_Players];
    initializePlayers(players, MAX_Players);

    // Multiplayer game loop
    for (int round = 0; round < 10; round++) {
        // Each player takes turns updating their status
        for (int i = 0; i < MAX_Players; i++) {
            updatePlayerStatus(&players[i]);
        }

        // Display each player's status
        for (int i = 0; i < MAX_Players; i++) {
            displayPlayerStatus(&players[i]);
        }

        // Calculate winner
        Player *winner = NULL;
        for (int i = 0; i < MAX_Players; i++) {
            if (players[i].pointsEarned > winner->pointsEarned) {
                winner = &players[i];
            }
        }

        // Announce winner
        if (winner) {
            printf("Winner: %s\n", winner->name);
        } else {
            printf("No winner!\n");
        }
    }

    return 0;
}