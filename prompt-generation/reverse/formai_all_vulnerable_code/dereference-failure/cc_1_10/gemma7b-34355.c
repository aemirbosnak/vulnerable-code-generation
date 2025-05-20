//Gemma-7B DATASET v1.0 Category: Error handling ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYER_NAME_LENGTH 20

typedef struct Player {
    char name[MAX_PLAYER_NAME_LENGTH];
    int score;
    struct Player* next;
} Player;

Player* createPlayer(char* name) {
    Player* newPlayer = malloc(sizeof(Player));
    strcpy(newPlayer->name, name);
    newPlayer->score = 0;
    newPlayer->next = NULL;
    return newPlayer;
}

void addPlayer(Player* head, char* name) {
    Player* newPlayer = createPlayer(name);
    if (head == NULL) {
        head = newPlayer;
    } else {
        head->next = newPlayer;
    }
    head = newPlayer;
}

int main() {
    Player* head = NULL;
    char* playerName;

    // Get the player's name
    printf("Enter your name: ");
    scanf("%s", playerName);

    // Add the player to the game
    addPlayer(head, playerName);

    // Check if the player has been added successfully
    if (head != NULL) {
        printf("Welcome, %s! You are now part of the game!\n", head->name);
    } else {
        printf("Error adding player. Please try again.\n");
    }

    return 0;
}