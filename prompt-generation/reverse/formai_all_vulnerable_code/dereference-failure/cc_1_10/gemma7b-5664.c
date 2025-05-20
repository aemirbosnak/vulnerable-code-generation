//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: curious
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

Node* createNode(int x, int y) {
    Node* node = malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->next = NULL;
    return node;
}

void generateMaze(int** maze, int w, int h) {
    srand(time(NULL));

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            maze[y][x] = rand() % 2;
        }
    }
}

void printMaze(int** maze, int w, int h) {
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            printf("%d ", maze[y][x]);
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

    for (int i = 0; i < h; i++) {
        free(maze[i]);
    }
    free(maze);

    return 0;
}