//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NODES 100
#define MAX_EDGES 200

// Define a structure to hold the network information
typedef struct {
    char name[50];
    int num_edges;
    int edges[MAX_EDGES];
} Node;

// Define a function to parse the input file
void parse_input(Node* nodes, FILE* input) {
    char line[100];
    char* token;
    int count = 0;

    while (fgets(line, sizeof(line), input)) {
        if (line[0] == '#') {
            // Skip comments
            continue;
        }

        // Parse the node name
        token = strtok(line, " ");
        strcpy(nodes[count].name, token);

        // Parse the number of edges
        token = strtok(NULL, " ");
        nodes[count].num_edges = atoi(token);

        // Parse the edges
        for (int i = 0; i < nodes[count].num_edges; i++) {
            token = strtok(NULL, " ");
            nodes[count].edges[i] = atoi(token);
        }

        count++;
    }
}

// Define a function to print the network topology
void print_topology(Node* nodes) {
    for (int i = 0; i < MAX_NODES; i++) {
        if (nodes[i].name[0]!= '\0') {
            printf("%s:\n", nodes[i].name);
            for (int j = 0; j < nodes[i].num_edges; j++) {
                printf("\t%d\n", nodes[i].edges[j]);
            }
        }
    }
}

// Define the main function
int main() {
    Node nodes[MAX_NODES];

    // Open the input file
    FILE* input = fopen("input.txt", "r");

    // Parse the input file
    parse_input(nodes, input);

    // Print the network topology
    print_topology(nodes);

    // Close the input file
    fclose(input);

    return 0;
}