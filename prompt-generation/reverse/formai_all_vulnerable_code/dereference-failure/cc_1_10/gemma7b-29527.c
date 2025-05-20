//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_Players 4

typedef struct Player {
    char name[20];
    int score;
    struct Player* next;
} Player;

Player* CreatePlayer(char* name, int score) {
    Player* player = malloc(sizeof(Player));
    strcpy(player->name, name);
    player->score = score;
    player->next = NULL;
    return player;
}

void AddPlayer(Player* head, char* name, int score) {
    Player* newPlayer = CreatePlayer(name, score);
    if (head == NULL) {
        head = newPlayer;
    } else {
        Player* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newPlayer;
    }
}

void PrintPlayers(Player* head) {
    Player* temp = head;
    while (temp) {
        printf("%s: %d\n", temp->name, temp->score);
        temp = temp->next;
    }
}

int main() {
    Player* head = NULL;
    int numPlayers = 0;

    // Join the game
    char* name = malloc(20);
    printf("Enter your name: ");
    scanf("%s", name);

    // Add the player to the game
    AddPlayer(head, name, 0);
    numPlayers++;

    // Invite other players to join
    printf("Enter the name of the player you want to invite: ");
    char* inviteeName = malloc(20);
    scanf("%s", inviteeName);

    // Add the invited player to the game
    AddPlayer(head, inviteeName, 0);
    numPlayers++;

    // Print the list of players
    PrintPlayers(head);

    // Start the game
    // (code omitted)

    return 0;
}