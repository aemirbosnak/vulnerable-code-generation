//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: curious
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 10
#define MAZE_HEIGHT 10

typedef struct Node {
    struct Node* up;
    struct Node* down;
    struct Node* left;
    struct Node* right;
    int x;
    int y;
} Node;

Node* createNode(int x, int y) {
    Node* node = malloc(sizeof(struct Node));
    node->up = NULL;
    node->down = NULL;
    node->left = NULL;
    node->right = NULL;
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
    if (chance == 1) {
        node->right = createNode(node->x + 1, node->y);
    }
}

void drawMaze(Node* node) {
    system("clear");
    for (int y = 0; y < MAZE_HEIGHT; y++) {
        for (int x = 0; x < MAZE_WIDTH; x++) {
            if (node->x == x && node->y == y) {
                printf("O ");
            } else if (node->up && node->up->x == x && node->up->y == y) {
                printf("-" " ");
            } else if (node->right && node->right->x == x && node->right->y == y) {
                printf("-- " );
            } else {
                printf(". " );
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