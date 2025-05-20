//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Maze {
    Node* head;
    int size;
} Maze;

void insertAtTail(Maze* maze, int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (maze->head == NULL) {
        maze->head = newNode;
    } else {
        maze->head->next = newNode;
    }

    maze->size++;
}

void findRoute(Maze* maze, int target) {
    Node* current = maze->head;
    while (current) {
        if (current->data == target) {
            printf("Route found!\n");
            return;
        } else if (current->data < target) {
            current = current->next;
        } else {
            printf("No route found.\n");
            return;
        }
    }
}

int main() {
    Maze* maze = malloc(sizeof(Maze));
    maze->head = NULL;
    maze->size = 0;

    insertAtTail(maze, 1);
    insertAtTail(maze, 2);
    insertAtTail(maze, 3);
    insertAtTail(maze, 4);
    insertAtTail(maze, 5);

    findRoute(maze, 4);

    return 0;
}