//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

#define ROW 6
#define COL 8

int visited[ROW][COL];

struct node {
    int row, col;
    struct node* next;
};

struct queue {
    struct node* front, * rear;
};

void init_queue(struct queue* q) {
    q->front = q->rear = NULL;
}

void enqueue(struct queue* q, int row, int col) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->row = row;
    temp->col = col;
    temp->next = NULL;

    if (q->front == NULL)
        q->front = q->rear = temp;
    else {
        q->rear->next = temp;
        q->rear = temp;
    }
}

struct node* dequeue(struct queue* q) {
    if (q->front == NULL)
        return NULL;

    struct node* temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    return temp;
}

int is_valid(int mat[][COL], int row, int col) {
    if (row < 0 || col < 0 || row >= ROW || col >= COL || mat[row][col] == 0 || visited[row][col] == 1)
        return 0;

    return 1;
}

void bfs(int mat[][COL], int start_row, int start_col, int end_row, int end_col) {
    struct queue q;
    init_queue(&q);

    visited[start_row][start_col] = 1;
    enqueue(&q, start_row, start_col);

    while (q.front != NULL) {
        struct node* temp = dequeue(&q);

        int row = temp->row;
        int col = temp->col;

        if (row == end_row && col == end_col) {
            printf("Destination Found!");
            return;
        }

        if (is_valid(mat, row - 1, col)) { //Up
            visited[row - 1][col] = 1;
            enqueue(&q, row - 1, col);
        }

        if (is_valid(mat, row + 1, col)) { //Down
            visited[row + 1][col] = 1;
            enqueue(&q, row + 1, col);
        }

        if (is_valid(mat, row, col - 1)) { //Left
            visited[row][col - 1] = 1;
            enqueue(&q, row, col - 1);
        }

        if (is_valid(mat, row, col + 1)) { //Right
            visited[row][col + 1] = 1;
            enqueue(&q, row, col + 1);
        }
    }

    printf("Destination not found!");
}

int main() {
    int mat[ROW][COL] = {
        { 1, 0, 1, 1, 1, 1, 0, 1 },
        { 1, 0, 1, 0, 1, 1, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 0, 1 },
        { 0, 0, 0, 0, 1, 0, 0, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 1 }
    };

    bfs(mat, 0, 0, 0, 7);

    return 0;
}