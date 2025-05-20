//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct Node {
    int data;
    struct Node* next;
};

void insertAtTail(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void roundRobin(struct Node* head) {
    int i = 0;
    struct Node* current = head;
    struct Node* next = NULL;

    while (current) {
        next = current->next;
        current->next = head;
        head = current;
        current = next;
        i++;
    }

    printf("Number of iterations: %d\n", i);
}

int main() {
    struct Node* head = NULL;
    insertAtTail(&head, 10);
    insertAtTail(&head, 20);
    insertAtTail(&head, 30);
    insertAtTail(&head, 40);
    insertAtTail(&head, 50);

    roundRobin(head);

    return 0;
}