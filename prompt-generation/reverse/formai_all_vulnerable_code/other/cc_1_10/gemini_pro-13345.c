//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <netinet/in.h>
#include <linux/if_ether.h>

#define MAX_INTERFACES 16

struct interface {
    char name[IFNAMSIZ];
    char mac[ETH_ALEN];
    unsigned int ip;
};

struct node {
    struct interface interface;
    struct node *next;
};

struct graph {
    struct node *nodes;
};

struct graph *create_graph() {
    struct graph *graph = malloc(sizeof(struct graph));
    if (!graph) {
        return NULL;
    }

    graph->nodes = NULL;

    return graph;
}

void free_graph(struct graph *graph) {
    struct node *node = graph->nodes;
    while (node) {
        struct node *next = node->next;
        free(node);
        node = next;
    }

    free(graph);
}

struct node *create_node(struct interface interface) {
    struct node *node = malloc(sizeof(struct node));
    if (!node) {
        return NULL;
    }

    node->interface = interface;
    node->next = NULL;

    return node;
}

void add_node_to_graph(struct graph *graph, struct node *node) {
    node->next = graph->nodes;
    graph->nodes = node;
}

int main(int argc, char **argv) {
    struct graph *graph = create_graph();
    if (!graph) {
        fprintf(stderr, "Failed to create graph\n");
        return EXIT_FAILURE;
    }

    struct ifreq ifr;
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Failed to create socket\n");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < MAX_INTERFACES; i++) {
        sprintf(ifr.ifr_name, "eth%d", i);

        if (ioctl(sockfd, SIOCGIFFLAGS, &ifr) < 0) {
            continue;
        }

        if (!(ifr.ifr_flags & IFF_UP)) {
            continue;
        }

        if (ioctl(sockfd, SIOCGIFHWADDR, &ifr) < 0) {
            continue;
        }

        struct interface interface = {
            .name = ifr.ifr_name,
            .mac = ifr.ifr_hwaddr.sa_data,
        };

        struct in_addr addr;
        if (ioctl(sockfd, SIOCGIFADDR, &ifr) >= 0) {
            addr = ((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr;
        } else {
            addr.s_addr = 0;
        }

        interface.ip = addr.s_addr;

        struct node *node = create_node(interface);
        if (!node) {
            fprintf(stderr, "Failed to create node\n");
            return EXIT_FAILURE;
        }

        add_node_to_graph(graph, node);
    }

    close(sockfd);

    struct node *node = graph->nodes;
    while (node) {
        printf("Interface: %s\n", node->interface.name);
        printf("MAC: %02x:%02x:%02x:%02x:%02x:%02x\n", node->interface.mac[0], node->interface.mac[1], node->interface.mac[2], node->interface.mac[3], node->interface.mac[4], node->interface.mac[5]);
        printf("IP: %s\n", inet_ntoa(((struct sockaddr_in *)&node->interface.ip)->sin_addr));

        node = node->next;
    }

    free_graph(graph);

    return EXIT_SUCCESS;
}