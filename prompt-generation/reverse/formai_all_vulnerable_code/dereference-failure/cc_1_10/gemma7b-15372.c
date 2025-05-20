//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: genius
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

Node* createNode(int x, int y) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->next = NULL;
    return node;
}

void generateMaze(int size) {
    Node* head = createNode(0, 0);
    Node* tail = head;

    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            tail = createNode(x, y);
            head->next = tail;
            head = tail;
        }
    }

    head = tail;

    // Randomly choose walls
    for (int i = 0; i < size * size / 4; i++) {
        Node* randNode = head->next;
        if (randNode) {
            randNode->x = -1;
            randNode->y = -1;
        }
    }

    // Print the maze
    for (Node* node = head; node; node = node->next) {
        if (node->x != -1 && node->y != -1) {
            printf("%c", node->x + 1, node->y + 1);
        } else {
            printf("#");
        }
    }

    printf("\n");
}

int main() {
    generateMaze(MAX_SIZE);
    return 0;
}