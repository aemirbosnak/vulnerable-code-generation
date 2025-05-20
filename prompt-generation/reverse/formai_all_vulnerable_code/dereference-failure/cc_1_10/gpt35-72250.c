//FormAI DATASET v1.0 Category: Graph representation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX 20

typedef struct{
    int front;
    int rear;
    int queue[MAX_VERTEX];
} QUEUE;

void init_queue(QUEUE *q){
    q->front = q->rear = -1;
}

int is_queue_empty(QUEUE *q){
    if(q->front == -1 && q->rear == -1){
        return 1;
    }
    return 0;
}

void enqueue(QUEUE *q, int vertex){
    if(q->rear == MAX_VERTEX - 1){
        printf("Queue overflow\n");
        return;
    }
    else if(is_queue_empty(q)){
        q->front = q->rear = 0;
    }
    else{
        q->rear++;
    }
    q->queue[q->rear] = vertex;
}

int dequeue(QUEUE *q){
    int vertex;
    if(is_queue_empty(q)){
        printf("Queue underflow\n");
        exit(1);
    }
    else if(q->front == q->rear){
        vertex = q->queue[q->front];
        q->front = q->rear = -1;
    }
    else{
        vertex = q->queue[q->front];
        q->front++;
    }
    return vertex;
}

void bfs(int **adj_matrix, int *visited, int start, int n){
    QUEUE q;
    init_queue(&q);
    visited[start] = 1;
    printf("Visited vertex: %d\n", start);
    enqueue(&q, start);
    while(!is_queue_empty(&q)){
        int current_vertex = dequeue(&q);
        for(int i = 1; i <= n; i++){
            if(adj_matrix[current_vertex][i] == 1 && visited[i] == 0){
                visited[i] = 1;
                printf("Visited vertex: %d\n", i);
                enqueue(&q, i);
            }
        }
    }
}

void print_matrix(int **adj_matrix, int n){
    printf("Adjacency matrix:\n");
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            printf("%d ", adj_matrix[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int n, start_vertex;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    int **adj_matrix = (int **)malloc((n + 1) * sizeof(int *));
    for(int i = 1; i <= n; i++){
        adj_matrix[i] = (int *)malloc((n + 1) * sizeof(int));
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            adj_matrix[i][j] = 0;
        }
    }
    int *visited = (int *)calloc(n + 1, sizeof(int));
    printf("Enter the adjacency matrix:\n");
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            scanf("%d", &adj_matrix[i][j]);
        }
    }
    print_matrix(adj_matrix, n);
    printf("Enter the starting vertex for BFS traversal: ");
    scanf("%d", &start_vertex);
    bfs(adj_matrix, visited, start_vertex, n);
    return 0;
}