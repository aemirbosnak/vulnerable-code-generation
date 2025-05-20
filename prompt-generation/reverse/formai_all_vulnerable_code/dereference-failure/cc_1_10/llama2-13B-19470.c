//LLAMA2-13B DATASET v1.0 Category: Recursive ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

// Definition of a node
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to create a new node
Node* newNode(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to print the linked list
void printList(Node* head) {
    if (head == NULL) {
        printf("The linked list is empty.\n");
        return;
    }

    printf("The linked list is: ");

    // Traverse the linked list
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }

    printf("\n");
}

// Function to reverse the linked list
Node* reverseList(Node* head) {
    if (head == NULL) {
        return NULL;
    }

    // Create a new node to store the reversed list
    Node* newHead = NULL;

    // Traverse the linked list and append the nodes to the new head
    while (head != NULL) {
        Node* temp = head->next;
        head->next = newHead;
        newHead = head;
        head = temp;
    }

    return newHead;
}

int main() {
    // Create a new node with data 1
    Node* head = newNode(1);

    // Create a new node with data 2
    Node* node2 = newNode(2);

    // Create a new node with data 3
    Node* node3 = newNode(3);

    // Append node2 to the head of the list
    head->next = node2;

    // Append node3 to the end of the list
    head->next->next = node3;

    // Print the linked list
    printList(head);

    // Reverse the linked list
    head = reverseList(head);

    // Print the reversed linked list
    printList(head);

    return 0;
}