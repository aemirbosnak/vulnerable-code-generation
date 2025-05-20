//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

typedef struct node {
    int x;
    int y;
    struct node *next;
} Node;

typedef struct queue {
    Node *front;
    Node *rear;
    int size;
} Queue;

int maze[ROWS][COLS] = {
    {0,0,0,0,1,0,0,0,0,0},
    {0,1,1,0,1,0,0,1,1,0},
    {0,0,0,1,0,0,0,0,1,0},
    {0,0,0,0,0,1,1,0,1,0},
    {1,1,1,1,0,0,0,0,1,0},
    {0,0,0,0,0,1,1,0,1,0},
    {0,1,1,0,0,0,0,0,1,0},
    {0,1,0,0,0,1,1,0,0,0},
    {0,1,0,0,0,0,0,0,1,0},
    {0,0,0,0,0,1,0,0,0,0}
};

int visited[ROWS][COLS] = {0};

Queue *createQueue() {
    Queue *queue = malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

Node *createNode(int x, int y) {
    Node *node = malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->next = NULL;
    return node;
}

void enqueue(Queue *queue, int x, int y) {
    Node *node = createNode(x, y);
    if(queue->rear == NULL) {
        queue->front = queue->rear = node;
    } else {
        queue->rear->next = node;
        queue->rear = node;
    }
    queue->size++;
}

void dequeue(Queue *queue) {
    if(queue->front == NULL) {
        return;
    }
    Node *temp = queue->front;
    queue->front = queue->front->next;
    if(queue->front == NULL) {
        queue->rear = NULL;
    }
    queue->size--;
    free(temp);
}

int getQueueSize(Queue *queue) {
    return queue->size;
}

void displayPath(Queue *queue) {
    Node *node = queue->rear;
    while(node != NULL) {
        printf("(%d,%d)\n", node->x, node->y);
        node = node->next;
    }
}

int isSafe(int x, int y) {
    if(x >= 0 && x < ROWS && y >= 0 && y < COLS && maze[x][y] == 0 && visited[x][y] == 0) {
        return 1;
    }
    return 0;
}

void findPath(int startX, int startY, int endX, int endY) {
    Queue *queue = createQueue();
    enqueue(queue, startX, startY);
    visited[startX][startY] = 1;
    int success = 0;
    while(getQueueSize(queue) > 0) {
        Node *node = queue->front;
        dequeue(queue);
        int x = node->x;
        int y = node->y;
        if(x == endX && y == endY) {
            printf("Found the path!\n");
            displayPath(queue);
            success = 1;
            break;
        }
        if(isSafe(x-1, y)) {
            enqueue(queue, x-1, y);
            visited[x-1][y] = 1;
        }
        if(isSafe(x+1, y)) {
            enqueue(queue, x+1, y);
            visited[x+1][y] = 1;
        }
        if(isSafe(x, y-1)) {
            enqueue(queue, x, y-1);
            visited[x][y-1] = 1;
        }
        if(isSafe(x, y+1)) {
            enqueue(queue, x, y+1);
            visited[x][y+1] = 1;
        }
    }
    if(!success) {
        printf("Could not find a path!\n");
    }
}

int main() {
    int startX = 0;
    int startY = 0;
    int endX = 9;
    int endY = 9;
    findPath(startX, startY, endX, endY);
    return 0;
}