//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: secure
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to create a new node with the given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the end of the linked list
void addNode(Node** head, int data) {
    Node* newNode = createNode(data);
    Node* temp = *head;

    // If the linked list is empty, set the new node as the head
    if (*head == NULL) {
        newNode->next = NULL;
        *head = newNode;
        return;
    }

    // Traverse to the end of the linked list and add the new node
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to delete a node with the given data from the linked list
void deleteNode(Node** head, int data) {
    Node* temp = *head;

    // If the linked list is empty or the head node has the given data, set the head to the next node
    if (*head == NULL || (*head)->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }

    // Traverse the linked list and delete the node with the given data
    while (temp!= NULL && temp->data!= data) {
        temp = temp->next;
    }

    if (temp == NULL) {
        return;
    }

    Node* prevNode = temp->next;
    free(temp);
    temp = prevNode;
}

// Function to reverse the linked list
void reverseLinkedList(Node** head) {
    Node* prev = NULL;
    Node* current = *head;

    // Traverse the linked list and reverse the pointers
    while (current!= NULL) {
        Node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    // Set the new head of the reversed linked list
    *head = prev;
}

// Function to print the linked list
void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;

    // Add some nodes to the linked list
    addNode(&head, 10);
    addNode(&head, 20);
    addNode(&head, 30);
    addNode(&head, 40);

    // Print the linked list
    printf("Original linked list:\n");
    printLinkedList(head);

    // Reverse the linked list
    reverseLinkedList(&head);

    // Print the reversed linked list
    printf("Reversed linked list:\n");
    printLinkedList(head);

    // Delete a node from the linked list
    deleteNode(&head, 30);

    // Print the updated linked list
    printf("Updated linked list:\n");
    printLinkedList(head);

    return 0;
}