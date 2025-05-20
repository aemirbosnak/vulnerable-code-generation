//Gemma-7B DATASET v1.0 Category: Benchmarking ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_Players 4

typedef struct Player {
    char name[20];
    int score;
    struct Node* next;
} Player;

typedef struct Node {
    Player* player;
    struct Node* next;
} Node;

void initializePlayers(Node* head) {
    for (int i = 0; i < MAX_Players; i++) {
        Player* newPlayer = (Player*)malloc(sizeof(Player));
        strcpy(newPlayer->name, "Player");
        newPlayer->score = 0;
        newPlayer->next = NULL;

        if (head == NULL) {
            head = (Node*)malloc(sizeof(Node));
            head->player = newPlayer;
            head->next = NULL;
        } else {
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->player = newPlayer;
            newNode->next = NULL;
            head->next = newNode;
            head = newNode;
        }
    }
}

void startGame(Node* head) {
    // Randomly choose the starting player
    srand(time(NULL));
    int startPlayer = rand() % MAX_Players;

    // Each player takes turns rolling the dice
    for (int i = 0; i < MAX_Players; i++) {
        // Get the player's turn
        if (startPlayer == i) {
            // Roll the dice
            int roll = rand() % 6 + 1;

            // Update the player's score
            head->player->score += roll;

            // Print the player's turn
            printf("%s rolled a %d and has a score of %d\n", head->player->name, roll, head->player->score);
        }
    }

    // Print the final scores
    for (Node* current = head; current; current = current->next) {
        printf("%s's final score is %d\n", current->player->name, current->player->score);
    }
}

int main() {
    Node* head = NULL;
    initializePlayers(head);
    startGame(head);

    return 0;
}