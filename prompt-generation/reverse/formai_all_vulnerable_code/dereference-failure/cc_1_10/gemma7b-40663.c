//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Players 4

typedef struct Player {
    char name[20];
    int id;
    struct Node* head;
    struct Node* tail;
} Player;

typedef struct Node {
    Player* player;
    struct Node* next;
} Node;

void join_game(Player* player) {
    Node* newNode = malloc(sizeof(Node));
    newNode->player = player;
    newNode->next = NULL;

    if (player->head == NULL) {
        player->head = newNode;
        player->tail = newNode;
    } else {
        player->tail->next = newNode;
        player->tail = newNode;
    }
}

void print_topology(Player* player) {
    Node* current = player->head;
    while (current) {
        printf("%s", current->player->name);
        if (current->next) {
            printf(", ");
        }
    }
    printf("\n");
}

int main() {
    Player players[MAX_Players];
    for (int i = 0; i < MAX_Players; i++) {
        players[i].id = i;
        players[i].head = NULL;
        players[i].tail = NULL;
    }

    // Multiplayer logic
    // Each player joins the game and their name is added to the topology
    join_game(&players[0]);
    join_game(&players[1]);
    join_game(&players[2]);
    join_game(&players[3]);

    // Print the topology
    print_topology(&players[0]);

    return 0;
}