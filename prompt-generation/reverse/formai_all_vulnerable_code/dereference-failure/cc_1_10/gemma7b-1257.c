//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct Node {
    char name[20];
    int index;
    struct Node* next;
} Node;

void insert(Node** head, char* name, int index) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->index = index;
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
            return head->index;
        } else {
            head = head->next;
        }
    }

    return -1;
}

int main() {
    Node* head = NULL;
    insert(&head, "John Doe", 1);
    insert(&head, "Jane Doe", 2);
    insert(&head, "Jack Doe", 3);
    insert(&head, "Jill Doe", 4);

    int index = search(head, "Jane Doe");
    if (index != -1) {
        printf("Index of Jane Doe: %d", index);
    } else {
        printf("Jane Doe not found");
    }

    return 0;
}