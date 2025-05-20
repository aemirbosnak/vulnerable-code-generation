//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 5

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

void generateMaze(Node** head) {
    int i, j, r, c;
    srand(time(NULL));

    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            r = rand() % 2;
            c = rand() % 2;
            if (r == 0 && c == 0) {
                Node* newNode = (Node*)malloc(sizeof(Node));
                newNode->x = i;
                newNode->y = j;
                newNode->next = *head;
                *head = newNode;
            }
        }
    }
}

void findRoute(Node* head, int target_x, int target_y) {
    Node* current = head;
    while (current) {
        if (current->x == target_x && current->y == target_y) {
            printf("Path found!\n");
            return;
        } else if (current->x > target_x || current->x < target_x) {
            findRoute(current->next, target_x, target_y);
        } else if (current->y > target_y || current->y < target_y) {
            findRoute(current->next, target_x, target_y);
        } else {
            current = current->next;
        }
    }
    printf("No path found.\n");
}

int main() {
    Node* head = NULL;
    generateMaze(&head);
    findRoute(head, 2, 2);
    return 0;
}