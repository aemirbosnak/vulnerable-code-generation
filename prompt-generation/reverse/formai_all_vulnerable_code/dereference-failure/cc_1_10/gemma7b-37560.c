//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: accurate
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
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->x = i;
            newNode->y = j;
            newNode->next = NULL;
            *head = newNode;
            head = &newNode->next;
        }
    }
}

void findRoute(Node* head) {
    int x, y;
    srand(time(NULL));
    x = rand() % MAX_SIZE;
    y = rand() % MAX_SIZE;
    printf("Starting point: (%d, %d)\n", x, y);

    while (head) {
        if (head->x == x && head->y == y) {
            printf("Goal reached: (%d, %d)\n", head->x, head->y);
            break;
        } else {
            head = head->next;
        }
    }

    if (head == NULL) {
        printf("No route found.\n");
    }
}

int main() {
    Node* head = NULL;
    createMaze(&head);
    findRoute(head);

    return 0;
}