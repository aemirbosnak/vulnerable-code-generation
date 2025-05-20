//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
struct Node {
    int data;
    struct Node *next;
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
    if (head == NULL) {
        printf("The list is empty\n");
        return;
    }

    printf("The linked list is: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to reverse the linked list
struct Node* reverseList(struct Node* head) {
    if (head == NULL) {
        return NULL;
    }

    struct Node* newHead = NULL;
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

// Function to find the first duplicate in the linked list
struct Node* findDuplicate(struct Node* head) {
    if (head == NULL) {
        return NULL;
    }

    struct Node* current = head;
    struct Node* previous = NULL;

    while (current != NULL) {
        if (current->data == previous->data) {
            return current;
        }
        previous = current;
        current = current->next;
    }

    return NULL;
}

int main() {
    struct Node* head = NULL;

    // Create a linked list with the numbers 1 to 10
    for (int i = 1; i <= 10; i++) {
        head = newNode(i);
        head->next = head;
    }

    // Print the linked list
    printList(head);

    // Reverse the linked list
    struct Node* reversedHead = reverseList(head);
    printList(reversedHead);

    // Find the first duplicate in the linked list
    struct Node* duplicate = findDuplicate(head);
    if (duplicate != NULL) {
        printf("The first duplicate is %d\n", duplicate->data);
    } else {
        printf("The linked list does not contain any duplicates\n");
    }

    return 0;
}