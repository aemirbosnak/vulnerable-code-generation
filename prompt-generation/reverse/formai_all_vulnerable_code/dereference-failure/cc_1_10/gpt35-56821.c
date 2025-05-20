//FormAI DATASET v1.0 Category: Linked list operations ; Style: Linus Torvalds
#include<stdio.h>
#include<stdlib.h>

// Define the structure of the node in the LinkedList
struct Node {
    int data;
    struct Node* next;
};

// Function to print out the linked list in its current state 
void printList(struct Node* head) {
    struct Node* curr = head;
    printf("Current LinkedList: ");
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

// Function that creates a new node and inserts into the linked list at given index 
void insertNode(struct Node** headRef, int index, int newData) {
    if (index < 0) {
        printf("Error: Invalid Index\n");
        return;
    }
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL;
    
    if (index == 0) {
        // Insert it at the beginning
        newNode->next = *headRef;
        *headRef = newNode;
    }
    else {
        struct Node* curr = *headRef;
        int i = 0;
        while (curr != NULL && i < index - 1) {
            curr = curr->next;
            i++;
        }
        if (curr == NULL) {
            printf("Error: Invalid Index\n");
            return;
        }
        // Insert newNode at index
        newNode->next = curr->next;
        curr->next = newNode;
    }
}

// Function that removes a node from the given index in the linked list 
void removeNode(struct Node** headRef, int index) {
    if (index < 0) {
        printf("Error: Invalid Index\n");
        return;
    }
    struct Node* curr = *headRef;
    if (index == 0) {
        // Remove first node
        *headRef = curr->next;
        free(curr);
        curr = NULL;
    }
    else {
        int i=0;
        struct Node* prev = NULL;
        while (curr != NULL && i < index) {
            prev = curr;
            curr = curr->next;
            i++;
        }
        if (curr == NULL) {
            printf("Error: Invalid Index\n");
            return;
        }
        // Remove node at index
        prev->next = curr->next;
        free(curr);
        curr = NULL;
    }
}

int main() {
    struct Node* head = NULL;
    
    // Insert a few nodes into the LinkedList
    insertNode(&head, 0, 1);
    insertNode(&head, 1, 2);
    insertNode(&head, 2, 3);
    insertNode(&head, 0, 4);
    
    // Print out the LinkedList
    printList(head);

    // Remove a node from the LinkedList
    removeNode(&head, 2);

    // Print out the LinkedList again
    printList(head);

    // Insert a node at an invalid index
    insertNode(&head, -1, 5);

    // Remove a node at an invalid index
    removeNode(&head, 10);

    // Clean up the memory by deleting all nodes
    while (head != NULL) {
        struct Node* curr = head;
        head = head->next;
        free(curr);
        curr = NULL;
    }
    return 0;
}