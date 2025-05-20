//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: Cryptic
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 20
#define MAZE_HEIGHT 20

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

void generateMaze(Node** maze) {
    time_t seed = time(NULL);
    srand(seed);

    int w = MAZE_WIDTH;
    int h = MAZE_HEIGHT;

    *maze = createNode(0, 0);

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (x == 0 || y == 0 || x == w - 1 || y == h - 1) {
                (*maze)->next = createNode(x, y);
            } else {
                (*maze)->next = createNode(x, y)
                    ? createNode(x, y)
                    : NULL;
            }
            (*maze) = (*maze)->next;
        }
    }

    (*maze)->next = NULL;
}

void traverseMaze(Node* maze) {
    while (maze) {
        printf("(%d, %d) ", maze->x, maze->y);
        maze = maze->next;
    }
}

int main() {
    Node* maze;
    generateMaze(&maze);
    traverseMaze(maze);
    return 0;
}