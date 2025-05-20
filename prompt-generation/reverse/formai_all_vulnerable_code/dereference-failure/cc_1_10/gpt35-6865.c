//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NODES 1024

typedef struct Node {
    char* name;
    int id;
    int num_neighbors;
    struct Node** neighbors;
} Node;

int nodes_count = 0;
Node* nodes[MAX_NODES];

Node* get_node_by_name(char* name) {
    int i;
    for (i = 0; i < nodes_count; i++) {
        if (strcmp(nodes[i]->name, name) == 0) {
            return nodes[i];
        }
    }
    return NULL;
}

Node* create_node(char* name) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->name = strdup(name);
    node->id = nodes_count;
    node->num_neighbors = 0;
    node->neighbors = (Node**) malloc(sizeof(Node*) * MAX_NODES);
    nodes[nodes_count++] = node;
    return node;
}

void connect_nodes(char* name1, char* name2) {
    Node* node1 = get_node_by_name(name1);
    Node* node2 = get_node_by_name(name2);
    if (node1 == NULL) {
        node1 = create_node(name1);
    }
    if (node2 == NULL) {
        node2 = create_node(name2);
    }
    node1->neighbors[node1->num_neighbors++] = node2;
    node2->neighbors[node2->num_neighbors++] = node1;
}

void print_topology_map() {
    printf("----------Topology Map----------\n");
    int i, j;
    for (i = 0; i < nodes_count; i++) {
        Node* node = nodes[i];
        printf("Node: %s (ID: %d)\n", node->name, node->id);
        printf("Neighbors:\n");
        for (j = 0; j < node->num_neighbors; j++) {
            printf("\t- %s (ID: %d)\n", node->neighbors[j]->name, node->neighbors[j]->id);
        }
    }
    printf("--------------------------------\n");
}

int main() {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen("network_topology.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, fp)) != -1) {
        char* name1 = strtok(line, ",");
        char* name2 = strtok(NULL, "\n");
        connect_nodes(name1, name2);
    }

    fclose(fp);
    if (line) {
        free(line);
    }

    print_topology_map();
    return 0;
}