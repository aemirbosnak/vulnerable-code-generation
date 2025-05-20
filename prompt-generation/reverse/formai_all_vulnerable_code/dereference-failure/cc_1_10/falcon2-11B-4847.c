//Falcon2-11B DATASET v1.0 Category: Data structures visualization ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Custom data structure to hold a single node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Linked list head
Node* head = NULL;

// Function to insert a new node into the linked list
void insert(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

// Function to delete a node from the linked list
void delete(int data) {
    Node* temp = head;
    Node* prev = NULL;

    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    if (prev!= NULL)
        prev->next = temp->next;
    else
        head = temp->next;

    free(temp);
}

// Function to print the linked list
void printList() {
    Node* temp = head;

    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    // Initialize the linked list
    insert(1);
    insert(2);
    insert(3);
    insert(4);

    // Print the initial linked list
    printf("Initial linked list: ");
    printList();

    // Simulate an asynchronous delete operation
    srand(time(NULL));
    int randomIndex = rand() % 4;
    printf("Deleting node at index %d...\n", randomIndex);
    delete(randomIndex);

    // Print the updated linked list
    printf("Updated linked list: ");
    printList();

    return 0;
}