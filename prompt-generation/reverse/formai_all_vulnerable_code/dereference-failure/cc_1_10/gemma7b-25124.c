//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: artistic
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 20
#define MAZE_HEIGHT 20

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

Node* CreateNode(int x, int y) {
    Node* node = malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->next = NULL;
    return node;
}

void GenerateMaze() {
    srand(time(NULL));
    int** maze = malloc(MAZE_HEIGHT * sizeof(int*));
    for (int i = 0; i < MAZE_HEIGHT; i++) {
        maze[i] = malloc(MAZE_WIDTH * sizeof(int));
        for (int j = 0; j < MAZE_WIDTH; j++) {
            maze[i][j] = 0;
        }
    }

    // Create the maze walls
    for (int i = 0; i < MAZE_HEIGHT; i++) {
        for (int j = 0; j < MAZE_WIDTH; j++) {
            if (i == 0 || j == 0 || i == MAZE_HEIGHT - 1 || j == MAZE_WIDTH - 1) {
                maze[i][j] = 1;
            }
        }
    }

    // Randomly remove some walls
    for (int i = 0; i < 50; i++) {
        int x = rand() % MAZE_WIDTH;
        int y = rand() % MAZE_HEIGHT;
        if (maze[y][x] == 1) {
            maze[y][x] = 0;
        }
    }

    // Free the memory
    for (int i = 0; i < MAZE_HEIGHT; i++) {
        free(maze[i]);
    }
    free(maze);
}

int main() {
    GenerateMaze();
    return 0;
}