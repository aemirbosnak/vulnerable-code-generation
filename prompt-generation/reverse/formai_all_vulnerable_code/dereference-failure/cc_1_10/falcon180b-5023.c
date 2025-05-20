//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *head = NULL;

void push(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        printf("List is empty, node added\n");
    } else {
        printf("Node added\n");
    }
}

void pop() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node *temp = head;
    head = head->next;
    printf("Node deleted\n");
    free(temp);
}

void printList() {
    Node *temp = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("List elements: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void search(int data) {
    Node *temp = head;
    while (temp!= NULL) {
        if (temp->data == data) {
            printf("Node found\n");
            return;
        }
        temp = temp->next;
    }
    printf("Node not found\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    printList();
    search(30);
    pop();
    pop();
    printList();
    return 0;
}