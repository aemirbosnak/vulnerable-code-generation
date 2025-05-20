//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: intelligent
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
    Node* node = malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->next = NULL;
    return node;
}

void generateMaze(int** maze, int width, int height) {
    srand(time(NULL));
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            maze[x][y] = EMPTY;
        }
    }

    int numWalls = rand() % (width * height) / 2;
    for (int i = 0; i < numWalls; i++) {
        int x = rand() % width;
        int y = rand() % height;
        if (maze[x][y] == EMPTY) {
            maze[x][y] = WALL;
        }
    }

    maze[0][0] = START;
}

void printMaze(int** maze, int width, int height) {
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
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
    int** maze = (int**)malloc(WIDTH * sizeof(int*));
    for (int i = 0; i < WIDTH; i++) {
        maze[i] = (int*)malloc(HEIGHT * sizeof(int));
    }

    generateMaze(maze, WIDTH, HEIGHT);
    printMaze(maze, WIDTH, HEIGHT);

    return 0;
}