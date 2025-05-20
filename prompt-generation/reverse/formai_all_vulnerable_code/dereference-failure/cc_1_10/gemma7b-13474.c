//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct Node {
    int x;
    int y;
    struct Node* next;
} Node;

void createMaze(Node** head, int x, int y) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void findRoute(Node* head, char** maze, int x, int y) {
    if (head == NULL) {
        return;
    }

    if (head->x == x && head->y == y) {
        printf("Path found!");
        return;
    }

    maze[head->x][head->y] = 'S';

    findRoute(head->next, maze, x, y);

    if (maze[x][y] != 'S') {
        maze[head->x][head->y] = 'O';
    }
}

int main() {
    Node* head = NULL;
    char** maze = NULL;

    createMaze(&head, 5, 5);

    maze = (char**)malloc(MAX_SIZE * sizeof(char*));
    for (int i = 0; i < MAX_SIZE; i++) {
        maze[i] = (char*)malloc(MAX_SIZE * sizeof(char));
    }

    findRoute(head, maze, 2, 2);

    return 0;
}