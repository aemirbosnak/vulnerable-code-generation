//FormAI DATASET v1.0 Category: Linked list operations ; Style: calm
#include <stdio.h>
#include <stdlib.h>

/*
 * Define a structure to hold a node of the linked list
*/
struct Node {
    int data;
    struct Node *next;
};

/*
 * Create a function to insert a new node at the head of the linked list
 * Arguments: a pointer to the head node and the data for the new node
 * Returns: a pointer to the new head node
*/
struct Node* insertAtHead(struct Node *head, int data) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    return head;
}

/*
 * Create a function to insert a new node at the end of the linked list
 * Arguments: a pointer to the head node and the data for the new node
 * Returns: a pointer to the new head node
*/
struct Node* insertAtEnd(struct Node *head, int data) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

/*
 * Create a function to delete the first occurrence of a node with given data
 * Arguments: a pointer to the head node and the data to be deleted
 * Returns: a pointer to the new head node
*/
struct Node* deleteNode(struct Node *head, int data) {
    struct Node *temp = head, *prev;
    if (temp != NULL && temp->data == data) {
        head = temp->next;
        free(temp);
        return head;
    }
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        return head;
    }
    prev->next = temp->next;
    free(temp);
    return head;
}

/*
 * Create a function to display the linked list from head to tail
 * Argument: a pointer to the head node
*/
void display(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main() {
    struct Node *head = NULL;
    
    // Testing insertAtHead function
    head = insertAtHead(head, 5);
    head = insertAtHead(head, 10);
    head = insertAtHead(head, 15);
    printf("List after inserting at head: ");
    display(head);
    
    // Testing insertAtEnd function
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 25);
    printf("List after inserting at end: ");
    display(head);
    
    // Testing deleteNode function
    head = deleteNode(head, 15);
    printf("List after deleting 15: ");
    display(head);
    
    return 0;
}