//FormAI DATASET v1.0 Category: Linked list operations ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;          
    struct Node* next; 
};

struct Node* head = NULL;

void insertAtBeginning(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->next = head;
    head = node;
}

void insertAtEnd(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    if (head == NULL) {
        head = node;
        return;
    }
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = node;
}

void insertAtPosition(int data, int position) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    if (position == 0) {
        node->next = head;
        head = node;
        return;
    }
    struct Node* current = head;
    for (int i = 0; i < position - 1; i++) {
        current = current->next;
        if (current == NULL) {
            printf("Position out of range\n");
            return;
        }
    }
    node->next = current->next;
    current->next = node;
}

void deleteAtPosition(int position) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (position == 0) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return;
    }
    struct Node* current = head;
    for (int i = 0; i < position - 1; i++) {
        current = current->next;
        if (current == NULL) {
            printf("Position out of range\n");
            return;
        }
    }
    struct Node* temp = current->next;
    current->next = temp->next;
    free(temp);
}

void displayList() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    insertAtEnd(1);
    insertAtEnd(2);
    insertAtEnd(3);
    insertAtBeginning(0);
    printf("Initial Linked List:\n");
    displayList();
    deleteAtPosition(2);
    printf("Linked List after deleting node at position 2:\n");
    displayList();
    insertAtPosition(4, 2);
    printf("Linked List after inserting node at position 2:\n");
    displayList();
    deleteAtPosition(4);
    printf("Linked List after deleting node at position 4:\n");
    displayList();
    return 0;
}