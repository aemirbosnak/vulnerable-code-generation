//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

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

void insertNode(Node* node, Node* newNode) {
    if (node == NULL) {
        node = newNode;
    } else {
        node->next = newNode;
        node = newNode;
    }
}

void findMazeRoute(int** maze, int x, int y) {
    Node* head = createNode(x, y);
    insertNode(head, createNode(x, y));

    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            if (maze[i][j] == 1 && i != x && j != y) {
                insertNode(head, createNode(i, j));
            }
        }
    }

    Node* current = head;
    while (current) {
        printf("(%d, %d) ", current->x, current->y);
        current = current->next;
    }

    printf("\n");
}

int main() {
    int maze[MAX_SIZE][MAX_SIZE] = {{0, 0, 1, 0, 0},
                              {0, 1, 1, 1, 0},
                              {0, 0, 1, 0, 0},
                              {0, 0, 0, 1, 0},
                              {0, 0, 0, 0, 0}};

    findMazeRoute(maze, 2, 2);

    return 0;
}