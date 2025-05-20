//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>

#define MAX_HOSTS 1024
#define MAX_PORTS 65535

typedef struct {
    char *ip;
    int port;
} host_t;

typedef struct {
    host_t *hosts;
    int num_hosts;
} network_t;

network_t *create_network(void) {
    network_t *network = malloc(sizeof(network_t));
    network->hosts = malloc(MAX_HOSTS * sizeof(host_t));
    network->num_hosts = 0;
    return network;
}

void free_network(network_t *network) {
    for (int i = 0; i < network->num_hosts; i++) {
        free(network->hosts[i].ip);
    }
    free(network->hosts);
    free(network);
}

int add_host(network_t *network, char *ip, int port) {
    if (network->num_hosts >= MAX_HOSTS) {
        return -1;
    }
    network->hosts[network->num_hosts].ip = strdup(ip);
    network->hosts[network->num_hosts].port = port;
    network->num_hosts++;
    return 0;
}

int scan_network(network_t *network, int start_port, int end_port) {
    int sockfd;
    struct sockaddr_in addr;
    for (int i = 0; i < network->num_hosts; i++) {
        for (int port = start_port; port <= end_port; port++) {
            sockfd = socket(AF_INET, SOCK_STREAM, 0);
            memset(&addr, 0, sizeof(addr));
            addr.sin_family = AF_INET;
            addr.sin_addr.s_addr = inet_addr(network->hosts[i].ip);
            addr.sin_port = htons(port);
            if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
                printf("Found open port %d on host %s\n", port, network->hosts[i].ip);
            }
            close(sockfd);
        }
    }
    return 0;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <start_port> <end_port>\n", argv[0]);
        return 1;
    }
    int start_port = atoi(argv[1]);
    int end_port = atoi(argv[2]);
    network_t *network = create_network();
    add_host(network, "192.168.1.1", 80);
    add_host(network, "192.168.1.2", 22);
    add_host(network, "192.168.1.3", 443);
    scan_network(network, start_port, end_port);
    free_network(network);
    return 0;
}