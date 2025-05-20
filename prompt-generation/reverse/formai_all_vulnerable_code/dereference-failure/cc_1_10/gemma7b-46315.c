//Gemma-7B DATASET v1.0 Category: Benchmarking ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char data;
    struct Node* next;
} Node;

int main() {
    // Create a linked list to store the characters from the input text
    Node* head = NULL;
    Node* tail = NULL;

    // Allocate memory for the first node
    head = malloc(sizeof(Node));
    tail = head;

    // Get the input text from the user
    char input[MAX_BUFFER_SIZE];
    printf("Enter text: ");
    fgets(input, MAX_BUFFER_SIZE, stdin);

    // Iterate over the input text and insert each character into the linked list
    for (int i = 0; input[i] != '\0'; i++) {
        // Allocate memory for a new node
        Node* newNode = malloc(sizeof(Node));
        newNode->data = input[i];
        newNode->next = NULL;

        // If the linked list is empty, make the new node the head
        if (head == NULL) {
            head = newNode;
        }

        // Otherwise, insert the new node at the tail
        tail->next = newNode;
        tail = newNode;
    }

    // Traverse the linked list and print each character
    Node* current = head;
    while (current) {
        printf("%c ", current->data);
        current = current->next;
    }

    // Free the memory allocated for the nodes
    free(head);

    return 0;
}