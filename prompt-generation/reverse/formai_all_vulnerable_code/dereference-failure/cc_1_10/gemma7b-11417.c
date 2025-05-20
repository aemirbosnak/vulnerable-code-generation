//Gemma-7B DATASET v1.0 Category: Benchmarking ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

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
        ((*head)->next) = newNode;
    }
}

void printList(Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    // Inserting nodes into the linked list
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);
    insert(&head, 50);

    // Printing the linked list
    printList(head);

    // Timing the list traversal
    time_t start = time(NULL);
    for (int i = 0; i < MAX_SIZE; i++) {
        printList(head);
    }
    time_t end = time(NULL);

    // Calculating the time taken
    int timeTaken = end - start;

    // Displaying the time taken
    printf("Time taken: %d seconds\n", timeTaken);

    return 0;
}