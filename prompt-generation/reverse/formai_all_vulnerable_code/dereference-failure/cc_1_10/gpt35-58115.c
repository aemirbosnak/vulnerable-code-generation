//FormAI DATASET v1.0 Category: Linked list operations ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct node {
    int data;
    struct node* next;
};

// Create new node with given data
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Add node to the front of the list
void insertFront(struct node** head, int data) {
    struct node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Add node to the end of the list
void insertEnd(struct node** head, int data) {
    struct node* newNode = createNode(data);
    struct node* curr = *head;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = newNode;
}

// Insert node at given position
void insertAtPosition(struct node** head, int data, int position) {
    struct node* newNode = createNode(data);
    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    int currentPosition = 1;
    struct node* curr = *head;
    while (currentPosition < position - 1 && curr != NULL) {
        curr = curr->next;
        currentPosition++;
    }
    if (curr == NULL) {
        printf("Position not found.\n");
        free(newNode);
        return;
    }
    newNode->next = curr->next;
    curr->next = newNode;
}

// Delete node at front of list
void deleteFront(struct node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node* curr = *head;
    *head = curr->next;
    free(curr);
}

// Delete node at end of list
void deleteEnd(struct node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    struct node* curr = *head;
    while (curr->next->next != NULL) {
        curr = curr->next;
    }
    free(curr->next);
    curr->next = NULL;
}

// Delete node at given position
void deleteAtPosition(struct node** head, int position) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (position == 1) {
        struct node* curr = *head;
        *head = curr->next;
        free(curr);
        return;
    }
    int currentPosition = 1;
    struct node* curr = *head;
    while (currentPosition < position - 1 && curr != NULL) {
        curr = curr->next;
        currentPosition++;
    }
    if (curr == NULL || curr->next == NULL) {
        printf("Position not found.\n");
        return;
    }
    struct node* temp = curr->next;
    curr->next = curr->next->next;
    free(temp);
}

// Print entire list
void printList(struct node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct node* head = NULL;
    insertFront(&head, 2);
    insertEnd(&head, 3);
    insertAtPosition(&head, 4, 2);
    printList(head);
    deleteFront(&head);
    deleteEnd(&head);
    deleteAtPosition(&head, 1);
    printList(head);
    return 0;
}