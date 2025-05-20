//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

// Data structures
typedef struct {
    char *hostname;
    char *ip_address;
    int num_hops;
    int distance;
} Node;

typedef struct {
    Node **nodes;
    int num_nodes;
} Graph;

// Function prototypes
Graph *create_graph(int num_nodes);
void add_node_to_graph(Graph *graph, Node *node);
Node *find_node_by_hostname(Graph *graph, char *hostname);
Node *find_node_by_ip_address(Graph *graph, char *ip_address);
int get_distance_between_nodes(Graph *graph, Node *node1, Node *node2);
void print_graph(Graph *graph);

// Main function
int main() {
    // Create a graph with 10 nodes
    Graph *graph = create_graph(10);

    // Add some nodes to the graph
    Node *node1 = malloc(sizeof(Node));
    node1->hostname = "www.google.com";
    node1->ip_address = "8.8.8.8";
    node1->num_hops = 1;
    node1->distance = 0;
    add_node_to_graph(graph, node1);

    Node *node2 = malloc(sizeof(Node));
    node2->hostname = "www.facebook.com";
    node2->ip_address = "31.13.94.34";
    node2->num_hops = 2;
    node2->distance = 1;
    add_node_to_graph(graph, node2);

    Node *node3 = malloc(sizeof(Node));
    node3->hostname = "www.amazon.com";
    node3->ip_address = "52.216.220.44";
    node3->num_hops = 3;
    node3->distance = 2;
    add_node_to_graph(graph, node3);

    // Find the distance between two nodes
    int distance = get_distance_between_nodes(graph, node1, node3);
    printf("The distance between %s and %s is %d\n", node1->hostname, node3->hostname, distance);

    // Print the graph
    print_graph(graph);

    return 0;
}

// Function to create a graph with a specified number of nodes
Graph *create_graph(int num_nodes) {
    Graph *graph = malloc(sizeof(Graph));
    graph->nodes = malloc(sizeof(Node *) * num_nodes);
    graph->num_nodes = 0;
    return graph;
}

// Function to add a node to a graph
void add_node_to_graph(Graph *graph, Node *node) {
    graph->nodes[graph->num_nodes] = node;
    graph->num_nodes++;
}

// Function to find a node in a graph by its hostname
Node *find_node_by_hostname(Graph *graph, char *hostname) {
    for (int i = 0; i < graph->num_nodes; i++) {
        if (strcmp(graph->nodes[i]->hostname, hostname) == 0) {
            return graph->nodes[i];
        }
    }
    return NULL;
}

// Function to find a node in a graph by its IP address
Node *find_node_by_ip_address(Graph *graph, char *ip_address) {
    for (int i = 0; i < graph->num_nodes; i++) {
        if (strcmp(graph->nodes[i]->ip_address, ip_address) == 0) {
            return graph->nodes[i];
        }
    }
    return NULL;
}

// Function to get the distance between two nodes in a graph
int get_distance_between_nodes(Graph *graph, Node *node1, Node *node2) {
    if (node1 == node2) {
        return 0;
    }
    int distance = -1;
    for (int i = 0; i < graph->num_nodes; i++) {
        if (graph->nodes[i] == node1) {
            distance = graph->nodes[i]->distance + 1;
        } else if (graph->nodes[i] == node2) {
            distance = graph->nodes[i]->distance + 1;
        }
    }
    return distance;
}

// Function to print a graph
void print_graph(Graph *graph) {
    for (int i = 0; i < graph->num_nodes; i++) {
        printf("%s (%s)\n", graph->nodes[i]->hostname, graph->nodes[i]->ip_address);
    }
}