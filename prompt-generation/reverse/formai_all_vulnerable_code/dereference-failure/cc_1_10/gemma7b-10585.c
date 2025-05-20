//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

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

int main() {
    Node* head = NULL;

    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);

    // Play the game
    int guessNumber;

    printf("Enter a number between 1 and 5: ");
    scanf("%d", &guessNumber);

    Node* current = head;

    while (current) {
        if (current->data == guessNumber) {
            printf("You found the number!\n");
            break;
        } else if (current->data < guessNumber) {
            printf("The number is greater than this.\n");
        } else {
            printf("The number is less than this.\n");
        }

        current = current->next;
    }

    if (current == NULL) {
        printf("The number was not found.\n");
    }

    return 0;
}