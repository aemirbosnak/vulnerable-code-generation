//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint32_t vertex_t;
typedef uint32_t edge_t;

struct vertex_data {
    vertex_t id;
    void *data;
};

struct edge_data {
    edge_t id;
    void *data;
};

struct graph {
    size_t vertex_count;
    size_t edge_count;
    struct vertex_data *vertices;
    struct edge_data *edges;
    size_t *vertex_index_map;
    size_t *edge_index_map;
};

struct graph *new_graph(size_t vertex_count, size_t edge_count) {
    struct graph *graph = malloc(sizeof(struct graph));
    graph->vertex_count = vertex_count;
    graph->edge_count = edge_count;
    graph->vertices = malloc(sizeof(struct vertex_data) * vertex_count);
    graph->edges = malloc(sizeof(struct edge_data) * edge_count);
    graph->vertex_index_map = malloc(sizeof(size_t) * vertex_count);
    graph->edge_index_map = malloc(sizeof(size_t) * edge_count);
    return graph;
}

void free_graph(struct graph *graph) {
    free(graph->vertices);
    free(graph->edges);
    free(graph->vertex_index_map);
    free(graph->edge_index_map);
    free(graph);
}

void add_vertex(struct graph *graph, vertex_t id, void *data) {
    graph->vertices[graph->vertex_count].id = id;
    graph->vertices[graph->vertex_count].data = data;
    graph->vertex_index_map[id] = graph->vertex_count;
    graph->vertex_count++;
}

void add_edge(struct graph *graph, edge_t id, vertex_t source, vertex_t destination, void *data) {
    graph->edges[graph->edge_count].id = id;
    graph->edges[graph->edge_count].data = data;
    graph->edge_index_map[id] = graph->edge_count;
    graph->edge_count++;
}

void remove_vertex(struct graph *graph, vertex_t id) {
    size_t index = graph->vertex_index_map[id];
    graph->vertex_index_map[id] = -1;
    graph->vertices[index] = graph->vertices[graph->vertex_count - 1];
    graph->vertex_index_map[graph->vertices[index].id] = index;
    graph->vertex_count--;
}

void remove_edge(struct graph *graph, edge_t id) {
    size_t index = graph->edge_index_map[id];
    graph->edge_index_map[id] = -1;
    graph->edges[index] = graph->edges[graph->edge_count - 1];
    graph->edge_index_map[graph->edges[index].id] = index;
    graph->edge_count--;
}

int main() {
    struct graph *graph = new_graph(10, 20);
    add_vertex(graph, 0, NULL);
    add_vertex(graph, 1, NULL);
    add_vertex(graph, 2, NULL);
    add_vertex(graph, 3, NULL);
    add_vertex(graph, 4, NULL);
    add_vertex(graph, 5, NULL);
    add_vertex(graph, 6, NULL);
    add_vertex(graph, 7, NULL);
    add_vertex(graph, 8, NULL);
    add_vertex(graph, 9, NULL);
    add_edge(graph, 0, 0, 1, NULL);
    add_edge(graph, 1, 1, 2, NULL);
    add_edge(graph, 2, 2, 3, NULL);
    add_edge(graph, 3, 3, 4, NULL);
    add_edge(graph, 4, 4, 5, NULL);
    add_edge(graph, 5, 5, 6, NULL);
    add_edge(graph, 6, 6, 7, NULL);
    add_edge(graph, 7, 7, 8, NULL);
    add_edge(graph, 8, 8, 9, NULL);
    add_edge(graph, 9, 9, 0, NULL);
    free_graph(graph);
    return 0;
}