//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Node {
    char data;
    struct Node* next;
} Node;

void insertAtTail(Node** head, char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void findRoute(Node* head, char target) {
    if (head == NULL) {
        return;
    }

    if (head->data == target) {
        printf("Route found!\n");
        return;
    }

    findRoute(head->next, target);

    if (head->next != NULL) {
        if (head->data != target) {
            printf("No route found.\n");
        }
    }
}

int main() {
    Node* head = NULL;
    insertAtTail(&head, 'a');
    insertAtTail(&head, 'b');
    insertAtTail(&head, 'c');
    insertAtTail(&head, 'd');
    insertAtTail(&head, 'e');

    findRoute(head, 'c');

    return 0;
}