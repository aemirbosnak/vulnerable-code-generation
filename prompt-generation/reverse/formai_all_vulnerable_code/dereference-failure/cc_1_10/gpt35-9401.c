//FormAI DATASET v1.0 Category: Data structures visualization ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// define a linked list node structure
struct node {
    int data;
    struct node* next;
};

// function to create a new node
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// function to insert a node at the beginning of the list
void insertAtBeginning(struct node** head, int data) {
    struct node* newNode = createNode(data);
    newNode->next = (*head);
    (*head) = newNode;
}

// function to insert a node at the end of the list
void insertAtEnd(struct node** head, int data) {
    struct node* newNode = createNode(data);
    struct node* last = *head;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = newNode;
}

// function to insert a node at a given position in the list
void insertAtPosition(struct node** head, int data, int position) {
    if (position == 0) {
        insertAtBeginning(head, data);
        return;
    }

    struct node* newNode = createNode(data);
    struct node* current = *head;

    for (int i = 0; i < position - 1; i++) {
        if (current->next == NULL) {
            printf("Invalid position\n");
            return;
        }
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

// function to delete a node from the list
void deleteNode(struct node** head, int key) {
    struct node* temp = *head;
    struct node* prev = NULL;

    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;

    free(temp);
}

// function to display the list
void displayList(struct node* head) {
    struct node* current = head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

// main function
int main() {
    struct node* head = NULL;

    printf("Inserting 5 at the beginning of the list\n");
    insertAtBeginning(&head, 5);
    displayList(head);

    printf("Inserting 10 at the end of the list\n");
    insertAtEnd(&head, 10);
    displayList(head);

    printf("Inserting 7 at position 1\n");
    insertAtPosition(&head, 7, 1);
    displayList(head);

    printf("Deleting node with data 5\n");
    deleteNode(&head, 5);
    displayList(head);

    return 0;
}