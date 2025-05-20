//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINKS 10
#define MAX_NODES 20

typedef struct Node {
    char name[20];
    struct Node** links;
    int numLinks;
} Node;

void mapNetwork(Node** nodes, int numNodes) {
    for (int i = 0; i < numNodes; i++) {
        nodes[i]->links = malloc(sizeof(struct Node*) * MAX_LINKS);
        nodes[i]->numLinks = 0;
    }
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            if (i != j) {
                int linkExists = 0;
                for (int k = 0; k < nodes[i]->numLinks; k++) {
                    if (strcmp(nodes[i]->links[k]->name, nodes[j]->name) == 0) {
                        linkExists = 1;
                    }
                }
                if (!linkExists) {
                    nodes[i]->links[nodes[i]->numLinks++] = nodes[j];
                }
            }
        }
    }
}

int main() {
    Node** nodes = malloc(sizeof(struct Node*) * MAX_NODES);
    for (int i = 0; i < MAX_NODES; i++) {
        nodes[i] = NULL;
    }

    mapNetwork(nodes, 5);

    for (int i = 0; i < 5; i++) {
        printf("%s has %d links:\n", nodes[i]->name, nodes[i]->numLinks);
        for (int j = 0; j < nodes[i]->numLinks; j++) {
            printf("  %s\n", nodes[i]->links[j]->name);
        }
    }

    return 0;
}