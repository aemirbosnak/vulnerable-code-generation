//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WIDTH 20
#define MAX_HEIGHT 20

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

void generateMaze(int** maze, int width, int height) {
    srand(time(NULL));
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            maze[x][y] = rand() % 2;
        }
    }
}

void printMaze(int** maze, int width, int height) {
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            printf("%d ", maze[x][y]);
        }
        printf("\n");
    }
}

int main() {
    int width = MAX_WIDTH;
    int height = MAX_HEIGHT;
    int** maze = malloc(width * sizeof(int*));
    for (int i = 0; i < width; i++) {
        maze[i] = malloc(height * sizeof(int));
    }

    generateMaze(maze, width, height);
    printMaze(maze, width, height);

    free(maze);

    return 0;
}