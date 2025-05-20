//Falcon-180B DATASET v1.0 Category: Recursive ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addNode(Node *head, int data) {
    Node *newNode = createNode(data);
    Node *tail = head;
    if (head == NULL) {
        head = newNode;
        return;
    }
    while (tail->next!= NULL) {
        tail = tail->next;
    }
    tail->next = newNode;
}

void printList(Node *head) {
    Node *temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void reverseList(Node *head) {
    Node *prev = NULL;
    Node *curr = head;
    while (curr!= NULL) {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

int main() {
    Node *head = NULL;
    addNode(head, 1);
    addNode(head, 2);
    addNode(head, 3);
    addNode(head, 4);
    addNode(head, 5);
    printf("Original list: ");
    printList(head);
    reverseList(head);
    printf("Reversed list: ");
    printList(head);
    return 0;
}