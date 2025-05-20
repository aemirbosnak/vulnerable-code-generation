//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

void createMaze(int **maze, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            maze[i][j] = rand() % MAX;
        }
    }
}

void findPath(Node* head, int **maze, int n, int m) {
    if (head == NULL) {
        return;
    }
    if (head->x == n - 1 && head->y == m - 1) {
        printf("Path found!\n");
        return;
    }
    maze[head->x][head->y] = 2;
    findPath(head->next, maze, n, m);
    if (maze[head->x - 1][head->y] == 0) {
        Node* newNode = malloc(sizeof(Node));
        newNode->x = head->x - 1;
        newNode->y = head->y;
        newNode->next = head;
        findPath(newNode, maze, n, m);
    }
    if (maze[head->x][head->y - 1] == 0) {
        Node* newNode = malloc(sizeof(Node));
        newNode->x = head->x;
        newNode->y = head->y - 1;
        newNode->next = head;
        findPath(newNode, maze, n, m);
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
    Node* head = malloc(sizeof(Node));
    head->x = 0;
    head->y = 0;
    head->next = NULL;
    findPath(head, maze, n, m);
    return 0;
}