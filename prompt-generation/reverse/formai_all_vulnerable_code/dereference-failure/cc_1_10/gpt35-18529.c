//FormAI DATASET v1.0 Category: Linked list operations ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// structure to represent a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// function to insert a node at the beginning of the linked list
void insertAtBeginning(struct Node** headRef, int newData) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = (*headRef);
    (*headRef) = newNode;
}

// function to insert a node at the end of the linked list
void insertAtEnd(struct Node** headRef, int newData) {
    struct Node* newNode = malloc(sizeof(struct Node));
    struct Node* last = (*headRef);

    newNode->data = newData;
    newNode->next = NULL;

    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = newNode;
    return;
}

// function to delete a node with a given key from the linked list
void deleteNode(struct Node** headRef, int key) {
    struct Node* temp = *headRef, *prev;

    // if the first node itself holds the key to be deleted
    if (temp != NULL && temp->data == key) {
        *headRef = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;

    free(temp);
}

// function to reverse the linked list
void reverseList(struct Node** headRef) {
    struct Node* prev = NULL;
    struct Node* current = *headRef;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *headRef = prev;
}

// main function
int main() {
    struct Node* head = NULL;

    // insert nodes at the beginning
    insertAtBeginning(&head, 6);
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 4);
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);

    printf("Linked List after inserting at the beginning: ");
    printList(head);

    // insert nodes at the end
    insertAtEnd(&head, 7);
    insertAtEnd(&head, 8);
    insertAtEnd(&head, 9);
    insertAtEnd(&head, 10);

    printf("Linked List after inserting at the end: ");
    printList(head);

    // delete nodes
    deleteNode(&head, 1);
    deleteNode(&head, 5);
    deleteNode(&head, 10);

    printf("Linked List after deleting nodes: ");
    printList(head);

    // reverse the linked list
    reverseList(&head);

    printf("Linked List after reversing: ");
    printList(head);

    return 0;
}