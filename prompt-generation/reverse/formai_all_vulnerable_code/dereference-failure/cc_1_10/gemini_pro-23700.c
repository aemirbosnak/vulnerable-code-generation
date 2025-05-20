//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node *createNode(int value) {
    Node *node = malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    return node;
}

void appendNode(Node **head, Node *node) {
    if (*head == NULL) {
        *head = node;
    } else {
        Node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = node;
    }
}

void printList(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

void reverseList(Node **head) {
    if (*head == NULL) {
        return;
    }
    Node *prev = NULL;
    Node *current = *head;
    Node *next;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

int main() {
    Node *head = NULL;
    appendNode(&head, createNode(1));
    appendNode(&head, createNode(2));
    appendNode(&head, createNode(3));
    appendNode(&head, createNode(4));
    appendNode(&head, createNode(5));
    printList(head);
    reverseList(&head);
    printList(head);
    return 0;
}