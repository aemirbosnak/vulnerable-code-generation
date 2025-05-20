//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

Node* createNode(int x, int y) {
    Node* newNode = malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;
    return newNode;
}

void generateMaze(int** maze, int w, int h) {
    int i, j;
    srand(time(NULL));

    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            maze[i][j] = rand() % 2;
        }
    }
}

void printMaze(int** maze, int w, int h) {
    int i, j;
    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int** maze = NULL;
    int w = WIDTH;
    int h = HEIGHT;

    maze = malloc(h * sizeof(int*));
    for (int i = 0; i < h; i++) {
        maze[i] = malloc(w * sizeof(int));
    }

    generateMaze(maze, w, h);
    printMaze(maze, w, h);

    return 0;
}