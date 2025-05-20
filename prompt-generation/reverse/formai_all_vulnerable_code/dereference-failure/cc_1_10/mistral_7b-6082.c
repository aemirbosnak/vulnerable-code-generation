//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    char *name;
    struct Node *next;
} Node;

Node *createNode(int data, const char *name) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    size_t len = strlen(name) + 1;
    newNode->name = (char *) malloc(len);
    strcpy(newNode->name, name);
    newNode->next = NULL;
    return newNode;
}

void append(Node **head, int data, const char *name) {
    Node *newNode = createNode(data, name);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void printList(const Node *head) {
    Node *current = head;
    printf("List:\n");
    while (current != NULL) {
        printf("%s: %d -> ", current->name, current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    Node *head = NULL;

    append(&head, 5, "Monkey");
    append(&head, 10, "Elephant");
    append(&head, 15, "Lion");
    append(&head, 20, "Tiger");
    append(&head, 25, "Zebra");

    printList(head);

    Node *current = head;
    while (current != NULL) {
        if (current->data > 15) {
            Node *toDelete = current;
            current = current->next;
            free(toDelete->name);
            free(toDelete);
        } else {
            current = current->next;
        }
    }

    printList(head);

    return 0;
}