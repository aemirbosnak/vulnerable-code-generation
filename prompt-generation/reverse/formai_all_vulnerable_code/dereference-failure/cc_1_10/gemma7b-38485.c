//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define MAX_Players 4

typedef struct Player {
    char name[20];
    int health;
    int position;
    int inventory[10];
    int isAlive;
} Player;

void initializePlayers(Player *players, int numPlayers) {
    for (int i = 0; i < numPlayers; i++) {
        players[i].health = 100;
        players[i].position = 0;
        players[i].isAlive = 1;
        players[i].inventory[0] = 0;
        players[i].inventory[1] = 0;
        players[i].inventory[2] = 0;
    }
}

void movePlayer(Player *player) {
    int direction;

    printf("Enter direction (N, S, E, W): ");
    scanf("%d", &direction);

    switch (direction) {
        case 1:
            player->position++;
            break;
        case 2:
            player->position--;
            break;
        case 3:
            player->position++;
            break;
        case 4:
            player->position--;
            break;
    }
}

void interactWithObject(Player *player) {
    int objectIndex;

    printf("Enter object index to interact with: ");
    scanf("%d", &objectIndex);

    if (player->inventory[objectIndex] > 0) {
        printf("You interacted with the object: %d", player->inventory[objectIndex]);
    } else {
        printf("You do not have that object.");
    }
}

int main() {
    Player players[MAX_Players];
    initializePlayers(players, MAX_Players);

    for (int i = 0; players[i].isAlive; i++) {
        movePlayer(&players[i]);
        interactWithObject(&players[i]);
    }

    return 0;
}