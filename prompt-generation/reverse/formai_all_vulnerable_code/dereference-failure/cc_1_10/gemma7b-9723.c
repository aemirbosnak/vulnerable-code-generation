//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WIDTH 50
#define MAX_HEIGHT 50

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

Node* createNode(int x, int y) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->next = NULL;
    return node;
}

void generateMaze(int** maze, int width, int height) {
    srand(time(NULL));

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            maze[y][x] = rand() % 2 == 0 ? 1 : 0;
        }
    }
}

void printMaze(int** maze, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            printf("%d ", maze[y][x]);
        }
        printf("\n");
    }
}

int main() {
    int width = MAX_WIDTH;
    int height = MAX_HEIGHT;
    int** maze = (int**)malloc(height * sizeof(int*));
    for (int i = 0; i < height; i++) {
        maze[i] = (int*)malloc(width * sizeof(int));
    }

    generateMaze(maze, width, height);
    printMaze(maze, width, height);

    free(maze);

    return 0;
}