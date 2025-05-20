//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#define MAX_NODES 255
#define MAX_EDGES 65025

typedef struct _Node {
    int node_id;
    char ip_address[16];
} Node;

typedef struct _Edge {
    int from;
    int to;
    int cost;
} Edge;

typedef struct _Graph {
    Node nodes[MAX_NODES];
    Edge edges[MAX_EDGES];
    int num_nodes;
    int num_edges;
} Graph;

Graph* init_graph() {
    Graph* graph = malloc(sizeof(Graph));
    graph->num_nodes = 0;
    graph->num_edges = 0;
    return graph;
}

void add_node(Graph* graph, int node_id, char* ip_address) {
    Node node;
    node.node_id = node_id;
    strcpy(node.ip_address, ip_address);
    graph->nodes[graph->num_nodes++] = node;
}

void add_edge(Graph* graph, int from, int to, int cost) {
    Edge edge;
    edge.from = from;
    edge.to = to;
    edge.cost = cost;
    graph->edges[graph->num_edges++] = edge;
}

void print_graph(Graph* graph) {
    printf("Nodes: \n");
    for(int i = 0; i < graph->num_nodes; i++) {
        printf("%d - %s\n", graph->nodes[i].node_id, graph->nodes[i].ip_address);
    }
    printf("\nEdges: \n");
    for(int i = 0; i < graph->num_edges; i++) {
        printf("%d -> %d (cost: %d)\n", graph->edges[i].from, graph->edges[i].to, graph->edges[i].cost);
    }
}

int main() {
    Graph* graph = init_graph();

    add_node(graph, 1, "192.168.0.1");
    add_node(graph, 2, "192.168.0.2");
    add_node(graph, 3, "192.168.0.3");

    add_edge(graph, 1, 2, 5);
    add_edge(graph, 2, 3, 2);
    add_edge(graph, 3, 1, 1);

    print_graph(graph);

    free(graph);
    return 0;
}