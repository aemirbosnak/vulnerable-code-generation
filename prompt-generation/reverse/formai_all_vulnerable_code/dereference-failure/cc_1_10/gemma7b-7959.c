//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 50
#define MAZE_HEIGHT 50

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

void GenerateMaze(int** maze, int seed) {
    srand(seed);
    for (int x = 0; x < MAZE_WIDTH; x++) {
        for (int y = 0; y < MAZE_HEIGHT; y++) {
            maze[x][y] = rand() % 2;
        }
    }
}

void PrintMaze(int** maze) {
    for (int x = 0; x < MAZE_WIDTH; x++) {
        for (int y = 0; y < MAZE_HEIGHT; y++) {
            printf("%d ", maze[x][y]);
        }
        printf("\n");
    }
}

int main() {
    int** maze = (int**)malloc(MAZE_WIDTH * sizeof(int*));
    for (int i = 0; i < MAZE_WIDTH; i++) {
        maze[i] = (int*)malloc(MAZE_HEIGHT * sizeof(int));
    }

    GenerateMaze(maze, time(NULL));
    PrintMaze(maze);

    for (int x = 0; x < MAZE_WIDTH; x++) {
        free(maze[x]);
    }
    free(maze);

    return 0;
}