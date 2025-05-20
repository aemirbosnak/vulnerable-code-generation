//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NODES 100
#define MAX_LINES 1000
#define MAX_LINE_LENGTH 100

typedef struct {
    char name[MAX_LINE_LENGTH];
    int num_connections;
    int *connected_nodes;
} Node;

typedef struct {
    int num_nodes;
    Node *nodes;
} Network;

void read_network(Network *net) {
    FILE *fp = fopen("network.txt", "r");
    char line[MAX_LINE_LENGTH];
    int num_nodes = 0;
    int i = 0;

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        if (line[0] == '#') {
            continue;
        }

        Node *node = &net->nodes[num_nodes];
        strcpy(node->name, line);
        node->num_connections = 0;
        node->connected_nodes = NULL;

        char *token = strtok(line, " ");
        while (token!= NULL) {
            if (num_nodes >= MAX_NODES) {
                printf("Error: Too many nodes.\n");
                exit(1);
            }

            if (i == 0) {
                node->connected_nodes = (int*)malloc(sizeof(int));
            } else {
                node->connected_nodes = (int*)realloc(node->connected_nodes, sizeof(int) * (i+1));
            }

            node->connected_nodes[i] = atoi(token);
            node->num_connections++;

            i++;
            token = strtok(NULL, " ");
        }

        num_nodes++;
    }

    fclose(fp);
}

void print_network(Network *net) {
    for (int i = 0; i < net->num_nodes; i++) {
        Node *node = &net->nodes[i];
        printf("%s (%d connections):\n", node->name, node->num_connections);

        for (int j = 0; j < node->num_connections; j++) {
            printf("\t%d\n", node->connected_nodes[j]);
        }
    }
}

void free_network(Network *net) {
    for (int i = 0; i < net->num_nodes; i++) {
        Node *node = &net->nodes[i];
        free(node->connected_nodes);
    }

    free(net->nodes);
}

int main() {
    Network net;
    read_network(&net);
    print_network(&net);
    free_network(&net);

    return 0;
}