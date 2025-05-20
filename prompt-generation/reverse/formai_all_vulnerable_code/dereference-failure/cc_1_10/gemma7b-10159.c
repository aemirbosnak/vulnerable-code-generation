//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: multiplayer
#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 20

typedef struct Player {
    char name[MAX_NAME_LENGTH];
    int score;
    struct Player* next;
} Player;

void addPlayer(Player** head) {
    Player* newPlayer = malloc(sizeof(Player));

    printf("Enter your name: ");
    scanf("%s", newPlayer->name);

    newPlayer->score = 0;
    newPlayer->next = NULL;

    if (*head == NULL) {
        *head = newPlayer;
    } else {
        (*head)->next = newPlayer;
    }
}

void printPlayers(Player* head) {
    Player* currentPlayer = head;

    printf("Players: ");
    while (currentPlayer) {
        printf("%s, ", currentPlayer->name);
        currentPlayer = currentPlayer->next;
    }

    printf("\n");
}

int main() {
    Player* head = NULL;

    addPlayer(&head);
    addPlayer(&head);
    addPlayer(&head);

    printPlayers(head);

    return 0;
}