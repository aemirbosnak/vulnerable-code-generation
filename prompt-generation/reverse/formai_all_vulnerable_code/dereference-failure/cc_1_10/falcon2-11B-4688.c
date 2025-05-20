//Falcon2-11B DATASET v1.0 Category: Memory Game ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
} MemoryGame;

void initMemoryGame(MemoryGame *game) {
    game->head = NULL;
    game->tail = NULL;
}

void addNode(MemoryGame *game, int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;

    if (game->head == NULL) {
        game->head = newNode;
        game->tail = newNode;
    } else {
        game->tail->next = newNode;
        game->tail = newNode;
    }
}

int main() {
    MemoryGame game;
    initMemoryGame(&game);

    addNode(&game, 5);
    addNode(&game, 10);
    addNode(&game, 15);

    printf("Game Memory: ");
    printf("%d ", game.head->value);

    while (game.head!= NULL) {
        printf("%d ", game.head->value);
        game.head = game.head->next;
    }

    return 0;
}