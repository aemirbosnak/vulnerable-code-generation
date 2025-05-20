//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

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
        ((*head)->next = newNode);
        *head = newNode;
    }
}

void findRoute(Node* head, char target) {
    if (head == NULL) {
        return;
    }

    if (head->data == target) {
        printf("Route found: ");
        while (head) {
            printf("%c ", head->data);
            head = head->next;
        }
        printf("\n");
        return;
    }

    findRoute(head->next, target);

    if (head->next == NULL) {
        return;
    }

    findRoute(head->next->next, target);
}

int main() {
    Node* head = NULL;

    insertAtTail(&head, 'a');
    insertAtTail(&head, 'b');
    insertAtTail(&head, 'c');
    insertAtTail(&head, 'd');
    insertAtTail(&head, 'e');
    insertAtTail(&head, 'f');

    findRoute(head, 'f');

    return 0;
}