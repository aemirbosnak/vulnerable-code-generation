//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

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

void schedule(Node* head) {
    srand(time(NULL));
    int quantum = rand() % MAX;
    int i = 0;

    while (head) {
        printf("Process %d is running...\n", head->data);
        sleep(quantum);
        printf("Process %d has finished.\n", head->data);

        quantum = rand() % MAX;
        i++;

        if (i >= quantum) {
            head = head->next;
            quantum = rand() % MAX;
            i = 0;
        }
    }
}

int main() {
    Node* head = NULL;

    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);

    schedule(head);

    return 0;
}