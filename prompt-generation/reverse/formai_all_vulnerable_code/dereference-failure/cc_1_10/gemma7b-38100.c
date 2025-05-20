//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void createMaze(Node** head) {
    *head = NULL;
    for (int i = 0; i < MAX; i++) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = i + 1;
        newNode->next = NULL;

        if (*head == NULL) {
            *head = newNode;
        } else {
            (*head)->next = newNode;
            *head = newNode;
        }
    }
}

void findRoute(Node* head, int target) {
    if (head == NULL) {
        return;
    }

    if (head->data == target) {
        printf("Route found: ");
        while (head) {
            printf("%d ", head->data);
            head = head->next;
        }
        printf("\n");
        return;
    }

    findRoute(head->next, target);

    if (head->next != NULL) {
        findRoute(head->next, target);
    }
}

int main() {
    Node* head = NULL;
    createMaze(&head);

    findRoute(head, 5);

    return 0;
}