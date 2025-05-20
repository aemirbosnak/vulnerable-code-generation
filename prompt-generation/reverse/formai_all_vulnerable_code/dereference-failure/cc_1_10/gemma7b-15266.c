//Gemma-7B DATASET v1.0 Category: Table Game ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM_PLAYER 4

typedef struct Player {
    char name[20];
    int score;
    struct Player* next;
} Player;

Player* createPlayer(char* name, int score) {
    Player* player = malloc(sizeof(Player));
    strcpy(player->name, name);
    player->score = score;
    player->next = NULL;
    return player;
}

void addPlayer(Player* head, char* name, int score) {
    Player* newPlayer = createPlayer(name, score);
    if (head == NULL) {
        head = newPlayer;
    } else {
        head->next = newPlayer;
    }
    head = newPlayer;
}

void playCTableGame() {
    Player* head = NULL;
    addPlayer(head, "John", 10);
    addPlayer(head, "Mary", 20);
    addPlayer(head, "Bob", 30);
    addPlayer(head, "Alice", 40);

    // Game logic goes here
    printf("Welcome to the C Table Game!\n");
    printf("Current players: ");
    Player* currentPlayer = head;
    while (currentPlayer) {
        printf("%s, ", currentPlayer->name);
        currentPlayer = currentPlayer->next;
    }
    printf("\n");
    printf("Let's start the game!\n");
    // ...
}

int main() {
    playCTableGame();
    return 0;
}