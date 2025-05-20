//FormAI DATASET v1.0 Category: Data structures visualization ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in a linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with the given data and next node address
struct Node* newNode(int data, struct Node* next) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->next = next;
    return node;
}

// Function to add a new node to the beginning of the linked list
struct Node* addNode(struct Node* head, int data) {
    struct Node* node = newNode(data, head);
    return node;
}

// Function to print all nodes in the linked list
void printList(struct Node* head) {
    printf("[");
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL) {
            printf(", ");
        }
        head = head->next;
    }
    printf("]\n");
}

int main() {
    // Initialize an empty linked list
    struct Node* head = NULL;

    // Create some nodes and add them to the linked list
    head = addNode(head, 1);
    head = addNode(head, 2);
    head = addNode(head, 3);

    // Print the linked list
    printf("Elementary, my dear Watson! Here is the linked list: \n");
    printList(head);
    
    // Create and add one more node to the linked list
    head = addNode(head, 4);

    // Print the linked list
    printf("Amazing, Watson! Now the linked list has been updated with a new node: \n");
    printList(head);

    // Free all memory allocated for the linked list
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}