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

void InsertPlayer(Node** head, Player* newPlayer) {
    Node* newNode = malloc(sizeof(struct Node));
    newNode->player = newPlayer;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void PlayGame(Node* head) {
    // Shuffle the order of players
    srand(time(NULL));
    int order[MAX_Players];
    for (int i = 0; i < MAX_Players; i++) {
        order[i] = rand() % MAX_Players;
    }

    // Each player plays their turn
    for (int i = 0; i < MAX_Players; i++) {
        Player* player = head->player;
        printf("%s, it is your turn!\n", player->name);

        // Get the player's input
        int input = 0;
        scanf("%d", &input);

        // Calculate the player's score
        int score = input + player->score;
        player->score = score;

        // Print the player's score
        printf("Your score is: %d\n", player->score);
    }

    // Print the winner
    Player* winner = head->player;
    printf("The winner is: %s!\n", winner->name);
}

int main() {
    // Create a list of players
    Player* head = NULL;
    InsertPlayer(&head, malloc(sizeof(struct Player)));
    strcpy(head->name, "John");
    head->score = 0;
    InsertPlayer(&head, malloc(sizeof(struct Player)));
    strcpy(head->name, "Mary");
    head->score = 0;
    InsertPlayer(&head, malloc(sizeof(struct Player)));
    strcpy(head->name, "Bob");
    head->score = 0;
    InsertPlayer(&head, malloc(sizeof(struct Player)));
    strcpy(head->name, "Alice");
    head->score = 0;

    // Play the game
    PlayGame(head);

    return 0;
}