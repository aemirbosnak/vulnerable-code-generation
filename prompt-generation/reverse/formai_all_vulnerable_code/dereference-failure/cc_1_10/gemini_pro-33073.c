//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: Sherlock Holmes
/*
 * The Adventure of the Network Topology
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_HOSTS 255

struct host {
    char *name;
    char *ip;
    int port;
};

struct network {
    struct host hosts[MAX_HOSTS];
    int num_hosts;
};

/*
 * Scans the network for hosts and returns a network structure with the
 * discovered hosts.
 */
struct network *scan_network(void) {
    struct network *network = malloc(sizeof(struct network));
    if (!network) {
        return NULL;
    }

    network->num_hosts = 0;

    for (int i = 0; i < MAX_HOSTS; i++) {
        struct host host;
        host.name = NULL;
        host.ip = NULL;
        host.port = 0;

        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) {
            continue;
        }

        struct sockaddr_in addr;
        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = inet_addr(i);
        addr.sin_port = htons(80);

        int result = connect(sock, (struct sockaddr *)&addr, sizeof(addr));
        if (result < 0) {
            close(sock);
            continue;
        }

        getsockname(sock, (struct sockaddr *)&addr, &result);
        host.ip = inet_ntoa(addr.sin_addr);
        host.port = ntohs(addr.sin_port);

        char hostname[128];
        result = gethostname(hostname, sizeof(hostname));
        if (result < 0) {
            host.name = NULL;
        } else {
            host.name = malloc(strlen(hostname) + 1);
            strcpy(host.name, hostname);
        }

        network->hosts[network->num_hosts++] = host;

        close(sock);
    }

    return network;
}

/*
 * Prints the network topology to the console.
 */
void print_network(struct network *network) {
    printf("Network Topology:\n");

    for (int i = 0; i < network->num_hosts; i++) {
        printf("Host %d:\n", i + 1);
        printf("  Name: %s\n", network->hosts[i].name);
        printf("  IP: %s\n", network->hosts[i].ip);
        printf("  Port: %d\n", network->hosts[i].port);
    }
}

/*
 * Main entry point
 */
int main(void) {
    struct network *network = scan_network();
    if (!network) {
        return 1;
    }

    print_network(network);

    return 0;
}