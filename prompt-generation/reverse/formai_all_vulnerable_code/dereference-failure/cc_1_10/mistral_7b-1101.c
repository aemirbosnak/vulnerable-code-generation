//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 50
#define NODE_SIZE sizeof(struct Node)

typedef struct Node {
    char data[MAX_LEN];
    struct Node *next;
} Node;

Node *createNode(const char *data) {
    Node *newNode = (Node *) malloc(NODE_SIZE);
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

void append(Node **head, Node *newNode) {
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node *current = *head;
    while (current->next != NULL)
        current = current->next;

    current->next = newNode;
}

void printList(const Node *head) {
    if (head == NULL) {
        printf("Empty List\n");
        return;
    }

    Node *current = head;
    while (current != NULL) {
        printf("%s -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main(int argc, char *argv[]) {
    Node *head = NULL;

    if (argc < 2) {
        printf("Usage : %s <data>\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; ++i) {
        Node *newNode = createNode(argv[i]);
        append(&head, newNode);
    }

    printList(head);

    Node *current = head;
    while (current != NULL) {
        Node *temp = current->next;
        free(current);
        current = temp;
    }

    return 0;
}