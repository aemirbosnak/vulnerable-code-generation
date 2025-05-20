//FormAI DATASET v1.0 Category: Linked list operations ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void printList(struct Node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void push(struct Node **head, int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = (*head);
    (*head) = newNode;
}

void insertAfter(struct Node *prevNode, int data) {
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL.\n");
        return;
    }
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

void append(struct Node **head, int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node *lastNode = *head;
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
}

void deleteByKey(struct Node **head, int key) {
    struct Node *temp = *head, *prev;
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
        printf("Key not found.\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void deleteByPos(struct Node **head, int pos) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = *head;
    if (pos == 0) {
        *head = temp->next;
        free(temp);
        return;
    }
    for (int i = 0; temp != NULL && i < pos-1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Out of range.\n");
        return;
    }
    struct Node *next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

int main() {
    struct Node *head = NULL;
    push(&head, 4);
    append(&head, 6);
    insertAfter(head->next, 5);
    printf("Original Linked List: ");
    printList(head);
    deleteByKey(&head, 5);
    printf("Linked List after deleting node with key 5: ");
    printList(head);
    deleteByPos(&head, 1);
    printf("Linked List after deleting node at position 1: ");
    printList(head);
    return 0;
}