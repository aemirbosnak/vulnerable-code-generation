//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    // Allocate memory for the first node
    head = (Node*)malloc(sizeof(Node));
    tail = head;

    // Initialize the data of the first node
    head->data = 10;

    // Allocate memory for the second node
    tail->next = (Node*)malloc(sizeof(Node));
    tail = tail->next;

    // Initialize the data of the second node
    tail->data = 20;

    // Allocate memory for the third node
    tail->next = (Node*)malloc(sizeof(Node));
    tail = tail->next;

    // Initialize the data of the third node
    tail->data = 30;

    // Print the data of each node in the list
    Node* current = head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }

    // Free the memory allocated for each node
    current = head;
    while (current) {
        free(current);
        current = current->next;
    }

    return 0;
}