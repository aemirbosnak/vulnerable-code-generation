//FormAI DATASET v1.0 Category: Linked list operations ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(Node** head, Node* newNode) {
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(Node** head, Node* newNode) {
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

void deleteNode(Node** head, int data) {
    Node* temp = *head, *prev;
    if (temp != NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void printList(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    insertAtBeginning(&head, createNode(1));
    insertAtBeginning(&head, createNode(2));
    insertAtEnd(&head, createNode(3));
    printList(head);
    deleteNode(&head, 2);
    printList(head);
    return 0;
}