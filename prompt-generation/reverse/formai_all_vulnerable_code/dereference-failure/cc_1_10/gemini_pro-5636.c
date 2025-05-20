//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct node {
    int data;
    struct node *next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(Node **head, int data) {
    Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(Node **head, int data) {
    Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to insert a node after a given node
void insertAfter(Node *prevNode, int data) {
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL\n");
    } else {
        Node *newNode = createNode(data);
        newNode->next = prevNode->next;
        prevNode->next = newNode;
    }
}

// Function to delete a node from the beginning of the list
void deleteFromBeginning(Node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
    } else {
        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

// Function to delete a node from the end of the list
void deleteFromEnd(Node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
    } else if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
    } else {
        Node *temp = *head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

// Function to delete a node after a given node
void deleteAfter(Node *prevNode) {
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL\n");
    } else if (prevNode->next == NULL) {
        printf("Node to be deleted does not exist\n");
    } else {
        Node *temp = prevNode->next;
        prevNode->next = temp->next;
        free(temp);
    }
}

// Function to search for a node in the list
Node* searchNode(Node *head, int data) {
    Node *temp = head;
    while (temp != NULL) {
        if (temp->data == data) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to print the list
void printList(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    // Create a linked list
    Node *head = NULL;
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);

    // Print the list
    printf("Original list: ");
    printList(head);

    // Insert a node at the beginning of the list
    insertAtBeginning(&head, 0);

    // Print the list
    printf("List after inserting a node at the beginning: ");
    printList(head);

    // Insert a node after a given node
    insertAfter(head->next, 2.5);

    // Print the list
    printf("List after inserting a node after a given node: ");
    printList(head);

    // Delete a node from the beginning of the list
    deleteFromBeginning(&head);

    // Print the list
    printf("List after deleting a node from the beginning: ");
    printList(head);

    // Delete a node from the end of the list
    deleteFromEnd(&head);

    // Print the list
    printf("List after deleting a node from the end: ");
    printList(head);

    // Delete a node after a given node
    deleteAfter(head->next);

    // Print the list
    printf("List after deleting a node after a given node: ");
    printList(head);

    // Search for a node in the list
    Node *foundNode = searchNode(head, 3);
    if (foundNode != NULL) {
        printf("Node found: %d\n", foundNode->data);
    } else {
        printf("Node not found\n");
    }

    return 0;
}