//Gemma-7B DATASET v1.0 Category: Data recovery tool ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Players 4

typedef struct Player {
    char name[20];
    int score;
    struct Player* next;
} Player;

Player* CreatePlayer(char* name, int score) {
    Player* newPlayer = (Player*)malloc(sizeof(Player));
    strcpy(newPlayer->name, name);
    newPlayer->score = score;
    newPlayer->next = NULL;
    return newPlayer;
}

void AddPlayer(Player* head, char* name, int score) {
    Player* newPlayer = CreatePlayer(name, score);
    if (head == NULL) {
        head = newPlayer;
    } else {
        head->next = newPlayer;
        head = newPlayer;
    }
}

void ShowPlayers(Player* head) {
    Player* currentPlayer = head;
    while (currentPlayer) {
        printf("%s - %d\n", currentPlayer->name, currentPlayer->score);
        currentPlayer = currentPlayer->next;
    }
}

int main() {
    Player* head = NULL;

    // Add players
    AddPlayer(head, "John", 100);
    AddPlayer(head, "Mary", 200);
    AddPlayer(head, "Bob", 300);
    AddPlayer(head, "Alice", 400);

    // Show players
    ShowPlayers(head);

    return 0;
}