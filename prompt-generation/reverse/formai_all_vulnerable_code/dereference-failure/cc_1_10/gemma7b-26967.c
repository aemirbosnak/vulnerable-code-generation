//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char data;
    struct Node* next;
} Node;

int main() {
    // Create a linked list
    Node* head = NULL;
    Node* tail = NULL;

    // Allocate memory for the first node
    head = malloc(sizeof(Node));
    tail = head;

    // Set the data of the first node
    tail->data = 'A';

    // Allocate memory for the second node
    tail->next = malloc(sizeof(Node));
    tail = tail->next;

    // Set the data of the second node
    tail->data = 'B';

    // Allocate memory for the third node
    tail->next = malloc(sizeof(Node));
    tail = tail->next;

    // Set the data of the third node
    tail->data = 'C';

    // Print the data of each node in the list
    Node* current = head;
    while (current) {
        printf("%c ", current->data);
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