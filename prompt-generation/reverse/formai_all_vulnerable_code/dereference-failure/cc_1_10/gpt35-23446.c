//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: automated
#include<stdio.h>
#include<stdlib.h>

#define ROW_SIZE 5
#define COL_SIZE 6
#define INF 1000000

int grid[ROW_SIZE][COL_SIZE] = {
    { 0, 1, 0, 0, 0, 0 },
    { 0, 1, 0, 1, 1, 0 },
    { 0, 0, 0, 0, 1, 0 },
    { 0, 1, 1, 1, 0, 0 },
    { 0, 0, 0, 0, 0, 0 },
};

struct point {
    int row;
    int col;
};

struct queue_node {
    struct point p;
    int dist;
};

struct Queue {
    struct queue_node *array;
    int front;
    int rear;
};

void createQueue(struct Queue **queue_ref) {
    (*queue_ref) = (struct Queue *)malloc(sizeof(struct Queue));
    (*queue_ref)->array = (struct queue_node *)malloc(sizeof(struct queue_node) * (ROW_SIZE * COL_SIZE));
    (*queue_ref)->front = -1;
    (*queue_ref)->rear = -1;
}

int isQueueEmpty(struct Queue *queue) {
    return queue->front == -1;
}

int isQueueFull(struct Queue *queue) {
    return (queue->rear + 1) % (ROW_SIZE * COL_SIZE) == queue->front;
}

void enqueue(struct Queue *queue, struct point p, int dist) {
    if(isQueueFull(queue)) {
        printf("Queue overflow!\n");
    } else {
        if(isQueueEmpty(queue)) {
            queue->front = 0;
            queue->rear = 0;
        } else {
            queue->rear = (queue->rear + 1) % (ROW_SIZE * COL_SIZE);
        }
        queue->array[queue->rear].p = p;
        queue->array[queue->rear].dist = dist;
    }
}

struct queue_node dequeue(struct Queue *queue) {
    struct queue_node result = { { -1, -1 }, -1 };
    if(isQueueEmpty(queue)) {
        printf("Queue underflow!\n");
    } else {
        result = queue->array[queue->front];
        if(queue->front == queue->rear) {
            queue->front = -1;
            queue->rear = -1;
        } else {
            queue->front = (queue->front + 1) % (ROW_SIZE * COL_SIZE);
        }
    }
    return result;
}

int isValid(int row, int col) {
    return (row >= 0) && (row < ROW_SIZE) && (col >= 0) && (col < COL_SIZE);
}

void bfs(int startX, int startY, int endX, int endY) {
    int distance[ROW_SIZE][COL_SIZE];
    for(int i = 0; i < ROW_SIZE; i++) {
        for(int j = 0; j < COL_SIZE; j++) {
            distance[i][j] = INF;
        }
    }

    struct Queue *queue;
    createQueue(&queue);
    distance[startX][startY] = 0;
    struct point start = { startX, startY };
    enqueue(queue, start, 0);

    while(!isQueueEmpty(queue)) {
        struct queue_node current = dequeue(queue);
        struct point p = current.p;

        if(p.row == endX && p.col == endY) {
            printf("Shortest path = %d\n", current.dist);
            return;
        }

        int row[] = { -1, 0, 0, 1 };
        int col[] = { 0, -1, 1, 0 };

        for(int i = 0; i < 4; i++) {
            int nextRow = p.row + row[i];
            int nextCol = p.col + col[i];
            if(isValid(nextRow, nextCol) && grid[nextRow][nextCol] == 0 && distance[nextRow][nextCol] == INF) {
                distance[nextRow][nextCol] = current.dist + 1;
                enqueue(queue, (struct point) {nextRow, nextCol}, distance[nextRow][nextCol]);
            }
        }
    }

    printf("No possible path!\n");
}

int main() {
    bfs(0, 0, 3, 4);
    return 0;
}