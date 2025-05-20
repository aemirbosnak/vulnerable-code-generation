//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: active
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

#define WALL 1
#define EMPTY 0

typedef struct Node {
    struct Node* up;
    struct Node* right;
    struct Node* down;
    struct Node* left;
    int x;
    int y;
} Node;

void generateMaze(Node* node) {
    srand(time(NULL));
    int r = rand() % 2;
    if (r == 0) {
        node->up = NULL;
    }
    r = rand() % 2;
    if (r == 0) {
        node->right = NULL;
    }
    r = rand() % 2;
    if (r == 0) {
        node->down = NULL;
    }
    r = rand() % 2;
    if (r == 0) {
        node->left = NULL;
    }
}

void printMaze(Node* node) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (node->x == x && node->y == y) {
                printf("O ");
            } else if (node->up == NULL && node->right == NULL && node->down == NULL && node->left == NULL) {
                printf("W ");
            } else {
                printf("E ");
            }
        }
        printf("\n");
    }
}

int main() {
    Node* node = malloc(sizeof(Node));
    node->x = 0;
    node->y = 0;
    generateMaze(node);
    printMaze(node);
    return 0;
}