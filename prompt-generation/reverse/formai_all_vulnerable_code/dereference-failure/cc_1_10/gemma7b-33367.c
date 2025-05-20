//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Maze {
    Node** graph;
    int size;
} Maze;

void createMaze(Maze* maze) {
    maze->graph = (Node**)malloc(maze->size * sizeof(Node*));
    for (int i = 0; i < maze->size; i++) {
        maze->graph[i] = NULL;
    }
}

void addNode(Maze* maze, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (maze->graph[data] == NULL) {
        maze->graph[data] = newNode;
    } else {
        maze->graph[data]->next = newNode;
    }
}

int findRoute(Maze* maze, int start, int end) {
    Node* current = maze->graph[start];

    while (current) {
        if (current->data == end) {
            return 1;
        } else if (current->next) {
            current = current->next;
        } else {
            return 0;
        }
    }

    return 0;
}

int main() {
    Maze* maze = (Maze*)malloc(sizeof(Maze));
    maze->size = MAX_SIZE;
    createMaze(maze);

    addNode(maze, 0);
    addNode(maze, 1);
    addNode(maze, 2);
    addNode(maze, 3);
    addNode(maze, 4);

    if (findRoute(maze, 0, 4) == 1) {
        printf("Route found!");
    } else {
        printf("No route found");
    }

    return 0;
}