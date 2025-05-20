//Gemma-7B DATASET v1.0 Category: Intrusion detection system ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_Players 2

typedef struct Player {
    char name[20];
    int score;
    int health;
    struct Player* next;
} Player;

Player* head = NULL;

void addPlayer(char* name) {
    Player* newPlayer = (Player*)malloc(sizeof(Player));
    strcpy(newPlayer->name, name);
    newPlayer->score = 0;
    newPlayer->health = 100;
    newPlayer->next = NULL;

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

void printPlayers() {
    Player* temp = head;
    printf("Players:\n");
    while (temp) {
        printf("%s (Health: %d, Score: %d)\n", temp->name, temp->health, temp->score);
        temp = temp->next;
    }
}

int main() {
    addPlayer("John");
    addPlayer("Mary");
    addPlayer("Bob");

    printPlayers();

    return 0;
}