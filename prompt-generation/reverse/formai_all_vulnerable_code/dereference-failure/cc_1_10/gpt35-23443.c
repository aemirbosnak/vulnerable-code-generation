//FormAI DATASET v1.0 Category: Mailing list manager ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char email[50];
    struct Node* next;
} Node;

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%s\n", current->email);
        current = current->next;
    }
}

void insert(Node* head, char email[]) {
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = (Node*) malloc(sizeof(Node));
    strcpy(current->next->email, email);
    current->next->next = NULL;
}

void delete(Node* head, char email[]) {
    Node* current = head;
    Node* previous = NULL;
    while (current != NULL) {
        if (strcmp(current->email, email) == 0) {
            if (previous != NULL) {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

int main() {
    Node* head = (Node*) malloc(sizeof(Node));
    strcpy(head->email, "alice@example.com");
    head->next = NULL;

    insert(head, "bob@example.com");
    insert(head, "charlie@example.com");

    printList(head);

    delete(head, "bob@example.com");

    printList(head);

    return 0;
}