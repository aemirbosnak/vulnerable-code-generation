//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* createLinkedList(int size) {
    Node* head = NULL;
    Node* current = NULL;
    int i;

    for (i = 0; i < size; i++) {
        Node* newNode = (Node*) malloc(sizeof(Node));
        newNode->data = i;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            current = head;
        } else {
            current->next = newNode;
            current = current->next;
        }
    }

    return head;
}

Node* searchLinkedList(Node* head, int target) {
    Node* current = head;

    while (current!= NULL && current->data!= target) {
        current = current->next;
    }

    return current;
}

void deleteLinkedList(Node* head) {
    Node* current = head;

    while (current!= NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    Node* linkedList = createLinkedList(MAX_SIZE);
    Node* targetNode = searchLinkedList(linkedList, 42);

    if (targetNode!= NULL) {
        printf("Node with data %d found\n", targetNode->data);
    } else {
        printf("Node with data %d not found\n", 42);
    }

    deleteLinkedList(linkedList);

    return 0;
}