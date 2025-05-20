//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

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

void findMostCommonElement(Node* head) {
    int frequency[MAX_SIZE] = {0};
    Node* current = head;
    while (current) {
        frequency[current->data]++;
        current = current->next;
    }

    int maxFrequency = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        if (frequency[i] > maxFrequency) {
            maxFrequency = frequency[i];
        }
    }

    printf("Most common element: %d, with frequency: %d\n", maxFrequency, maxFrequency);
}

int main() {
    Node* head = NULL;
    insertAtTail(&head, 10);
    insertAtTail(&head, 20);
    insertAtTail(&head, 30);
    insertAtTail(&head, 20);
    insertAtTail(&head, 40);

    findMostCommonElement(head);

    return 0;
}