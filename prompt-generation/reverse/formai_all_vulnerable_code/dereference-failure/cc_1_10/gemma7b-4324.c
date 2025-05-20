//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insertAtTail(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void playMemoryGame(Node* head) {
    int i, randomIndex, guessNumber, isWon = 0;

    for (i = 0; i < MAX_SIZE; i++) {
        randomIndex = rand() % MAX_SIZE;
        guessNumber = head->data;

        if (guessNumber == randomIndex) {
            isWon = 1;
            break;
        }

        head = head->next;
    }

    if (isWon) {
        printf("Congratulations! You won!\n");
    } else {
        printf("Sorry, you lost.\n");
    }
}

int main() {
    Node* head = NULL;

    // Insert some data into the linked list
    insertAtTail(&head, 10);
    insertAtTail(&head, 20);
    insertAtTail(&head, 30);
    insertAtTail(&head, 40);
    insertAtTail(&head, 50);

    // Play the memory game
    playMemoryGame(head);

    return 0;
}