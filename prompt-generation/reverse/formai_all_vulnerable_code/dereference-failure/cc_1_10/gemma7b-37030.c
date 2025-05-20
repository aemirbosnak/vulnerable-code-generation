//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insertAtTail(Node** head, int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void simulate(Node** head) {
    srand(time(NULL));
    int quantum = rand() % MAX;

    Node* current = *head;
    while (current) {
        printf("Process %d is running...\n", current->data);
        sleep(quantum);
        printf("Process %d has finished.\n", current->data);

        current = current->next;
    }

    printf("All processes have finished.\n");
}

int main() {
    Node* head = NULL;
    insertAtTail(&head, 1);
    insertAtTail(&head, 2);
    insertAtTail(&head, 3);
    insertAtTail(&head, 4);

    simulate(&head);

    return 0;
}