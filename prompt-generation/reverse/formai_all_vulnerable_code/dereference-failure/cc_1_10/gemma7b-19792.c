//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Node {
    char name[MAX_SIZE];
    struct Node* next;
} Node;

void insertAtTail(Node** head, char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void printList(Node* head) {
    while (head) {
        printf("%s ", head->name);
        head = head->next;
    }
    printf("\n");
}

void search(Node* head, char* name) {
    if (head == NULL) {
        return;
    }

    if (strcmp(head->name, name) == 0) {
        printf("Found: %s\n", head->name);
    } else if (strcmp(head->name, name) > 0) {
        search(head->next, name);
    }
}

int main() {
    Node* head = NULL;

    insertAtTail(&head, "John");
    insertAtTail(&head, "Mary");
    insertAtTail(&head, "Bob");
    insertAtTail(&head, "Alice");

    printList(head);

    search(head, "Mary");

    return 0;
}