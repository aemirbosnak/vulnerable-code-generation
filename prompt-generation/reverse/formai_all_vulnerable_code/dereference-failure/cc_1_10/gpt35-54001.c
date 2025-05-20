//FormAI DATASET v1.0 Category: Linked list operations ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// define node structure
struct Node {
    int data;
    struct Node *next;
};

// function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// function to insert a new node at the beginning of linked list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// function to insert a new node at the end of linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;
    if(temp == NULL) {
        *head = newNode;
        return;
    }
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// function to insert a new node after a given node
void insertAfterNode(struct Node* prevNode, int data) {
    if(prevNode == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

// function to delete a node with given key
void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head;
    struct Node* prev;
    if(temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }
    while(temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) {
        printf("Node with key %d not found\n", key);
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Node with key %d deleted successfully\n", key);
}

// function to print the linked list
void printList(struct Node* head) {
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    // initialize an empty linked list
    struct Node* head = NULL;

    // insert nodes at the beginning
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);
    printf("Linked list after inserting nodes at the beginning: ");
    printList(head);

    // insert nodes at the end
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);
    insertAtEnd(&head, 60);
    printf("Linked list after inserting nodes at the end: ");
    printList(head);

    // insert node after a given node
    insertAfterNode(head->next->next, 70);
    printf("Linked list after inserting node after a given node: ");
    printList(head);

    // delete a node with given key
    deleteNode(&head, 50);
    deleteNode(&head, 80);

    printf("Linked list after deleting nodes with given keys: ");
    printList(head);

    return 0;
}