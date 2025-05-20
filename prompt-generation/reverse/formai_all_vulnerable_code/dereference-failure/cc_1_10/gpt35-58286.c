//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 5
#define COL 5

int maze[ROW][COL] = {
    {1, 0, 0, 0, 1},
    {1, 1, 0, 0, 1},
    {0, 1, 1, 1, 1},
    {0, 0, 1, 0, 0},
    {1, 1, 1, 1, 1}
};

struct Node {
    int row, col;
};

struct Queue {
    struct Node* items[ROW * COL];
    int front;
    int rear;
};

struct Node* createNode(int row, int col) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->row = row;
    node->col = col;
    return node;
}

bool isValid(int row, int col) {
    return (row >= 0 && row < ROW && col >= 0 && col < COL && maze[row][col] == 1);
}

bool isDestination(int row, int col, struct Node* dest) {
    return (row == dest->row && col == dest->col);
}

void enqueue(struct Queue* q, struct Node* node) {
    q->items[q->rear++] = node;
}

struct Node* dequeue(struct Queue* q) {
    return q->items[q->front++];
}

void initializeQueue(struct Queue* q) {
    q->front = 0;
    q->rear = 0;
}

bool BFS(struct Node* src, struct Node* dest, struct Node* path[]) {
    bool visited[ROW][COL];
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            visited[i][j] = false;
        }
    }
    visited[src->row][src->col] = true;
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    initializeQueue(q);
    enqueue(q, src);
    while (q->front != q->rear) {
        struct Node* current = dequeue(q);
        int row = current->row;
        int col = current->col;
        if (isDestination(row, col, dest)) {
            path[row * COL + col] = current;
            return true;
        }
        if (isValid(row - 1, col) && !visited[row - 1][col]) {
            visited[row - 1][col] = true;
            struct Node* newNode = createNode(row - 1, col);
            enqueue(q, newNode);
            path[(row - 1) * COL + col] = current;
        }
        if (isValid(row + 1, col) && !visited[row + 1][col]) {
            visited[row + 1][col] = true;
            struct Node* newNode = createNode(row + 1, col);
            enqueue(q, newNode);
            path[(row + 1) * COL + col] = current;
        }
        if (isValid(row, col - 1) && !visited[row][col - 1]) {
            visited[row][col - 1] = true;
            struct Node* newNode = createNode(row, col - 1);
            enqueue(q, newNode);
            path[row * COL + col - 1] = current;
        }
        if (isValid(row, col + 1) && !visited[row][col + 1]) {
            visited[row][col + 1] = true;
            struct Node* newNode = createNode(row, col + 1);
            enqueue(q, newNode);
            path[row * COL + col + 1] = current;
        }
    }
    return false;
}

void printPath(struct Node* path[], struct Node* dest) {
    if (path[dest->row * COL + dest->col] == NULL) {
        printf("No path found!");
        return;
    }
    int row = dest->row;
    int col = dest->col;
    while (row != 0 || col != 0) {
        printf("(%d,%d) ", row, col);
        struct Node* temp = path[row * COL + col];
        row = temp->row;
        col = temp->col;
    }
    printf("(%d,%d)", 0, 0);
}

int main() {
    struct Node* src = createNode(0, 0);
    struct Node* dest = createNode(ROW - 1, COL - 1);
    struct Node* path[ROW * COL] = { NULL };
    if (BFS(src, dest, path)) {
        printf("Shortest path from (0,0) to (%d,%d):\n", ROW - 1, COL - 1);
        printPath(path, dest);
    }
    else {
        printf("No path found!");
    }
    return 0;
}