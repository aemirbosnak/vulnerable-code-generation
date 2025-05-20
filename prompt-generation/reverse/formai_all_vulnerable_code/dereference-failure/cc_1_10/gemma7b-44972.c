//Gemma-7B DATASET v1.0 Category: Table Game ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX_Players 2

typedef struct Player {
    char name[20];
    int score;
    struct Player* next;
} Player;

Player* createPlayer(char* name) {
    Player* player = (Player*)malloc(sizeof(Player));
    strcpy(player->name, name);
    player->score = 0;
    player->next = NULL;
    return player;
}

void addPlayer(Player* head, char* name) {
    Player* newPlayer = createPlayer(name);
    if (head == NULL) {
        head = newPlayer;
    } else {
        head->next = newPlayer;
        head = newPlayer;
    }
}

void playGame() {
    Player* head = NULL;
    addPlayer(head, "John");
    addPlayer(head, "Alice");

    // Game logic
    for (int i = 0; i < MAX_Players; i++) {
        // Get the player's turn
        Player* currentPlayer = head;
        while (currentPlayer->next != NULL) {
            currentPlayer = currentPlayer->next;
        }

        // Simulate rolling the dice
        int roll = rand() % 6 + 1;

        // Update the player's score
        currentPlayer->score += roll;

        // Print the player's score
        printf("%s's score is %d\n", currentPlayer->name, currentPlayer->score);
    }

    // Print the winner
    Player* winner = head;
    while (winner->next != NULL) {
        winner = winner->next;
    }
    printf("The winner is: %s\n", winner->name);
}

int main() {
    playGame();
    return 0;
}