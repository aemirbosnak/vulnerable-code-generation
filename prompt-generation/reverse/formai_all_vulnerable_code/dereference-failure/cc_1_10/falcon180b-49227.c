//Falcon-180B DATASET v1.0 Category: Educational ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NUM_EDGES 1000
#define MAX_NUM_NODES 1000
#define INF 1000000

typedef struct {
    int src;
    int dest;
    int weight;
} Edge;

typedef struct {
    int num_edges;
    Edge edges[MAX_NUM_EDGES];
} Graph;

void add_edge(Graph* graph, int src, int dest, int weight) {
    graph->edges[graph->num_edges].src = src;
    graph->edges[graph->num_edges].dest = dest;
    graph->edges[graph->num_edges].weight = weight;
    graph->num_edges++;
}

void dijkstra(Graph* graph, int start_node, int num_nodes, int* dist) {
    int i, j, u, v;
    int min_dist = INF;

    for (i = 0; i < num_nodes; i++) {
        dist[i] = INF;
    }

    dist[start_node] = 0;

    for (i = 0; i < num_nodes - 1; i++) {
        for (j = 0; j < graph->num_edges; j++) {
            u = graph->edges[j].src;
            v = graph->edges[j].dest;
            if (dist[u]!= INF && dist[u] + graph->edges[j].weight < dist[v]) {
                dist[v] = dist[u] + graph->edges[j].weight;
            }
        }
    }
}

int main() {
    int num_nodes, num_edges, start_node, i, j;
    Graph graph;
    int dist[MAX_NUM_NODES];

    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);

    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);

    printf("Enter the edges:\n");
    for (i = 0; i < num_edges; i++) {
        printf("Enter the source and destination nodes: ");
        scanf("%d %d", &graph.edges[i].src, &graph.edges[i].dest);
        printf("Enter the weight: ");
        scanf("%d", &graph.edges[i].weight);
        add_edge(&graph, graph.edges[i].src, graph.edges[i].dest, graph.edges[i].weight);
    }

    printf("Enter the starting node: ");
    scanf("%d", &start_node);

    dijkstra(&graph, start_node, num_nodes, dist);

    printf("The shortest distances from node %d:\n", start_node);
    for (i = 0; i < num_nodes; i++) {
        if (dist[i]!= INF) {
            printf("%d ", dist[i]);
        } else {
            printf("INF ");
        }
    }

    return 0;
}