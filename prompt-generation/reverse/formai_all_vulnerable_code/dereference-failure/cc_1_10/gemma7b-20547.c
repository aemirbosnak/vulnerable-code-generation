//Gemma-7B DATASET v1.0 Category: Benchmarking ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10000

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

void printList(Node* head) {
    Node* current = head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    // Inserting data into the linked list
    for (int i = 0; i < MAX_SIZE; i++) {
        insertAtTail(head, i);
    }

    // Printing the linked list
    printList(head);

    // Timing the linked list traversal
    time_t start = time(NULL);
    for (Node* current = head; current; current = current->next) {
        ;
    }
    time_t end = time(NULL);

    // Calculating the time taken
    int timeTaken = end - start;

    // Printing the time taken
    printf("Time taken to traverse the linked list: %d seconds\n", timeTaken);

    return 0;
}