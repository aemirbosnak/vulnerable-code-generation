//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: peaceful
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
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            *head = malloc(sizeof(Node));
            (*head)->x = i;
            (*head)->y = j;
            (*head)->next = NULL;
            head++;
        }
    }
}

void findRoute(Node* head) {
    int x, y, dx, dy, visited = 0;
    time_t start_time, end_time;

    start_time = time(NULL);

    for (x = 0; x < MAX_SIZE; x++) {
        for (y = 0; y < MAX_SIZE; y++) {
            if (head->x == x && head->y == y) {
                visited = 1;
            }
            if (visited == 0) {
                dx = rand() % 4 - 2;
                dy = rand() % 4 - 2;
                if (dx == 0 && dy == 0) {
                    continue;
                }
                head->next = malloc(sizeof(Node));
                (head->next)->x = x + dx;
                (head->next)->y = y + dy;
                head->next->next = NULL;
                head = head->next;
            }
        }
    }

    end_time = time(NULL);

    printf("Time taken to find route: %.2lf seconds\n", (double)(end_time - start_time));
}

int main() {
    Node* head = NULL;
    createMaze(&head);
    findRoute(head);

    return 0;
}