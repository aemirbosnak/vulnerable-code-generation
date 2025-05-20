//Gemma-7B DATASET v1.0 Category: Table Game ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define MAX_Players 4

typedef struct Player {
    char name[20];
    int score;
    struct Player* next;
} Player;

Player* CreatePlayer(char* name) {
    Player* player = malloc(sizeof(Player));
    strcpy(player->name, name);
    player->score = 0;
    player->next = NULL;
    return player;
}

void AddPlayer(Player* head, char* name) {
    Player* newPlayer = CreatePlayer(name);
    if (head == NULL) {
        head = newPlayer;
    } else {
        head->next = newPlayer;
        head = newPlayer;
    }
}

void PlayGame() {
    Player* head = NULL;
    AddPlayer(head, "John");
    AddPlayer(head, "Mary");
    AddPlayer(head, "Bob");
    AddPlayer(head, "Alice");

    // Game logic here
    // For example, roll a die, move the player's token, etc.

    // Calculate the winner
    Player* winner = head;
    while (winner->next) {
        winner = winner->next;
    }

    // Announce the winner
    printf("The winner is: %s", winner->name);
}

int main() {
    PlayGame();
    return 0;
}