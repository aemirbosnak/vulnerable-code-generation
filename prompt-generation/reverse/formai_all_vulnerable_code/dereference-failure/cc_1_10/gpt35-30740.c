//FormAI DATASET v1.0 Category: Linked list operations ; Style: excited
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void printList(struct node* head) {
    struct node* current = head;

    printf("List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void insertFirst(struct node** head, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));

    newNode->data = data;
    newNode->next = *head;
    *head = newNode;

    printf("%d inserted at the beginning.\n", data);
}

void insertLast(struct node** head, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    struct node* current = *head;

    if (*head == NULL) {
        insertFirst(head, data);
        return;
    }

    newNode->data = data;
    newNode->next = NULL;

    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;

    printf("%d inserted at the end.\n", data);
}

void deleteFirst(struct node** head) {
    if (*head == NULL) {
        printf("List is already empty.\n");
        return;
    }

    struct node* temp = *head;
    *head = (*head)->next;
    free(temp);

    printf("First node deleted.\n");
}

void deleteLast(struct node** head) {
    if (*head == NULL) {
        printf("List is already empty.\n");
        return;
    }

    if ((*head)->next == NULL) {
        deleteFirst(head);
        return;
    }

    struct node* current = *head;
    struct node* previous = NULL;

    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }
    previous->next = NULL;
    free(current);

    printf("Last node deleted.\n");
}

int main() {
    struct node* head = NULL;

    insertFirst(&head, 10);
    insertFirst(&head, 20);
    insertFirst(&head, 30);
    insertLast(&head, 40);
    printList(head);
    deleteLast(&head);
    deleteFirst(&head);
    printList(head);

    return 0;
}