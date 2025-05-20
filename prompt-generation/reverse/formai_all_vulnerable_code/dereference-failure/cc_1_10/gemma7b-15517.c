//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void Insert(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void RoundRobin(Node** head) {
    time_t start, end;
    start = time(NULL);

    Node* current = (*head)->next;
    Node* next = (*head)->next->next;

    while (current) {
        printf("%d ", current->data);
        current = next;
        next = current->next;
    }

    end = time(NULL);
    printf("\nTime taken: %ld seconds", end - start);
}

int main() {
    Node* head = NULL;

    Insert(&head, 10);
    Insert(&head, 20);
    Insert(&head, 30);
    Insert(&head, 40);
    Insert(&head, 50);

    RoundRobin(&head);

    return 0;
}