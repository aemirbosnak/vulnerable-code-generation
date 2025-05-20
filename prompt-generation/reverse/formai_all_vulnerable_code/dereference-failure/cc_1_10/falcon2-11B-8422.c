//Falcon2-11B DATASET v1.0 Category: Data structures visualization ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node {
    int data;
    struct Node* next;
};

void display(struct Node* head) {
    struct Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* addNodeAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

struct Node* addNodeAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    struct Node* temp = head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

struct Node* addNodeAtPosition(struct Node* head, int position, int data) {
    struct Node* newNode = createNode(data);
    struct Node* temp = head;
    int count = 0;
    while (temp!= NULL && count < position) {
        temp = temp->next;
        count++;
    }
    if (temp == NULL) {
        printf("Invalid position\n");
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return head;
}

int main() {
    struct Node* head = NULL;
    head = addNodeAtBeginning(head, 1);
    head = addNodeAtBeginning(head, 2);
    head = addNodeAtBeginning(head, 3);
    head = addNodeAtBeginning(head, 4);
    head = addNodeAtEnd(head, 5);
    display(head);
    return 0;
}