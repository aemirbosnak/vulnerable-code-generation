//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYER_NAME_LENGTH 20

typedef struct Player {
    char name[MAX_PLAYER_NAME_LENGTH];
    int score;
    struct Node* next;
} Player;

typedef struct Node {
    Player* player;
    struct Node* next;
} Node;

void insertPlayer(Node** head, Player* player) {
    Node* newNode = malloc(sizeof(Node));
    newNode->player = player;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void printPlayers(Node* head) {
    Node* current = head;
    while (current) {
        printf("%s, ", current->player->name);
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    Player* player1 = malloc(sizeof(Player));
    strcpy(player1->name, "John");
    player1->score = 100;

    Player* player2 = malloc(sizeof(Player));
    strcpy(player2->name, "Mary");
    player2->score = 50;

    insertPlayer(&head, player1);
    insertPlayer(&head, player2);

    printPlayers(head);

    return 0;
}