//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: Romeo and Juliet
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAZE_WIDTH 50
#define MAZE_HEIGHT 50

#define WALL_CHAR '#'
#define EMPTY_CHAR '.'
#define PLAYER_CHAR 'P'

typedef struct Node {
    struct Node* up;
    struct Node* right;
    struct Node* down;
    struct Node* left;
    int x;
    int y;
} Node;

Node* createNode(int x, int y) {
    Node* node = malloc(sizeof(struct Node));
    node->up = NULL;
    node->right = NULL;
    node->down = NULL;
    node->left = NULL;
    node->x = x;
    node->y = y;
    return node;
}

void generateMaze(Node* node) {
    int r = rand() % 4;
    switch (r) {
        case 0:
            node->up = createNode(node->x, node->y - 1);
            break;
        case 1:
            node->right = createNode(node->x + 1, node->y);
            break;
        case 2:
            node->down = createNode(node->x, node->y + 1);
            break;
        case 3:
            node->left = createNode(node->x - 1, node->y);
            break;
    }
}

void printMaze(Node* node) {
    for (int y = 0; y < MAZE_HEIGHT; y++) {
        for (int x = 0; x < MAZE_WIDTH; x++) {
            if (node->x == x && node->y == y) {
                printf("%c ", PLAYER_CHAR);
            } else if (node->x == x && node->y == y - 1) {
                printf("%c ", WALL_CHAR);
            } else {
                printf("%c ", EMPTY_CHAR);
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    Node* start = createNode(0, 0);
    generateMaze(start);
    printMaze(start);

    return 0;
}