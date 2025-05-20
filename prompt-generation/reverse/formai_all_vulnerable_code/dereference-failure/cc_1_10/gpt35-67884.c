//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Graph {
    int num_vertices;
    int **adj_matrix;
};

struct HeapNode {
    int vertex;
    int distance;
};

struct Heap {
    struct HeapNode *data;
    int capacity;
    int size;
};

void init_graph(struct Graph *graph, int num_vertices) {
    graph->num_vertices = num_vertices;
    graph->adj_matrix = malloc(sizeof(int *) * num_vertices);
    for (int i = 0; i < num_vertices; i++) {
        graph->adj_matrix[i] = calloc(num_vertices, sizeof(int));
    }
}

void add_edge(struct Graph *graph, int u, int v, int weight) {
    graph->adj_matrix[u][v] = weight;
}

void init_heap(struct Heap *heap, int capacity) {
    heap->data = malloc(sizeof(struct HeapNode) * capacity);
    heap->capacity = capacity;
    heap->size = 0;
}

void insert(struct Heap *heap, int vertex, int distance) {
    heap->size++;
    int i = heap->size - 1;
    heap->data[i].vertex = vertex;
    heap->data[i].distance = distance;
    while (i != 0 && heap->data[(i - 1) / 2].distance > heap->data[i].distance) {
        struct HeapNode temp = heap->data[i];
        heap->data[i] = heap->data[(i - 1) / 2];
        heap->data[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

struct HeapNode extract_min(struct Heap *heap) {
    struct HeapNode min_node = heap->data[0];
    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;
    int i = 0;
    while (2 * i + 1 < heap->size) {
        int j = 2 * i + 1;
        if (j + 1 < heap->size && heap->data[j + 1].distance < heap->data[j].distance) {
            j++;
        }
        if (heap->data[i].distance > heap->data[j].distance) {
            struct HeapNode temp = heap->data[i];
            heap->data[i] = heap->data[j];
            heap->data[j] = temp;
            i = j;
        } else {
            break;
        }
    }
    return min_node;
}

void dijkstra(struct Graph *graph, int source, int *distances) {
    struct Heap heap;
    init_heap(&heap, graph->num_vertices);
    int *visited = calloc(graph->num_vertices, sizeof(int));
    for (int i = 0; i < graph->num_vertices; i++) {
        distances[i] = INT_MAX;
    }
    distances[source] = 0;
    insert(&heap, source, 0);
    while (heap.size > 0) {
        struct HeapNode min_node = extract_min(&heap);
        int u = min_node.vertex;
        visited[u] = 1;
        for (int v = 0; v < graph->num_vertices; v++) {
            int weight = graph->adj_matrix[u][v];
            if (weight > 0 && !visited[v]) {
                int new_distance = distances[u] + weight;
                if (new_distance < distances[v]) {
                    distances[v] = new_distance;
                    insert(&heap, v, new_distance);
                }
            }
        }
    }
    free(visited);
}

int main() {
    struct Graph graph;
    init_graph(&graph, 7);
    add_edge(&graph, 0, 1, 5);
    add_edge(&graph, 0, 2, 2);
    add_edge(&graph, 1, 2, 1);
    add_edge(&graph, 1, 3, 4);
    add_edge(&graph, 2, 3, 2);
    add_edge(&graph, 2, 4, 6);
    add_edge(&graph, 3, 4, 3);
    add_edge(&graph, 4, 5, 1);
    add_edge(&graph, 4, 6, 4);
    add_edge(&graph, 5, 6, 2);
    int *distances = malloc(sizeof(int) * graph.num_vertices);
    dijkstra(&graph, 0, distances);
    for (int i = 0; i < graph.num_vertices; i++) {
        printf("Shortest distance from node 0 to node %d: %d\n", i, distances[i]);
    }
    free(distances);
    for (int i = 0; i < graph.num_vertices; i++) {
        free(graph.adj_matrix[i]);
    }
    free(graph.adj_matrix);
    return 0;
}