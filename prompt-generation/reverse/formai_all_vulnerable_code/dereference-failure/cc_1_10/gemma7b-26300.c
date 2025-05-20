//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct Node {
    char data;
    struct Node* next;
} Node;

typedef struct Maze {
    Node** graph;
    int size;
} Maze;

void createMaze(Maze* maze, int size) {
    maze->graph = (Node**)malloc(size * sizeof(Node*));
    maze->size = size;

    for (int i = 0; i < size; i++) {
        maze->graph[i] = NULL;
    }
}

void insertNode(Node** head, char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

int main() {
    Maze* maze = (Maze*)malloc(sizeof(Maze));
    createMaze(maze, MAX_SIZE);

    insertNode(&maze->graph[0], 'A');
    insertNode(&maze->graph[0], 'B');
    insertNode(&maze->graph[0], 'C');
    insertNode(&maze->graph[1], 'D');
    insertNode(&maze->graph[1], 'E');
    insertNode(&maze->graph[2], 'F');

    // Find the route from A to F
    char current = 'A';
    char target = 'F';

    while (current != target) {
        for (int i = 0; i < maze->size; i++) {
            if (maze->graph[i] && maze->graph[i]->data == current) {
                current = maze->graph[i]->next->data;
            }
        }
    }

    printf("The route from %c to %c is: ", current, target);

    return 0;
}