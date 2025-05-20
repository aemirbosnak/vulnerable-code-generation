//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

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

void search(Node* head, char* name) {
    while (head) {
        if (strcmp(head->name, name) == 0) {
            printf("Name: %s\n", head->name);
            break;
        } else {
            head = head->next;
        }
    }

    if (head == NULL) {
        printf("Name not found.\n");
    }
}

int main() {
    Node* head = NULL;

    insert(&head, "John Doe");
    insert(&head, "Jane Doe");
    insert(&head, "Peter Pan");
    insert(&head, "Mary Poppins");

    search(head, "Jane Doe");
    search(head, "Peter Pan");
    search(head, "Mary Poppins");

    return 0;
}