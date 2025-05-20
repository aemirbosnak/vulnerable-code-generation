//FormAI DATASET v1.0 Category: Linked list operations ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void append(Node **head, int data) {
    Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node *lastNode = *head;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
}

void traverse(Node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

bool contains(Node *head, int data) {
    while (head != NULL) {
        if (head->data == data) {
            return true;
        }
        head = head->next;
    }
    return false;
}

void delete(Node **head, int data) {
    if (*head == NULL) {
        return;
    }

    Node *prevNode = NULL;
    Node *currNode = *head;
    while (currNode != NULL && currNode->data != data) {
        prevNode = currNode;
        currNode = currNode->next;
    }

    if (currNode == NULL) {
        return;
    }

    if (prevNode == NULL) {
        *head = currNode->next;
    } else {
        prevNode->next = currNode->next;
    }
    free(currNode);
}

int main() {
    Node *head = NULL;
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    append(&head, 40);
    traverse(head);

    printf("\nIs 20 in the list? %s\n", contains(head, 20) ? "Yes" : "No");
    delete(&head, 20);
    printf("After deletion of 20: ");
    traverse(head);
    printf("\nIs 20 in the list? %s", contains(head, 20) ? "Yes" : "No");

    return 0;
}