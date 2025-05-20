//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void initialize(Node** head) {
    *head = NULL;
}

void insert(Node** head, int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void playGame(Node* head) {
    int guessNumber;
    printf("Welcome to the Memory Game!\n");
    printf("Guess a number between 1 and %d: ", MAX_SIZE);
    scanf("%d", &guessNumber);

    Node* current = head;
    while (current) {
        if (guessNumber == current->data) {
            printf("You guessed the number! Congratulations!\n");
            return;
        } else if (guessNumber < current->data) {
            printf("Your guess is too low. Try again.\n");
        } else {
            printf("Your guess is too high. Try again.\n");
        }

        current = current->next;
    }

    printf("Sorry, you lost. The number was %d.\n", head->data);
}

int main() {
    Node* head = NULL;
    initialize(&head);
    insert(head, 2);
    insert(head, 4);
    insert(head, 6);
    insert(head, 8);
    insert(head, 10);

    playGame(head);

    return 0;
}