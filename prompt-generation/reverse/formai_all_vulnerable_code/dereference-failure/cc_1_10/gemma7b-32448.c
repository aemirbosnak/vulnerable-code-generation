//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

#define EMPTY 0
#define WALL 1
#define VISITED 2
#define START 3

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

Node* createNode(int x, int y) {
    Node* node = malloc(sizeof(struct Node));
    node->x = x;
    node->y = y;
    node->next = NULL;
    return node;
}

void generateMaze(int** maze, int seed) {
    srand(seed);
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            maze[x][y] = EMPTY;
        }
    }

    int numWalls = rand() % 5;
    for (int i = 0; i < numWalls; i++) {
        int x = rand() % WIDTH;
        int y = rand() % HEIGHT;
        maze[x][y] = WALL;
    }

    maze[0][0] = START;
    maze[WIDTH - 1][HEIGHT - 1] = START;
}

void printMaze(int** maze) {
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            switch (maze[x][y]) {
                case EMPTY:
                    printf(" ");
                    break;
                case WALL:
                    printf("#");
                    break;
                case VISITED:
                    printf("V");
                    break;
                case START:
                    printf("S");
                    break;
            }
        }
        printf("\n");
    }
}

int main() {
    int seed = time(NULL);
    int** maze = malloc(WIDTH * sizeof(int*));
    for (int i = 0; i < WIDTH; i++) {
        maze[i] = malloc(HEIGHT * sizeof(int));
    }

    generateMaze(maze, seed);
    printMaze(maze);

    return 0;
}