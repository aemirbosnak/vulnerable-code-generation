//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int maze[MAX_SIZE][MAX_SIZE] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 1, 1, 1, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 0, 1, 1, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

typedef struct Node {
    int x, y;
    struct Node *parent;
} Node;

Node *start, *end;

void printPath(Node *current) {
    if (current->parent == NULL) {
        printf("[%d, %d]", current->x, current->y);
        return;
    }

    printPath(current->parent);
    printf(" -> [%d, %d]", current->x, current->y);
}

void traverseMaze(Node *current) {
    int x = current->x, y = current->y;

    // Check if current node is the end node
    if (x == end->x && y == end->y) {
        printf("Path found: ");
        printPath(current);
        printf("\n");
        return;
    }

    // Check if current node is within the bounds of the maze and is a valid path
    if (x < 0 || y < 0 || x >= MAX_SIZE || y >= MAX_SIZE || maze[x][y] == 1) {
        return;
    }

    // Mark current node as visited
    maze[x][y] = 1;

    // Check all adjacent nodes
    Node *adjacentNodes[4];

    int numAdjacentNodes = 0;

    // Up
    Node *up = (Node *) malloc(sizeof(Node));
    up->x = x - 1;
    up->y = y;
    up->parent = current;
    adjacentNodes[numAdjacentNodes++] = up;

    // Down
    Node *down = (Node *) malloc(sizeof(Node));
    down->x = x + 1;
    down->y = y;
    down->parent = current;
    adjacentNodes[numAdjacentNodes++] = down;

    // Left
    Node *left = (Node *) malloc(sizeof(Node));
    left->x = x;
    left->y = y - 1;
    left->parent = current;
    adjacentNodes[numAdjacentNodes++] = left;

    // Right
    Node *right = (Node *) malloc(sizeof(Node));
    right->x = x;
    right->y = y + 1;
    right->parent = current;
    adjacentNodes[numAdjacentNodes++] = right;

    for (int i = 0; i < numAdjacentNodes; i++) {
        traverseMaze(adjacentNodes[i]);
    }
}

int main() {
    // Set starting position and end position
    start = (Node *) malloc(sizeof(Node));
    start->x = 1;
    start->y = 1;

    end = (Node *) malloc(sizeof(Node));
    end->x = 8;
    end->y = 8;

    // Traverse maze to find path
    traverseMaze(start);

    return 0;
}