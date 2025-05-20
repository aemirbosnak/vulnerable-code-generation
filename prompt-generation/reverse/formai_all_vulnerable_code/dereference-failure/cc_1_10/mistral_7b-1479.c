//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) {
        printf("Memory error: unable to allocate node\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* insertNode(Node *head, int data) {
    Node *newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return head;
    }

    Node *current = head;
    while(current->next != NULL)
        current = current->next;

    current->next = newNode;
    return head;
}

void printList(Node *head) {
    Node *current = head;
    while(current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    Node *head = NULL;
    head = insertNode(head, 1);
    head = insertNode(head, 2);
    head = insertNode(head, 3);
    head = insertNode(head, 4);
    printList(head);

    Node *nodeToDelete = NULL;
    nodeToDelete = head;
    head = nodeToDelete->next;
    free(nodeToDelete);
    printList(head);

    return EXIT_SUCCESS;
}