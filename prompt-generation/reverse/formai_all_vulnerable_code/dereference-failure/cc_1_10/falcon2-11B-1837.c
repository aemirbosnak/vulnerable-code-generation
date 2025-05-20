//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// Structure for Node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode!= NULL) {
        newNode->data = data;
        newNode->next = NULL;
    }
    return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node** headRef, int newData) {
    struct Node* newNode = createNode(newData);
    if (*headRef!= NULL) {
        newNode->next = *headRef;
    }
    *headRef = newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** headRef, int newData) {
    struct Node* newNode = createNode(newData);
    if (*headRef == NULL) {
        *headRef = newNode;
    } else {
        struct Node* current = *headRef;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to insert a node after a specific node
void insertAfterNode(struct Node** headRef, int dataToInsert, struct Node* searchNode) {
    struct Node* newNode = createNode(dataToInsert);
    if (*headRef == NULL) {
        *headRef = newNode;
    } else {
        struct Node* current = *headRef;
        while (current->next!= searchNode) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to delete a node from the list
void deleteNode(struct Node** headRef, int dataToDelete) {
    if (*headRef == NULL) {
        printf("List is empty!\n");
        return;
    } else if (*headRef == (struct Node*)malloc(sizeof(struct Node))) {
        *headRef = NULL;
    } else {
        struct Node* current = *headRef;
        while (current->data!= dataToDelete) {
            current = current->next;
        }
        if (current == *headRef) {
            *headRef = current->next;
        } else {
            struct Node* prev = *headRef;
            while (current->next!= *headRef) {
                prev = current;
                current = current->next;
            }
            prev->next = current->next;
            free(current);
        }
    }
}

// Function to print the list
void printList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
    } else {
        struct Node* current = head;
        while (current!= NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

// Main function
int main() {
    struct Node* head = NULL;
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 15);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 25);
    insertAfterNode(&head, 20, head);
    printf("Original list: ");
    printList(head);
    printf("\nDeleted 20: ");
    deleteNode(&head, 20);
    printList(head);
    return 0;
}