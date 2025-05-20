//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

struct Node* Insert(struct Node* head, int x, int y) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    return head;
}

void FindPath(struct Node* head, int targetX, int targetY) {
    struct Node* current = head;
    struct Node* next = NULL;

    while (current) {
        if (current->x == targetX && current->y == targetY) {
            printf("Path found!\n");
            return;
        }

        next = current->next;
        current->next = NULL;

        if (next) {
            current = next;
        } else {
            current = head;
        }
    }

    printf("No path found.\n");
}

int main() {
    struct Node* head = Insert(NULL, 0, 0);
    Insert(head, 1, 0);
    Insert(head, 2, 0);
    Insert(head, 3, 0);
    Insert(head, 4, 0);
    Insert(head, 5, 0);
    Insert(head, 6, 0);
    Insert(head, 7, 0);
    Insert(head, 8, 0);
    Insert(head, 9, 0);

    FindPath(head, 8, 0);

    return 0;
}