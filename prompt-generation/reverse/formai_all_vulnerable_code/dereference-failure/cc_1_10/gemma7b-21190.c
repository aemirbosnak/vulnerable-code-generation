//Gemma-7B DATASET v1.0 Category: Table Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM_OF_PLAYERS 4

typedef struct Player {
    char name[20];
    int score;
    struct Player* next;
} Player;

void initializePlayers(Player** head) {
    *head = NULL;
}

void addPlayer(Player** head, char* name, int score) {
    Player* newPlayer = malloc(sizeof(Player));
    strcpy(newPlayer->name, name);
    newPlayer->score = score;
    newPlayer->next = NULL;

    if (*head == NULL) {
        *head = newPlayer;
    } else {
        (*head)->next = newPlayer;
    }
}

void playGame(Player* head) {
    // Game logic
    // For example, calculate player's turn, move pieces, etc.
}

int main() {
    Player* head = NULL;
    initializePlayers(&head);

    // Add players
    addPlayer(&head, "John", 10);
    addPlayer(&head, "Mary", 20);
    addPlayer(&head, "Bob", 30);
    addPlayer(&head, "Alice", 40);

    // Play the game
    playGame(head);

    // Print the results
    Player* currentPlayer = head;
    while (currentPlayer) {
        printf("%s's score: %d\n", currentPlayer->name, currentPlayer->score);
        currentPlayer = currentPlayer->next;
    }

    return 0;
}