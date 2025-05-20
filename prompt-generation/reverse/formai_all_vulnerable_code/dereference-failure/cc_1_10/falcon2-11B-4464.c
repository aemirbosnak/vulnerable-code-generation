//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = (*head);
    (*head) = newNode;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    struct Node* current = (*head);
    while (current->next!= NULL) {
        current = current->next;
    }
    current->next = newNode;
}

void insertAfter(struct Node** head, int data, int key) {
    struct Node* newNode = createNode(data);
    struct Node* current = (*head);
    while (current->data!= key) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

void deleteAtBeginning(struct Node** head) {
    struct Node* current = (*head);
    (*head) = (*head)->next;
    free(current);
}

void deleteAtEnd(struct Node** head) {
    struct Node* current = (*head);
    while (current->next!= NULL) {
        current = current->next;
    }
    current->next = NULL;
    free(current);
}

void deleteNode(struct Node** head, int key) {
    struct Node* current = (*head);
    while (current->data!= key) {
        current = current->next;
    }
    if (current->next == NULL) {
        current->next = NULL;
        free(current);
    } else {
        struct Node* temp = current->next;
        current->next = current->next->next;
        free(temp);
    }
}

void display(struct Node* head) {
    struct Node* current = head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    insertAtBeginning(&head, 10);
    insertAtEnd(&head, 20);
    insertAfter(&head, 10, 15);
    deleteAtBeginning(&head);
    deleteAtEnd(&head);
    deleteNode(&head, 10);
    display(head);
    return 0;
}