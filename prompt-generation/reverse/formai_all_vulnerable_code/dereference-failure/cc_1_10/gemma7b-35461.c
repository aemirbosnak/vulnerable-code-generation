//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insertAtTail(Node* head, int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    head = newNode;
}

void playMemoryGame() {
    Node* head = NULL;

    // Inserting data into the linked list
    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);
    insertAtTail(head, 50);

    // Displaying the linked list
    Node* current = head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }

    // Getting the user input
    int userGuess = 0;
    printf("\nEnter your guess: ");
    scanf("%d", &userGuess);

    // Checking if the user guess is correct
    if (userGuess == head->data) {
        printf("Congratulations! You won!");
    } else {
        printf("Sorry, your guess is incorrect.");
    }
}

int main() {
    playMemoryGame();

    return 0;
}