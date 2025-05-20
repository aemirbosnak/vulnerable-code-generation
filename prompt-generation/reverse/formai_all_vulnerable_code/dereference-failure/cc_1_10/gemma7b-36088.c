//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 1024

typedef struct Node {
    char name[MAX_SIZE];
    struct Node* next;
} Node;

void insert(Node** head, char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

int search(Node* head, char* name) {
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

    insert(&head, "John Doe");
    insert(&head, "Jane Doe");
    insert(&head, "Peter Pan");

    if (search(head, "Jane Doe") == 1) {
        printf("Jane Doe found.\n");
    } else {
        printf("Jane Doe not found.\n");
    }

    return 0;
}