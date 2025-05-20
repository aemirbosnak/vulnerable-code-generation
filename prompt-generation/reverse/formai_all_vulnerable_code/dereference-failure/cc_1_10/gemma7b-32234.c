//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

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

void playMemoryGame() {
    Node* head = NULL;
    int i, guessNumber, score = 0;

    for (i = 0; i < MAX_SIZE; i++) {
        insertAtTail(&head, rand() % 10);
    }

    printf("Welcome to the Memory Game!\n");
    printf("Guess the number: ");
    scanf("%d", &guessNumber);

    for (i = 0; head && i < MAX_SIZE; i++) {
        if (head->data == guessNumber) {
            score++;
            printf("Congratulations! You found the number!\n");
            break;
        } else {
            head = head->next;
        }
    }

    if (score == 0) {
        printf("Sorry, the number was not found.\n");
    }

    printf("Your score: %d\n", score);
}

int main() {
    playMemoryGame();

    return 0;
}