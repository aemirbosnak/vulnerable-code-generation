//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct node {
    char data[MAX_SIZE];
    struct node *next;
} Node;

Node *head = NULL;

void addNode(char *data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void deleteNode(char *data) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (strcmp(head->data, data) == 0) {
        Node *temp = head;
        head = head->next;
        free(temp);
        return;
    }

    Node *temp = head;
    while (temp->next!= NULL && strcmp(temp->next->data, data)!= 0) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("Node not found.\n");
        return;
    }

    Node *nodeToDelete = temp->next;
    temp->next = temp->next->next;
    free(nodeToDelete);
}

void printList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node *temp = head;
    while (temp!= NULL) {
        printf("%s\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    addNode("Hello");
    addNode("World");
    printList();

    deleteNode("Hello");
    printList();

    return 0;
}