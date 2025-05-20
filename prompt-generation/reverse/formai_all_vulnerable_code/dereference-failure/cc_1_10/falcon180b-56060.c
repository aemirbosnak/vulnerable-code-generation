//Falcon-180B DATASET v1.0 Category: Recursive ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct Node *next;
} Node;

Node *createNode(int data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addNode(Node **head, int data) {
    Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node *temp = *head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteNode(Node **head, int data) {
    Node *temp = *head;
    if (temp!= NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp!= NULL && temp->data!= data) {
        temp = temp->next;
    }
    if (temp == NULL) {
        return;
    }
    Node *nextNode = temp->next;
    temp->next = nextNode->next;
    free(nextNode);
}

void printList(Node *head) {
    Node *temp = head;
    while (temp!= NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node *head = NULL;
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    printList(head);

    deleteNode(&head, 2);
    printList(head);

    deleteNode(&head, 1);
    printList(head);

    deleteNode(&head, 3);
    printList(head);

    return 0;
}