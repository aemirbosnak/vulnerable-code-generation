//FormAI DATASET v1.0 Category: Linked list operations ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// define the structure of a list node
struct Node {
    int data;
    struct Node* next;
};

// function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = NULL;
    newNode = (struct Node*) malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Error: memory allocation failed!");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// function to insert a node at the front of the list
void insertAtFront(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *headRef;
    *headRef = newNode;
}

// function to insert a node after a given node in the list
void insertAfter(struct Node* prevNode, int data) {
    if (prevNode == NULL) {
        printf("Error: the previous node cannot be NULL!");
        exit(1);
    }
    struct Node* newNode = createNode(data);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

// function to insert a node at the end of the list
void insertAtEnd(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    struct Node* lastNode = *headRef;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
}

// function to delete a node from the list by key
void deleteByKey(struct Node** headRef, int key) {
    struct Node* temp = *headRef;
    struct Node* prevNode = NULL;

    if (temp != NULL && temp->data == key) {
        *headRef = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prevNode = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Error: key not found in list!");
        return;
    }

    prevNode->next = temp->next;
    free(temp);
}

// function to print the elements of the list
void printList(struct Node* head) {
    printf("Linked List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// main function
int main() {
    struct Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtFront(&head, 5);
    insertAtEnd(&head, 20);
    insertAfter(head->next, 15);
    printList(head);

    deleteByKey(&head, 5);
    deleteByKey(&head, 15);
    printList(head);

    insertAtFront(&head, 30);
    insertAtEnd(&head, 40);
    printList(head);

    return 0;
}