//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>

// Creative variable names
typedef struct {
    char *name;
    char *ip_address;
    char *mac_address;
    int num_connected_devices;
} node_t;

typedef struct {
    node_t *node1;
    node_t *node2;
    int weight;
} edge_t;

typedef struct {
    node_t **nodes;
    edge_t **edges;
    int num_nodes;
    int num_edges;
} graph_t;

// Creative function names
node_t *create_node(char *name, char *ip_address, char *mac_address) {
    node_t *node = malloc(sizeof(node_t));
    node->name = strdup(name);
    node->ip_address = strdup(ip_address);
    node->mac_address = strdup(mac_address);
    node->num_connected_devices = 0;
    return node;
}

edge_t *create_edge(node_t *node1, node_t *node2, int weight) {
    edge_t *edge = malloc(sizeof(edge_t));
    edge->node1 = node1;
    edge->node2 = node2;
    edge->weight = weight;
    return edge;
}

graph_t *create_graph() {
    graph_t *graph = malloc(sizeof(graph_t));
    graph->nodes = malloc(sizeof(node_t *) * 100);
    graph->edges = malloc(sizeof(edge_t *) * 100);
    graph->num_nodes = 0;
    graph->num_edges = 0;
    return graph;
}

void add_node_to_graph(graph_t *graph, node_t *node) {
    graph->nodes[graph->num_nodes] = node;
    graph->num_nodes++;
}

void add_edge_to_graph(graph_t *graph, edge_t *edge) {
    graph->edges[graph->num_edges] = edge;
    graph->num_edges++;
}

void print_graph(graph_t *graph) {
    for (int i = 0; i < graph->num_nodes; i++) {
        printf("Node %s:\n", graph->nodes[i]->name);
        printf("    IP Address: %s\n", graph->nodes[i]->ip_address);
        printf("    MAC Address: %s\n", graph->nodes[i]->mac_address);
        printf("    Number of Connected Devices: %d\n", graph->nodes[i]->num_connected_devices);
    }

    for (int i = 0; i < graph->num_edges; i++) {
        printf("Edge %d:\n", i);
        printf("    Node 1: %s\n", graph->edges[i]->node1->name);
        printf("    Node 2: %s\n", graph->edges[i]->node2->name);
        printf("    Weight: %d\n", graph->edges[i]->weight);
    }
}

int main() {
    // Create a graph to represent the network topology
    graph_t *graph = create_graph();

    // Add nodes to the graph
    node_t *node1 = create_node("Node 1", "192.168.1.1", "00:11:22:33:44:55");
    add_node_to_graph(graph, node1);

    node_t *node2 = create_node("Node 2", "192.168.1.2", "11:22:33:44:55:66");
    add_node_to_graph(graph, node2);

    node_t *node3 = create_node("Node 3", "192.168.1.3", "22:33:44:55:66:77");
    add_node_to_graph(graph, node3);

    // Add edges to the graph
    edge_t *edge1 = create_edge(node1, node2, 10);
    add_edge_to_graph(graph, edge1);

    edge_t *edge2 = create_edge(node2, node3, 20);
    add_edge_to_graph(graph, edge2);

    edge_t *edge3 = create_edge(node1, node3, 30);
    add_edge_to_graph(graph, edge3);

    // Print the graph
    print_graph(graph);

    return 0;
}