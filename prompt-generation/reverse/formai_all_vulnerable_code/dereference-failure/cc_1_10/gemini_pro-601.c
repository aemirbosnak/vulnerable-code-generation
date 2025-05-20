//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Node structure represents each element in the linked list
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node with the given data
struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(struct Node **head, int data) {
    struct Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to find the first occurrence of a given element in the linked list
struct Node *findFirstOccurrence(struct Node *head, int data) {
    struct Node *current = head;
    while (current != NULL) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to find the last occurrence of a given element in the linked list
struct Node *findLastOccurrence(struct Node *head, int data) {
    struct Node *lastOccurrence = NULL;
    struct Node *current = head;
    while (current != NULL) {
        if (current->data == data) {
            lastOccurrence = current;
        }
        current = current->next;
    }
    return lastOccurrence;
}

// Function to find all occurrences of a given element in the linked list
void findAllOccurrences(struct Node *head, int data) {
    struct Node *current = head;
    while (current != NULL) {
        if (current->data == data) {
            printf("%d ", current->data);
        }
        current = current->next;
    }
    printf("\n");
}

// Function to count the number of occurrences of a given element in the linked list
int countOccurrences(struct Node *head, int data) {
    int count = 0;
    struct Node *current = head;
    while (current != NULL) {
        if (current->data == data) {
            count++;
        }
        current = current->next;
    }
    return count;
}

// Function to print the linked list
void printLinkedList(struct Node *head) {
    struct Node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Main driver function
int main() {
    // Create a linked list
    struct Node *head = NULL;
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);
    insertAtBeginning(&head, 40);
    insertAtBeginning(&head, 50);

    // Print the linked list
    printf("Original linked list: ");
    printLinkedList(head);

    // Find the first occurrence of a given element
    int element = 30;
    struct Node *firstOccurrence = findFirstOccurrence(head, element);
    if (firstOccurrence != NULL) {
        printf("First occurrence of %d: %p\n", element, firstOccurrence);
    } else {
        printf("Element %d not found in the linked list.\n", element);
    }

    // Find the last occurrence of a given element
    struct Node *lastOccurrence = findLastOccurrence(head, element);
    if (lastOccurrence != NULL) {
        printf("Last occurrence of %d: %p\n", element, lastOccurrence);
    } else {
        printf("Element %d not found in the linked list.\n", element);
    }

    // Find all occurrences of a given element
    printf("All occurrences of %d: ", element);
    findAllOccurrences(head, element);

    // Count the number of occurrences of a given element
    int count = countOccurrences(head, element);
    printf("Number of occurrences of %d: %d\n", element, count);

    return 0;
}