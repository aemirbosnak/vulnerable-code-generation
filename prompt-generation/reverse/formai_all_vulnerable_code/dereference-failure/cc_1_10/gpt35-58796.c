//FormAI DATASET v1.0 Category: Linked list operations ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

// Creating struct for each node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a new node at the beginning of the linked list
struct Node* insertAtStart(struct Node* head, int data) {
    struct Node* new_node = createNode(data);
    new_node->next = head;
    head = new_node;
    return head;
}

// Function to insert a new node at the end of the linked list
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* new_node = createNode(data);
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    return head;
}

// Function to insert a new node at a particular position in the linked list
struct Node* insertAtPosition(struct Node* head, int data, int position) {
    struct Node* new_node = createNode(data);
    struct Node* temp = head;
    int i;
    for (i = 1; i < position - 1; i++) {
        temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
    return head;
}

// Function to delete the first node of the linked list
struct Node* deleteAtStart(struct Node* head) {
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Function to delete the last node of the linked list
struct Node* deleteAtEnd(struct Node* head) {
    struct Node* temp1 = head;
    struct Node* temp2 = head;
    while (temp1->next != NULL) {
        temp2 = temp1;
        temp1 = temp1->next;
    }
    temp2->next = NULL;
    free(temp1);
    return head;
}

// Function to delete a node from a particular position of the linked list
struct Node* deleteAtPosition(struct Node* head, int position) {
    struct Node* temp1 = head;
    struct Node* temp2 = head;
    int i;
    for (i = 1; i < position; i++) {
        temp2 = temp1;
        temp1 = temp1->next;
    }
    temp2->next = temp1->next;
    free(temp1);
    return head;
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Inserting nodes
    head = insertAtStart(head, 10);
    head = insertAtStart(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtPosition(head, 40, 3);

    // Displaying the list after insertion
    displayList(head);

    // Deleting nodes
    head = deleteAtStart(head);
    head = deleteAtEnd(head);
    head = deleteAtPosition(head, 2);

    // Displaying the list after deletion
    displayList(head);

    return 0;
}