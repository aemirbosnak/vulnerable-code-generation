//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int x;
    int y;
    struct Node* next;
} Node;

void createMaze(int** maze, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            maze[i][j] = rand() % 2;
        }
    }
}

void findRoute(Node* node, int** maze, int n, int m) {
    if (node == NULL) {
        return;
    }
    if (node->x == n - 1 && node->y == m - 1) {
        printf("The route is: ");
        while (node) {
            printf("(%d, %d) ", node->x, node->y);
            node = node->next;
        }
        exit(0);
    }
    maze[node->x][node->y] = 2;
    findRoute(node->next, maze, n, m);
}

int main() {
    int n, m;
    scanf("Enter the number of rows: ", &n);
    scanf("Enter the number of columns: ", &m);

    int** maze = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        maze[i] = (int*)malloc(m * sizeof(int));
    }

    createMaze(maze, n, m);

    Node* node = (Node*)malloc(sizeof(Node));
    node->x = 0;
    node->y = 0;
    node->next = NULL;

    findRoute(node, maze, n, m);

    return 0;
}