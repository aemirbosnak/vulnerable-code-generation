//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: modular
#include <stdlib.h>
#include <time.h>

#define MAZE_SIZE 10

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

void generateMaze(Node* node) {
    int x, y;
    srand(time(NULL));
    for (x = 0; x < MAZE_SIZE; x++) {
        for (y = 0; y < MAZE_SIZE; y++) {
            if (rand() % 2 == 0) {
                node = createNode(x, y);
                node->next = NULL;
            }
        }
    }
}

void printMaze(Node* node) {
    int x, y;
    for (x = 0; x < MAZE_SIZE; x++) {
        for (y = 0; y < MAZE_SIZE; y++) {
            if (node) {
                if (node->x == x && node->y == y) {
                    printf("O ");
                } else {
                    printf(". ");
                }
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

int main() {
    Node* node = createNode(0, 0);
    generateMaze(node);
    printMaze(node);

    return 0;
}