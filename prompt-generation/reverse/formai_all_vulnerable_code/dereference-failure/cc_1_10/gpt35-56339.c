//FormAI DATASET v1.0 Category: Linked list operations ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

// Node definition
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new Node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Function to add a new Node at the end of the linked list
void append(struct Node** headRef, int data) {
    struct Node* temp = newNode(data);
    if (*headRef == NULL)
        *headRef = temp;
    else {
        struct Node* current = *headRef;
        while (current->next != NULL)
            current = current->next;
        current->next = temp;
    }
    printf("Added %d to the linked list\n", data);
}

// Function to delete the first occurrence of a node with given data
void deleteNode(struct Node** headRef, int key) {
    struct Node* temp = *headRef, *prev = NULL;
    if (temp != NULL && temp->data == key) {
        *headRef = temp->next;
        free(temp);
        printf("Deleted %d from the list\n", key);
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("%d not found in the list\n", key);
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Deleted %d from the list\n", key);
}

// Function to display the contents of the linked list
void printList(struct Node* node) {
    printf("Contents of the linked list are:\n");
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    
    // Adding elements to the linked list
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);
    append(&head, 6);

    // Displaying the elements of the linked list
    printList(head);

    // Deleting elements from the linked list
    deleteNode(&head, 3);
    deleteNode(&head, 7);
    deleteNode(&head, 1);

    // Displaying the updated elements of the linked list
    printList(head);

    return 0;
}