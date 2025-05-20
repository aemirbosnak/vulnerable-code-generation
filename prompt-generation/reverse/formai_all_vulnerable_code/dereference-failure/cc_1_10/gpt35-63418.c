//FormAI DATASET v1.0 Category: Linked list operations ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Create a Node struct that has an int data member and a Node* next member
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new Node with the given int value
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new Node at the beginning of a given linked list
void insertAtBegin(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
    printf("Inserted %d at the beginning of the linked list.\n", data);
}

// Function to insert a new Node at the end of a given linked list
void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        printf("Inserted %d at the end of the linked list.\n", data);
        return;
    }
    Node* curr = *head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = newNode;
    printf("Inserted %d at the end of the linked list.\n", data);
}

// Function to delete the first occurrence of a given Node from a linked list
void deleteNode(Node** head, int data) {
    if (*head == NULL) {
        printf("Linked list is empty. Cannot delete.\n");
        return;
    }
    Node* curr = *head;
    Node* prev = NULL;
    while (curr != NULL && curr->data != data) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL) {
        printf("Did not find %d in the linked list. Cannot delete.\n", data);
        return;
    }
    if (prev == NULL) {
        *head = curr->next;
    } else {
        prev->next = curr->next;
    }
    free(curr);
    printf("Deleted %d from the linked list.\n", data);
}

// Function to print the elements of a linked list
void printList(Node* head) {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }
    printf("Linked list contents: ");
    Node* curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    insertAtBegin(&head, 1);
    insertAtEnd(&head, 2);
    insertAtBegin(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);
    printList(head);
    deleteNode(&head, 2);
    printList(head);
    deleteNode(&head, 3);
    printList(head);
    deleteNode(&head, 6);
    printList(head);
    return 0;
}