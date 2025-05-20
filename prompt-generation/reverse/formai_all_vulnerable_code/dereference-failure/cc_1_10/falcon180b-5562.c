//Falcon-180B DATASET v1.0 Category: Memory management ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node* head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
}

void deleteNode(Node* head, int data) {
    Node* curr = head;
    Node* prev = NULL;

    while (curr!= NULL && curr->data!= data) {
        prev = curr;
        curr = curr->next;
    }

    if (curr!= NULL) {
        if (prev == NULL) {
            head = curr->next;
        } else {
            prev->next = curr->next;
        }
        free(curr);
    }
}

int searchNode(Node* head, int data) {
    Node* curr = head;

    while (curr!= NULL) {
        if (curr->data == data) {
            return 1;
        }
        curr = curr->next;
    }

    return 0;
}

void printList(Node* head) {
    Node* curr = head;

    while (curr!= NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
}

int main() {
    Node* head = NULL;

    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 3);

    printList(head);
    printf("\n");

    deleteNode(head, 2);

    printList(head);
    printf("\n");

    int searchData = 3;
    int isFound = searchNode(head, searchData);

    if (isFound) {
        printf("Data found\n");
    } else {
        printf("Data not found\n");
    }

    return 0;
}