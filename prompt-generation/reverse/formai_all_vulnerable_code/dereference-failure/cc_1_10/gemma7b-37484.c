//Gemma-7B DATASET v1.0 Category: Table Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define MAX_Players 5

typedef struct Player {
    char name[20];
    int score;
    struct Player* next;
} Player;

void initializeGame(Player** head) {
    *head = NULL;
}

void addPlayer(Player** head, char name) {
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

void playRound(Player* currentPlayer, int roundNumber) {
    // Logic for each round goes here
    currentPlayer->score += roundNumber;
}

int main() {
    Player* head = NULL;

    // Initialize the game
    initializeGame(&head);

    // Add players
    addPlayer(&head, "John");
    addPlayer(&head, "Mary");
    addPlayer(&head, "Bob");
    addPlayer(&head, "Alice");

    // Play a round
    playRound(head->next, 10);

    // Print the scores
    for (Player* player = head; player; player = player->next) {
        printf("%s's score is %d\n", player->name, player->score);
    }

    return 0;
}