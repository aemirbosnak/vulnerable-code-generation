//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Function to create a new node
Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
Node *insertAtBeginning(Node *head, int data) {
    Node *newNode = createNode(data);
    newNode->next = head;
    head = newNode;
    return head;
}

// Function to insert a node at the end of the list
Node *insertAtEnd(Node *head, int data) {
    Node *newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return head;
}

// Function to insert a node after a given node
Node *insertAfterNode(Node *head, int data, int afterData) {
    Node *newNode = createNode(data);
    Node *temp = head;
    while (temp != NULL && temp->data != afterData) {
        temp = temp->next;
    }
    if (temp != NULL) {
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return head;
}

// Function to delete a node from the beginning of the list
Node *deleteFromBeginning(Node *head) {
    if (head != NULL) {
        Node *temp = head;
        head = head->next;
        free(temp);
    }
    return head;
}

// Function to delete a node from the end of the list
Node *deleteFromEnd(Node *head) {
    if (head == NULL) {
        return NULL;
    } else if (head->next == NULL) {
        free(head);
        return NULL;
    } else {
        Node *temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
        return head;
    }
}

// Function to delete a node with a given value
Node *deleteNode(Node *head, int data) {
    Node *temp = head;
    Node *prev = NULL;
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }
    if (temp != NULL) {
        if (prev == NULL) {
            head = head->next;
        } else {
            prev->next = temp->next;
        }
        free(temp);
    }
    return head;
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

// Main function
int main() {
    // Create a list
    Node *head = NULL;

    // Insert some nodes
    head = insertAtBeginning(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAfterNode(head, 30, 10);

    // Print the list
    printf("List: ");
    printList(head);

    // Delete a node from the beginning
    head = deleteFromBeginning(head);

    // Delete a node from the end
    head = deleteFromEnd(head);

    // Delete a node with a given value
    head = deleteNode(head, 30);

    // Print the list
    printf("List: ");
    printList(head);

    return 0;
}