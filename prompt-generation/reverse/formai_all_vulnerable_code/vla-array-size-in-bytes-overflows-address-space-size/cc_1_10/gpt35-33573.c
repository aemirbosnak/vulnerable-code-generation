//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *front;
    Node *rear;
} Queue;

void initQueue(Queue **queue) {
    (*queue) = (Queue*) malloc(sizeof(Queue));
    (*queue)->front = NULL;
    (*queue)->rear = NULL;
}

void push(Queue *queue, int data) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if(queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    }
    else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

void pop(Queue *queue) {
    if(queue->front == NULL)
        return;
    Node *temp = queue->front;
    queue->front = queue->front->next;
    if(queue->front == NULL)
        queue->rear = NULL;
    free(temp);
}

int empty(Queue *queue) {
    return queue->front == NULL;
}

int bfs(int source, int destination, int adjacencyMatrix[][10], int n) {
    int queueIterator, adjacentNode;
    int visited[n-1];
    for(int i = 0;i < n;i++)
        visited[i] = 0;
    Queue *queue;
    initQueue(&queue);
    push(queue, source);
    visited[source] = 1;
    while(!empty(queue)) {
        int currentNode = queue->front->data;
        if(currentNode == destination)
            return 1;
        pop(queue);
        for(adjacentNode = 0;adjacentNode < n;adjacentNode++) {
            if(adjacencyMatrix[currentNode][adjacentNode] == 1 && !visited[adjacentNode]) {
                visited[adjacentNode] = 1;
                push(queue, adjacentNode);
            }
        }
    }
    return 0;
}

int main() {
    int adjacencyMatrix[10][10], n;
    printf("Enter number of vertices\n");
    scanf("%d", &n);
    printf("Enter adjacency matrix\n");
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            scanf("%d", &adjacencyMatrix[i][j]);
        }
    }
    int source, destination;
    printf("Enter source vertex\n");
    scanf("%d", &source);
    printf("Enter destination vertex\n");
    scanf("%d", &destination);
    if(bfs(source, destination, adjacencyMatrix, n))
        printf("Path exists\n");
    else
        printf("Path does not exist\n");
    return 0;
}