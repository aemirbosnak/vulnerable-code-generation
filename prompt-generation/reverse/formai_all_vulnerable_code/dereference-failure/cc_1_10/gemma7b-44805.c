//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

void createMaze(Node* head) {
    srand(time(NULL));
    int x, y;
    for (x = 0; x < MAX_SIZE; x++) {
        for (y = 0; y < MAX_SIZE; y++) {
            if (rand() % 2 == 0) {
                Node* newNode = malloc(sizeof(Node));
                newNode->x = x;
                newNode->y = y;
                newNode->next = head;
                head = newNode;
            }
        }
    }
}

void findRoute(Node* head) {
    int x, y;
    printf("Enter start x: ");
    scanf("%d", &x);
    printf("Enter start y: ");
    scanf("%d", &y);
    printf("Enter end x: ");
    scanf("%d", &x);
    printf("Enter end y: ");

    Node* current = head;
    while (current) {
        if (current->x == x && current->y == y) {
            printf("Path found!\n");
            break;
        }
        current = current->next;
    }

    if (!current) {
        printf("No path found.\n");
    }
}

int main() {
    Node* head = NULL;
    createMaze(head);
    findRoute(head);

    return 0;
}