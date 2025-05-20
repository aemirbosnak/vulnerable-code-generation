//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_NAME_LENGTH 255

typedef struct Node {
    char name[MAX_NAME_LENGTH];
    struct Node* next;
} Node;

Node* insertNode(Node* head, char* name) {
    Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    head->next = newNode;
    return newNode;
}

void deleteNode(Node* head, char* name) {
    Node* previous = NULL;
    Node* current = head;

    while (current) {
        if (strcmp(current->name, name) == 0) {
            if (previous) {
                previous->next = current->next;
            } else {
                head = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }

    return;
}

int main() {
    Node* head = NULL;

    // Insert nodes
    insertNode(head, "John Doe");
    insertNode(head, "Jane Doe");
    insertNode(head, "Bob Smith");

    // Delete nodes
    deleteNode(head, "Jane Doe");
    deleteNode(head, "Bob Smith");

    // Print remaining nodes
    Node* current = head;
    while (current) {
        printf("%s\n", current->name);
        current = current->next;
    }

    return 0;
}