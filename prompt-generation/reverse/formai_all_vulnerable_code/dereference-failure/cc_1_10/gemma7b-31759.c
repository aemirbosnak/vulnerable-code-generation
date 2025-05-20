//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

typedef struct Node {
    int x;
    int y;
    struct Node* next;
} Node;

void createMaze(Node** head) {
    time_t t = time(NULL);
    srand(t);

    int size = rand() % MAX_SIZE + 1;
    *head = malloc(size * sizeof(Node));

    for (int i = 0; i < size; i++) {
        (*head)->x = rand() % MAX_SIZE;
        (*head)->y = rand() % MAX_SIZE;
        (*head)->next = malloc((size - 1) * sizeof(Node));
        head = &((*head)->next);
    }
    *head = NULL;
}

void findRoute(Node* head, int target_x, int target_y) {
    if (head == NULL) {
        return;
    }

    if (head->x == target_x && head->y == target_y) {
        printf("Path found!\n");
        return;
    }

    findRoute(head->next, target_x, target_y);

    if (head->x + 1 == target_x) {
        printf("Move right.\n");
    } else if (head->y + 1 == target_y) {
        printf("Move down.\n");
    } else if (head->x - 1 == target_x) {
        printf("Move left.\n");
    } else if (head->y - 1 == target_y) {
        printf("Move up.\n");
    }
}

int main() {
    Node* head = NULL;
    createMaze(&head);

    findRoute(head, 5, 5);

    return 0;
}