//FormAI DATASET v1.0 Category: Linked list operations ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// Define the structure for each node in the linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to display the linked list
void displayList(Node* head) {
    Node* curr = head;
    printf("Linked List: ");
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

// Function to insert a node at the beginning of the linked list
Node* insertAtBeginning(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

// Function to insert a node at the end of the linked list
Node* insertAtEnd(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        return newNode;
    }
    Node* curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = newNode;
    return head;
}

// Function to delete a node at the beginning of the linked list
Node* deleteAtBeginning(Node* head) {
    if (head == NULL) {
        printf("The linked list is empty.\n");
        return NULL;
    }
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Function to delete a node at the end of the linked list
Node* deleteAtEnd(Node* head) {
    if (head == NULL) {
        printf("The linked list is empty.\n");
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    Node* curr = head;
    while (curr->next->next != NULL) {
        curr = curr->next;
    }
    free(curr->next);
    curr->next = NULL;
    return head;
}

// Function to delete a node with a specific value from the linked list
Node* deleteWithValue(Node* head, int data) {
    if (head == NULL) {
        printf("The linked list is empty.\n");
        return NULL;
    }
    if (head->data == data) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node* curr = head;
    while (curr->next != NULL && curr->next->data != data) {
        curr = curr->next;
    }
    if (curr->next == NULL) {
        printf("The value %d was not found in the linked list.\n", data);
        return head;
    }
    Node* temp = curr->next;
    curr->next = curr->next->next;
    free(temp);
    return head;
}

int main() {
    Node* head = NULL;

    // Insert some nodes at the beginning of the linked list
    printf("Inserting 5 nodes at the beginning of the linked list.\n");
    for (int i = 5; i >= 1; i--) {
        head = insertAtBeginning(head, i);
    }
    displayList(head);

    // Insert some nodes at the end of the linked list
    printf("Inserting 5 nodes at the end of the linked list.\n");
    for (int i = 6; i <= 10; i++) {
        head = insertAtEnd(head, i);
    }
    displayList(head);

    // Delete the first node of the linked list
    printf("Deleting the first node of the linked list.\n");
    head = deleteAtBeginning(head);
    displayList(head);

    // Delete the last node of the linked list
    printf("Deleting the last node of the linked list.\n");
    head = deleteAtEnd(head);
    displayList(head);

    // Delete a node with a specific value
    printf("Deleting a node with value 5 from the linked list.\n");
    head = deleteWithValue(head, 5);
    displayList(head);

    // Delete a node with a value that is not in the linked list
    printf("Deleting a node with value 100 from the linked list.\n");
    head = deleteWithValue(head, 100);

    return 0;
}