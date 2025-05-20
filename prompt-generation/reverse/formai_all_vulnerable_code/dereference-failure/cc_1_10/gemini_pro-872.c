//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct graph {
    int num_vertices;
    int num_edges;
    struct node **adj_lists;
};

struct graph *create_graph(int num_vertices) {
    struct graph *graph = malloc(sizeof(struct graph));
    graph->num_vertices = num_vertices;
    graph->num_edges = 0;
    graph->adj_lists = malloc(num_vertices * sizeof(struct node *));
    for (int i = 0; i < num_vertices; i++) {
        graph->adj_lists[i] = NULL;
    }
    return graph;
}

void add_edge(struct graph *graph, int src, int dest) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = dest;
    new_node->next = graph->adj_lists[src];
    graph->adj_lists[src] = new_node;
    graph->num_edges++;
}

void print_graph(struct graph *graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        struct node *curr = graph->adj_lists[i];
        printf("%d: ", i);
        while (curr != NULL) {
            printf("%d -> ", curr->data);
            curr = curr->next;
        }
        printf("\n");
    }
}

struct queue {
    int *items;
    int front;
    int rear;
    int size;
};

struct queue *create_queue(int size) {
    struct queue *queue = malloc(sizeof(struct queue));
    queue->items = malloc(size * sizeof(int));
    queue->front = -1;
    queue->rear = -1;
    queue->size = size;
    return queue;
}

void enqueue(struct queue *queue, int item) {
    if (queue->rear == queue->size - 1) {
        printf("Queue is full!\n");
        return;
    }
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->rear++;
    queue->items[queue->rear] = item;
}

int dequeue(struct queue *queue) {
    if (queue->front == -1) {
        printf("Queue is empty!\n");
        return -1;
    }
    int item = queue->items[queue->front];
    queue->front++;
    if (queue->front > queue->rear) {
        queue->front = queue->rear = -1;
    }
    return item;
}

int is_empty(struct queue *queue) {
    return queue->front == -1;
}

void bfs(struct graph *graph, int start) {
    struct queue *queue = create_queue(graph->num_vertices);
    int visited[graph->num_vertices];
    for (int i = 0; i < graph->num_vertices; i++) {
        visited[i] = 0;
    }
    enqueue(queue, start);
    visited[start] = 1;
    while (!is_empty(queue)) {
        int curr = dequeue(queue);
        printf("%d ", curr);
        struct node *adj = graph->adj_lists[curr];
        while (adj != NULL) {
            if (!visited[adj->data]) {
                enqueue(queue, adj->data);
                visited[adj->data] = 1;
            }
            adj = adj->next;
        }
    }
    printf("\n");
}

int main() {
    struct graph *graph = create_graph(5);
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 4);
    print_graph(graph);
    bfs(graph, 0);
    return 0;
}