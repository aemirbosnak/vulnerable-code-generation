//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct Graph {
    int vertices;
    int adj_matrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

Graph* create_graph(int vertices) {
    Graph* g = malloc(sizeof(Graph));
    g->vertices = vertices;
    
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adj_matrix[i][j] = 0; // Initialize
        }
    }
    return g;
}

void add_edge(Graph* g, int src, int dest) {
    if (src < g->vertices && dest < g->vertices) {
        g->adj_matrix[src][dest] = 1; // Directed edge
        g->adj_matrix[dest][src] = 1; // For undirected, comment this line
    } else {
        printf("Edge cannot be added - vertex out of bounds!\n");
    }
}

void display_graph(Graph* g) {
    for (int i = 0; i < g->vertices; i++) {
        printf("\nVertex %d: ", i);
        for (int j = 0; j < g->vertices; j++) {
            if (g->adj_matrix[i][j]) {
                printf(" -> %d", j);
            }
        }
    }
    printf("\n");
}

void delete_edge(Graph* g, int src, int dest) {
    if (src < g->vertices && dest < g->vertices) {
        g->adj_matrix[src][dest] = 0; // Delete edge
        g->adj_matrix[dest][src] = 0; // For undirected, comment this line
    } else {
        printf("Edge cannot be deleted - vertex out of bounds!\n");
    }
}

void free_graph(Graph* g) {
    free(g);
}

typedef struct Queue {
    int items[MAX_VERTICES];
    int front, rear;
} Queue;

Queue* create_queue() {
    Queue* q = malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int is_empty(Queue* q) {
    return q->front == -1;
}

void enqueue(Queue* q, int value) {
    if (q->rear == MAX_VERTICES - 1) {
        printf("Queue is full!\n");
        return;
    }
    if (is_empty(q)) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(Queue* q) {
    if (is_empty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int value = q->items[q->front];
    q->front++;
    if (q->front > q->rear) { // Reset queue
        q->front = q->rear = -1;
    }
    return value;
}

void bfs(Graph* g, int start_vertex) {
    int visited[MAX_VERTICES] = {0};
    Queue* q = create_queue();
    visited[start_vertex] = 1;
    enqueue(q, start_vertex);
    
    while (!is_empty(q)) {
        int current_vertex = dequeue(q);
        printf("%d ", current_vertex);
        
        for (int i = 0; i < g->vertices; i++) {
            if (g->adj_matrix[current_vertex][i] && !visited[i]) {
                visited[i] = 1;
                enqueue(q, i);
            }
        }
    }
    free(q);
}

void dfs_util(Graph* g, int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    
    for (int i = 0; i < g->vertices; i++) {
        if (g->adj_matrix[vertex][i] && !visited[i]) {
            dfs_util(g, i, visited);
        }
    }
}

void dfs(Graph* g, int start_vertex) {
    int visited[MAX_VERTICES] = {0};
    dfs_util(g, start_vertex, visited);
}

int main() {
    int vertices = 6;
    Graph* g = create_graph(vertices);
    
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 3);
    add_edge(g, 1, 4);
    add_edge(g, 2, 5);
    add_edge(g, 3, 4);
    
    printf("Graph adjacency list:\n");
    display_graph(g);
    
    printf("Breadth First Search starting from vertex 0:\n");
    bfs(g, 0);
    printf("\nDepth First Search starting from vertex 0:\n");
    dfs(g, 0);
    
    delete_edge(g, 1, 4);
    printf("\nGraph after deleting edge 1-4:\n");
    display_graph(g);
    
    free_graph(g);
    return 0;
}