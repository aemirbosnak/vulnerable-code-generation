//Gemma-7B DATASET v1.0 Category: Table Game ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX_PLAYER_COUNT 2

typedef struct Player {
    char name[20];
    int score;
    struct Player* next;
} Player;

void initGame(Player** head) {
    *head = NULL;
}

void addPlayer(Player** head, char* name) {
    Player* newPlayer = malloc(sizeof(Player));
    strcpy(newPlayer->name, name);
    newPlayer->score = 0;
    newPlayer->next = NULL;

    if (*head == NULL) {
        *head = newPlayer;
    } else {
        (*head)->next = newPlayer;
    }
}

void playGame(Player* head) {
    // Roll the dice
    int roll = rand() % 6 + 1;

    // Move the player's piece
    head->score += roll;

    // Check if the player has won
    if (head->score >= 100) {
        printf("%s has won the game!\n", head->name);
    } else {
        printf("%s's turn.\n", head->name);
    }
}

int main() {
    Player* head = NULL;
    initGame(&head);

    // Add players to the game
    addPlayer(&head, "John");
    addPlayer(&head, "Mary");

    // Play the game
    playGame(head);

    return 0;
}