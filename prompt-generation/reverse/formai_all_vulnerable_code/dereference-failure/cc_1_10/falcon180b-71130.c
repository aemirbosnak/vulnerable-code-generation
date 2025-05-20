//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_LINKS 200

typedef struct node {
    int id;
    char name[50];
    int num_links;
    int *links;
} Node;

typedef struct link {
    int from;
    int to;
    int cost;
} Link;

void add_link(Node *node, int from, int to, int cost) {
    node->num_links++;
    node->links = realloc(node->links, sizeof(int) * node->num_links);
    node->links[node->num_links - 1] = from;
}

int main() {
    Node nodes[MAX_NODES];
    Link links[MAX_LINKS];
    int num_nodes = 0;
    int num_links = 0;

    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);

    for (int i = 0; i < num_nodes; i++) {
        printf("Enter the name of node %d: ", i + 1);
        scanf("%s", nodes[i].name);
        nodes[i].id = i + 1;
        nodes[i].num_links = 0;
        nodes[i].links = NULL;
    }

    printf("Enter the number of links: ");
    scanf("%d", &num_links);

    for (int i = 0; i < num_links; i++) {
        printf("Enter the link details (from, to, cost): ");
        scanf("%d %d %d", &links[i].from, &links[i].to, &links[i].cost);
        add_link(&nodes[links[i].from - 1], links[i].from, links[i].to, links[i].cost);
    }

    printf("Network Topology:\n");
    for (int i = 0; i < num_nodes; i++) {
        printf("Node %d: %s\n", nodes[i].id, nodes[i].name);
        for (int j = 0; j < nodes[i].num_links; j++) {
            printf("  -> Node %d (cost %d)\n", nodes[i].links[j], nodes[i].links[j]);
        }
    }

    return 0;
}