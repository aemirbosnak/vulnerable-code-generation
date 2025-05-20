//FormAI DATASET v1.0 Category: Linked list operations ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* insert(Node* head, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

Node* delete(Node *head, int data) {
    Node *curr = head;
    Node *prev = NULL;
    while (curr && curr->data != data) {
        prev = curr;
        curr = curr->next;
    }
    if (prev) {
        prev->next = curr->next;
        free(curr);
        return head;
    } else if (curr) {
        Node *newHead = curr->next;
        free(curr);
        return newHead;
    } else {
        return head;
    }
}

void display(Node *head) {
    while (head) {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    Node *head = NULL;
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 4);
    display(head);
    head = delete(head, 3);
    display(head);
    head = delete(head, 1);
    display(head);
    return 0;
}