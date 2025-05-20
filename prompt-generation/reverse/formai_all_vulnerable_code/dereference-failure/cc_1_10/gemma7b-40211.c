//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

void createMaze(Node* head) {
    head = malloc(sizeof(Node));
    head->x = 0;
    head->y = 0;
    head->next = NULL;

    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            Node* newNode = malloc(sizeof(Node));
            newNode->x = i;
            newNode->y = j;
            newNode->next = NULL;

            if (head) {
                head->next = newNode;
                head = newNode;
            } else {
                head = newNode;
            }
        }
    }
}

void findRoute(Node* head, int x, int y) {
    if (head == NULL) {
        return;
    }

    if (head->x == x && head->y == y) {
        printf("Path found!\n");
        return;
    }

    findRoute(head->next, x, y);

    if (head->x - 1 >= 0 && head->y == y) {
        printf("Moving left...\n");
        head->x--;
        findRoute(head, x, y);
    } else if (head->x + 1 < MAX_SIZE && head->y == y) {
        printf("Moving right...\n");
        head->x++;
        findRoute(head, x, y);
    } else if (head->x == x && head->y - 1 >= 0) {
        printf("Moving down...\n");
        head->y--;
        findRoute(head, x, y);
    } else if (head->x == x && head->y + 1 < MAX_SIZE) {
        printf("Moving up...\n");
        head->y++;
        findRoute(head, x, y);
    }
}

int main() {
    Node* head = NULL;
    createMaze(head);

    findRoute(head, 2, 2);

    return 0;
}