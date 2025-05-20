//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define INF 9999

typedef struct {
    int node;
    int weight;
    int next;
} Edge;

typedef struct {
    int num_nodes;
    int num_edges;
    Edge edges[MAX_EDGES];
} Graph;

void add_edge(Graph* graph, int node1, int node2, int weight) {
    Edge* new_edge = (Edge*) malloc(sizeof(Edge));
    new_edge->node = node2;
    new_edge->weight = weight;
    new_edge->next = graph->edges[node1].next;
    graph->edges[node1].next = new_edge;
}

void dijkstra(Graph* graph, int start_node) {
    int num_nodes = graph->num_nodes;
    int* distances = (int*) malloc(sizeof(int) * num_nodes);
    int* visited = (int*) malloc(sizeof(int) * num_nodes);
    int* previous = (int*) malloc(sizeof(int) * num_nodes);

    for (int i = 0; i < num_nodes; i++) {
        distances[i] = INF;
        visited[i] = 0;
        previous[i] = -1;
    }

    distances[start_node] = 0;

    for (int i = 0; i < num_nodes - 1; i++) {
        int min_distance = INF;
        int u = -1;

        for (int j = 0; j < num_nodes; j++) {
            if (!visited[j] && distances[j] < min_distance) {
                min_distance = distances[j];
                u = j;
            }
        }

        visited[u] = 1;

        for (Edge* edge = graph->edges[u].next; edge!= NULL; edge = edge->next) {
            int v = edge->node;
            int weight = edge->weight;

            if (!visited[v] && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                previous[v] = u;
            }
        }
    }

    printf("Shortest distances from node %d:\n", start_node);
    for (int i = 0; i < num_nodes; i++) {
        printf("%d ", distances[i]);
    }

    printf("\nPrevious nodes:\n");
    for (int i = 0; i < num_nodes; i++) {
        if (previous[i]!= -1) {
            printf("%d ", previous[i]);
        } else {
            printf("-1 ");
        }
    }
}

int main() {
    int num_nodes, num_edges;
    printf("Enter number of nodes: ");
    scanf("%d", &num_nodes);

    Graph graph;
    graph.num_nodes = num_nodes;
    graph.num_edges = 0;

    printf("Enter number of edges: ");
    scanf("%d", &num_edges);

    for (int i = 0; i < num_edges; i++) {
        int node1, node2, weight;
        printf("Enter edge %d (node1 node2 weight): ", i+1);
        scanf("%d %d %d", &node1, &node2, &weight);
        add_edge(&graph, node1, node2, weight);
    }

    int start_node;
    printf("Enter start node: ");
    scanf("%d", &start_node);

    dijkstra(&graph, start_node);

    return 0;
}