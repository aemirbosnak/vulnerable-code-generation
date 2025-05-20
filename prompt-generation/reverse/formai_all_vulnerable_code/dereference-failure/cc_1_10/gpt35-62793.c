//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<unistd.h>

#define MAX_NODES 100
#define MAX_EDGES 1000

struct Edge{
    int src, dest;
    float cost;
};

struct Graph{
    int num_nodes, num_edges;
    struct Edge edges[MAX_EDGES];
};

void init_graph(struct Graph* graph, int num_nodes, int num_edges){
    graph->num_nodes = num_nodes;
    graph->num_edges = num_edges;
}

void add_edge(struct Graph* graph, int src, int dest, float cost){
    struct Edge edge = {src, dest, cost};
    graph->edges[graph->num_edges++] = edge;
}

struct Node{
    int id;
    struct sockaddr_in address;
};

struct Node nodes[MAX_NODES];
int num_nodes = 0;

void add_node(char* ip){
    struct Node node;
    node.id = num_nodes;
    num_nodes++;

    memset(&node.address, 0, sizeof(node.address));
    node.address.sin_family = AF_INET;
    node.address.sin_port = htons(1024); //arbitrary port for now
    inet_pton(AF_INET, ip, &(node.address.sin_addr));

    nodes[node.id] = node;
}

void map_network(struct Graph* graph){
    //code to map the network here
}

int main(){
    int num_nodes, num_edges;
    printf("Enter number of nodes: ");
    scanf("%d", &num_nodes);
    printf("Enter number of edges: ");
    scanf("%d", &num_edges);

    struct Graph graph;
    init_graph(&graph, num_nodes, num_edges);

    for(int i=0; i<num_edges; i++){
        int src, dest;
        float cost;
        printf("Enter details for edge %d:\n", i+1);
        printf("Source node id: ");
        scanf("%d", &src);
        printf("Destination node id: ");
        scanf("%d", &dest);
        printf("Cost of edge: ");
        scanf("%f", &cost);
        add_edge(&graph, src, dest, cost);
    }

    for(int i=0; i<num_nodes; i++){
        char ip[20];
        printf("Enter IP address for node %d: ", i);
        scanf("%s", ip);
        add_node(ip);
    }

    map_network(&graph);

    return 0;
}