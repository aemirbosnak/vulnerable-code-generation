//Gemma-7B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

void initialize(Node** head) {
    *head = NULL;
}

void insert(Node** head, int x, int y) {
    Node* newNode = malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

int distance(int x1, int y1, int x2, int y2) {
    return abs(x2 - x1) + abs(y2 - y1);
}

int main() {
    Node* head = NULL;

    initialize(&head);
    insert(&head, 0, 0);
    insert(&head, 1, 1);
    insert(&head, 2, 2);
    insert(&head, 3, 3);

    int targetX = 2;
    int targetY = 2;

    int currentX = 0;
    int currentY = 0;

    int cost = distance(currentX, currentY, targetX, targetY);

    while (cost > 0) {
        int dx = 1;
        int dy = 1;

        for (int i = 0; i < dx; i++) {
            for (int j = 0; j < dy; j++) {
                int newX = currentX + i;
                int newY = currentY + j;

                if (newX >= 0 && newX < MAX_SIZE && newY >= 0 && newY < MAX_SIZE) {
                    int newCost = distance(newX, newY, targetX, targetY);

                    if (newCost < cost) {
                        currentX = newX;
                        currentY = newY;
                        cost = newCost;
                    }
                }
            }
        }

        currentX++;
        currentY++;
    }

    printf("Path found: (%d, %d) to (%d, %d) = %d\n", currentX, currentY, targetX, targetY, cost);

    return 0;
}