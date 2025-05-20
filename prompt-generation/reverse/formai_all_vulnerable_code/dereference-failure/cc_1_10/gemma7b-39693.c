//Gemma-7B DATASET v1.0 Category: Table Game ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX_PLAYER_NAME_LENGTH 20

typedef struct Player {
    char name[MAX_PLAYER_NAME_LENGTH];
    int score;
    struct Player* next;
} Player;

void initializePlayer(Player** head) {
    *head = malloc(sizeof(Player));
    (*head)->name[0] = '\0';
    (*head)->score = 0;
    (*head)->next = NULL;
}

void addPlayer(Player** head) {
    Player* newPlayer = malloc(sizeof(Player));
    newPlayer->name[0] = '\0';
    newPlayer->score = 0;
    newPlayer->next = NULL;

    if (*head) {
        ((*head)->next = newPlayer);
        *head = newPlayer;
    } else {
        *head = newPlayer;
    }
}

void playGame(Player* head) {
    // Game logic goes here
    printf("Welcome, %s, to the game!\n", head->name);
    printf("Your current score is: %d\n", head->score);

    // Simulate some gameplay
    head->score++;
    printf("You have scored 1 point! Your new score is: %d\n", head->score);
}

int main() {
    Player* head = NULL;

    initializePlayer(&head);
    addPlayer(&head);
    addPlayer(&head);
    addPlayer(&head);

    playGame(head);

    return 0;
}