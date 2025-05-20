//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: authentic
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
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* insertAtEnd(Node* head, int data) {
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

Node* insertAtBeginning(Node* head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
    return head;
}

Node* insertAtPosition(Node* head, int data, int position) {
    Node* newNode = createNode(data);
    Node* temp = head;
    if (position == 1) {
        newNode->next = head;
        head = newNode;
        return head;
    }
    for (int i = 1; i < position - 1 && temp!= NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position\n");
        return head;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

int deleteNode(Node* head, int data) {
    Node* temp = head;
    Node* prev = NULL;
    if (head!= NULL && head->data == data) {
        head = head->next;
        free(temp);
        return 1;
    }
    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        return 0;
    }
    prev->next = temp->next;
    free(temp);
    return 1;
}

void displayList(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    head = insertAtEnd(head, 1);
    head = insertAtBeginning(head, 2);
    head = insertAtBeginning(head, 3);
    head = insertAtPosition(head, 4, 2);
    displayList(head);
    deleteNode(head, 2);
    displayList(head);
    deleteNode(head, 4);
    displayList(head);
    return 0;
}