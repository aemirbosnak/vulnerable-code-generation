//FormAI DATASET v1.0 Category: Data structures visualization ; Style: Ken Thompson
#include <stdio.h>

// Define a node structure for the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node with the given data value
Node* newNode(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to insert a node at the beginning of the linked list
Node* insertAtBeginning(Node* head, int data) {
    Node* node = newNode(data);
    node->next = head;
    return node;
}

// Function to insert a node at the end of the linked list
Node* insertAtEnd(Node* head, int data) {
    Node* node = newNode(data);
    if (head == NULL) {
        return node;
    }
    Node* curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = node;
    return head;
}

// Function to delete a node with the given data value from the linked list
Node* deleteNode(Node* head, int data) {
    if (head == NULL) {
        return NULL;
    }
    if (head->data == data) {
        head = head->next;
        free(head);
        return head;
    }
    Node* curr = head;
    while (curr->next != NULL && curr->next->data != data) {
        curr = curr->next;
    }
    if (curr->next == NULL) {
        return head;
    }
    Node* temp = curr->next;
    curr->next = curr->next->next;
    free(temp);
    return head;
}

// Function to print the linked list
void printList(Node* head) {
    Node* curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
}

int main() {
    Node* head = NULL;
    head = insertAtBeginning(head, 1);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 3);
    head = insertAtEnd(head, 4);
    head = insertAtEnd(head, 5);
    printList(head);
    head = deleteNode(head, 3);
    printf("\n");
    printList(head);
    return 0;
}