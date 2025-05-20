//FormAI DATASET v1.0 Category: Data structures visualization ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Defining the structure for a node of a linked list.
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with given data and NULL next pointer.
struct Node* createNode(int data) {
    struct Node* newNode;
    newNode = (struct Node*) malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the linked list.
void push(struct Node** head_ref, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head_ref;
    *head_ref = newNode;
}

// Function to insert a node after a given node.
void insertAfter(struct Node* prevNode, int data) {
    if (prevNode == NULL) {
        printf("The given previous node cannot be NULL!\n");
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

// Function to insert a node at the end of the linked list.
void append(struct Node** head_ref, int data) {
    struct Node* newNode = createNode(data);
    struct Node* last = *head_ref;
    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = newNode;
}

// Function to delete a node with given key value.
void deleteNode(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref;
    struct Node* prev = NULL;
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Key not found in the linked list!\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

// Function to search for an element in the linked list.
bool search(struct Node* head_ref, int key) {
    struct Node* current = head_ref;
    while (current != NULL) {
        if (current->data == key)
            return true;
        current = current->next;
    }
    return false;
}

// Function to print the linked list.
void printList(struct Node* head_ref) {
    struct Node* ptr;
    ptr = head_ref;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

// Main function to test the linked list functions.
int main() {
    struct Node* head = NULL;
    printf("Linked list before inserting elements: ");
    printList(head);
    push(&head, 15);
    printf("Linked list after pushing 15 at the beginning: ");
    printList(head);
    push(&head, 10);
    printf("Linked list after pushing 10 at the beginning: ");
    printList(head);
    append(&head, 50);
    printf("Linked list after appending 50 to the end: ");
    printList(head);
    insertAfter(head->next, 20);
    printf("Linked list after inserting 20 after 10: ");
    printList(head);
    if (search(head, 20))
        printf("Element 20 is present in the linked list.\n");
    else
        printf("Element 20 is not present in the linked list.\n");
    deleteNode(&head, 10);
    printf("Linked list after deleting node with key 10: ");
    printList(head);
    return 0;
}