//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

typedef struct Node {
    struct Node* up;
    struct Node* right;
    struct Node* down;
    struct Node* left;
    int x;
    int y;
} Node;

Node* createNode(int x, int y) {
    Node* node = malloc(sizeof(Node));
    node->up = NULL;
    node->right = NULL;
    node->down = NULL;
    node->left = NULL;
    node->x = x;
    node->y = y;
    return node;
}

void generateMaze(Node* node) {
    srand(time(NULL));
    int chance = rand() % 2;
    if (chance == 0) {
        node->up = createNode(node->x, node->y - 1);
    }
    chance = rand() % 2;
    if (chance == 0) {
        node->right = createNode(node->x + 1, node->y);
    }
    chance = rand() % 2;
    if (chance == 0) {
        node->down = createNode(node->x, node->y + 1);
    }
    chance = rand() % 2;
    if (chance == 0) {
        node->left = createNode(node->x - 1, node->y);
    }
}

void drawMaze(Node* node) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (node->x == x && node->y == y) {
                printf("O ");
            } else if (node->up || node->right || node->down || node->left) {
                printf(". ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int main() {
    Node* start = createNode(0, 0);
    generateMaze(start);
    drawMaze(start);
    return 0;
}