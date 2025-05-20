//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct Node {
    char data;
    struct Node* next;
} Node;

void insert(Node** head, char data) {
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
        printf("Route found: ");
        while (head) {
            printf("%c ", head->data);
            head = head->next;
        }
        printf("\n");
        return;
    }

    findRoute(head->next, target);

    if (head->next != NULL) {
        insert(&head, head->next->data);
    }
}

int main() {
    Node* head = NULL;
    insert(&head, 'a');
    insert(&head, 'b');
    insert(&head, 'c');
    insert(&head, 'd');
    insert(&head, 'e');

    findRoute(head, 'e');

    return 0;
}