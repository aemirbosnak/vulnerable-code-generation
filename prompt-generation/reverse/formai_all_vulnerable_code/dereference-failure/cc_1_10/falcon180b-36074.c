//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: Ada Lovelace
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
    Node* temp = head;
    Node* prev = NULL;
    if (temp!= NULL && temp->data == data) {
        head = temp->next;
        free(temp);
        return head;
    }
    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Element not found\n");
        return head;
    }
    prev->next = temp->next;
    free(temp);
    return head;
}

void displayList(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    Node* head = NULL;
    head = insertNode(head, 5);
    head = insertNode(head, 10);
    head = insertNode(head, 15);
    displayList(head);
    head = deleteNode(head, 10);
    displayList(head);
    return 0;
}