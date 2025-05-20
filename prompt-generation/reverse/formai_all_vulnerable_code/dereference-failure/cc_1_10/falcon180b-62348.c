//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 10
#define MAX_SCORES 100

typedef struct {
    char name[20];
    int score;
} Player;

typedef struct node {
    Player player;
    struct node* next;
} Node;

Node* createNode(Player player) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    newNode->player = player;
    newNode->next = NULL;
    return newNode;
}

void addPlayer(Node** head, char name[20], int score) {
    Node* newNode = createNode((Player) {name, score});
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printPlayers(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%s - %d\n", temp->player.name, temp->player.score);
        temp = temp->next;
    }
}

void sortPlayers(Node** head) {
    Node* temp = *head;
    Node* prev = NULL;
    while (temp!= NULL) {
        while (temp->next!= NULL && temp->player.score < temp->next->player.score) {
            temp = temp->next;
        }
        if (prev!= temp) {
            Node* next = temp->next;
            temp->next = prev;
            prev->next = next;
            prev = temp;
        }
        temp = temp->next;
    }
    *head = prev;
}

int main() {
    srand(time(NULL));
    Node* head = NULL;
    int numPlayers = rand() % MAX_PLAYERS + 1;
    for (int i = 0; i < numPlayers; i++) {
        char name[20];
        sprintf(name, "Player %d", i + 1);
        addPlayer(&head, name, rand() % MAX_SCORES + 1);
    }
    printf("Initial list:\n");
    printPlayers(head);
    sortPlayers(&head);
    printf("\nSorted list:\n");
    printPlayers(head);
    return 0;
}