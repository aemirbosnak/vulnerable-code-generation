//FormAI DATASET v1.0 Category: Linked list operations ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

// define a structure for a node
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// function to create a new node
Node* createNode(int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// function to insert a node at the beginning of the list
void insertAtBeginning(Node **head, int data) {
    Node *new_node = createNode(data);
    new_node->next = *head;
    *head = new_node;
}

// function to insert a node at the end of the list
void insertAtEnd(Node **head, int data) {
    Node *new_node = createNode(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

// function to insert a node at a given position
void insertAtPosition(Node **head, int data, int position) {
    Node *new_node = createNode(data);
    if (position == 1) {
        new_node->next = *head;
        *head = new_node;
        return;
    }
    Node *temp = *head;
    for (int i = 1; i < position - 1; i++) {
        temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

// function to delete a node from the list
void delete(Node **head, int key) {
    if (*head == NULL) {
        return;
    }
    Node *temp = *head, *prev;
    // if key is present at the beginning
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }
    // search for the key to be deleted, keep track of prev node
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    // if key was not present in the list
    if (temp == NULL) {
        return;
    }
    // unlink the node from the list
    prev->next = temp->next;
    free(temp);
}

// function to print the list
void printList(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// main function
int main() {
    Node *head = NULL;
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtEnd(&head, 3);
    insertAtPosition(&head, 4, 2);
    printf("Linked list: \n");
    printList(head);
    delete(&head, 4);
    printf("Linked list after deletion: \n");
    printList(head);
    return 0;
}