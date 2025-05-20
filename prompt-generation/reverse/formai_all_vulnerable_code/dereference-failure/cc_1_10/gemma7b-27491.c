//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 20

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

void CreateMaze(Node** head) {
    int i, j;
    *head = NULL;
    for (i = 0; i < MAP_SIZE; i++) {
        for (j = 0; j < MAP_SIZE; j++) {
            Node* newNode = malloc(sizeof(Node));
            newNode->x = i;
            newNode->y = j;
            newNode->next = NULL;
            if (*head == NULL) {
                *head = newNode;
            } else {
                (*head)->next = newNode;
                *head = newNode;
            }
        }
    }
}

void FindRoute(Node* head, int targetX, int targetY) {
    int x, y;
    Node* current = head;
    while (current) {
        x = current->x;
        y = current->y;
        if (x == targetX && y == targetY) {
            printf("Route found!\n");
            return;
        }
        if (x - 1 >= 0 && current->next && current->next->x != targetX) {
            current = current->next;
        } else if (x + 1 < MAP_SIZE && current->next && current->next->x != targetX) {
            current = current->next;
        } else if (y - 1 >= 0 && current->next && current->next->y != targetY) {
            current = current->next;
        } else if (y + 1 < MAP_SIZE && current->next && current->next->y != targetY) {
            current = current->next;
        } else {
            current = current->next;
        }
    }
    printf("No route found.\n");
}

int main() {
    Node* head = NULL;
    CreateMaze(&head);
    FindRoute(head, 5, 5);
    return 0;
}