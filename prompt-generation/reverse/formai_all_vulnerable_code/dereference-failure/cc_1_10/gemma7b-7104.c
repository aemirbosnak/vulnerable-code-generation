//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
    int x;
    int y;
    struct Node* next;
} Node;

void insert(Node** head, int x, int y) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

int find(Node* head, int x, int y) {
    while (head) {
        if (head->x == x && head->y == y) {
            return 1;
        }
        head = head->next;
    }
    return 0;
}

int main() {
    Node* head = NULL;
    insert(&head, 10, 10);
    insert(&head, 10, 20);
    insert(&head, 20, 20);
    insert(&head, 20, 30);
    insert(&head, 30, 30);

    if (find(head, 20, 30) == 1) {
        printf("Found!");
    } else {
        printf("Not found!");
    }

    return 0;
}