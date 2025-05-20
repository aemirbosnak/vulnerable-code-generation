//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    int x;
    int y;
    struct Node* next;
} Node;

void createMaze(Node** head, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            Node* newNode = (Node*)malloc(sizeof(Node));
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

void findRoute(Node* head, int targetX, int targetY) {
    Node* current = head;
    while (current) {
        if (current->x == targetX && current->y == targetY) {
            printf("Path found!\n");
            return;
        } else if (current->x == targetX && current->y != targetY) {
            printf("Moving right...\n");
            current = current->next;
        } else if (current->x != targetX && current->y == targetY) {
            printf("Moving down...\n");
            current = current->next;
        } else {
            printf("Going nowhere...\n");
            current = current->next;
        }
    }

    printf("No path found.\n");
}

int main() {
    Node* head = NULL;
    createMaze(&head, MAX_SIZE);

    findRoute(head, 2, 2);

    return 0;
}