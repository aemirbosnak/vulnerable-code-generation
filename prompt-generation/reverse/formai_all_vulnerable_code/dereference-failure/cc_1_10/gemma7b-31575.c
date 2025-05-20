//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    int x;
    int y;
    struct Node* next;
} Node;

void createMaze(Node** head) {
    *head = NULL;
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
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

int main() {
    Node* head = NULL;
    createMaze(&head);

    // Find the route from (0, 0) to (MAX_SIZE - 1, MAX_SIZE - 1)
    Node* current = head;
    current->x = 0;
    current->y = 0;
    while (current->x != MAX_SIZE - 1 || current->y != MAX_SIZE - 1) {
        // Move randomly
        int direction = rand() % 4;
        switch (direction) {
            case 0:
                current->x++;
                break;
            case 1:
                current->y++;
                break;
            case 2:
                current->x--;
                break;
            case 3:
                current->y--;
                break;
        }

        // Check if the cell is free
        if (current->x < 0 || current->x >= MAX_SIZE || current->y < 0 || current->y >= MAX_SIZE) {
            current->x = 0;
            current->y = 0;
        }
    }

    return 0;
}