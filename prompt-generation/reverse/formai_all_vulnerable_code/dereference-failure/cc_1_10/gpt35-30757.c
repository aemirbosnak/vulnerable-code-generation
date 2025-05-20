//FormAI DATASET v1.0 Category: Linked list operations ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

// Linked list node structure
struct Node {
    int data;
    struct Node *next;
};

// A global variable to store the head of the linked list
struct Node *head = NULL;

/* Function to create a new node with given data */
struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/* Function to add node at the end of the linked list */
void addNode(int data) {
    struct Node *newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

/* Function to insert node at given position */
void insertNode(int data, int pos) {
    struct Node *newNode = createNode(data);
    if (pos == 1) {
        newNode->next = head;
        head = newNode;
    } else {
        struct Node *temp = head;
        for (int i = 1; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Invalid position\n");
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

/* Function to delete node at given position */
void deleteNode(int pos) {
    if (head == NULL) {
        printf("List is empty\n");
    } else if (pos == 1) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    } else {
        struct Node *temp1 = head, *temp2;
        for (int i = 1; i < pos - 1 && temp1 != NULL; i++) {
            temp1 = temp1->next;
        }
        if (temp1 == NULL || temp1->next == NULL) {
            printf("Invalid position\n");
        } else {
            temp2 = temp1->next;
            temp1->next = temp2->next;
            free(temp2);
        }
    }
}

/* Function to display the linked list */
void displayList() {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        struct Node *temp = head;
        printf("List elements: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    // Adding nodes to the linked list
    addNode(1);
    addNode(2);
    addNode(3);
    addNode(4);
    addNode(5);

    // Displaying the linked list before insertion
    printf("Linked list before insertion: \n");
    displayList();

    // Inserting node at 3rd position
    insertNode(6, 3);

    // Displaying the linked list after insertion
    printf("Linked list after insertion: \n");
    displayList();

    // Deleting node at 4th position
    deleteNode(4);

    // Displaying the linked list after deletion
    printf("Linked list after deletion: \n");
    displayList();

    return 0;
}