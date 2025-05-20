//Falcon-180B DATASET v1.0 Category: Memory management ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Linked list node structure
struct node {
    int data;
    struct node* next;
};

// Function to create a new node with given data
struct node* newNode(int data) {
    struct node* node = (struct node*) malloc(sizeof(struct node));
    if (node == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to add a node at the end of the list
void addNode(struct node** head, int data) {
    struct node* node = newNode(data);
    struct node* temp = *head;
    if (*head == NULL) {
        node->next = NULL;
        *head = node;
        return;
    }
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = node;
}

// Function to print the list
void printList(struct node* head) {
    struct node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to delete a node with given data
struct node* deleteNode(struct node* head, int data) {
    struct node* temp = head;
    struct node* prev = NULL;
    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        return NULL;
    }
    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
    return head;
}

// Function to search a node with given data
struct node* searchNode(struct node* head, int data) {
    struct node* temp = head;
    while (temp!= NULL && temp->data!= data) {
        temp = temp->next;
    }
    return temp;
}

int main() {
    struct node* head = NULL;

    // Adding nodes
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    addNode(&head, 4);

    // Printing list
    printf("List: ");
    printList(head);

    // Deleting node with data 3
    head = deleteNode(head, 3);

    // Printing list after deletion
    printf("List after deleting 3: ");
    printList(head);

    // Searching node with data 4
    struct node* result = searchNode(head, 4);
    if (result!= NULL) {
        printf("Node found with data %d\n", result->data);
    } else {
        printf("Node not found\n");
    }

    return 0;
}