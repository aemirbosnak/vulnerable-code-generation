//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct Node {
    int data;
    struct Node* next;
} Node;

int main() {
    Node* head = NULL;
    int size = 0;

    // Allocate memory for the first node
    head = (Node*)malloc(sizeof(Node));
    head->data = 1;
    head->next = NULL;
    size++;

    // Create a few more nodes
    for (int i = 2; i <= MAX_SIZE; i++) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = i;
        newNode->next = NULL;

        head->next = newNode;
        head = newNode;
        size++;
    }

    // Play the game
    int guessNumber;
    printf("Enter a number between 1 and %d: ", MAX_SIZE);
    scanf("%d", &guessNumber);

    Node* current = head;
    while (current) {
        if (current->data == guessNumber) {
            printf("Congratulations! You found the number.\n");
            break;
        } else if (current->data < guessNumber) {
            current = current->next;
        }
    }

    if (current == NULL) {
        printf("Sorry, the number was not found.\n");
    }

    return 0;
}