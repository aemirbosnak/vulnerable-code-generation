//Gemma-7B DATASET v1.0 Category: Image Classification system ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Players 2

typedef struct Player {
    char name[20];
    int team;
    int score;
    struct Node *node;
} Player;

typedef struct Node {
    Player *player;
    struct Node *next;
} Node;

void join_team(Player *player, int team) {
    player->team = team;
    player->node = NULL;
}

void add_player(Node **head, Player *player) {
    Node *newNode = malloc(sizeof(Node));
    newNode->player = player;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

int main() {
    Player players[MAX_Players];
    Node *head = NULL;

    // Initialize players
    for (int i = 0; i < MAX_Players; i++) {
        players[i].name[0] = '\0';
        players[i].team = -1;
        players[i].score = 0;
    }

    // Join teams
    join_team(&players[0], 0);
    join_team(&players[1], 1);

    // Add players to the list
    add_player(&head, &players[0]);
    add_player(&head, &players[1]);

    // Print team information
    for (Node *node = head; node; node = node->next) {
        printf("%s is on team %d\n", node->player->name, node->player->team);
    }

    return 0;
}