//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

void createMaze(Node** head) {
    int i, j;
    *head = (Node*)malloc(sizeof(Node));
    (*head)->x = 0;
    (*head)->y = 0;
    (*head)->next = NULL;

    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->x = i;
            newNode->y = j;
            newNode->next = NULL;

            (*head)->next = newNode;
            (*head) = newNode;
        }
    }
}

void findRoute(Node* head) {
    time_t start = time(NULL);

    while (head) {
        if (head->x == MAX_SIZE - 1 && head->y == MAX_SIZE - 1) {
            printf("Route found in %f seconds.\n", time(NULL) - start);
            return;
        }

        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};

        for (int i = 0; i < 4; i++) {
            int newX = head->x + dx[i];
            int newY = head->y + dy[i];

            if (newX >= 0 && newX < MAX_SIZE && newY >= 0 && newY < MAX_SIZE && head->next == NULL) {
                head->next = (Node*)malloc(sizeof(Node));
                head->next->x = newX;
                head->next->y = newY;
                head = head->next;
            }
        }
    }

    printf("No route found.\n");
}

int main() {
    Node* head = NULL;
    createMaze(&head);
    findRoute(head);

    return 0;
}