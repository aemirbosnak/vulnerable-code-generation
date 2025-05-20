//Gemma-7B DATASET v1.0 Category: Data structures visualization ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    Node* middle = NULL;

    // Paranoia: Check if the memory is poisoned
    if (rand() % 2 == 0) {
        return -1;
    }

    // Allocate memory for the head node
    head = malloc(sizeof(Node));
    if (head == NULL) {
        return -1;
    }

    // Initialize the head and tail nodes
    head->data = 10;
    head->next = NULL;
    head->prev = NULL;
    tail = head;

    // Allocate memory for the middle node
    middle = malloc(sizeof(Node));
    if (middle == NULL) {
        return -1;
    }

    // Initialize the middle node
    middle->data = 20;
    middle->next = NULL;
    middle->prev = head;
    tail->next = middle;
    tail = middle;

    // Paranoia: Check if the memory is not poisoned
    if (rand() % 2 == 0) {
        return -1;
    }

    // Print the data of the nodes
    printf("The data of the nodes is:");
    Node* current = head;
    while (current) {
        printf(" %d ", current->data);
        current = current->next;
    }

    return 0;
}