//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to initialize the head of the linked list
struct Node* createLinkedList() {
    struct Node* head = NULL;
    struct Node* temp = NULL;

    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = 0;
    temp->next = NULL;

    head = temp;

    return head;
}

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;

    *head = newNode;
}

// Function to insert a new node at the end of the linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to delete a node from the linked list
void deleteNode(struct Node** head, int data) {
    struct Node* temp = *head;

    if (*head == NULL) {
        return;
    }

    if ((*head)->data == data) {
        *head = (*head)->next;
        free(temp);
        return;
    }

    while (temp->next!= NULL && temp->next->data!= data) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        return;
    }

    struct Node* temp2 = temp->next;
    temp->next = temp2->next;
    free(temp2);
}

// Function to reverse the linked list
void reverseLinkedList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* curr = *head;
    struct Node* next = NULL;

    while (curr!= NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    *head = prev;
}

// Function to print the linked list
void printLinkedList(struct Node* head) {
    struct Node* temp = head;

    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct Node* head = createLinkedList();

    // Insert elements at the beginning of the linked list
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 4);
    insertAtBeginning(&head, 5);

    // Print the linked list
    printLinkedList(head);

    // Delete element at the beginning of the linked list
    deleteNode(&head, 1);

    // Print the linked list after deletion
    printLinkedList(head);

    // Reverse the linked list
    reverseLinkedList(&head);

    // Print the reversed linked list
    printLinkedList(head);

    return 0;
}