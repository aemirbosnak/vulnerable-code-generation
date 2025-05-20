//GPT-4o-mini DATASET v1.0 Category: Pathfinding algorithms ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10
#define INF 99999

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point point;
    int distance;
} Node;

typedef struct {
    Node* elements;
    int front;
    int rear;
    int capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->rear = 0;
    queue->elements = (Node*)malloc(capacity * sizeof(Node));
    return queue;
}

bool isFull(Queue* queue) {
    return (queue->rear + 1) % queue->capacity == queue->front;
}

bool isEmpty(Queue* queue) {
    return queue->front == queue->rear;
}

void enqueue(Queue* queue, Node node) {
    if (!isFull(queue)) {
        queue->elements[queue->rear] = node;
        queue->rear = (queue->rear + 1) % queue->capacity;
    }
}

Node dequeue(Queue* queue) {
    Node node = { .point = { -1, -1 }, .distance = INF };
    if (!isEmpty(queue)) {
        node = queue->elements[queue->front];
        queue->front = (queue->front + 1) % queue->capacity;
    }
    return node;
}

void freeQueue(Queue* queue) {
    free(queue->elements);
    free(queue);
}

int grid[SIZE][SIZE] = {
    { 0, 1, 0, 0, 0, 0, 0, 0, 1, 0 },
    { 0, 1, 0, 1, 1, 1, 0, 0, 1, 0 },
    { 0, 0, 0, 0, 0, 1, 1, 1, 0, 0 },
    { 1, 1, 1, 1, 0, 0, 0, 1, 0, 1 },
    { 0, 0, 0, 1, 1, 1, 1, 1, 0, 0 },
    { 0, 1, 0, 0, 1, 0, 0, 0, 1, 0 },
    { 0, 1, 1, 1, 1, 0, 1, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 1, 1, 1, 0 },
    { 0, 1, 1, 0, 1, 0, 0, 0, 1, 0 },
    { 0, 0, 0, 0, 1, 1, 1, 0, 0, 0 }
};

bool isValid(int x, int y) {
    return (x >= 0 && x < SIZE && y >= 0 && y < SIZE && grid[x][y] == 0);
}

void printPath(int parent[SIZE][SIZE], Point start, Point end) {
    if (end.x == start.x && end.y == start.y) {
        printf("Start point (%d, %d) reached.\n", end.x, end.y);
        return;
    }
    printPath(parent, start, (Point){ parent[end.x][end.y] / SIZE, parent[end.x][end.y] % SIZE });
    printf("-> (%d, %d) ", end.x, end.y);
}

void bfs(Point start, Point end) {
    Queue* queue = createQueue(SIZE * SIZE);
    bool visited[SIZE][SIZE] = { false };
    int parent[SIZE][SIZE];

    enqueue(queue, (Node){ start, 0 });
    visited[start.x][start.y] = true;
    parent[start.x][start.y] = start.x * SIZE + start.y;

    int rowOffsets[] = { 0, 1, 0, -1 };
    int colOffsets[] = { 1, 0, -1, 0 };

    while (!isEmpty(queue)) {
        Node current = dequeue(queue);

        if (current.point.x == end.x && current.point.y == end.y) {
            printf("Path found! ");
            printPath(parent, start, end);
            printf("\n");
            freeQueue(queue);
            return;
        }

        for (int i = 0; i < 4; i++) {
            int newX = current.point.x + rowOffsets[i];
            int newY = current.point.y + colOffsets[i];

            if (isValid(newX, newY) && !visited[newX][newY]) {
                enqueue(queue, (Node){ { newX, newY }, current.distance + 1 });
                visited[newX][newY] = true;
                parent[newX][newY] = current.point.x * SIZE + current.point.y;
            }
        }
    }

    printf("No path found from (%d, %d) to (%d, %d).\n", start.x, start.y, end.x, end.y);
    freeQueue(queue);
}

int main() {
    Point start = { 0, 0 }; // Starting point
    Point end = { 9, 9 }; // Ending point

    printf("Searching for a path from (%d, %d) to (%d, %d)...\n", start.x, start.y, end.x, end.y);
    bfs(start, end);

    return 0;
}