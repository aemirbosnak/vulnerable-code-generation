//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_HOSTS 256
#define MAX_PORTS 65535

struct host_info {
    char *hostname;
    struct hostent *host;
    struct in_addr addr;
};

struct port_info {
    int port;
    int open;
};

struct topology {
    struct host_info hosts[MAX_HOSTS];
    int num_hosts;
    struct port_info ports[MAX_PORTS];
    int num_ports;
    struct adjacency_list {
        int *neighbors;
        int num_neighbors;
    } adj_list[MAX_HOSTS];
};

struct topology *create_topology(void) {
    struct topology *topo = malloc(sizeof(struct topology));
    if (!topo) {
        return NULL;
    }
    topo->num_hosts = 0;
    topo->num_ports = 0;
    return topo;
}

void destroy_topology(struct topology *topo) {
    int i;
    for (i = 0; i < topo->num_hosts; i++) {
        free(topo->hosts[i].hostname);
    }
    free(topo);
}

int add_host(struct topology *topo, char *hostname, struct in_addr addr) {
    if (topo->num_hosts >= MAX_HOSTS) {
        return -1;
    }
    topo->hosts[topo->num_hosts].hostname = strdup(hostname);
    topo->hosts[topo->num_hosts].host = gethostbyname(hostname);
    topo->hosts[topo->num_hosts].addr = addr;
    topo->num_hosts++;
    return 0;
}

int add_port(struct topology *topo, int port) {
    if (topo->num_ports >= MAX_PORTS) {
        return -1;
    }
    topo->ports[topo->num_ports].port = port;
    topo->ports[topo->num_ports].open = 0;
    topo->num_ports++;
    return 0;
}

int scan_port(struct topology *topo, struct host_info *host, int port) {
    int sockfd;
    struct sockaddr_in addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        return -1;
    }
    addr.sin_family = AF_INET;
    addr.sin_addr = host->addr;
    addr.sin_port = htons(port);
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
        topo->ports[port].open = 1;
        return 0;
    }
    close(sockfd);
    return -1;
}

int scan_ports(struct topology *topo) {
    int i, j;
    for (i = 0; i < topo->num_hosts; i++) {
        for (j = 0; j < topo->num_ports; j++) {
            scan_port(topo, &topo->hosts[i], topo->ports[j].port);
        }
    }
    return 0;
}

int build_adjacency_list(struct topology *topo) {
    int i, j, k;
    for (i = 0; i < topo->num_hosts; i++) {
        topo->adj_list[i].neighbors = malloc(sizeof(int) * topo->num_hosts);
        if (!topo->adj_list[i].neighbors) {
            return -1;
        }
        topo->adj_list[i].num_neighbors = 0;
        for (j = 0; j < topo->num_hosts; j++) {
            for (k = 0; k < topo->num_ports; k++) {
                if (topo->ports[k].open && topo->hosts[j].addr.s_addr == topo->hosts[i].addr.s_addr) {
                    topo->adj_list[i].neighbors[topo->adj_list[i].num_neighbors++] = j;
                }
            }
        }
    }
    return 0;
}

void print_topology(struct topology *topo) {
    int i, j;
    printf("Topology:\n");
    for (i = 0; i < topo->num_hosts; i++) {
        printf("Host %s (%s):\n", topo->hosts[i].hostname, inet_ntoa(topo->hosts[i].addr));
        for (j = 0; j < topo->adj_list[i].num_neighbors; j++) {
            printf("  - Neighbor: %s (%s)\n", topo->hosts[topo->adj_list[i].neighbors[j]].hostname, inet_ntoa(topo->hosts[topo->adj_list[i].neighbors[j]].addr));
        }
    }
}

int main(int argc, char **argv) {
    struct topology *topo;
    int i;
    if (argc < 2) {
        printf("Usage: %s <host1> <host2> ... <hostn>\n", argv[0]);
        return 1;
    }
    topo = create_topology();
    if (!topo) {
        printf("Error: Could not create topology.\n");
        return 1;
    }
    for (i = 1; i < argc; i++) {
        struct hostent *host = gethostbyname(argv[i]);
        if (!host) {
            printf("Error: Could not resolve hostname %s.\n", argv[i]);
            continue;
        }
        add_host(topo, argv[i], ((struct sockaddr_in *)host->h_addr)->sin_addr);
    }
    scan_ports(topo);
    build_adjacency_list(topo);
    print_topology(topo);
    destroy_topology(topo);
    return 0;
}