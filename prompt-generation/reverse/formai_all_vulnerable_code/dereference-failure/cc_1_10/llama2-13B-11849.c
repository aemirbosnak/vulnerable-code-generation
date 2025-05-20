//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Definition of Linked List Node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a Linked List
Node* createList(int* arr, int size) {
    Node* head = NULL;
    int i;

    for (i = 0; i < size; i++) {
        Node* newNode = (Node*) malloc(sizeof(Node));
        newNode->data = arr[i];
        newNode->next = head;
        head = newNode;
    }

    return head;
}

// Function to traverse the Linked List
void traverseList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to insert an element at the beginning of the Linked List
Node* insertAtBeginning(Node** head_ref, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head_ref;
    *head_ref = newNode;
    return *head_ref;
}

// Function to delete an element from the Linked List
Node* deleteFromList(Node** head_ref, int data) {
    Node* current = *head_ref;
    Node* previous = NULL;

    while (current != NULL) {
        if (current->data == data) {
            if (previous == NULL) {
                *head_ref = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return current;
        }
        previous = current;
        current = current->next;
    }

    return NULL;
}

// Function to search an element in the Linked List
Node* searchInList(Node* head, int data) {
    Node* current = head;

    while (current != NULL) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    Node* head = createList(arr, size);

    // Traverse the Linked List
    traverseList(head);

    // Insert an element at the beginning of the Linked List
    head = insertAtBeginning(&head, 6);

    // Delete an element from the Linked List
    head = deleteFromList(&head, 2);

    // Search an element in the Linked List
    Node* search = searchInList(head, 4);

    // Print the result
    if (search != NULL) {
        printf("Element found at index %d\n", search->data);
    } else {
        printf("Element not found\n");
    }

    return 0;
}