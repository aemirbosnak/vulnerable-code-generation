//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Node {
    char name[MAX];
    struct Node* next;
} Node;

Node* insert(Node* head, char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = insert(head->next, name);
    }

    return head;
}

int search(Node* head, char* name) {
    while (head) {
        if (strcmp(head->name, name) == 0) {
            return 1;
        } else {
            head = head->next;
        }
    }

    return 0;
}

int main() {
    Node* head = NULL;

    insert(head, "John Doe");
    insert(head, "Jane Doe");
    insert(head, "Jack Doe");

    if (search(head, "Jane Doe") == 1) {
        printf("Jane Doe is found.\n");
    } else {
        printf("Jane Doe is not found.\n");
    }

    return 0;
}