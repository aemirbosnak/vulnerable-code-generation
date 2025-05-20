//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define INF 0x3f3f3f3f

//Node structure
struct node {
    int id;
    char name[20];
    int degree;
    int *adj_list;
};

//Edge structure
struct edge {
    int src;
    int dest;
    int weight;
};

//Topology Mapper function
void topology_mapper(int num_nodes, struct edge edges[], int num_edges) {
    //Initialize all nodes
    struct node nodes[MAX_NODES];
    int num_nodes_used = 0;
    for (int i = 0; i < num_nodes; i++) {
        nodes[i].id = i;
        strcpy(nodes[i].name, "Node ");
        nodes[i].degree = 0;
        nodes[i].adj_list = (int *)malloc(MAX_EDGES * sizeof(int));
        memset(nodes[i].adj_list, -1, MAX_EDGES * sizeof(int));
        num_nodes_used++;
    }

    //Add edges to nodes
    for (int i = 0; i < num_edges; i++) {
        int src_node_id = edges[i].src;
        int dest_node_id = edges[i].dest;
        int weight = edges[i].weight;

        //Add edge to source node
        nodes[src_node_id].degree++;
        nodes[src_node_id].adj_list[nodes[src_node_id].degree - 1] = dest_node_id;

        //Add edge to destination node
        nodes[dest_node_id].degree++;
        nodes[dest_node_id].adj_list[nodes[dest_node_id].degree - 1] = src_node_id;

        //Add weight to edge
        nodes[src_node_id].adj_list[nodes[src_node_id].degree - 1] = weight;
        nodes[dest_node_id].adj_list[nodes[dest_node_id].degree - 1] = weight;
    }

    //Print topology map
    printf("Topology Map:\n");
    for (int i = 0; i < num_nodes_used; i++) {
        printf("Node %d: %s\n", nodes[i].id, nodes[i].name);
        printf("Degree: %d\n", nodes[i].degree);
        printf("Adjacency List:\n");
        for (int j = 0; j < nodes[i].degree; j++) {
            printf("%d -> %d (Weight: %d)\n", nodes[i].id, nodes[i].adj_list[j], nodes[i].adj_list[j]);
        }
        printf("\n");
    }
}

//Main function
int main() {
    //Initialize topology mapper
    int num_nodes = 5;
    struct edge edges[] = {{0, 1, 5}, {0, 2, 8}, {1, 2, 2}, {1, 3, 3}, {2, 3, 4}, {2, 4, 6}};
    int num_edges = sizeof(edges) / sizeof(edges[0]);

    //Call topology_mapper function
    topology_mapper(num_nodes, edges, num_edges);

    return 0;
}