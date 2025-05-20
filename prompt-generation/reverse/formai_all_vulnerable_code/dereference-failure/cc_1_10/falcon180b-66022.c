//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NODES 100
#define MAX_LINKS 100

typedef struct {
    char name[20];
    int id;
    int links[MAX_LINKS];
    int num_links;
} Node;

void add_link(Node *node1, Node *node2) {
    int i;
    for (i = 0; i < node1->num_links; i++) {
        if (node1->links[i] == node2->id) {
            return;
        }
    }
    node1->links[node1->num_links] = node2->id;
    node1->num_links++;
}

int main() {
    int num_nodes, i;
    char input[100];

    printf("Enter number of nodes: ");
    scanf("%d", &num_nodes);

    Node nodes[MAX_NODES];
    for (i = 0; i < num_nodes; i++) {
        printf("Enter name of node %d: ", i+1);
        scanf("%s", nodes[i].name);
        nodes[i].id = i+1;
        nodes[i].num_links = 0;
    }

    printf("Enter links (node1 node2):\n");
    while (fgets(input, 100, stdin)!= NULL) {
        int node1_id, node2_id;
        sscanf(input, "%d %d", &node1_id, &node2_id);
        Node *node1 = &nodes[node1_id-1];
        Node *node2 = &nodes[node2_id-1];
        add_link(node1, node2);
        add_link(node2, node1);
    }

    printf("Network topology:\n");
    for (i = 0; i < num_nodes; i++) {
        printf("Node %d: %s\n", i+1, nodes[i].name);
        printf("Links:");
        for (int j = 0; j < nodes[i].num_links; j++) {
            printf(" %d", nodes[i].links[j]);
        }
        printf("\n");
    }

    return 0;
}