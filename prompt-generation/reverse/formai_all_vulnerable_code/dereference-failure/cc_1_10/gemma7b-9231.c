//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    int x, y;
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

int main() {
    Node* head = NULL;
    insert(&head, 0, 0);
    insert(&head, 1, 1);
    insert(&head, 2, 2);
    insert(&head, 3, 3);

    int x, y;
    printf("Enter the starting point (x, y): ");
    scanf("%d %d", &x, &y);

    printf("Enter the destination point (x, y): ");
    scanf("%d %d", &x, &y);

    Node* current = head;
    while (current) {
        if (current->x == x && current->y == y) {
            printf("Path found!\n");
            break;
        } else {
            current = current->next;
        }
    }

    if (current == NULL) {
        printf("No path found.\n");
    }

    return 0;
}