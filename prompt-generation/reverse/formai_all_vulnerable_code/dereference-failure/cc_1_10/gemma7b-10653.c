//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

void initializeMaze(Node** maze, int size) {
    *maze = (Node*)malloc(size * sizeof(Node));
    for (int i = 0; i < size; i++) {
        (*maze)[i].x = -1;
        (*maze)[i].y = -1;
        (*maze)[i].next = NULL;
    }
}

void insertIntoMaze(Node** maze, int x, int y) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;

    if ((*maze)[x].y == -1) {
        (*maze)[x].y = y;
    } else {
        ((*maze)[x].next) = newNode;
        (*maze)[x].next = newNode;
    }
}

void findMazeRoute(Node* current, Node* end) {
    if (current == end) {
        return;
    }

    printf("(%d, %d) -> ", current->x, current->y);

    findMazeRoute(current->next, end);

    return;
}

int main() {
    int size = MAX_SIZE;
    Node** maze = NULL;

    initializeMaze(maze, size);

    insertIntoMaze(maze, 0, 0);
    insertIntoMaze(maze, 1, 0);
    insertIntoMaze(maze, 2, 0);
    insertIntoMaze(maze, 2, 1);
    insertIntoMaze(maze, 2, 2);
    insertIntoMaze(maze, 3, 2);

    Node* current = maze[0];
    Node* end = maze[3];

    findMazeRoute(current, end);

    return 0;
}