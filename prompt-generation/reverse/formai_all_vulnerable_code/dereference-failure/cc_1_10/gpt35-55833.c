//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_HOSTS 256

typedef struct {
    char name[64];
    char ip_addr[16];
} host_t;

typedef struct {
    int n_hosts;
    host_t hosts[MAX_HOSTS];
} network_t;

int scan_network(network_t *network, char *network_prefix) {
    struct hostent *host;
    struct in_addr **addr_list;
    char host_ip[16];
    int n_hosts = 0;

    for (int i = 1; i <= 255; i++) {
        char address[64];
        sprintf(address, "%s.%d", network_prefix, i);

        if ((host = gethostbyname(address)) != NULL) {
            addr_list = (struct in_addr **) host->h_addr_list;

            for (int j = 0; addr_list[j] != NULL; j++) {
                strcpy(host_ip, inet_ntoa(*addr_list[j]));
                strcpy(network->hosts[n_hosts].ip_addr, host_ip);
                strcpy(network->hosts[n_hosts].name, address);
                n_hosts++;
            }
        }
    }

    return n_hosts;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <network_prefix>\n", argv[0]);
        return 1;
    }

    char *network_prefix = argv[1];

    network_t network;
    network.n_hosts = scan_network(&network, network_prefix);

    printf("Mapped %d hosts in network %s:\n", network.n_hosts, network_prefix);
    for (int i = 0; i < network.n_hosts; i++) {
        printf("%s\t%s\n", network.hosts[i].name, network.hosts[i].ip_addr);
    }

    return 0;
}