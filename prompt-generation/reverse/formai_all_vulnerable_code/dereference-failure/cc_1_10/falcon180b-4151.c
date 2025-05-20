//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NODES 100
#define MAX_LINES 1000

typedef struct {
    char name[20];
    int connections[MAX_NODES];
    int num_connections;
} Node;

Node nodes[MAX_NODES];
int num_nodes = 0;

void add_node(char *name) {
    nodes[num_nodes].name[0] = '\0';
    strcpy(nodes[num_nodes].name, name);
    nodes[num_nodes].num_connections = 0;
    for (int i = 0; i < MAX_NODES; i++) {
        nodes[num_nodes].connections[i] = -1;
    }
    num_nodes++;
}

void add_connection(char *line) {
    char *token = strtok(line, " ");
    int node1 = -1;
    for (int i = 0; i < num_nodes; i++) {
        if (strcmp(token, nodes[i].name) == 0) {
            node1 = i;
            break;
        }
    }
    if (node1 == -1) {
        add_node(token);
        node1 = num_nodes - 1;
    }
    int num_connections = 0;
    while ((token = strtok(NULL, " "))!= NULL) {
        for (int i = 0; i < num_nodes; i++) {
            if (strcmp(token, nodes[i].name) == 0) {
                nodes[node1].connections[num_connections++] = i;
            }
        }
    }
    nodes[node1].num_connections = num_connections;
}

void print_node(int index) {
    printf("Node %s: ", nodes[index].name);
    for (int i = 0; i < num_nodes; i++) {
        if (nodes[index].connections[i]!= -1) {
            printf("%s ", nodes[i].name);
        }
    }
    printf("\n");
}

int main() {
    char line[MAX_LINES];
    while (fgets(line, MAX_LINES, stdin)!= NULL) {
        add_connection(line);
    }
    for (int i = 0; i < num_nodes; i++) {
        print_node(i);
    }
    return 0;
}