//Gemma-7B DATASET v1.0 Category: Table Game ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define MAX_Players 4

typedef struct Player {
    char name[20];
    int score;
    struct Player* next;
} Player;

void initializePlayers(Player** head) {
    *head = NULL;
    for (int i = 0; i < MAX_Players; i++) {
        Player* newPlayer = (Player*)malloc(sizeof(Player));
        strcpy(newPlayer->name, "Player");
        newPlayer->score = 0;
        newPlayer->next = *head;
        *head = newPlayer;
    }
}

void playGame(Player* head) {
    // Roll the dice and get the number
    int roll = rand() % 6 + 1;

    // Move the player's piece around the board
    Player* currentPlayer = head;
    while (currentPlayer) {
        if (currentPlayer->score + roll >= MAX_Players) {
            currentPlayer->score = MAX_Players - 1;
            break;
        } else {
            currentPlayer->score += roll;
            currentPlayer = currentPlayer->next;
        }
    }

    // Print the winner
    currentPlayer = head;
    while (currentPlayer) {
        if (currentPlayer->score == MAX_Players - 1) {
            printf("%s won the game!", currentPlayer->name);
            break;
        }
        currentPlayer = currentPlayer->next;
    }
}

int main() {
    Player** head = NULL;
    initializePlayers(head);
    playGame(head);

    return 0;
}