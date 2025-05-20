//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 20
#define MAZE_HEIGHT 20

typedef struct Node {
    int x;
    int y;
    struct Node* next;
} Node;

Node* CreateNode(int x, int y) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->next = NULL;
    return node;
}

void GenerateMaze(int** maze, int w, int h) {
    srand(time(NULL));
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            maze[y][x] = rand() % 2;
        }
    }
}

void PrintMaze(int** maze, int w, int h) {
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            printf("%d ", maze[y][x]);
        }
        printf("\n");
    }
}

int main() {
    int** maze = (int**)malloc(MAZE_HEIGHT * sizeof(int*));
    for (int i = 0; i < MAZE_HEIGHT; i++) {
        maze[i] = (int*)malloc(MAZE_WIDTH * sizeof(int));
    }

    GenerateMaze(maze, MAZE_WIDTH, MAZE_HEIGHT);
    PrintMaze(maze, MAZE_WIDTH, MAZE_HEIGHT);

    return 0;
}