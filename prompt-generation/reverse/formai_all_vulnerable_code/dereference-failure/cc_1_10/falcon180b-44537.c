//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

// Node structure definition
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
void addNode(struct Node** headRef, int data);
void deleteNode(struct Node** headRef, int data);
void displayList(struct Node* head);
void sortList(struct Node* head);

int main() {
    struct Node* head = NULL;

    // Add nodes to the list
    addNode(&head, 5);
    addNode(&head, 3);
    addNode(&head, 7);
    addNode(&head, 1);
    addNode(&head, 9);

    // Display the list
    printf("Unsorted list:\n");
    displayList(head);

    // Sort the list
    sortList(head);

    // Display the sorted list
    printf("\nSorted list:\n");
    displayList(head);

    return 0;
}

// Function to add a node to the list
void addNode(struct Node** headRef, int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }

    struct Node* last = *headRef;

    while (last->next!= NULL) {
        last = last->next;
    }

    last->next = newNode;
}

// Function to delete a node from the list
void deleteNode(struct Node** headRef, int data) {
    struct Node* temp = *headRef;
    struct Node* prev = NULL;

    if (temp!= NULL && temp->data == data) {
        *headRef = temp->next;
        free(temp);
        return;
    }

    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Function to display the list
void displayList(struct Node* head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to sort the list
void sortList(struct Node* head) {
    struct Node* curr = head;
    struct Node* next = NULL;
    int temp;

    while (curr!= NULL) {
        next = curr->next;
        curr->next = NULL;

        while (next!= NULL) {
            if (curr->data > next->data) {
                temp = curr->data;
                curr->data = next->data;
                next->data = temp;
            }

            next = next->next;
        }

        curr->next = next;
        curr = next;
    }
}