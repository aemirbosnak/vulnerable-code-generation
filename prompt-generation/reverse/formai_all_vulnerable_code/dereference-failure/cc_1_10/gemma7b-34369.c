//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_SIZE 100

typedef struct Node {
    char name[MAX_SIZE];
    struct Node* next;
} Node;

Node* InsertAtTail(Node* head, char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

int SearchByName(Node* head, char* name) {
    while (head) {
        if (strcmp(head->name, name) == 0) {
            return 1;
        }
        head = head->next;
    }

    return 0;
}

int main() {
    Node* head = NULL;

    InsertAtTail(head, "John Doe");
    InsertAtTail(head, "Jane Doe");
    InsertAtTail(head, "Peter Pan");

    if (SearchByName(head, "John Doe") == 1) {
        printf("John Doe found.\n");
    }

    if (SearchByName(head, "Peter Pan") == 1) {
        printf("Peter Pan found.\n");
    }

    return 0;
}