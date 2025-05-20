//FormAI DATASET v1.0 Category: Linked list operations ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>

/* Node structure */
struct node {
    int data;
    struct node *next;
};

/* Function to add node at the beginning */
void insertAtBeginning(struct node **headRef, int data) {
    struct node *newNode = (struct node *) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = *headRef;
    *headRef = newNode;
}

/* Function to add node at the end */
void insertAtEnd(struct node **headRef, int data) {
    struct node *newNode = (struct node *) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    if(*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    struct node *currentNode = *headRef;
    while(currentNode->next != NULL) {
        currentNode = currentNode->next;
    }
    currentNode->next = newNode;
}

/* Function to delete node by key */
void deleteByKey(struct node **headRef, int key) {
    struct node *currentNode = *headRef, *prevNode = NULL;
    if(currentNode != NULL && currentNode->data == key) {
        *headRef = currentNode->next;
        free(currentNode);
        return;
    }
    while(currentNode != NULL && currentNode->data != key) {
        prevNode = currentNode;
        currentNode = currentNode->next;
    }
    if(currentNode == NULL) {
        return;
    }
    prevNode->next = currentNode->next;
    free(currentNode);
}

/* Function to delete node at position */
void deleteAtPosition(struct node **headRef, int position) {
    struct node *currentNode = *headRef, *prevNode = NULL;
    if(position == 0) {
        *headRef = currentNode->next;
        free(currentNode);
        return;
    }
    int i;
    for(i = 0; i < position && currentNode != NULL; i++) {
        prevNode = currentNode;
        currentNode = currentNode->next;
    }
    if(currentNode == NULL) {
        return;
    }
    prevNode->next = currentNode->next;
    free(currentNode);
}

/* Function to print linked list */
void printLinkedList(struct node *head) {
    struct node *currentNode = head;
    while(currentNode != NULL) {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");
}

/* Driver code */
int main() {
    struct node *head = NULL;
    insertAtEnd(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);
    insertAtEnd(&head, 40);
    printf("Linked list before deletion: ");
    printLinkedList(head);
    deleteByKey(&head, 20);
    printf("Linked list after deletion by key: ");
    printLinkedList(head);
    deleteAtPosition(&head, 0);
    printf("Linked list after deletion at position 0: ");
    printLinkedList(head);
    return 0;
}