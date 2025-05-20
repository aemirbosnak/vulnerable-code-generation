//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_LINKS 200
#define NODE_NAME_LEN 20
#define LINK_NAME_LEN 20
#define LINK_BANDWIDTH_LEN 10

typedef struct {
    char name[NODE_NAME_LEN];
    int id;
} node_t;

typedef struct {
    char name[LINK_NAME_LEN];
    int src_node_id;
    int dst_node_id;
    char link_bandwidth[LINK_BANDWIDTH_LEN];
} link_t;

int num_nodes, num_links;
node_t nodes[MAX_NODES];
link_t links[MAX_LINKS];

void print_usage() {
    printf("Usage:./network_topology_mapper <num_nodes> <num_links>\n");
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        print_usage();
        return 1;
    }

    num_nodes = atoi(argv[1]);
    num_links = atoi(argv[2]);

    for (int i = 0; i < num_nodes; i++) {
        printf("Enter node name (max %d characters): ", NODE_NAME_LEN);
        scanf("%s", nodes[i].name);
        nodes[i].id = i;
    }

    for (int i = 0; i < num_links; i++) {
        printf("Enter link name (max %d characters): ", LINK_NAME_LEN);
        scanf("%s", links[i].name);

        printf("Enter source node ID: ");
        scanf("%d", &links[i].src_node_id);

        printf("Enter destination node ID: ");
        scanf("%d", &links[i].dst_node_id);

        printf("Enter link bandwidth (max %d characters): ", LINK_BANDWIDTH_LEN);
        scanf("%s", links[i].link_bandwidth);
    }

    // TODO: Implement network topology mapping logic

    return 0;
}