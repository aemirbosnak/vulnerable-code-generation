//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
struct Node {
    int data;
    struct Node *next;
};

// Function to perform various linked list operations
void manipulateList(struct Node **head_ref) {
    // Operation 1: Reverse the linked list
    struct Node *current = *head_ref;
    struct Node *prev = NULL;
    while (current != NULL) {
        struct Node *next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;

    // Operation 2: Remove duplicates from the linked list
    current = *head_ref;
    while (current != NULL) {
        if (current->next == NULL || current->data != current->next->data) {
            current->next = current->next->next;
        }
        current = current->next;
    }

    // Operation 3: Rotate the linked list by n nodes
    int n = 3; // rotate by 3 nodes
    current = *head_ref;
    while (n-- > 0) {
        current = current->next;
    }
    current->next = *head_ref;
    *head_ref = current;

    // Operation 4: Find the first node with value x
    int x = 10; // search for value 10
    current = *head_ref;
    while (current != NULL && current->data != x) {
        current = current->next;
    }
    if (current != NULL) {
        printf("Found node with value %d\n", current->data);
    } else {
        printf("Not found\n");
    }

    // Operation 5: Remove all nodes with value x
    current = *head_ref;
    while (current != NULL) {
        if (current->data == x) {
            current->next = current->next->next;
        }
        current = current->next;
    }
}

int main() {
    struct Node *head = NULL;
    struct Node *node1 = NULL;
    struct Node *node2 = NULL;
    struct Node *node3 = NULL;

    // Create a linked list with nodes 1, 2, 3, 4, 5
    node1 = malloc(sizeof(struct Node));
    node1->data = 1;
    node1->next = NULL;
    head = head->next = node1;

    node2 = malloc(sizeof(struct Node));
    node2->data = 2;
    node2->next = NULL;
    head->next = node2;

    node3 = malloc(sizeof(struct Node));
    node3->data = 3;
    node3->next = NULL;
    head->next->next = node3;

    manipulateList(&head);

    return 0;
}