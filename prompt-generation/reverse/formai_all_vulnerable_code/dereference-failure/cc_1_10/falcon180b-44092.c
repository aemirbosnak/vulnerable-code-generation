//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* appendNode(Node* head, int data) {
    Node* newNode = createNode(data);
    Node* temp = head;
    if (head == NULL) {
        head = newNode;
        return head;
    }
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

Node* prependNode(Node* head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

Node* insertNode(Node* head, int data, int position) {
    Node* newNode = createNode(data);
    Node* temp = head;
    if (position == 1) {
        newNode->next = head;
        return newNode;
    }
    int count = 1;
    while (temp!= NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }
    newNode->next = temp->next;
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
        return head;
    }
    prev->next = temp->next;
    free(temp);
    return head;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    Node* head = NULL;
    head = appendNode(head, 5);
    head = appendNode(head, 10);
    head = prependNode(head, 2);
    head = insertNode(head, 3, 2);
    printList(head);
    head = deleteNode(head, 5);
    printList(head);
    return 0;
}