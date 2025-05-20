//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: rigorous
/* This program implements Dijkstra's algorithm for finding the shortest path between two nodes in a graph. */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 1000

struct Node {
    int id;
    int distance;
    int visited;
    int num_neighbors;
    struct Edge *neighbors[MAX_NODES];
};

struct Edge {
    int distance;
    struct Node *dest;
};

struct Graph {
    int num_nodes;
    struct Node *nodes[MAX_NODES];
};

struct Node *create_node(int id) {
    struct Node *node = malloc(sizeof(struct Node));
    node->id = id;
    node->distance = INT_MAX;
    node->visited = 0;
    node->num_neighbors = 0;
    return node;
}

struct Edge *create_edge(struct Node *dest, int distance) {
    struct Edge *edge = malloc(sizeof(struct Edge));
    edge->dest = dest;
    edge->distance = distance;
    return edge;
}

struct Graph *create_graph(int num_nodes) {
    struct Graph *graph = malloc(sizeof(struct Graph));
    graph->num_nodes = num_nodes;
    for (int i = 0; i < num_nodes; i++) {
        graph->nodes[i] = create_node(i);
    }
    return graph;
}

void add_edge(struct Node *node1, struct Node *node2, int distance) {
    struct Edge *edge = create_edge(node2, distance);
    node1->neighbors[node1->num_neighbors] = edge;
    node1->num_neighbors++;
}

struct Node *find_min_distance(struct Graph *graph) {
    int min_distance = INT_MAX;
    struct Node *min_node = NULL;
    for (int i = 0; i < graph->num_nodes; i++) {
        struct Node *node = graph->nodes[i];
        if (!node->visited && node->distance < min_distance) {
            min_distance = node->distance;
            min_node = node;
        }
    }
    return min_node;
}

void dijkstra(struct Graph *graph, struct Node *start, struct Node *end) {
    start->distance = 0;
    while (1) {
        struct Node *node = find_min_distance(graph);
        if (node == NULL) break;
        node->visited = 1;
        for (int i = 0; i < node->num_neighbors; i++) {
            struct Edge *edge = node->neighbors[i];
            struct Node *dest = edge->dest;
            int distance = edge->distance;
            if (!dest->visited && node->distance + distance < dest->distance) {
                dest->distance = node->distance + distance;
            }
        }
    }
    printf("Shortest distance from node %d to node %d is %d\n", start->id, end->id, end->distance);
}

int main() {
    struct Graph *graph = create_graph(6);
    add_edge(graph->nodes[0], graph->nodes[1], 7);
    add_edge(graph->nodes[0], graph->nodes[2], 9);
    add_edge(graph->nodes[0], graph->nodes[5], 14);
    add_edge(graph->nodes[1], graph->nodes[2], 10);
    add_edge(graph->nodes[1], graph->nodes[3], 15);
    add_edge(graph->nodes[2], graph->nodes[3], 11);
    add_edge(graph->nodes[2], graph->nodes[5], 2);
    add_edge(graph->nodes[3], graph->nodes[4], 6);
    add_edge(graph->nodes[4], graph->nodes[5], 9);
    dijkstra(graph, graph->nodes[0], graph->nodes[4]);
    return 0;
}