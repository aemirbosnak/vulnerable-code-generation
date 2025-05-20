//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a linked list node
struct Node {
    int data;
    struct Node *next;
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

// Function to find the first common ancestor of two nodes
struct Node* findCommonAncestor(struct Node* node1, struct Node* node2) {
    struct Node* current1 = node1;
    struct Node* current2 = node2;

    while (current1 != current2) {
        if (current1 == NULL || current2 == NULL) {
            return NULL;
        }

        current1 = current1->next;
        current2 = current2->next;
    }

    return current1;
}

int main() {
    struct Node* head = NULL;

    // Create a list with the following nodes: 1, 2, 3, 4, 5
    head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    // Print the list
    printList(head);

    // Reverse the list
    head = reverseList(head);

    // Find the first common ancestor of nodes 3 and 5
    struct Node* node3 = head->next->next;
    struct Node* node5 = head->next->next->next->next;
    struct Node* commonAncestor = findCommonAncestor(node3, node5);

    // Print the common ancestor
    printf("Common ancestor of 3 and 5: %d\n", commonAncestor->data);

    return 0;
}