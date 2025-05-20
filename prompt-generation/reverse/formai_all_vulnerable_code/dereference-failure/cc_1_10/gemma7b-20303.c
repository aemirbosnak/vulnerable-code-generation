//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct Node {
    int x;
    int y;
    struct Node* next;
} Node;

void insertNode(Node** head, int x, int y) {
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

void findMazeRoute(Node* head) {
    int x, y;
    printf("The route is: ");
    while (head) {
        x = head->x;
        y = head->y;
        printf("(%d, %d) ", x, y);
        head = head->next;
    }
}

int main() {
    Node* head = NULL;
    insertNode(&head, 0, 0);
    insertNode(&head, 1, 0);
    insertNode(&head, 2, 0);
    insertNode(&head, 2, 1);
    insertNode(&head, 2, 2);
    insertNode(&head, 1, 2);
    insertNode(&head, 0, 2);

    findMazeRoute(head);

    return 0;
}