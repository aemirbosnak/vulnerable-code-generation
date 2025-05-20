//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: asynchronous
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

typedef struct graph {
    int num_vertices;
    int num_edges;
    node_t **adj_list;
} graph_t;

typedef struct thread_args {
    graph_t *graph;
    int start_vertex;
    int end_vertex;
} thread_args_t;

void *bfs(void *args) {
    thread_args_t *thread_args = (thread_args_t *)args;
    graph_t *graph = thread_args->graph;
    int start_vertex = thread_args->start_vertex;
    int end_vertex = thread_args->end_vertex;

    // Initialize the queue with the start vertex
    node_t *queue = malloc(sizeof(node_t));
    queue->data = start_vertex;
    queue->next = NULL;

    // Initialize the visited array
    int *visited = malloc(sizeof(int) * graph->num_vertices);
    for (int i = 0; i < graph->num_vertices; i++) {
        visited[i] = 0;
    }

    // Perform BFS until the queue is empty
    while (queue != NULL) {
        // Dequeue the next vertex
        node_t *current_node = queue;
        queue = queue->next;
        int current_vertex = current_node->data;
        free(current_node);

        // If the current vertex is the end vertex, then we have found the path
        if (current_vertex == end_vertex) {
            free(visited);
            return NULL;
        }

        // Mark the current vertex as visited
        visited[current_vertex] = 1;

        // Enqueue the neighbors of the current vertex
        node_t *neighbor = graph->adj_list[current_vertex];
        while (neighbor != NULL) {
            if (visited[neighbor->data] == 0) {
                node_t *new_node = malloc(sizeof(node_t));
                new_node->data = neighbor->data;
                new_node->next = queue;
                queue = new_node;
            }
            neighbor = neighbor->next;
        }
    }

    free(visited);
    return NULL;
}

int main() {
    // Create a graph
    graph_t graph;
    graph.num_vertices = 6;
    graph.num_edges = 8;
    graph.adj_list = malloc(sizeof(node_t *) * graph.num_vertices);
    for (int i = 0; i < graph.num_vertices; i++) {
        graph.adj_list[i] = NULL;
    }
    node_t *node1 = malloc(sizeof(node_t));
    node1->data = 0;
    node1->next = graph.adj_list[0];
    graph.adj_list[0] = node1;
    node_t *node2 = malloc(sizeof(node_t));
    node2->data = 1;
    node2->next = graph.adj_list[0];
    graph.adj_list[0] = node2;
    node_t *node3 = malloc(sizeof(node_t));
    node3->data = 2;
    node3->next = graph.adj_list[1];
    graph.adj_list[1] = node3;
    node_t *node4 = malloc(sizeof(node_t));
    node4->data = 3;
    node4->next = graph.adj_list[1];
    graph.adj_list[1] = node4;
    node_t *node5 = malloc(sizeof(node_t));
    node5->data = 4;
    node5->next = graph.adj_list[2];
    graph.adj_list[2] = node5;
    node_t *node6 = malloc(sizeof(node_t));
    node6->data = 5;
    node6->next = graph.adj_list[2];
    graph.adj_list[2] = node6;
    node_t *node7 = malloc(sizeof(node_t));
    node7->data = 3;
    node7->next = graph.adj_list[3];
    graph.adj_list[3] = node7;
    node_t *node8 = malloc(sizeof(node_t));
    node8->data = 4;
    node8->next = graph.adj_list[3];
    graph.adj_list[3] = node8;

    // Create the thread arguments
    thread_args_t thread_args;
    thread_args.graph = &graph;
    thread_args.start_vertex = 0;
    thread_args.end_vertex = 5;

    // Create the thread
    pthread_t thread;
    pthread_create(&thread, NULL, bfs, (void *)&thread_args);

    // Wait for the thread to finish
    pthread_join(thread, NULL);

    // Free the graph
    for (int i = 0; i < graph.num_vertices; i++) {
        node_t *node = graph.adj_list[i];
        while (node != NULL) {
            node_t *next_node = node->next;
            free(node);
            node = next_node;
        }
    }
    free(graph.adj_list);

    return 0;
}