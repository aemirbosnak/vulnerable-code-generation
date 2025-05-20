//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

void createMaze(Node** head) {
    *head = malloc(sizeof(Node));
    (*head)->x = 0;
    (*head)->y = 0;
    (*head)->next = NULL;
}

void traverseMaze(Node* head, char** maze, int x, int y) {
    if (maze[x][y] == 'O') {
        return;
    }
    maze[x][y] = 'S';

    if (head->next) {
        traverseMaze(head->next, maze, x + 1, y);
    }
    if (head->next) {
        traverseMaze(head->next, maze, x, y + 1);
    }
}

int main() {
    Node* head = NULL;
    createMaze(&head);

    char** maze = (char**)malloc(MAX_SIZE * MAX_SIZE * sizeof(char));
    for (int i = 0; i < MAX_SIZE; i++) {
        maze[i] = (char*)malloc(MAX_SIZE * sizeof(char));
        for (int j = 0; j < MAX_SIZE; j++) {
            maze[i][j] = '#';
        }
    }

    maze[2][2] = 'O';

    traverseMaze(head, maze, 0, 0);

    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }

    return 0;
}