//FormAI DATASET v1.0 Category: Linked list operations ; Style: safe
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

typedef struct node Node;

int listLength(Node* head) {
    int count = 0;
    Node* current = head;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

void insertAtBeginning(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

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

void insertAtIndex(Node** head, int data, int index) {
    if (index < 0 || index > listLength(*head)) {
        printf("Index out of bounds\n");
        return;
    }

    if (index == 0) {
        insertAtBeginning(head, data);
        return;
    }

    if (index == listLength(*head)) {
        insertAtEnd(head, data);
        return;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    Node* current = *head;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void deleteAtIndex(Node** head, int index) {
    if (index < 0 || index >= listLength(*head)) {
        printf("Index out of bounds\n");
        return;
    }

    if (index == 0) {
        Node* temp = *head;
        *head = temp->next;
        free(temp);
        return;
    }

    Node* current = *head;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }

    Node* temp = current->next;
    current->next = temp->next;
    free(temp);
}

void printList(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    printf("Inserting elements at beginning of list:\n");
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 3);
    printList(head);

    printf("Inserting elements at end of list:\n");
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 6);
    printList(head);

    printf("Inserting element at index 1 of list:\n");
    insertAtIndex(&head, 7, 1);
    printList(head);

    printf("Deleting element at index 4 of list:\n");
    deleteAtIndex(&head, 4);
    printList(head);

    printf("Deleting first element of list:\n");
    deleteAtIndex(&head, 0);
    printList(head);

    printf("Deleting last element of list:\n");
    deleteAtIndex(&head, listLength(head) - 1);
    printList(head);

    return 0;
}