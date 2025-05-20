//Gemma-7B DATASET v1.0 Category: Log analysis ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Players 4

typedef struct Player {
    char name[20];
    int score;
    int team;
    struct Player* next;
} Player;

Player* CreatePlayer(char* name, int score, int team) {
    Player* newPlayer = (Player*)malloc(sizeof(Player));
    strcpy(newPlayer->name, name);
    newPlayer->score = score;
    newPlayer->team = team;
    newPlayer->next = NULL;
    return newPlayer;
}

void AddPlayerToTeam(Player* player, int team) {
    player->team = team;
}

void PrintPlayerList(Player* head) {
    while (head) {
        printf("%s: %d, Team: %d\n", head->name, head->score, head->team);
        head = head->next;
    }
}

int main() {
    Player* head = NULL;

    // Create a list of players
    Player* player1 = CreatePlayer("John Doe", 100, 1);
    Player* player2 = CreatePlayer("Jane Doe", 50, 2);
    Player* player3 = CreatePlayer("Mike Smith", 75, 1);
    Player* player4 = CreatePlayer("Alice White", 25, 2);

    // Add players to their teams
    AddPlayerToTeam(player1, 1);
    AddPlayerToTeam(player2, 2);
    AddPlayerToTeam(player3, 1);
    AddPlayerToTeam(player4, 2);

    // Print the player list
    PrintPlayerList(head);

    return 0;
}