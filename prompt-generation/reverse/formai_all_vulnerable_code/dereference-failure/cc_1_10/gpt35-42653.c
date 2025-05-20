//FormAI DATASET v1.0 Category: Educational ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

// Structure definition for linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode != NULL) {
        newNode->data = data;
        newNode->next = NULL;
    }
    return newNode;
}

// Function to add a new node to the end of the linked list
void addNode(Node** head, int data) {
    Node* newNode = createNode(data);
    if(*head != NULL) {
        Node* current = *head;
        while(current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    } else {
        *head = newNode;
    }
}

// Function to print the linked list
void printList(Node* head) {
    Node* current = head;
    while(current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to remove the first occurrence of a node with given data
void removeNode(Node** head, int data) {
    if(*head != NULL) {
        Node* current = *head;
        Node* prev = NULL;
        while(current != NULL && current->data != data) {
            prev = current;
            current = current->next;
        }
        if(current != NULL) {
            if(prev == NULL) {
                *head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
        }
    }
}

// Main function
int main() {
    Node* head = NULL;
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    addNode(&head, 4);
    addNode(&head, 5);
    printf("Original List: ");
    printList(head);
    removeNode(&head, 3);
    printf("List after removing 3: ");
    printList(head);
    removeNode(&head, 1);
    printf("List after removing 1: ");
    printList(head);
    removeNode(&head, 5);
    printf("List after removing 5: ");
    printList(head);
    return 0;
}