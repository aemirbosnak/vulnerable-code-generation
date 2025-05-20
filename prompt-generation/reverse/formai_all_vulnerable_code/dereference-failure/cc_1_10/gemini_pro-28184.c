//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 16
#define MAX_COLORS 16
#define MAX_NODES 1024

typedef struct {
    int id;
    int num_neighbors;
    int *neighbors;
    int color;
} node_t;

typedef struct {
    int num_nodes;
    node_t *nodes;
} graph_t;

graph_t *graph;
int num_threads;
int num_colors;

void *color_node(void *arg) {
    int id = *((int *)arg);
    node_t *node = &graph->nodes[id];
    int used_colors[MAX_COLORS];
    memset(used_colors, 0, sizeof(used_colors));
    for (int i = 0; i < node->num_neighbors; i++) {
        used_colors[graph->nodes[node->neighbors[i]].color] = 1;
    }
    for (int i = 0; i < num_colors; i++) {
        if (!used_colors[i]) {
            node->color = i;
            break;
        }
    }
    return NULL;
}

int main(int argc, char **argv) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <num_nodes> <num_colors> <num_threads>\n", argv[0]);
        return 1;
    }
    int num_nodes = atoi(argv[1]);
    num_colors = atoi(argv[2]);
    num_threads = atoi(argv[3]);
    if (num_nodes <= 0 || num_colors <= 0 || num_threads <= 0) {
        fprintf(stderr, "Invalid arguments\n");
        return 1;
    }
    graph = malloc(sizeof(graph_t));
    graph->num_nodes = num_nodes;
    graph->nodes = malloc(sizeof(node_t) * num_nodes);
    for (int i = 0; i < num_nodes; i++) {
        graph->nodes[i].id = i;
        graph->nodes[i].num_neighbors = 0;
        graph->nodes[i].neighbors = NULL;
        graph->nodes[i].color = -1;
    }
    int num_edges;
    scanf("%d", &num_edges);
    for (int i = 0; i < num_edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph->nodes[u].num_neighbors++;
        graph->nodes[u].neighbors = realloc(graph->nodes[u].neighbors, sizeof(int) * graph->nodes[u].num_neighbors);
        graph->nodes[u].neighbors[graph->nodes[u].num_neighbors - 1] = v;
        graph->nodes[v].num_neighbors++;
        graph->nodes[v].neighbors = realloc(graph->nodes[v].neighbors, sizeof(int) * graph->nodes[v].num_neighbors);
        graph->nodes[v].neighbors[graph->nodes[v].num_neighbors - 1] = u;
    }
    pthread_t threads[MAX_THREADS];
    int thread_args[MAX_THREADS];
    for (int i = 0; i < num_threads; i++) {
        thread_args[i] = i;
        pthread_create(&threads[i], NULL, color_node, &thread_args[i]);
    }
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
    int max_color = -1;
    for (int i = 0; i < num_nodes; i++) {
        if (graph->nodes[i].color > max_color) {
            max_color = graph->nodes[i].color;
        }
    }
    printf("%d\n", max_color + 1);
    free(graph->nodes);
    free(graph);
    return 0;
}