//Gemma-7B DATASET v1.0 Category: Table Game ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX_PLAYER 2

typedef struct Player {
    char name[20];
    int score;
    struct Node* next;
} Player;

typedef struct Node {
    Player* player;
    struct Node* next;
} Node;

void initGame(Node** head) {
    *head = NULL;
}

void addPlayer(Node** head, Player* player) {
    Node* newNode = malloc(sizeof(Node));
    newNode->player = player;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void playGame(Node* head) {
    while (head) {
        Player* player = head->player;
        printf("Player: %s, Score: %d\n", player->name, player->score);
        head = head->next;
    }
}

int main() {
    Node* head = NULL;

    Player* player1 = malloc(sizeof(Player));
    strcpy(player1->name, "John");
    player1->score = 10;

    Player* player2 = malloc(sizeof(Player));
    strcpy(player2->name, "Mary");
    player2->score = 20;

    initGame(&head);
    addPlayer(&head, player1);
    addPlayer(&head, player2);

    playGame(head);

    return 0;
}