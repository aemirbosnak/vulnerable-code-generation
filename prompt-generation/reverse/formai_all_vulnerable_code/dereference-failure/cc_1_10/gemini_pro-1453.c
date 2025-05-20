//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdbool.h>

// Custom data structures to store nodes and edges
typedef struct node {
    char *name;
    struct node *next;
} node_t;

typedef struct edge {
    struct node *src;
    struct node *dst;
    int weight;
    struct edge *next;
} edge_t;

// Function to create a new node
node_t *create_node(char *name) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->name = strdup(name);
    new_node->next = NULL;
    return new_node;
}

// Function to create a new edge
edge_t *create_edge(node_t *src, node_t *dst, int weight) {
    edge_t *new_edge = (edge_t *)malloc(sizeof(edge_t));
    new_edge->src = src;
    new_edge->dst = dst;
    new_edge->weight = weight;
    new_edge->next = NULL;
    return new_edge;
}

// Function to add a node to the network
void add_node(node_t **head, char *name) {
    node_t *new_node = create_node(name);
    if (*head == NULL) {
        *head = new_node;
    } else {
        node_t *tmp = *head;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = new_node;
    }
}

// Function to add an edge to the network
void add_edge(edge_t **head, node_t *src, node_t *dst, int weight) {
    edge_t *new_edge = create_edge(src, dst, weight);
    if (*head == NULL) {
        *head = new_edge;
    } else {
        edge_t *tmp = *head;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = new_edge;
    }
}

// Function to print the network
void print_network(node_t *head, edge_t *head_edge) {
    printf("Nodes:\n");
    node_t *tmp = head;
    while (tmp != NULL) {
        printf("  %s\n", tmp->name);
        tmp = tmp->next;
    }

    printf("Edges:\n");
    edge_t *tmp_edge = head_edge;
    while (tmp_edge != NULL) {
        printf("  %s -> %s (%d)\n", tmp_edge->src->name, tmp_edge->dst->name, tmp_edge->weight);
        tmp_edge = tmp_edge->next;
    }
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <network file>\n", argv[0]);
        return 1;
    }

    // Open the network file
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("Error opening network file");
        return 1;
    }

    // Read the number of nodes and edges from the file
    int num_nodes, num_edges;
    fscanf(fp, "%d %d", &num_nodes, &num_edges);

    // Create an array to store the nodes
    node_t *nodes[num_nodes];

    // Read the nodes from the file
    for (int i = 0; i < num_nodes; i++) {
        char name[256];
        fscanf(fp, "%s", name);
        add_node(nodes, name);
    }

    // Create an array to store the edges
    edge_t *edges[num_edges];

    // Read the edges from the file
    for (int i = 0; i < num_edges; i++) {
        char src_name[256], dst_name[256];
        int weight;
        fscanf(fp, "%s %s %d", src_name, dst_name, &weight);
        node_t *src = NULL, *dst = NULL;
        for (int j = 0; j < num_nodes; j++) {
            if (strcmp(nodes[j]->name, src_name) == 0) {
                src = nodes[j];
            } else if (strcmp(nodes[j]->name, dst_name) == 0) {
                dst = nodes[j];
            }
        }
        add_edge(edges, src, dst, weight);
    }

    // Print the network
    print_network(nodes[0], edges[0]);

    // Close the network file
    fclose(fp);

    return 0;
}