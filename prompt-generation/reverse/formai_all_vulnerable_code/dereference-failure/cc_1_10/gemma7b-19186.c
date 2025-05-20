//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Players 4

typedef struct Player {
    char name[20];
    int score;
    struct Node *next;
} Player;

typedef struct Node {
    Player *player;
    struct Node *next;
} Node;

Node *head = NULL;

void insertPlayer(char *name, int score) {
    Node *newNode = malloc(sizeof(Node));
    Player *newPlayer = malloc(sizeof(Player));

    strcpy(newPlayer->name, name);
    newPlayer->score = score;

    newNode->player = newPlayer;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node *temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void playGame() {
    Node *currentPlayer = head;

    while (currentPlayer) {
        printf("%s's turn:\n", currentPlayer->player->name);
        printf("Enter your move: ");
        char move;
        scanf("%c", &move);

        // Implement move logic based on move and current player's turn
    }

    printf("Game over!\n");
}

int main() {
    insertPlayer("John", 10);
    insertPlayer("Mary", 5);
    insertPlayer("Bob", 7);
    insertPlayer("Alice", 2);

    playGame();

    return 0;
}