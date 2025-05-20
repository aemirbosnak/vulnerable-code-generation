//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* createNode(int data);
Node* insertNode(Node* head, int data);
Node* deleteNode(Node* head, int data);
void printList(Node* head);

int main() {
    Node* head = NULL;

    head = insertNode(head, 5);
    printList(head);

    head = insertNode(head, 3);
    printList(head);

    head = deleteNode(head, 5);
    printList(head);

    head = insertNode(head, 7);
    printList(head);

    head = deleteNode(head, 3);
    printList(head);

    return 0;
}

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

Node* insertNode(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return head;
    }
    Node* temp = head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

Node* deleteNode(Node* head, int data) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    if (head->data == data) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node* temp = head;
    while (temp->next!= NULL && temp->next->data!= data) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        printf("Element not found\n");
        return head;
    }
    Node* delNode = temp->next;
    temp->next = temp->next->next;
    free(delNode);
    return head;
}

void printList(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}