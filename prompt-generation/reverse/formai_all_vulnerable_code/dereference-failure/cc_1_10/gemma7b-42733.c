//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

void createMaze(Node** head) {
    int i, j, r, c;
    Node* newNode;

    r = rand() % MAX_SIZE;
    c = rand() % MAX_SIZE;

    newNode = malloc(sizeof(Node));
    newNode->x = r;
    newNode->y = c;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }

    createMaze(head);
}

void findRoute(Node* head) {
    int x, y, dx, dy, i, j;
    Node* current, *next;

    current = head;
    dx = 1;
    dy = 0;

    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            next = current->next;

            if (next != NULL && next->x == x + dx && next->y == y + dy) {
                current = next;
                x += dx;
                y += dy;
            } else {
                dx = -dx;
                dy = 1;
            }
        }
    }

    printf("The route is: (%d, %d) -> ", current->x, current->y);
}

int main() {
    Node* head = NULL;

    createMaze(&head);
    findRoute(head);

    return 0;
}