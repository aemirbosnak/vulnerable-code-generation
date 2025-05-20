//Falcon2-11B DATASET v1.0 Category: Data structures visualization ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

void printList(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
    } else {
        printf("List is not empty.\n");
        Node* current = head;
        while (current!= NULL) {
            printf(" %d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

void insertAtHead(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void insertAtTail(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = data;
    Node* tail = *head;
    while (tail->next!= NULL) {
        tail = tail->next;
    }
    tail->next = newNode;
}

void deleteFromHead(Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteFromTail(Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* tail = *head;
    while (tail->next->next!= NULL) {
        tail = tail->next;
    }
    tail->next = NULL;
    free(tail);
}

int main() {
    Node* head = NULL;

    insertAtHead(&head, 1);
    insertAtTail(&head, 2);
    insertAtHead(&head, 3);
    insertAtTail(&head, 4);
    insertAtHead(&head, 5);

    printList(head);

    deleteFromTail(&head);
    printList(head);

    deleteFromHead(&head);
    printList(head);

    return 0;
}