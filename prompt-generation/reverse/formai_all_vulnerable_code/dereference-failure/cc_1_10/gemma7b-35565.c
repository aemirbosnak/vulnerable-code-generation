//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 10
#define MAZE_HEIGHT 10

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

void generateMaze(Node** head) {
    // Allocate memory for the maze
    *head = (Node*)malloc(sizeof(Node));
    (*head)->x = 0;
    (*head)->y = 0;
    (*head)->next = NULL;

    // Create the maze walls
    for (int i = 0; i < MAZE_WIDTH; i++) {
        for (int j = 0; j < MAZE_HEIGHT; j++) {
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->x = i;
            newNode->y = j;
            newNode->next = NULL;

            if (i == 0 || j == 0 || i == MAZE_WIDTH - 1 || j == MAZE_HEIGHT - 1) {
                (*head)->next = newNode;
                *head = newNode;
            } else {
                (*head)->next = newNode;
                *head = newNode;
            }
        }
    }

    // Randomly remove some walls
    srand(time(NULL));
    int numWallsToRemove = rand() % 5;
    for (int i = 0; i < numWallsToRemove; i++) {
        Node* wall = (*head)->next;
        (*head)->next = wall->next;
        free(wall);
    }
}

void findRoute(Node* head, int targetX, int targetY) {
    // Traverse the maze
    while (head) {
        if (head->x == targetX && head->y == targetY) {
            // Route found!
            printf("Path found!\n");
            return;
        } else if (head->x < targetX) {
            findRoute(head->next, targetX, targetY);
        } else if (head->y < targetY) {
            findRoute(head, targetX, targetY);
        } else if (head->x > targetX) {
            findRoute(head->next, targetX, targetY);
        } else if (head->y > targetY) {
            findRoute(head, targetX, targetY);
        }
        head = head->next;
    }

    // No route found
    printf("No route found.\n");
}

int main() {
    // Generate the maze
    Node* head = NULL;
    generateMaze(&head);

    // Find the route
    findRoute(head, 5, 5);

    return 0;
}