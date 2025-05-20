//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: multiplayer
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

Node* head = NULL;

void addPlayer(char* name) {
    Player* newPlayer = (Player*)malloc(sizeof(Player));
    strcpy(newPlayer->name, name);
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

void startGame() {
    time_t t = time(NULL);
    srand(t);

    for (int i = 0; i < MAX_Players; i++) {
        int roll = rand() % 6 + 1;
        printf("%s rolled a %d.\n", head->player->name, roll);
        head->player->score += roll;
        head = head->next;
    }

    for (Node* current = head; current; current = current->next) {
        printf("%s's final score is %d.\n", current->player->name, current->player->score);
    }
}

int main() {
    addPlayer("John");
    addPlayer("Mary");
    addPlayer("Bob");
    addPlayer("Alice");

    startGame();

    return 0;
}