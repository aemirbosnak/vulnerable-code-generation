//Gemma-7B DATASET v1.0 Category: Queue Implementation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void enque(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

int deque(Node** head, int* data) {
    if (*head == NULL) {
        return 0;
    }

    *data = (*head)->data;
    free(*head);
    *head = (*head)->next;

    return 1;
}

int main() {
    Node* head = NULL;
    int data;

    enque(&head, 10);
    enque(&head, 20);
    enque(&head, 30);
    enque(&head, 40);
    enque(&head, 50);

    deque(&head, &data);
    printf("Data: %d\n", data);

    deque(&head, &data);
    printf("Data: %d\n", data);

    deque(&head, &data);
    printf("Data: %d\n", data);

    deque(&head, &data);
    printf("Data: %d\n", data);

    return 0;
}