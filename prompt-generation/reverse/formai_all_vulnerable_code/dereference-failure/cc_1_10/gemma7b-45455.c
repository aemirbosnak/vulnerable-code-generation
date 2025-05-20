//Gemma-7B DATASET v1.0 Category: Disk space analyzer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Players 4

typedef struct Player {
    char name[20];
    int score;
    struct Node* node;
} Player;

typedef struct Node {
    Player* player;
    struct Node* next;
} Node;

void AnalyzeDiskSpace(Node* head) {
    int totalSpace = 0;
    Node* current = head;
    while (current) {
        totalSpace += current->player->score;
        current = current->next;
    }
    printf("Total space used: %d KB", totalSpace);
}

int main() {
    // Create a linked list of players
    Node* head = NULL;
    for (int i = 0; i < MAX_Players; i++) {
        Player* player = (Player*)malloc(sizeof(Player));
        strcpy(player->name, "Player");
        player->score = rand() % 100;
        Node* node = (Node*)malloc(sizeof(Node));
        node->player = player;
        node->next = NULL;
        if (head) {
            head->next = node;
            head = node;
        } else {
            head = node;
        }
    }

    // Analyze disk space
    AnalyzeDiskSpace(head);

    return 0;
}