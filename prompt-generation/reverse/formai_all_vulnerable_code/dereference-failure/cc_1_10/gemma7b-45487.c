//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* insertAtTail(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

void playMemoryGame(Node* head) {
    int randomIndex;
    Node* current = head;

    for (int i = 0; i < MAX_SIZE; i++) {
        randomIndex = rand() % MAX_SIZE;
        current = head;

        for (int j = 0; j < randomIndex; j++) {
            current = current->next;
        }

        printf("The data of the memory cell at index %d is: %d\n", randomIndex, current->data);
    }
}

int main() {
    Node* head = insertAtTail(NULL, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);
    insertAtTail(head, 50);

    playMemoryGame(head);

    return 0;
}