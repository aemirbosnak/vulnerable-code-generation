//Gemma-7B DATASET v1.0 Category: Pathfinding algorithms ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

void printMap(Node* head) {
    Node* current = head;
    while (current) {
        printf("(%d, %d) ", current->x, current->y);
        current = current->next;
    }
    printf("\n");
}

void findPath(int x, int y, Node** head) {
    if (*head == NULL) {
        *head = (Node*)malloc(sizeof(Node));
        (*head)->x = x;
        (*head)->y = y;
        (*head)->next = NULL;
    }

    Node* current = *head;
    while (current) {
        if (current->x == x && current->y == y) {
            return;
        } else if (current->x == x - 1 && current->y == y) {
            current->next = (Node*)malloc(sizeof(Node));
            current->next->x = x;
            current->next->y = y;
            current->next->next = NULL;
            current = current->next;
        } else if (current->x == x + 1 && current->y == y) {
            current->next = (Node*)malloc(sizeof(Node));
            current->next->x = x;
            current->next->y = y;
            current->next->next = NULL;
            current = current->next;
        } else if (current->x == x && current->y == y - 1) {
            current->next = (Node*)malloc(sizeof(Node));
            current->next->x = x;
            current->next->y = y;
            current->next->next = NULL;
            current = current->next;
        } else if (current->x == x && current->y == y + 1) {
            current->next = (Node*)malloc(sizeof(Node));
            current->next->x = x;
            current->next->y = y;
            current->next->next = NULL;
            current = current->next;
        }
    }

    return;
}

int main() {
    Node* head = NULL;
    findPath(1, 1, &head);
    findPath(2, 2, &head);
    findPath(3, 3, &head);
    printMap(head);

    return 0;
}