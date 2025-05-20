//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

void createMaze(int** maze, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            maze[i][j] = rand() % 2;
        }
    }
}

void findPath(Node* node, int** maze, int n, int m) {
    if (node->x == n - 1 && node->y == m - 1) {
        return;
    }

    maze[node->x][node->y] = 2;

    findPath(node->next, maze, n, m);

    if (node->x - 1 >= 0 && maze[node->x - 1][node->y] == 0) {
        node->next = malloc(sizeof(Node));
        node->next->x = node->x - 1;
        node->next->y = node->y;
        findPath(node->next, maze, n, m);
    }

    if (node->y - 1 >= 0 && maze[node->x][node->y - 1] == 0) {
        node->next = malloc(sizeof(Node));
        node->next->x = node->x;
        node->next->y = node->y - 1;
        findPath(node->next, maze, n, m);
    }
}

int main() {
    int n, m;
    scanf("Enter the number of rows: ", &n);
    scanf("Enter the number of columns: ", &m);

    int** maze = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        maze[i] = malloc(m * sizeof(int));
    }

    createMaze(maze, n, m);

    Node* node = malloc(sizeof(Node));
    node->x = 0;
    node->y = 0;
    findPath(node, maze, n, m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }

    return 0;
}