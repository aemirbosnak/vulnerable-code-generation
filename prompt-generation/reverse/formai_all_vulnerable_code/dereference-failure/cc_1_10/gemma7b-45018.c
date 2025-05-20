//Gemma-7B DATASET v1.0 Category: Data structures visualization ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Node {
    char name[MAX_SIZE];
    struct Node* next;
} Node;

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    // Allocate memory for the first node
    head = malloc(sizeof(Node));
    tail = head;

    // Give the first node a name
    strcpy(head->name, "Alice");

    // Add the first node to the linked list
    tail->next = NULL;

    // Allocate memory for the second node
    tail = malloc(sizeof(Node));
    tail->next = NULL;

    // Give the second node a name
    strcpy(tail->name, "Bob");

    // Add the second node to the linked list
    head->next = tail;

    // Allocate memory for the third node
    tail = malloc(sizeof(Node));
    tail->next = NULL;

    // Give the third node a name
    strcpy(tail->name, "Charlie");

    // Add the third node to the linked list
    head->next->next = tail;

    // Traverse the linked list and print the name of each node
    Node* current = head;
    while (current) {
        printf("%s ", current->name);
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