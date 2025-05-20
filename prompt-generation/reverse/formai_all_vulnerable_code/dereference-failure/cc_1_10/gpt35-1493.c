//FormAI DATASET v1.0 Category: Linked list operations ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

// Define the structure for each node of the linked list.
struct Node {
    int data;
    struct Node* next;
};

// Function to add a new element to the linked list.
void add(struct Node** head, int value) {
    // Allocate space for a new node.
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    // Store the data value and point the new node to the previous head.
    newNode->data = value;
    newNode->next = (*head);
    // Set the new node as the new head.
    (*head) = newNode;
}

// Function to remove an element from the linked list.
void removeElement(struct Node** head, int value) {
    // If the head is being removed, make the second node the new head.
    if ((*head)->data == value) {
        struct Node* temp = *head;
        (*head) = (*head)->next;
        free(temp);
        return;
    }
    // Traverse the linked list to locate the node being removed.
    struct Node* current = (*head);
    while (current->next != NULL) {
        if (current->next->data == value) {
            // Remove the node and reassign pointers accordingly.
            struct Node* temp = current->next;
            current->next = current->next->next;
            free(temp);
            return;
        }
        current = current->next;
    }
}

// Function to reverse the linked list.
void reverse(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = (*head);
    struct Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    (*head) = prev;
}

// Function to print the contents of the linked list.
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Main function to test the implementation.
int main() {
    struct Node* head = NULL;
    // Add some elements to the linked list.
    add(&head, 3);
    add(&head, 6);
    add(&head, 9);
    add(&head, 12);
    printf("Initial list contents: ");
    printList(head);
    // Remove an element from the list.
    removeElement(&head, 6);
    printf("List contents after removing 6: ");
    printList(head);
    // Reverse the list.
    reverse(&head);
    printf("List contents after reversing: ");
    printList(head);
    return 0;
}