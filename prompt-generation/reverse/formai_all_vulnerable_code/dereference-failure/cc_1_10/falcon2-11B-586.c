//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

void printGraph(Node *head) {
    if (head == NULL) {
        printf("Graph is empty\n");
        return;
    }

    printf("Printing Graph:\n");
    Node *current = head;
    while (current!= NULL) {
        printf("%d --> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory Allocation Failed\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* createGraph(int size) {
    Node *head = NULL;
    Node *current = NULL;
    for (int i = 0; i < size; i++) {
        Node *newNode = createNode(i);
        if (newNode == NULL) {
            return NULL;
        }
        if (head == NULL) {
            head = newNode;
        }
        else {
            current->next = newNode;
            current = newNode;
        }
    }
    return head;
}

int main() {
    int size = 5;
    Node *head = createGraph(size);
    if (head == NULL) {
        printf("Graph Creation Failed\n");
        return 1;
    }
    printGraph(head);
    return 0;
}