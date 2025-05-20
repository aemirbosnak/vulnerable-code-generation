//Gemma-7B DATASET v1.0 Category: Memory management ; Style: all-encompassing
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_ALLOC 10

typedef struct Node {
    char *data;
    struct Node *next;
} Node;

Node *head = NULL;

void insert(char *data) {
    Node *newNode = malloc(sizeof(Node));
    newNode->data = strdup(data);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node *temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void traverse() {
    Node *temp = head;
    while (temp) {
        printf("%s ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    insert("John");
    insert("Mary");
    insert("Bob");
    insert("Alice");

    traverse();

    free(head);

    return 0;
}