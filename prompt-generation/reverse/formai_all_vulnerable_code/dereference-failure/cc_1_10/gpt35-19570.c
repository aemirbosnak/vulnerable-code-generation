//FormAI DATASET v1.0 Category: Linked list operations ; Style: calm
#include<stdio.h>
#include<stdlib.h>

// Defining the structure of linked list node
struct node {
    int data;
    struct node *next;
};

// Initialization of the Linked list
struct node *head = NULL;

// Insertion of an element at the beginning of the Linked list
void insertAtBeginning(int x) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->next = NULL;

    if(head == NULL) {
        head = newNode;
    }
    else {
        newNode->next = head;
        head = newNode;
    }
}

// Insertion of an element at the end of the Linked list
void insertAtEnd(int x) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->next = NULL;

    if(head == NULL) {
        head = newNode;
    }
    else {
        struct node *currentNode = head;
        while(currentNode->next != NULL) {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
    }
}

// Deletion of an element from the beginning of the Linked list
void deleteFromBeginning() {
    if(head == NULL) {
        printf("Linked list is empty\n");
        return;
    }

    struct node *temp = head;
    head = head->next;
    free(temp);
}

// Deletion of an element from the end of the Linked list
void deleteFromEnd() {
    if(head == NULL) {
        printf("Linked list is empty\n");
        return;
    }

    if(head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    struct node *currentNode = head->next;
    struct node *previousNode = head;

    while(currentNode->next != NULL) {
        previousNode = currentNode;
        currentNode = currentNode->next;
    }

    free(currentNode);
    previousNode->next = NULL;
}

// Displaying the whole Linked list
void displayList() {
    if(head == NULL) {
        printf("Linked list is empty\n");
        return;
    }

    struct node *currentNode = head;

    while(currentNode != NULL) {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
}

// Main function to run the above operations
int main() {
    insertAtBeginning(1);
    insertAtBeginning(2);
    insertAtBeginning(3);
    insertAtEnd(4);
    insertAtEnd(5);

    displayList();

    deleteFromBeginning();

    displayList();

    deleteFromEnd();

    displayList();
    
    return 0;
}