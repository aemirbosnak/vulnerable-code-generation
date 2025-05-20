//FormAI DATASET v1.0 Category: Queue Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

// Node structure for queue
struct Node {
    int data;
    struct Node* next;
};

// Function to add elements to the queue
void enqueue(struct Node** head, struct Node** tail, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if (*tail == NULL) {
        *head = *tail = newNode;
        return;
    }

    (*tail)->next = newNode;
    *tail = newNode;
}

// Function to remove elements from the queue
void dequeue(struct Node** head, struct Node** tail) {
    if (*head == NULL) {
        return;
    }

    struct Node* temp = *head;
    *head = (*head)->next;

    if (*head == NULL) {
        *tail = NULL;
    }

    free(temp);
}

// Function to display elements in the queue
void display(struct Node* head) {
    printf("Queue: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    struct Node* tail = NULL;

    enqueue(&head, &tail, 1);
    display(head);

    enqueue(&head, &tail, 2);
    display(head);

    enqueue(&head, &tail, 3);
    display(head);

    dequeue(&head, &tail);
    display(head);

    dequeue(&head, &tail);
    display(head);

    dequeue(&head, &tail);
    display(head);

    enqueue(&head, &tail, 4);
    display(head);

    return 0;
}