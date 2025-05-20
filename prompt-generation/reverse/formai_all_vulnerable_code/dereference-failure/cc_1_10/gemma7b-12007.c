//Gemma-7B DATASET v1.0 Category: System boot optimizer ; Style: multiplayer
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

void optimize(Node* head) {
    Node* current = head;
    while (current) {
        Player* player = current->player;
        if (player->score < 0) {
            current->player = NULL;
            free(player);
        }
        current = current->next;
    }
}

int main() {
    Node* head = NULL;
    for (int i = 0; i < MAX_PLAYER; i++) {
        Player* player = (Player*)malloc(sizeof(Player));
        strcpy(player->name, "Player");
        player->score = i;
        Node* node = (Node*)malloc(sizeof(Node));
        node->player = player;
        node->next = head;
        head = node;
    }

    optimize(head);

    printf("Optimized list:\n");
    for (Node* current = head; current; current = current->next) {
        Player* player = current->player;
        printf("%s: %d\n", player->name, player->score);
    }

    return 0;
}