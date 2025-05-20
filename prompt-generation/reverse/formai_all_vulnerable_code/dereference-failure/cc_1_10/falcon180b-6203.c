//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Node structure for linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function prototypes
void createLinkedList(Node** headRef, int size, int data);
void printLinkedList(Node* node);
Node* searchLinkedList(Node* head, int key);
int deleteLinkedList(Node** headRef, int key);

int main() {
    // Test case 1
    Node* head1 = NULL;
    createLinkedList(&head1, 5, 1);
    printLinkedList(head1);
    Node* foundNode1 = searchLinkedList(head1, 3);
    if (foundNode1!= NULL) {
        printf("Found node with value %d\n", foundNode1->data);
    } else {
        printf("Node not found\n");
    }
    head1 = deleteLinkedList(&head1, 1);
    printLinkedList(head1);

    // Test case 2
    Node* head2 = NULL;
    createLinkedList(&head2, 3, 2);
    printLinkedList(head2);
    Node* foundNode2 = searchLinkedList(head2, 3);
    if (foundNode2!= NULL) {
        printf("Found node with value %d\n", foundNode2->data);
    } else {
        printf("Node not found\n");
    }
    head2 = deleteLinkedList(&head2, 2);
    printLinkedList(head2);

    return 0;
}

// Function to create a linked list with given size and data
void createLinkedList(Node** headRef, int size, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    *headRef = newNode;

    Node* temp = *headRef;
    for (int i = 1; i < size; i++) {
        newNode = (Node*)malloc(sizeof(Node));
        if (newNode == NULL) {
            printf("Memory error\n");
            exit(0);
        }
        newNode->data = i * 2;
        newNode->next = NULL;
        temp->next = newNode;
        temp = temp->next;
    }
}

// Function to print the linked list
void printLinkedList(Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Function to search for a node with given key in the linked list
Node* searchLinkedList(Node* head, int key) {
    Node* current = head;
    while (current!= NULL) {
        if (current->data == key) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to delete a node with given key from the linked list
int deleteLinkedList(Node** headRef, int key) {
    Node* head = *headRef;
    Node* prev = NULL;
    Node* current = head;

    while (current!= NULL && current->data!= key) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        return 0;
    }

    if (prev == NULL) {
        *headRef = current->next;
        free(current);
    } else {
        prev->next = current->next;
        free(current);
    }

    return 1;
}