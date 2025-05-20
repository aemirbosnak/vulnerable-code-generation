//FormAI DATASET v1.0 Category: Linked list operations ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

// Define a structure for each node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Create a new node with the given data and the next node
Node* newNode(int data, Node* next) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = next;
    return node;
}

// Insert a node at the beginning of the linked list
void insertFirst(Node** head, int data) {
    // Create a new node with the data and the current head node as its next node
    Node* node = newNode(data, *head);
    // Set the new node as the head of the linked list
    *head = node;
}

// Insert a node at the end of the linked list
void insertLast(Node** head, int data) {
    // If the linked list is empty, create a new node and set it as the head
    if (*head == NULL) {
        *head = newNode(data, NULL);
        return;
    }
    // Traverse the linked list till the end
    Node* node = *head;
    while (node->next != NULL) {
        node = node->next;
    }
    // Create a new node with the data and set it as the last node's next node
    node->next = newNode(data, NULL);
}

// Delete the first node in the linked list and return its data
int deleteFirst(Node** head) {
    // If the linked list is empty, return -1
    if (*head == NULL) {
        return -1;
    }
    // Save the data of the first node
    int data = (*head)->data;
    // Set the second node as the new head and delete the first node
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
    // Return the saved data
    return data;
}

// Delete the last node in the linked list and return its data
int deleteLast(Node** head) {
    // If the linked list is empty, return -1
    if (*head == NULL) {
        return -1;
    }
    // If there is only one node in the linked list, delete it and set the head to NULL
    if ((*head)->next == NULL) {
        int data = (*head)->data;
        free(*head);
        *head = NULL;
        return data;
    }
    // Traverse the linked list till one node before the last node
    Node* node = *head;
    while (node->next->next != NULL) {
        node = node->next;
    }
    // Save the data of the last node and delete it
    int data = node->next->data;
    free(node->next);
    node->next = NULL;
    // Return the saved data
    return data;
}

// Search the linked list for a node with the given data and return its index (i.e. position)
int search(Node* head, int data) {
    // Initialize the index to zero
    int index = 0;
    // Traverse the linked list and compare each node's data with the given data
    Node* node = head;
    while (node != NULL) {
        if (node->data == data) {
            // If a node with the given data is found, return its index
            return index;
        }
        index++;
        node = node->next;
    }
    // If a node with the given data is not found, return -1
    return -1;
}

// Print all the nodes in the linked list
void printList(Node* head) {
    // Traverse the linked list and print each node's data
    Node* node = head;
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    // Initialize an empty linked list
    Node* head = NULL;
    
    // Insert some nodes at the beginning of the linked list
    insertFirst(&head, 10);
    insertFirst(&head, 20);
    insertFirst(&head, 30);
    printf("List after inserting nodes at the beginning: ");
    printList(head);
    
    // Insert some nodes at the end of the linked list
    insertLast(&head, 40);
    insertLast(&head, 50);
    insertLast(&head, 60);
    printf("List after inserting nodes at the end: ");
    printList(head);
    
    // Delete the first node and print the list
    deleteFirst(&head);
    printf("List after deleting the first node: ");
    printList(head);
    
    // Delete the last node and print the list
    deleteLast(&head);
    printf("List after deleting the last node: ");
    printList(head);
    
    // Search for some nodes and print their indices
    int index = search(head, 10);
    printf("Index of 10 in the list: %d\n", index);
    index = search(head, 30);
    printf("Index of 30 in the list: %d\n", index);
    index = search(head, 60);
    printf("Index of 60 in the list: %d\n", index);
    index = search(head, 90);
    printf("Index of 90 in the list: %d\n", index);
    
    // Delete the remaining nodes and print the list
    deleteFirst(&head);
    deleteFirst(&head);
    deleteFirst(&head);
    printf("List after deleting all the nodes: ");
    printList(head);
    
    return 0;
}