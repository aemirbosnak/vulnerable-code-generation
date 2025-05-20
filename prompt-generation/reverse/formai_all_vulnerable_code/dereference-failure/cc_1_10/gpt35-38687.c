//FormAI DATASET v1.0 Category: Data recovery tool ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure of linked list node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node in linked list
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of linked list
void insertEnd(Node** head_ref, int data) {
    Node* newNode = createNode(data);
    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }
    Node* temp = *head_ref;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to check if the linked list is sorted
bool isSorted(Node* head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }
    if (head->data > head->next->data) {
        return false;
    }
    return isSorted(head->next);
}

// Function to recover data from the linked list
void recoverData(Node* head, int* max) {
    if (head == NULL) {
        return;
    }
    recoverData(head->next, max);
    if (head->data > *max) {
        *max = head->data;
    }
    head->data = *max;
}

// Main function
int main() {
    Node* head = NULL;
    insertEnd(&head, 5);
    insertEnd(&head, 2);
    insertEnd(&head, 8);
    insertEnd(&head, 3);
    insertEnd(&head, 6);
    printf("Original linked list: ");
    printList(head);
    if (isSorted(head)) {
        printf("Linked list is already sorted, no recovery needed!\n");
        return 0;
    }
    int max = head->data;
    recoverData(head, &max);
    printf("Recovered linked list: ");
    printList(head);
    return 0;
}