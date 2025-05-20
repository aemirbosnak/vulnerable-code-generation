//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    char data[MAX_SIZE];
    struct node* next;
} Node;

Node* createNode(char* data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

void addNode(Node** head, char* data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* currNode = *head;
    while (currNode->next!= NULL) {
        currNode = currNode->next;
    }
    currNode->next = newNode;
}

void printList(Node* head) {
    Node* currNode = head;
    while (currNode!= NULL) {
        printf("%s -> ", currNode->data);
        currNode = currNode->next;
    }
    printf("NULL\n");
}

void deleteNode(Node** head, char* data) {
    Node* currNode = *head;
    Node* prevNode = NULL;
    while (currNode!= NULL && strcmp(currNode->data, data)!= 0) {
        prevNode = currNode;
        currNode = currNode->next;
    }
    if (currNode == NULL) {
        printf("Node not found.\n");
        return;
    }
    if (prevNode == NULL) {
        *head = currNode->next;
    } else {
        prevNode->next = currNode->next;
    }
    free(currNode);
}

int main() {
    Node* head = NULL;
    addNode(&head, "Hello");
    addNode(&head, "World");
    printList(head);
    deleteNode(&head, "Hello");
    printList(head);
    deleteNode(&head, "World");
    printList(head);
    return 0;
}