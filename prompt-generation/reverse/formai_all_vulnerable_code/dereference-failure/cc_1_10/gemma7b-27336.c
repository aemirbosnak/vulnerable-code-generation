//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_L 20
#define MAX_H 20

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

Node* newNode(int x, int y) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->next = NULL;
    return node;
}

void solveMaze(char** maze, Node* current) {
    if (maze[current->x][current->y] == 'S') {
        printf("Congratulations! You have reached the end of the maze.\n");
        return;
    }

    if (maze[current->x][current->y] == '#') {
        return;
    }

    maze[current->x][current->y] = 'A';

    Node* next = newNode(current->x - 1, current->y);
    solveMaze(maze, next);

    next = newNode(current->x + 1, current->y);
    solveMaze(maze, next);

    next = newNode(current->x, current->y - 1);
    solveMaze(maze, next);

    next = newNode(current->x, current->y + 1);
    solveMaze(maze, next);

    free(current);
}

int main() {
    char** maze = (char**)malloc(MAX_H * sizeof(char*));
    for (int h = 0; h < MAX_H; h++) {
        maze[h] = (char*)malloc(MAX_L * sizeof(char));
    }

    // Create the maze
    maze[0][0] = 'S';
    maze[0][1] = '#';
    maze[0][2] = '#';
    maze[1][0] = '#';
    maze[1][1] = ' ';
    maze[1][2] = '#';
    maze[2][0] = '#';
    maze[2][1] = ' ';
    maze[2][2] = 'A';

    Node* current = newNode(0, 0);
    solveMaze(maze, current);

    free(maze);
    return 0;
}