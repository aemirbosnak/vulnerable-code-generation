//FormAI DATASET v1.0 Category: Linked list operations ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertFront(struct Node** head, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void insertEnd(struct Node** head, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    struct Node* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
    return;
}

void deleteNode(struct Node** head, int key) {
    if (*head == NULL) {
        printf("Linked List is empty");
        return;
    }
    struct Node* temp = *head;
    struct Node* prev = NULL;
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
        printf("Element not found");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void displayList(struct Node* head) {
    if (head == NULL) {
        printf("Linked List is empty");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

int main() {
    struct Node* head = NULL;
    insertFront(&head, 5);
    insertEnd(&head, 6);
    insertFront(&head, 4);
    insertFront(&head, 3);
    insertFront(&head, 2);
    insertEnd(&head, 7);
    deleteNode(&head, 2);
    displayList(head);
    return 0;
}