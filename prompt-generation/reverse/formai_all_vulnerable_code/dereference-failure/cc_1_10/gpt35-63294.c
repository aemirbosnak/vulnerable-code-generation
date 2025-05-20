//FormAI DATASET v1.0 Category: Memory management ; Style: lively
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

// Function to create new nodes
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert new nodes at the beginning
void insertNode(struct node** head, int data) {
    struct node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to delete nodes
void deleteNode(struct node** head, int key) {
    struct node* temp = *head, *prev;
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key) {
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
void displayList(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct node* head = NULL; // Initialize the list to empty

    printf("Inserting 3 at the beginning\n");
    insertNode(&head, 3);
    displayList(head);

    printf("Inserting 5 at the beginning\n");
    insertNode(&head, 5);
    displayList(head);

    printf("Inserting 7 at the beginning\n");
    insertNode(&head, 7);
    displayList(head);

    printf("Deleting 5 from the list\n");
    deleteNode(&head, 5);
    displayList(head);

    printf("Deleting 3 from the list\n");
    deleteNode(&head, 3);
    displayList(head);

    printf("Deleting 7 from the list\n");
    deleteNode(&head, 7);
    displayList(head);

    return 0;
}