//Falcon-180B DATASET v1.0 Category: Sorting ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with given data
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to sort the linked list using merge sort
void mergeSort(struct Node** headRef) {
    struct Node* head = *headRef;
    struct Node* second = NULL;
    struct Node* current = head;

    // Base case for single-node list
    if (head == NULL || head->next == NULL)
        return;

    // Split the list into two halves
    while (current->next!= NULL && current->next->next!= NULL) {
        second = current->next;
        while (second->next!= NULL && second->next->next!= NULL) {
            second = second->next;
        }
        current->next = second->next;
        second->next = NULL;
        current = current->next;
    }

    // Recursively sort the two halves
    mergeSort(&head);
    mergeSort(&second);

    // Merge the sorted halves back together
    struct Node dummy = {0, NULL};
    struct Node* tail = &dummy;

    while (head!= NULL && second!= NULL) {
        if (head->data <= second->data) {
            tail->next = head;
            head = head->next;
        } else {
            tail->next = second;
            second = second->next;
        }
        tail = tail->next;
    }

    while (head!= NULL) {
        tail->next = head;
        head = head->next;
        tail = tail->next;
    }

    while (second!= NULL) {
        tail->next = second;
        second = second->next;
        tail = tail->next;
    }

    *headRef = dummy.next;
}

// Main function
int main() {
    struct Node* head = NULL;

    // Create a sample linked list
    head = newNode(12);
    head->next = newNode(11);
    head->next->next = newNode(13);
    head->next->next->next = newNode(5);
    head->next->next->next->next = newNode(6);
    head->next->next->next->next->next = newNode(7);

    // Print the original list
    printf("Original List: ");
    printList(head);

    // Sort the list using merge sort
    mergeSort(&head);

    // Print the sorted list
    printf("\nSorted List: ");
    printList(head);

    return 0;
}