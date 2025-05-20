//FormAI DATASET v1.0 Category: Linked list operations ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

void append(Node **headRef, int newData) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    Node *last = *headRef;
    newNode->data = newData;
    newNode->next = NULL;
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = newNode;
    return;
}

void deleteNode(Node **headRef, int key) {
    Node *temp = *headRef, *prev;
    if (temp != NULL && temp->data == key) {
        *headRef = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    prev->next = temp->next;
    free(temp);
}

void displayList(Node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    Node *head = NULL;
    append(&head, 2);
    append(&head, 3);
    append(&head, 5);
    append(&head, 7);
    append(&head, 11);
    printf("Linked List: ");
    displayList(head);
    deleteNode(&head, 7);
    printf("\nLinked List after deleting 7: ");
    displayList(head);
    return 0;
}