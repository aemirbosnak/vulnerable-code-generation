//FormAI DATASET v1.0 Category: Data structures visualization ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// define the node struct for our linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// print the linked list
void printLinkedList(Node* head) {
    Node* current = head;
    while(current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// create a new node with given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// insert a node at the beginning of the linked list
void insertAtBeginning(Node** head_ref, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head_ref;
    *head_ref = newNode;
}

// insert a node at the end of the linked list
void insertAtEnd(Node** head_ref, int data) {
    Node* newNode = createNode(data);
    Node* current = *head_ref;
    while(current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

int main() {
    Node* head = createNode(5);
    insertAtBeginning(&head, 3);
    insertAtEnd(&head, 7);
    insertAtEnd(&head, 1);
    printLinkedList(head);
    return 0;
}