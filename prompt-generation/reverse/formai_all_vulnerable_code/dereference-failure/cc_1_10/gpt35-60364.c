//FormAI DATASET v1.0 Category: Data structures visualization ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in a singly-linked list
typedef struct node {
    int data;
    struct node *next;
} Node;

// Function to create a new node for the list
Node* createNode(int data) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the list
Node* insertBegin(Node *head, int data) {
    Node *newNode = createNode(data);
    newNode -> next = head;
    return newNode;
}

// Function to insert a new node at the end of the list
Node* insertEnd(Node *head, int data) {
    Node *newNode = createNode(data);
    if(head == NULL) {
        return newNode;
    }
    Node *curr = head;
    while(curr -> next != NULL) {
        curr = curr -> next;
    }
    curr -> next = newNode;
    return head;
}

// Function to delete a node with a given value from the list
Node* deleteNode(Node *head, int data) {
    if(head == NULL) {
        return NULL;
    }
    if(head -> data == data) {
        Node *temp = head -> next;
        free(head);
        return temp;
    }
    Node *curr = head;
    while(curr -> next != NULL && curr -> next -> data != data) {
        curr = curr -> next;
    }
    if(curr -> next == NULL) {
        return head;
    }
    Node *temp = curr -> next;
    curr -> next = curr -> next -> next;
    free(temp);
    return head;
}

// Function to print the list in order from beginning to end
void printList(Node *head) {
    Node *curr = head;
    while(curr != NULL) {
        printf("%d ", curr -> data);
        curr = curr -> next;
    }
    printf("\n");
}

// Main function to test the linked list implementation
int main() {
    // Create an empty linked list
    Node *head = NULL;
    
    // Insert some nodes at the beginning
    head = insertBegin(head, 5);
    head = insertBegin(head, 10);
    head = insertBegin(head, 15);
    head = insertBegin(head, 20);
    
    // Print the list
    printf("Linked List after inserting at the beginning:\n");
    printList(head);
    
    // Insert some nodes at the end
    head = insertEnd(head, 25);
    head = insertEnd(head, 30);
    
    // Print the list
    printf("Linked List after inserting at the end:\n");
    printList(head);
    
    // Delete some nodes from the list
    head = deleteNode(head, 10);
    head = deleteNode(head, 25);
    
    // Print the list
    printf("Linked List after deleting some nodes:\n");
    printList(head);
    
    return 0;
}