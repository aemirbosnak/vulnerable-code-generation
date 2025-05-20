//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

void createMaze(Node** head) {
    int i, j;
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            *head = malloc(sizeof(Node));
            (*head)->x = i;
            (*head)->y = j;
            (*head)->next = NULL;
            head = &((*head)->next);
        }
    }
}

void findRoute(Node* head, int target_x, int target_y) {
    if (head == NULL) {
        return;
    }

    if (head->x == target_x && head->y == target_y) {
        printf("Route found!\n");
        return;
    }

    findRoute(head->next, target_x, target_y);

    if (head->x - target_x > 0) {
        printf("Move right\n");
    } else if (head->x - target_x < 0) {
        printf("Move left\n");
    }

    if (head->y - target_y > 0) {
        printf("Move down\n");
    } else if (head->y - target_y < 0) {
        printf("Move up\n");
    }
}

int main() {
    Node* head = NULL;
    createMaze(&head);

    findRoute(head, 5, 5);

    return 0;
}