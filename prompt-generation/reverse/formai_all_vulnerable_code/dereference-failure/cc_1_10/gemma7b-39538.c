//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAZE_SIZE 10

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

Node* newNode(int x, int y) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->next = NULL;
    return node;
}

void generateMaze(Node* start) {
    int x, y;
    srand(time(NULL));
    for (x = 0; x < MAZE_SIZE; x++) {
        for (y = 0; y < MAZE_SIZE; y++) {
            if (x == start->x && y == start->y) {
                continue;
            }
            if (rand() % 2 == 0) {
                newNode(x, y);
            }
        }
    }
}

void printMaze(Node* node) {
    int x, y;
    for (x = 0; x < MAZE_SIZE; x++) {
        for (y = 0; y < MAZE_SIZE; y++) {
            if (node->x == x && node->y == y) {
                printf("O ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

int main() {
    Node* start = newNode(0, 0);
    generateMaze(start);
    printMaze(start);
    return 0;
}