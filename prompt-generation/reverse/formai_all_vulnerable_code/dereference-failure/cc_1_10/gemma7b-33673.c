//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 50

typedef struct Node {
    int x;
    int y;
    struct Node* next;
} Node;

Node* createNode(int x, int y) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->next = NULL;
    return node;
}

void generateMaze(Node* head) {
    srand(time(NULL));
    int w, h, x, y;
    w = WIDTH;
    h = HEIGHT;
    for (x = 0; x < w; x++) {
        for (y = 0; y < h; y++) {
            if (rand() % 2 == 0) {
                head = createNode(x, y);
            }
        }
    }
}

void printMaze(Node* head) {
    int x, y;
    for (x = 0; x < WIDTH; x++) {
        for (y = 0; y < HEIGHT; y++) {
            if (head != NULL && head->x == x && head->y == y) {
                printf("O ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

int main() {
    Node* head = NULL;
    generateMaze(head);
    printMaze(head);
    return 0;
}