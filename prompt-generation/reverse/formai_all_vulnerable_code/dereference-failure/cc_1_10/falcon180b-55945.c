//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: safe
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* addNode(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return head;
    }
    Node* current = head;
    while (current->next!= NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

Node* deleteNode(Node* head, int data) {
    Node* previous = NULL;
    Node* current = head;
    while (current!= NULL && current->data!= data) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Data not found\n");
        return head;
    }
    if (previous == NULL) {
        head = current->next;
        free(current);
        return head;
    }
    previous->next = current->next;
    free(current);
    return head;
}

void displayList(Node* head) {
    Node* current = head;
    while (current!= NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    head = addNode(head, 5);
    head = addNode(head, 10);
    head = addNode(head, 15);
    head = addNode(head, 20);
    displayList(head);
    head = deleteNode(head, 10);
    displayList(head);
    head = deleteNode(head, 5);
    displayList(head);
    head = deleteNode(head, 15);
    displayList(head);
    head = deleteNode(head, 20);
    displayList(head);
    return 0;
}