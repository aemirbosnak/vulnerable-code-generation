//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100

// Define a structure to represent a node in the network
typedef struct {
    char name[20]; // Name of the node
    int num_connections; // Number of connections to other nodes
    int connections[MAX_NODES]; // Array of indices for connected nodes
} Node;

// Function to print the network topology
void print_network(Node nodes[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s (connections: %d): ", nodes[i].name, nodes[i].num_connections);
        for (int j = 0; j < nodes[i].num_connections; j++) {
            printf("%d ", nodes[i].connections[j]);
        }
        printf("\n");
    }
}

int main() {
    Node nodes[MAX_NODES]; // Initialize the array of nodes
    int num_nodes = 0; // Initialize the number of nodes

    // Read in the network topology from a file
    FILE *fp = fopen("network.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    char line[100]; // Buffer to store each line of the file
    while (fgets(line, sizeof(line), fp)!= NULL) {
        // Parse the line to extract the node name and its connections
        char *token = strtok(line, " ");
        strcpy(nodes[num_nodes].name, token);
        nodes[num_nodes].num_connections = 0;

        while ((token = strtok(NULL, " "))!= NULL) {
            int connection = atoi(token);
            nodes[num_nodes].connections[nodes[num_nodes].num_connections++] = connection;
        }

        num_nodes++;
    }

    fclose(fp);

    // Print the network topology
    print_network(nodes, num_nodes);

    return 0;
}