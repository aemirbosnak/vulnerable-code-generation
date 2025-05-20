//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_NODES 100 // Maximum number of nodes in the network
#define INF INT_MAX   // Infinity for Dijkstra's algorithm

// Node structure to store information about a network node
struct Node {
    int id;
    int num_neighbors;
    int* neighbor_ids;
};

// Graph structure to store the network topology information
struct Graph {
    int num_nodes;
    struct Node* nodes;
    int** adj_matrix;
};

// Function to create a new node with the given id
struct Node* create_node(int id) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->id = id;
    node->num_neighbors = 0;
    node->neighbor_ids = NULL;
    return node;
}

// Function to add a neighbor to the given node
void add_neighbor(struct Node* node, int neighbor_id) {
    node->num_neighbors++;
    node->neighbor_ids = (int*) realloc(node->neighbor_ids, node->num_neighbors * sizeof(int));
    node->neighbor_ids[node->num_neighbors - 1] = neighbor_id;
}

// Function to create a new graph with the given number of nodes
struct Graph* create_graph(int num_nodes) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->num_nodes = num_nodes;
    graph->nodes = (struct Node*) malloc(num_nodes * sizeof(struct Node));
    graph->adj_matrix = (int**) malloc(num_nodes * sizeof(int*));
    for (int i = 0; i < num_nodes; i++) {
        graph->nodes[i] = *create_node(i);
        graph->adj_matrix[i] = (int*) calloc(num_nodes, sizeof(int)); // Initialize adjacency matrix with all zeros
    }
    return graph;
}

// Function to add an edge between the specified nodes with the given weight
void add_edge(struct Graph* graph, int node1_id, int node2_id, int weight) {
    graph->adj_matrix[node1_id][node2_id] = weight;
    graph->adj_matrix[node2_id][node1_id] = weight;
    add_neighbor(&graph->nodes[node1_id], node2_id);
    add_neighbor(&graph->nodes[node2_id], node1_id);
}

// Function to print the adjacency matrix of the given graph
void print_adj_matrix(struct Graph* graph) {
    printf("Adjacency matrix:\n");
    for (int i = 0; i < graph->num_nodes; i++) {
        for (int j = 0; j < graph->num_nodes; j++) {
            printf("%d ", graph->adj_matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to print the list of neighbor nodes for each node in the given graph
void print_neighbor_list(struct Graph* graph) {
    printf("Neighbor list:\n");
    for (int i = 0; i < graph->num_nodes; i++) {
        printf("Node %d: ", i);
        for (int j = 0; j < graph->nodes[i].num_neighbors; j++) {
            printf("%d ", graph->nodes[i].neighbor_ids[j]);
        }
        printf("\n");
    }
}

// Function to find the shortest paths from the given source node to all other nodes in the graph using Dijkstra's algorithm
void dijkstra(struct Graph* graph, int source_id, int* dist) {
    bool visited[graph->num_nodes];
    for (int i = 0; i < graph->num_nodes; i++) {
        visited[i] = false;
        dist[i] = INF;
    }
    dist[source_id] = 0;
    for (int count = 0; count < graph->num_nodes - 1; count++) {
        int u = -1;
        for (int i = 0; i < graph->num_nodes; i++) {
            if (!visited[i] && (u == -1 || dist[i] < dist[u])) {
                u = i;
            }
        }
        visited[u] = true;
        for (int i = 0; i < graph->nodes[u].num_neighbors; i++) {
            int v = graph->nodes[u].neighbor_ids[i];
            int weight = graph->adj_matrix[u][v];
            if (!visited[v] && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }
    printf("Shortest paths from node %d:\n", source_id);
    for (int i = 0; i < graph->num_nodes; i++) {
        printf("To node %d: %d\n", i, dist[i]);
    }
}

int main() {
    struct Graph* graph = create_graph(5);
    add_edge(graph, 0, 1, 2);
    add_edge(graph, 0, 4, 5);
    add_edge(graph, 1, 3, 6);
    add_edge(graph, 2, 3, 1);
    add_edge(graph, 3, 4, 4);
    print_adj_matrix(graph);
    print_neighbor_list(graph);
    int dist[graph->num_nodes];
    dijkstra(graph, 0, dist);
    free(graph);
    return 0;
}