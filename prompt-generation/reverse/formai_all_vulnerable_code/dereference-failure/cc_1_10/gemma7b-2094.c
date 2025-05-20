//Gemma-7B DATASET v1.0 Category: Weather simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_Players 4

typedef struct Player {
    char name[20];
    int x, y;
    int windDir;
    int windSpeed;
} Player;

void initializePlayers(Player *players, int numPlayers) {
    for (int i = 0; i < numPlayers; i++) {
        players[i].x = rand() % 100;
        players[i].y = rand() % 100;
        players[i].windDir = rand() % 4;
        players[i].windSpeed = rand() % 5;
    }
}

void updatePlayerPosition(Player *players, int numPlayers) {
    for (int i = 0; i < numPlayers; i++) {
        switch (players[i].windDir) {
            case 0:
                players[i].x++;
                break;
            case 1:
                players[i].x--;
                break;
            case 2:
                players[i].y++;
                break;
            case 3:
                players[i].y--;
                break;
        }

        players[i].x += players[i].windSpeed;
        players[i].y += players[i].windSpeed;
    }
}

void printPlayerPositions(Player *players, int numPlayers) {
    for (int i = 0; i < numPlayers; i++) {
        printf("%s is at (%d, %d)\n", players[i].name, players[i].x, players[i].y);
    }
}

int main() {
    int numPlayers = 2;
    Player *players = (Player *)malloc(numPlayers * sizeof(Player));

    initializePlayers(players, numPlayers);
    updatePlayerPosition(players, numPlayers);
    printPlayerPositions(players, numPlayers);

    free(players);
    return 0;
}