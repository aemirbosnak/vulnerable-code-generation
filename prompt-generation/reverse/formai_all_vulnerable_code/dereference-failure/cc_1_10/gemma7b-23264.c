//Gemma-7B DATASET v1.0 Category: Data mining ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Players 4

typedef struct Player {
    char name[20];
    int score;
    struct Player* next;
} Player;

void initGame(Player** head) {
    *head = NULL;
}

void addPlayer(Player** head, char* name) {
    Player* newNode = malloc(sizeof(Player));
    strcpy(newNode->name, name);
    newNode->score = 0;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void playGame(Player** head) {
    Player* currentPlayer = *head;
    while (currentPlayer) {
        printf("Current player: %s\n", currentPlayer->name);
        printf("Enter your move: ");
        char move;
        scanf("%c", &move);

        // Implement logic to handle player move
        currentPlayer->score++;
        printf("Your score: %d\n", currentPlayer->score);
        currentPlayer = currentPlayer->next;
    }
}

int main() {
    Player** head = NULL;
    initGame(head);

    // Add players
    addPlayer(head, "John");
    addPlayer(head, "Jane");
    addPlayer(head, "Jack");
    addPlayer(head, "Jill");

    // Play the game
    playGame(head);

    return 0;
}