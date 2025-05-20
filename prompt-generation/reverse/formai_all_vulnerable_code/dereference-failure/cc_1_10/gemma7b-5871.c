//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 20

typedef struct Node {
    int x;
    int y;
    struct Node* next;
} Node;

Node* createNode(int x, int y) {
    Node* node = malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->next = NULL;
    return node;
}

void generateMaze(int** maze, int size) {
    srand(time(NULL));
    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            maze[x][y] = rand() % 2;
        }
    }
}

void printMaze(int** maze, int size) {
    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            printf("%d ", maze[x][y]);
        }
        printf("\n");
    }
}

int main() {
    int size = MAX_SIZE;
    int** maze = malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        maze[i] = malloc(size * sizeof(int));
    }

    generateMaze(maze, size);
    printMaze(maze, size);

    return 0;
}