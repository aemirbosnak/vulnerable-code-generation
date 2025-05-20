//FormAI DATASET v1.0 Category: Linked list operations ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertFront(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    Node* current = *head;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

void insertAt(Node** head, int data, int position) {
    Node* newNode = createNode(data);
    Node* current = *head;
    int count = 1;
    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    while (current != NULL && count < position-1) {
        current = current->next;
        count++;
    }
    if (current == NULL) {
        printf("Position out of range\n");
        return;
    }
    newNode->next = current->next;
    current->next = newNode;
}

void deleteFront(Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteEnd(Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* current = *head;
    if (current->next == NULL) {
        *head = NULL;
        free(current);
        return;
    }
    while (current->next->next != NULL) {
        current = current->next;
    }
    Node* temp = current->next;
    current->next = NULL;
    free(temp);
}

void deleteAt(Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* current = *head;
    int count = 1;
    if (position == 1) {
        *head = (*head)->next;
        free(current);
        return;
    }
    while (current != NULL && count < position-1) {
        current = current->next;
        count++;
    }
    if (current == NULL || current->next == NULL) {
        printf("Position out of range\n");
        return;
    }
    Node* temp = current->next;
    current->next = temp->next;
    free(temp);
}

void display(Node* head) {
    Node* current = head;
    if (current == NULL) {
        printf("List is empty\n");
        return;
    }
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    insertFront(&head, 1); // [1]
    insertEnd(&head, 3); // [1, 3]
    insertAt(&head, 2, 2); // [1, 2, 3]
    display(head); // 1 2 3
    deleteFront(&head); // [2, 3]
    deleteEnd(&head); // [2]
    deleteAt(&head, 1); // []
    display(head); // List is empty
    return 0;
}