//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>
#include <arpa/inet.h>

struct host {
    char *ip_addr;
    char *mac_addr;
    struct host *next;
};

struct link {
    struct host *host1;
    struct host *host2;
    struct link *next;
};

struct network {
    struct host *hosts;
    struct link *links;
};

struct network *create_network() {
    struct network *network = malloc(sizeof(struct network));
    network->hosts = NULL;
    network->links = NULL;
    return network;
}

void add_host(struct network *network, char *ip_addr, char *mac_addr) {
    struct host *host = malloc(sizeof(struct host));
    host->ip_addr = strdup(ip_addr);
    host->mac_addr = strdup(mac_addr);
    host->next = network->hosts;
    network->hosts = host;
}

void add_link(struct network *network, char *ip_addr1, char *ip_addr2) {
    struct host *host1 = NULL;
    struct host *host2 = NULL;
    struct link *link = malloc(sizeof(struct link));

    // Find the hosts by their IP addresses
    for (struct host *host = network->hosts; host != NULL; host = host->next) {
        if (strcmp(host->ip_addr, ip_addr1) == 0) {
            host1 = host;
        } else if (strcmp(host->ip_addr, ip_addr2) == 0) {
            host2 = host;
        }
    }

    // If both hosts were found, add the link
    if (host1 != NULL && host2 != NULL) {
        link->host1 = host1;
        link->host2 = host2;
        link->next = network->links;
        network->links = link;
    }
}

void print_network(struct network *network) {
    printf("Hosts:\n");
    for (struct host *host = network->hosts; host != NULL; host = host->next) {
        printf("  %s (%s)\n", host->ip_addr, host->mac_addr);
    }

    printf("Links:\n");
    for (struct link *link = network->links; link != NULL; link = link->next) {
        printf("  %s - %s\n", link->host1->ip_addr, link->host2->ip_addr);
    }
}

void free_network(struct network *network) {
    // Free the hosts
    for (struct host *host = network->hosts; host != NULL; ) {
        struct host *next = host->next;
        free(host->ip_addr);
        free(host->mac_addr);
        free(host);
        host = next;
    }

    // Free the links
    for (struct link *link = network->links; link != NULL; ) {
        struct link *next = link->next;
        free(link);
        link = next;
    }

    // Free the network
    free(network);
}

int main() {
    // Create a network
    struct network *network = create_network();

    // Add some hosts to the network
    add_host(network, "192.168.1.1", "00:11:22:33:44:55");
    add_host(network, "192.168.1.2", "00:22:33:44:55:66");
    add_host(network, "192.168.1.3", "00:33:44:55:66:77");

    // Add some links to the network
    add_link(network, "192.168.1.1", "192.168.1.2");
    add_link(network, "192.168.1.1", "192.168.1.3");
    add_link(network, "192.168.1.2", "192.168.1.3");

    // Print the network
    print_network(network);

    // Free the network
    free_network(network);

    return 0;
}