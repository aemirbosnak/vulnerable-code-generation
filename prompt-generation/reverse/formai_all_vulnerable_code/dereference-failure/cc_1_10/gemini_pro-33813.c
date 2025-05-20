//GEMINI-pro DATASET v1.0 Category: Pathfinding algorithms ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>

#define MAX_VERTICES 100

// Graph represented as an adjacency list
typedef struct graph {
    int num_vertices;
    int** adj_list;
} graph;

// Node in the priority queue
typedef struct node {
    int vertex;
    int distance;
} node;

// Priority queue implemented as a min-heap
typedef struct priority_queue {
    int size;
    node* nodes;
} priority_queue;

// Initialize a graph with num_vertices vertices
graph* create_graph(int num_vertices) {
    graph* g = malloc(sizeof(graph));
    g->num_vertices = num_vertices;
    g->adj_list = malloc(sizeof(int*) * num_vertices);
    for (int i = 0; i < num_vertices; i++) {
        g->adj_list[i] = malloc(sizeof(int) * num_vertices);
        for (int j = 0; j < num_vertices; j++) {
            g->adj_list[i][j] = 0;
        }
    }
    return g;
}

// Add an edge to the graph
void add_edge(graph* g, int vertex1, int vertex2, int weight) {
    g->adj_list[vertex1][vertex2] = weight;
    g->adj_list[vertex2][vertex1] = weight;
}

// Initialize a priority queue with size num_nodes
priority_queue* create_priority_queue(int num_nodes) {
    priority_queue* pq = malloc(sizeof(priority_queue));
    pq->size = 0;
    pq->nodes = malloc(sizeof(node) * num_nodes);
    return pq;
}

// Insert a node into the priority queue
void insert_node(priority_queue* pq, node n) {
    pq->nodes[pq->size++] = n;
    int i = pq->size - 1;

    // Maintain the heap property
    while (i > 0 && pq->nodes[i].distance < pq->nodes[(i - 1) / 2].distance) {
        node temp = pq->nodes[i];
        pq->nodes[i] = pq->nodes[(i - 1) / 2];
        pq->nodes[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

// Extract the minimum node from the priority queue
node extract_min(priority_queue* pq) {
    assert(pq->size > 0);

    node min = pq->nodes[0];
    pq->nodes[0] = pq->nodes[pq->size - 1];
    pq->size--;

    // Maintain the heap property
    int i = 0;
    while (2 * i + 1 < pq->size) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int min_child = left;
        if (right < pq->size && pq->nodes[right].distance < pq->nodes[left].distance) {
            min_child = right;
        }
        if (pq->nodes[min_child].distance < pq->nodes[i].distance) {
            node temp = pq->nodes[i];
            pq->nodes[i] = pq->nodes[min_child];
            pq->nodes[min_child] = temp;
            i = min_child;
        } else {
            break;
        }
    }

    return min;
}

// Dijkstra's algorithm for finding the shortest path from a source vertex to all other vertices in a graph
int* dijkstra(graph* g, int source) {
    int* distances = malloc(sizeof(int) * g->num_vertices);
    for (int i = 0; i < g->num_vertices; i++) {
        distances[i] = INT_MAX;
    }
    distances[source] = 0;

    priority_queue* pq = create_priority_queue(g->num_vertices);
    for (int i = 0; i < g->num_vertices; i++) {
        node n;
        n.vertex = i;
        n.distance = distances[i];
        insert_node(pq, n);
    }

    while (pq->size > 0) {
        node min = extract_min(pq);
        for (int i = 0; i < g->num_vertices; i++) {
            if (g->adj_list[min.vertex][i] > 0 && distances[min.vertex] + g->adj_list[min.vertex][i] < distances[i]) {
                distances[i] = distances[min.vertex] + g->adj_list[min.vertex][i];
                node n;
                n.vertex = i;
                n.distance = distances[i];
                insert_node(pq, n);
            }
        }
    }

    free(pq);
    return distances;
}

// Print the shortest path from a source vertex to a destination vertex
void print_shortest_path(graph* g, int source, int destination, int* distances) {
    if (source == destination) {
        printf("%d", source);
        return;
    }

    for (int i = 0; i < g->num_vertices; i++) {
        if (g->adj_list[source][i] > 0 && distances[source] + g->adj_list[source][i] == distances[destination]) {
            print_shortest_path(g, i, destination, distances);
            printf(" -> %d", source);
            return;
        }
    }
}

int main() {
    graph* g = create_graph(9);
    add_edge(g, 0, 1, 4);
    add_edge(g, 0, 6, 7);
    add_edge(g, 1, 6, 11);
    add_edge(g, 1, 7, 20);
    add_edge(g, 1, 2, 9);
    add_edge(g, 2, 3, 6);
    add_edge(g, 2, 4, 2);
    add_edge(g, 3, 4, 10);
    add_edge(g, 3, 5, 5);
    add_edge(g, 4, 5, 15);
    add_edge(g, 4, 7, 1);
    add_edge(g, 4, 8, 5);
    add_edge(g, 5, 8, 12);
    add_edge(g, 6, 7, 1);
    add_edge(g, 7, 8, 3);

    int* distances = dijkstra(g, 0);
    print_shortest_path(g, 0, 8, distances);

    free(g);
    free(distances);
    return 0;
}