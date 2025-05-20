//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to add a node at the end of the list
void addNode(struct Node** head, int data) {
    struct Node* node = newNode(data);
    if (*head == NULL) {
        *head = node;
        return;
    }
    struct Node* temp = *head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = node;
}

// Function to print the list
void printList(struct Node* head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to search for a node in the list
struct Node* searchNode(struct Node* head, int data) {
    while (head!= NULL) {
        if (head->data == data) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

// Function to delete a node from the list
void deleteNode(struct Node** head, int data) {
    struct Node* node = searchNode(*head, data);
    if (node == NULL) {
        return;
    }
    if (node == *head) {
        *head = node->next;
        free(node);
        return;
    }
    struct Node* temp = *head;
    while (temp->next!= node) {
        temp = temp->next;
    }
    temp->next = node->next;
    free(node);
}

int main() {
    struct Node* head = NULL;
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    addNode(&head, 4);
    addNode(&head, 5);
    printf("Original List: ");
    printList(head);
    struct Node* node = searchNode(head, 3);
    if (node!= NULL) {
        deleteNode(&head, 3);
        printf("List after deleting node with value 3: ");
        printList(head);
    } else {
        printf("Node with value 3 not found in the list.\n");
    }
    return 0;
}