//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_HOSTS 1024
#define MAX_CONNECTIONS 1024
#define MAX_GRAPH_SIZE 1024 * 1024

typedef struct host_info {
    char *name;
    unsigned int ip;
    int port;
    int connected;
} host_info;

typedef struct graph_edge {
    host_info *host1;
    host_info *host2;
    int weight;
} graph_edge;

typedef struct graph {
    host_info *hosts[MAX_HOSTS];
    graph_edge *edges[MAX_GRAPH_SIZE];
    int num_hosts;
    int num_edges;
} graph;

host_info *create_host_info(char *name, unsigned int ip, int port) {
    host_info *host = malloc(sizeof(host_info));
    host->name = strdup(name);
    host->ip = ip;
    host->port = port;
    host->connected = 0;
    return host;
}

void free_host_info(host_info *host) {
    free(host->name);
    free(host);
}

graph_edge *create_graph_edge(host_info *host1, host_info *host2, int weight) {
    graph_edge *edge = malloc(sizeof(graph_edge));
    edge->host1 = host1;
    edge->host2 = host2;
    edge->weight = weight;
    return edge;
}

void free_graph_edge(graph_edge *edge) {
    free(edge);
}

graph *create_graph() {
    graph *g = malloc(sizeof(graph));
    g->num_hosts = 0;
    g->num_edges = 0;
    return g;
}

void free_graph(graph *g) {
    for (int i = 0; i < g->num_hosts; i++) {
        free_host_info(g->hosts[i]);
    }
    for (int i = 0; i < g->num_edges; i++) {
        free_graph_edge(g->edges[i]);
    }
    free(g);
}

int add_host_to_graph(graph *g, host_info *host) {
    if (g->num_hosts >= MAX_HOSTS) {
        return -1;
    }
    g->hosts[g->num_hosts++] = host;
    return 0;
}

int add_edge_to_graph(graph *g, graph_edge *edge) {
    if (g->num_edges >= MAX_GRAPH_SIZE) {
        return -1;
    }
    g->edges[g->num_edges++] = edge;
    return 0;
}

int connect_to_host(host_info *host) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        return -1;
    }

    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(host->port);
    servaddr.sin_addr.s_addr = host->ip;

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        return -1;
    }

    host->connected = 1;
    return sockfd;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <hostfile>\n", argv[0]);
        return 1;
    }

    FILE *hostfile = fopen(argv[1], "r");
    if (hostfile == NULL) {
        printf("Error opening hostfile.\n");
        return 1;
    }

    graph *g = create_graph();

    char line[1024];
    while (fgets(line, sizeof(line), hostfile) != NULL) {
        char *name = strtok(line, " ");
        char *ip_str = strtok(NULL, " ");
        char *port_str = strtok(NULL, " ");

        if (name == NULL || ip_str == NULL || port_str == NULL) {
            continue;
        }

        unsigned int ip = inet_addr(ip_str);
        int port = atoi(port_str);

        host_info *host = create_host_info(name, ip, port);
        add_host_to_graph(g, host);
    }

    fclose(hostfile);

    int num_connections = 0;
    for (int i = 0; i < g->num_hosts; i++) {
        host_info *host1 = g->hosts[i];

        for (int j = i + 1; j < g->num_hosts; j++) {
            host_info *host2 = g->hosts[j];

            int sockfd1 = connect_to_host(host1);
            if (sockfd1 == -1) {
                continue;
            }

            int sockfd2 = connect_to_host(host2);
            if (sockfd2 == -1) {
                close(sockfd1);
                continue;
            }

            num_connections++;

            graph_edge *edge = create_graph_edge(host1, host2, 1);
            add_edge_to_graph(g, edge);

            close(sockfd1);
            close(sockfd2);
        }
    }

    printf("Discovered %d hosts and %d connections.\n", g->num_hosts, num_connections);

    free_graph(g);

    return 0;
}