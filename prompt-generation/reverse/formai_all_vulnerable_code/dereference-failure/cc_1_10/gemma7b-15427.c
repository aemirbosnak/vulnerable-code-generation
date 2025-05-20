//Gemma-7B DATASET v1.0 Category: Table Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAX_PLAYER_COUNT 4

typedef struct Player {
    char name[20];
    int score;
    struct Node* next;
} Player;

typedef struct Node {
    Player* player;
    struct Node* next;
} Node;

Node* createNode(Player* player) {
    Node* newNode = malloc(sizeof(Node));
    newNode->player = player;
    newNode->next = NULL;
    return newNode;
}

void addPlayer(Player** head, char* name) {
    Player* newPlayer = malloc(sizeof(Player));
    strcpy(newPlayer->name, name);
    newPlayer->score = 0;
    newPlayer->next = NULL;

    if (*head == NULL) {
        *head = createNode(newPlayer);
    } else {
        (*head)->next = createNode(newPlayer);
    }
}

void playGame() {
    Player* head = NULL;
    addPlayer(&head, "John");
    addPlayer(&head, "Mary");
    addPlayer(&head, "Bob");
    addPlayer(&head, "Alice");

    // Game logic here

    // For example, print each player's name and score
    for (Player* player = head; player; player = player->next) {
        printf("%s: %d\n", player->name, player->score);
    }
}

int main() {
    playGame();
    return 0;
}