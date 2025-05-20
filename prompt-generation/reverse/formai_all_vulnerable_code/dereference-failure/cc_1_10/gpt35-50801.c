//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 6
#define COL 8

int grid[ROW][COL] = {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 0, 1, 1, 1, 0},
    {0, 1, 1, 0, 1, 0, 1, 0},
    {0, 1, 1, 0, 1, 0, 1, 0},
    {0, 1, 1, 1, 1, 0, 1, 0},
    {0, 1, 1, 0, 1, 1, 1, 0}
};

struct Node {
    int row;
    int col;
    int distance;
    struct Node* parent;
};

struct Queue {
    int rear;
    int front;
    int size;
    struct Node* arr;
};

void init(struct Queue* q) {
    q->rear = -1;
    q->front = -1;
    q->size = 0;
    q->arr = (struct Node*) malloc(sizeof(struct Node) * ROW * COL);
}

bool is_empty(struct Queue* q) {
    return q->size == 0;
}

bool is_valid(int row, int col) {
    if (row >= 0 && row < ROW && col >= 0 && col < COL && grid[row][col] == 1) return true;
    return false;
}

void enqueue(struct Queue* q, struct Node n) {
    if (q->size == 0) {
        q->front = 0;
    }
    q->size++;
    q->rear++;
    q->arr[q->rear] = n;
}

struct Node dequeue(struct Queue* q) {
    q->size--;
    struct Node n = q->arr[q->front];
    q->front++;
    return n;
}

void print_path(struct Node* current) {
    if (current == NULL) return;
    print_path(current->parent);
    printf("(%d, %d)\n", current->row, current->col);
}

void bfs(int row_start, int col_start, int row_end, int col_end) {
    struct Node start = {row_start, col_start, 0, NULL};
    struct Queue q;
    init(&q);
    enqueue(&q, start);
    while (!is_empty(&q)) {
        struct Node current = dequeue(&q);
        int row = current.row;
        int col = current.col;
        int distance = current.distance;
        if (row == row_end && col == col_end) {
            printf("Path Found:\n");
            print_path(&current);
            return;
        }
        if (is_valid(row-1, col)) {
            struct Node n = {row-1, col, distance+1, &current};
            grid[row-1][col] = 2;
            enqueue(&q, n);
        }
        if (is_valid(row+1, col)) {
            struct Node n = {row+1, col, distance+1, &current};
            grid[row+1][col] = 2;
            enqueue(&q, n);
        }
        if (is_valid(row, col-1)) {
            struct Node n = {row, col-1, distance+1, &current};
            grid[row][col-1] = 2;
            enqueue(&q, n);
        }
        if (is_valid(row, col+1)) {
            struct Node n = {row, col+1, distance+1, &current};
            grid[row][col+1] = 2;
            enqueue(&q, n);
        }
    }
    printf("Path not found!\n");
}

int main() {
    int row_start = 1;
    int col_start = 1;
    int row_end = 4;
    int col_end = 7;
    bfs(row_start, col_start, row_end, col_end);
    return 0;
}