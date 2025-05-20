//Gemma-7B DATASET v1.0 Category: Benchmarking ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER 1000

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

    // Insert 1000 random numbers into the list
    for (int i = 0; i < MAX_NUMBER; i++) {
        insertAtTail(head, rand() % MAX_NUMBER);
    }

    // Print the list
    printList(head);

    // Time the list traversal
    clock_t start = clock();
    for (int i = 0; i < MAX_NUMBER; i++) {
        printList(head);
    }
    clock_t end = clock();

    // Print the time taken
    printf("Time taken: %.2f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}