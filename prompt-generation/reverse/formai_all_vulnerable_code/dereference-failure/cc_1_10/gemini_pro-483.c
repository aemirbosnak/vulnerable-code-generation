//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>

// Structure to store the topology map
typedef struct topology_map {
    int num_nodes;
    int num_edges;
    int **adj_matrix;
} topology_map;

// Function to create a new topology map
topology_map* create_topology_map() {
    topology_map *map = malloc(sizeof(topology_map));
    map->num_nodes = 0;
    map->num_edges = 0;
    map->adj_matrix = NULL;
    return map;
}

// Function to add a node to the topology map
void add_node_to_topology_map(topology_map *map, char *hostname) {
    // Check if the node already exists in the map
    for (int i = 0; i < map->num_nodes; i++) {
        if (strcmp(map->adj_matrix[i], hostname) == 0) {
            return;
        }
    }

    // Add the node to the map
    map->num_nodes++;
    map->adj_matrix = realloc(map->adj_matrix, map->num_nodes * sizeof(int *));
    map->adj_matrix[map->num_nodes - 1] = malloc(map->num_nodes * sizeof(int));
    for (int i = 0; i < map->num_nodes; i++) {
        map->adj_matrix[map->num_nodes - 1][i] = 0;
        map->adj_matrix[i][map->num_nodes - 1] = 0;
    }
}

// Function to add an edge to the topology map
void add_edge_to_topology_map(topology_map *map, char *hostname1, char *hostname2) {
    // Check if the nodes already exist in the map
    int node1 = -1;
    int node2 = -1;
    for (int i = 0; i < map->num_nodes; i++) {
        if (strcmp(map->adj_matrix[i], hostname1) == 0) {
            node1 = i;
        }
        if (strcmp(map->adj_matrix[i], hostname2) == 0) {
            node2 = i;
        }
    }

    // If either node does not exist, add it to the map
    if (node1 == -1) {
        add_node_to_topology_map(map, hostname1);
        node1 = map->num_nodes - 1;
    }
    if (node2 == -1) {
        add_node_to_topology_map(map, hostname2);
        node2 = map->num_nodes - 1;
    }

    // Add the edge to the map
    map->adj_matrix[node1][node2] = 1;
    map->adj_matrix[node2][node1] = 1;
    map->num_edges++;
}

// Function to print the topology map
void print_topology_map(topology_map *map) {
    printf("Topology map:\n");
    for (int i = 0; i < map->num_nodes; i++) {
        printf("%s: ", map->adj_matrix[i]);
        for (int j = 0; j < map->num_nodes; j++) {
            printf("%d ", map->adj_matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to free the memory allocated for the topology map
void free_topology_map(topology_map *map) {
    for (int i = 0; i < map->num_nodes; i++) {
        free(map->adj_matrix[i]);
    }
    free(map->adj_matrix);
    free(map);
}

int main() {
    // Create a new topology map
    topology_map *map = create_topology_map();

    // Add some nodes to the map
    add_node_to_topology_map(map, "node1");
    add_node_to_topology_map(map, "node2");
    add_node_to_topology_map(map, "node3");

    // Add some edges to the map
    add_edge_to_topology_map(map, "node1", "node2");
    add_edge_to_topology_map(map, "node2", "node3");
    add_edge_to_topology_map(map, "node3", "node1");

    // Print the topology map
    print_topology_map(map);

    // Free the memory allocated for the topology map
    free_topology_map(map);

    return 0;
}