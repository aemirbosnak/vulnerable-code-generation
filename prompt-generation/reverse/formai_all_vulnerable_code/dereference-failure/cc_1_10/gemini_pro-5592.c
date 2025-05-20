//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#define MAX_LINK 20
#define MAX_NODE 10
struct link {
    int node1, node2;
    int weight;
};
struct node {
    char *name;
    int x, y;
    int num_links;
    struct link links[MAX_LINK];
};
struct graph {
    int num_nodes;
    struct node nodes[MAX_NODE];
};
void print_graph(struct graph *g) {
    for (int i = 0; i < g->num_nodes; i++) {
        printf("%s (%d, %d)\n", g->nodes[i].name, g->nodes[i].x, g->nodes[i].y);
        for (int j = 0; j < g->nodes[i].num_links; j++) {
            printf("  - %s (%d)\n", g->nodes[g->nodes[i].links[j].node2].name, g->nodes[i].links[j].weight);
        }
    }
}
int main() {
    struct graph g;
    g.num_nodes = 4;
    g.nodes[0].name = "A";
    g.nodes[0].x = 0;
    g.nodes[0].y = 0;
    g.nodes[0].num_links = 2;
    g.nodes[0].links[0].node2 = 1;
    g.nodes[0].links[0].weight = 1;
    g.nodes[0].links[1].node2 = 2;
    g.nodes[0].links[1].weight = 2;
    g.nodes[1].name = "B";
    g.nodes[1].x = 1;
    g.nodes[1].y = 0;
    g.nodes[1].num_links = 2;
    g.nodes[1].links[0].node2 = 0;
    g.nodes[1].links[0].weight = 1;
    g.nodes[1].links[1].node2 = 2;
    g.nodes[1].links[1].weight = 3;
    g.nodes[2].name = "C";
    g.nodes[2].x = 2;
    g.nodes[2].y = 0;
    g.nodes[2].num_links = 2;
    g.nodes[2].links[0].node2 = 0;
    g.nodes[2].links[0].weight = 2;
    g.nodes[2].links[1].node2 = 1;
    g.nodes[2].links[1].weight = 3;
    g.nodes[3].name = "D";
    g.nodes[3].x = 3;
    g.nodes[3].y = 0;
    g.nodes[3].num_links = 1;
    g.nodes[3].links[0].node2 = 2;
    g.nodes[3].links[0].weight = 4;
    print_graph(&g);
    return 0;
}