//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* newNode(int data) {
    struct Node* node = malloc(sizeof(struct Node));
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

// Function to reverse the linked list
struct Node* reverseList(struct Node* head) {
    struct Node* current = head;
    struct Node* previous = NULL;

    while (current != NULL) {
        struct Node* next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    return previous;
}

// Function to find the middle node of the linked list
struct Node* findMiddle(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head->next->next;

    while (fast != NULL) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

// Function to delete the node at the given position
struct Node* deleteNodeAt(struct Node* head, int position) {
    struct Node* current = head;
    struct Node* previous = NULL;

    for (int i = 0; i < position; i++) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Invalid position\n");
        return NULL;
    }

    previous->next = current->next;
    free(current);
    return previous;
}

int main() {
    struct Node* head = NULL;

    // Create a list of 5 nodes
    head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    // Print the list
    printList(head);

    // Reverse the list
    head = reverseList(head);

    // Find the middle node
    struct Node* middle = findMiddle(head);
    printf("Middle node: %d\n", middle->data);

    // Delete the node at position 3
    head = deleteNodeAt(head, 3);

    // Print the updated list
    printList(head);

    return 0;
}