//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10
#define MAX_QUEUE_SIZE 100

typedef struct Node {
    int x, y;
    struct Node *next;
} Node;

typedef struct Queue {
    int size;
    Node *front;
    Node *rear;
} Queue;

void initQueue(Queue **queue) {
    *queue = (Queue *)malloc(sizeof(Queue));
    (*queue)->size = 0;
    (*queue)->front = (*queue)->rear = NULL;
}

bool isEmpty(Queue *queue) {
    return queue->size == 0;
}

bool isFull(Queue *queue) {
    return queue->size == MAX_QUEUE_SIZE;
}

void enqueue(Queue *queue, int x, int y) {
    if (isFull(queue)) {
        printf("Error: Queue overflow!\n");
        exit(EXIT_FAILURE);
    }
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;
    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    queue->size++;
}

void dequeue(Queue *queue, int *x, int *y) {
    if (isEmpty(queue)) {
        printf("Error: Queue underflow!\n");
        exit(EXIT_FAILURE);
    }
    Node *temp = queue->front;
    *x = temp->x;
    *y = temp->y;
    queue->front = queue->front->next;
    free(temp);
    queue->size--;
}

void clearQueue(Queue *queue) {
    int x, y;
    while (!isEmpty(queue)) {
        dequeue(queue, &x, &y);
    }
}

bool isValid(int x, int y) {
    return x >= 0 && x < ROWS && y >= 0 && y < COLS;
}

void printMaze(int maze[][COLS]) {
    printf("Maze:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

void printPath(Queue *path) {
    printf("Path:\n");
    while (!isEmpty(path)) {
        int x, y;
        dequeue(path, &x, &y);
        printf("(%d,%d) ", x, y);
    }
    printf("\n");
}

void findPath(int maze[][COLS], int start_x, int start_y, int end_x, int end_y, Queue **path) {
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    bool visited[ROWS][COLS] = {{false}};
    int dist[ROWS][COLS] = {{0}};
    int prev[ROWS][COLS][2] = {{{-1, -1}}};
    Queue *queue;
    Node *node;
    initQueue(&queue);
    enqueue(queue, start_x, start_y);
    visited[start_x][start_y] = true;
    while (!isEmpty(queue)) {
        int x, y;
        dequeue(queue, &x, &y);
        if (x == end_x && y == end_y) {
            // Path found, backtrack to construct path
            int tmp_x = x, tmp_y = y;
            while (tmp_x != start_x || tmp_y != start_y) {
                Node *newNode = (Node *)malloc(sizeof(Node));
                newNode->x = tmp_x;
                newNode->y = tmp_y;
                newNode->next = NULL;
                if (isEmpty(*path)) {
                    (*path)->front = (*path)->rear = newNode;
                } else {
                    newNode->next = (*path)->front;
                    (*path)->front = newNode;
                }
                int tmp = prev[tmp_x][tmp_y][0];
                tmp_y = prev[tmp_x][tmp_y][1];
                tmp_x = tmp;
            }
            // Enqueue start node to complete path
            Node *newNode = (Node *)malloc(sizeof(Node));
            newNode->x = start_x;
            newNode->y = start_y;
            newNode->next = NULL;
            if (isEmpty(*path)) {
                (*path)->front = (*path)->rear = newNode;
            } else {
                newNode->next = (*path)->front;
                (*path)->front = newNode;
            }
            // Clean up
            clearQueue(queue);
            return;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (isValid(nx, ny) && maze[nx][ny] != 1 && !visited[nx][ny]) {
                visited[nx][ny] = true;
                dist[nx][ny] = dist[x][y] + 1;
                prev[nx][ny][0] = x;
                prev[nx][ny][1] = y;
                enqueue(queue, nx, ny);
            }
        }
    }
    printf("Error: Path not found!\n");
}

int main() {
    int maze[ROWS][COLS] = {
        {0, 1, 1, 0, 1, 0, 0, 0, 0, 1},
        {0, 0, 1, 0, 1, 0, 1, 1, 0, 0},
        {0, 0, 1, 1, 1, 0, 1, 0, 0, 0},
        {1, 1, 0, 1, 0, 0, 1, 0, 1, 0},
        {1, 0, 0, 0, 1, 1, 1, 0, 1, 0},
        {1, 1, 1, 1, 1, 0, 0, 1, 1, 1},
        {0, 1, 0, 1, 0, 0, 0, 1, 0, 0},
        {0, 1, 0, 1, 1, 1, 1, 1, 1, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 1, 1, 1, 1, 1, 1, 0, 0}
    };
    Queue *path;
    initQueue(&path);
    int start_x = 0, start_y = 0;
    int end_x = ROWS - 1, end_y = COLS - 1;
    printf("Finding path from (%d,%d) to (%d,%d)...\n", start_x, start_y, end_x, end_y);
    findPath(maze, start_x, start_y, end_x, end_y, &path);
    printMaze(maze);
    printPath(path);
    clearQueue(path);
    free(path);
    return 0;
}