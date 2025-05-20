//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with given data
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

// Function to remove the first occurrence of a given value from the linked list
struct Node* removeValue(struct Node* head, int value) {
    struct Node* current = head;
    struct Node* previous = NULL;

    while (current != NULL) {
        if (current->data == value) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return head;
        }
        previous = current;
        current = current->next;
    }

    return head;
}

int main() {
    struct Node* head = NULL;

    // Create a linked list with the following nodes
    head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);

    // Print the linked list
    printList(head);

    // Reverse the linked list
    head = reverseList(head);
    printList(head);

    // Remove the first occurrence of 3 from the linked list
    head = removeValue(head, 3);
    printList(head);

    return 0;
}