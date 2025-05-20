//FormAI DATASET v1.0 Category: Linked list operations ; Style: curious
// Welcome to the curious world of C Linked lists!

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a Node in the linked list
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

// Function to add a new node to the linked list
void addNode(struct Node** head, int data) {
    struct Node* node = newNode(data);
    node->next = *head;
    *head = node;
    printf("Added node with data: %d\n", data);
}

// Function to find the length of the linked list
int length(struct Node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

// Function to delete a node from the linked list
void deleteNode(struct Node** head, int data) {
    struct Node* curr = *head;
    struct Node* prev = NULL;
    while (curr != NULL && curr->data != data) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL) {
        printf("Node with data %d not found\n", data);
    } else if (prev == NULL) {
        *head = curr->next;
        free(curr);
        printf("Deleted node with data: %d\n", data);
    } else {
        prev->next = curr->next;
        free(curr);
        printf("Deleted node with data: %d\n", data);
    }
}

// Function to reverse the linked list
void reverseList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* curr = *head;
    struct Node* next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
    printf("Linked list reversed!\n");
}

// Function to display the linked list
void display(struct Node* head) {
    printf("Linked list: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct Node* head = NULL;
    // Let's create a linked list of length 5
    addNode(&head, 5);
    addNode(&head, 4);
    addNode(&head, 3);
    addNode(&head, 2);
    addNode(&head, 1);
    // Display the linked list
    printf("Length of linked list is: %d\n", length(head));
    display(head);
    // Let's delete a node with data 3
    deleteNode(&head, 3);
    display(head);
    // Let's reverse the linked list now
    reverseList(&head);
    display(head);
    return 0;
}