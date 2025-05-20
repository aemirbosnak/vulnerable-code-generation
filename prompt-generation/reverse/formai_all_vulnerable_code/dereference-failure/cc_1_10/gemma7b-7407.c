//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: complete
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
}

void playMemoryGame() {
    Node* head = NULL;

    // Inserting data into the linked list
    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);
    insertAtTail(head, 50);

    // Playing the memory game
    printf("Enter the number you want to find:");
    int targetNumber;
    scanf("%d", &targetNumber);

    Node* current = head;
    while (current) {
        if (current->data == targetNumber) {
            printf("Found!\n");
            break;
        } else if (current->next == NULL) {
            printf("Not found.\n");
            break;
        }
        current = current->next;
    }
}

int main() {
    playMemoryGame();

    return 0;
}