//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to find the hidden treasure
struct Node* findTreasure(struct Node* head) {
    int count = 0;
    struct Node* current = head;

    // Traverse the linked list and count the number of nodes that are not the treasure
    while (current != NULL) {
        if (current->data != 42) {
            count++;
        }
        current = current->next;
    }

    // If the count is equal to 5, the hidden treasure is at the current node
    if (count == 5) {
        return current;
    }

    return NULL;
}

int main() {
    struct Node* head = NULL;

    // Create a linked list with 5 nodes
    head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    // Print the linked list
    printList(head);

    // Find the hidden treasure
    struct Node* treasure = findTreasure(head);

    // Print the treasure
    if (treasure != NULL) {
        printf("The hidden treasure is at node %d\n", treasure->data);
    } else {
        printf("The hidden treasure is not found\n");
    }

    return 0;
}