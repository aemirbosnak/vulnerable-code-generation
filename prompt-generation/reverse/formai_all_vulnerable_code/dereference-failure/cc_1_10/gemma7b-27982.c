//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: statistical
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAZE_SIZE 10

typedef struct Node {
    int x;
    int y;
    struct Node* next;
} Node;

void createMaze(Node** head) {
    int i, j;
    *head = NULL;

    for (i = 0; i < MAZE_SIZE; i++) {
        for (j = 0; j < MAZE_SIZE; j++) {
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

    // Randomly choose a start and end point
    srand(time(NULL));
    int startx = rand() % MAZE_SIZE;
    int starty = rand() % MAZE_SIZE;
    int endx = rand() % MAZE_SIZE;
    int endy = rand() % MAZE_SIZE;

    // Traverse the maze
    Node* current = head;
    while (current) {
        if (current->x == startx && current->y == starty) {
            printf("Start: (%d, %d)\n", startx, starty);
        } else if (current->x == endx && current->y == endy) {
            printf("End: (%d, %d)\n", endx, endy);
        } else {
            printf("Current: (%d, %d)\n", current->x, current->y);
        }

        current = current->next;
    }

    return 0;
}