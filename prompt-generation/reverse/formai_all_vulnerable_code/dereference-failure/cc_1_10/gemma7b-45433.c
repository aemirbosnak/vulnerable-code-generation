//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAP_SIZE 20

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

void generateMaze(Node** head) {
    int x, y, i, j;
    *head = NULL;

    for (x = 0; x < MAP_SIZE; x++) {
        for (y = 0; y < MAP_SIZE; y++) {
            Node* newNode = malloc(sizeof(Node));
            newNode->x = x;
            newNode->y = y;
            newNode->next = NULL;

            if (*head == NULL) {
                *head = newNode;
            } else {
                (*head)->next = newNode;
                *head = newNode;
            }
        }
    }

    for (i = 0; i < MAP_SIZE; i++) {
        for (j = 0; j < MAP_SIZE; j++) {
            // Randomly choose a direction
            int direction = rand() % 4;

            // Dig a tunnel
            switch (direction) {
                case 0:
                    (*head)->next = malloc(sizeof(Node));
                    ((*head)->next)->x = x + 1;
                    ((*head)->next)->y = y;
                    *head = (*head)->next;
                    break;
                case 1:
                    (*head)->next = malloc(sizeof(Node));
                    ((*head)->next)->x = x - 1;
                    ((*head)->next)->y = y;
                    *head = (*head)->next;
                    break;
                case 2:
                    (*head)->next = malloc(sizeof(Node));
                    ((*head)->next)->x = x;
                    ((*head)->next)->y = y - 1;
                    *head = (*head)->next;
                    break;
                case 3:
                    (*head)->next = malloc(sizeof(Node));
                    ((*head)->next)->x = x;
                    ((*head)->next)->y = y + 1;
                    *head = (*head)->next;
                    break;
            }
        }
    }
}

int main() {
    Node* head = NULL;
    generateMaze(&head);

    // Print the maze
    for (int x = 0; x < MAP_SIZE; x++) {
        for (int y = 0; y < MAP_SIZE; y++) {
            if (head && head->x == x && head->y == y) {
                printf("O ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }

    return 0;
}