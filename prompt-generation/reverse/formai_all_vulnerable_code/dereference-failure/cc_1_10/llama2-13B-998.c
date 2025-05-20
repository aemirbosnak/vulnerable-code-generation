//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new linked list
struct Node* newList(void) {
    struct Node* head = NULL;
    head->data = 0;
    head->next = NULL;
    return head;
}

// Function to insert an element into the linked list
struct Node* insert(struct Node** head_ref, int data) {
    struct Node* new_node = malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = (*head_ref)->next;
    (*head_ref)->next = new_node;
    return new_node;
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to find the first duplicate element in the linked list
struct Node* findDuplicate(struct Node* head) {
    struct Node* current = head;
    struct Node* previous = NULL;

    while (current != NULL) {
        if (previous != NULL && current->data == previous->data) {
            return current;
        }
        previous = current;
        current = current->next;
    }

    return NULL;
}

int main() {
    struct Node* head = newList();

    // Insert some elements into the linked list
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);

    // Print the linked list
    printList(head);

    // Find the first duplicate element in the linked list
    struct Node* duplicate = findDuplicate(head);
    if (duplicate != NULL) {
        printf("First duplicate element is %d\n", duplicate->data);
    } else {
        printf("No duplicate elements found\n");
    }

    return 0;
}