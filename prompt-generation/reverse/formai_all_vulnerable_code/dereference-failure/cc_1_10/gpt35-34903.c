//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NETWORK_SIZE 100

/**
 * This is a simple example program that maps the topology of a small network.
 * The program reads network information (nodes and their connections) from a file,
 * then it builds a network graph and prints it to the console.
 *
 * The network graph is represented as an adjacency matrix.
 */

int get_node_index(char* node, char** nodes, int node_count) {
    for (int i = 0; i < node_count; i++) {
        if (strcmp(node, nodes[i]) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    // Read network information from file
    char* filename = "network.txt";
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Could not open file %s\n", filename);
        return 1;
    }

    char* nodes[MAX_NETWORK_SIZE];
    int connections[MAX_NETWORK_SIZE][MAX_NETWORK_SIZE];
    memset(connections, 0, sizeof(connections));

    int node_count = 0;
    char line[100];
    while (fgets(line, sizeof(line), file)) {
        char* node1 = strtok(line, " \n");
        char* node2 = strtok(NULL, " \n");

        int index1 = get_node_index(node1, nodes, node_count);
        if (index1 == -1) {
            nodes[node_count] = node1;
            index1 = node_count;
            node_count++;
        }

        int index2 = get_node_index(node2, nodes, node_count);
        if (index2 == -1) {
            nodes[node_count] = node2;
            index2 = node_count;
            node_count++;
        }

        connections[index1][index2] = 1;
        connections[index2][index1] = 1;
    }

    // Print network graph
    printf("Network Topology:\n");
    for (int i = 0; i < node_count; i++) {
        printf("%s | ", nodes[i]);
        for (int j = 0; j < node_count; j++) {
            printf("%d ", connections[i][j]);
        }
        printf("\n");
    }

    return 0;
}