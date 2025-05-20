//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertFront(Node** headRef, int data) {
    Node* newNode = createNode(data);
    newNode->next = (*headRef);
    (*headRef) = newNode;
}

void insertRear(Node** headRef, int data) {
    Node* newNode = createNode(data);
    Node* lastNode = (*headRef);
    while (lastNode->next!= NULL) {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
}

Node* removeFront(Node** headRef) {
    if (*headRef == NULL) {
        return NULL;
    }
    Node* temp = (*headRef);
    (*headRef) = (*headRef)->next;
    free(temp);
    return (*headRef);
}

Node* removeRear(Node** headRef) {
    if (*headRef == NULL) {
        return NULL;
    }
    Node* temp = (*headRef);
    Node* prevNode = NULL;
    while (temp->next!= NULL) {
        prevNode = temp;
        temp = temp->next;
    }
    prevNode->next = NULL;
    free(temp);
    return (*headRef);
}

void printQueue(Node* head) {
    if (head == NULL) {
        printf("Queue is empty.\n");
    } else {
        Node* temp = head;
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    Node* head = NULL;
    insertFront(&head, 1);
    insertFront(&head, 2);
    insertFront(&head, 3);
    insertFront(&head, 4);
    insertRear(&head, 5);
    insertRear(&head, 6);
    insertRear(&head, 7);
    printQueue(head);
    removeFront(&head);
    removeRear(&head);
    printQueue(head);
    removeFront(&head);
    removeRear(&head);
    printQueue(head);
    return 0;
}