//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

struct host {
    char *name;
    char *ip;
    struct host *next;
};

struct link {
    struct host *host1;
    struct host *host2;
    int weight;
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

void add_host(struct network *network, char *name, char *ip) {
    struct host *host = malloc(sizeof(struct host));
    host->name = strdup(name);
    host->ip = strdup(ip);
    host->next = network->hosts;
    network->hosts = host;
}

void add_link(struct network *network, char *host1_name, char *host2_name, int weight) {
    struct host *host1 = NULL, *host2 = NULL;
    for (struct host *host = network->hosts; host != NULL; host = host->next) {
        if (!strcmp(host->name, host1_name)) {
            host1 = host;
        }
        if (!strcmp(host->name, host2_name)) {
            host2 = host;
        }
    }
    if (host1 == NULL || host2 == NULL) {
        fprintf(stderr, "Error: host not found\n");
        return;
    }
    struct link *link = malloc(sizeof(struct link));
    link->host1 = host1;
    link->host2 = host2;
    link->weight = weight;
    link->next = network->links;
    network->links = link;
}

void print_network(struct network *network) {
    for (struct host *host = network->hosts; host != NULL; host = host->next) {
        printf("Host: %s (%s)\n", host->name, host->ip);
    }
    for (struct link *link = network->links; link != NULL; link = link->next) {
        printf("Link: %s - %s (%d)\n",
            link->host1->name, link->host2->name, link->weight);
    }
}

void free_network(struct network *network) {
    for (struct host *host = network->hosts; host != NULL; ) {
        struct host *next = host->next;
        free(host->name);
        free(host->ip);
        free(host);
        host = next;
    }
    for (struct link *link = network->links; link != NULL; ) {
        struct link *next = link->next;
        free(link);
        link = next;
    }
    free(network);
}

int main() {
    struct network *network = create_network();
    add_host(network, "host1", "192.168.1.1");
    add_host(network, "host2", "192.168.1.2");
    add_host(network, "host3", "192.168.1.3");
    add_link(network, "host1", "host2", 10);
    add_link(network, "host2", "host3", 20);
    add_link(network, "host1", "host3", 30);
    print_network(network);
    free_network(network);
    return 0;
}