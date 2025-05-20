//FormAI DATASET v1.0 Category: Linked list operations ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

/* Function to create a new linked list node */
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

/* Function to insert a new node at the beginning of the list */
void push(struct Node** head_ref, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = (*head_ref);
    (*head_ref) = newNode;
    printf("New node with value %d has been added to the beginning of the list!\n", value);
}

/* Function to insert a new node after a specific node in the list */
void insertAfter(struct Node* prev_node, int value) {
    if (prev_node == NULL) {
        printf("Error: Previous node cannot be NULL!\n");
        return;
    }

    struct Node* newNode = createNode(value);
    newNode->next = prev_node->next;
    prev_node->next = newNode;
    printf("New node with value %d has been added after the previous node!\n", value);
}

/* Function to insert a new node at the end of the list */
void append(struct Node** head_ref, int value) {
    struct Node* newNode = createNode(value);

    if ((*head_ref) == NULL) {
        (*head_ref) = newNode;
        return;
    }

    struct Node* lastNode = (*head_ref);
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }

    lastNode->next = newNode;
    printf("New node with value %d has been added to the end of the list!\n", value);
}

/* Function to delete a node with a specific value from the list */
void deleteNode(struct Node** head_ref, int value) {
    struct Node* temp = (*head_ref);
    struct Node* prev = NULL;

    if (temp != NULL && temp->data == value) {
        (*head_ref) = temp->next;
        free(temp);
        printf("Node with value %d has been deleted from the list!\n", value);
        return;
    }

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Error: Node with value %d not found in the list!\n", value);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Node with value %d has been deleted from the list!\n", value);
}

/* Function to print the contents of the list */
void printList(struct Node* node) {
    printf("Current list: ");
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Main function */
int main() {
    struct Node* head = NULL;

    /* Insert nodes */
    push(&head, 10);
    insertAfter(head, 20);
    append(&head, 30);
    append(&head, 40);
    insertAfter(head->next, 50);
    push(&head, 5);

    /* Print the list */
    printList(head);

    /* Delete nodes */
    deleteNode(&head, 20);
    deleteNode(&head, 5);

    /* Print the list */
    printList(head);

    return 0;
}