//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <ifaddrs.h>
#define MAX_IP_LEN 16

struct Node {
    char ip[MAX_IP_LEN];
    struct Node* next;
};

void append(struct Node** head, char* ip) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    strcpy(new_node->ip, ip);
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    struct Node* last_node = *head;
    while (last_node->next != NULL) {
        last_node = last_node->next;
    }
    last_node->next = new_node;
}

void print_topology(struct Node** topology, int num_nodes) {
    for (int i = 0; i < num_nodes; i++) {
        printf("Node %d: ", i+1);
        struct Node* neighbours = topology[i];

        while (neighbours != NULL) {
            printf("%s ", neighbours->ip);
            neighbours = neighbours->next;
        }
        printf("\n");
    }
}

void destroy_topology(struct Node** topology, int num_nodes) {
    for (int i = 0; i < num_nodes; i++) {
        struct Node* node = topology[i];
        while (node != NULL) {
            struct Node* temp = node;
            node = node->next;
            free(temp);
        }
    }
    free(topology);
}

int main() {

    struct ifaddrs* ifaddr, *ifa;
    int family, s;
    char host[NI_MAXHOST];

    if (getifaddrs(&ifaddr) == -1) {
        perror("getifaddrs");
        exit(EXIT_FAILURE);
    }

    // count number of interfaces
    int num_interfaces = 0;
    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr == NULL) {
            continue;
        }
        family = ifa->ifa_addr->sa_family;
        if (family == AF_INET || family == AF_INET6) {
            num_interfaces++;
        }
    }

    // create topology array
    int num_nodes = num_interfaces;
    struct Node** topology = (struct Node**)malloc(num_nodes * sizeof(struct Node*));
    for (int i = 0; i < num_nodes; i++) {
        topology[i] = NULL;
    }

    // build topology
    int curr_node = -1;
    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr == NULL) {
            continue;
        }
        family = ifa->ifa_addr->sa_family;
        if (family == AF_INET) {
            s = getnameinfo(ifa->ifa_addr, sizeof(struct sockaddr_in), host, NI_MAXHOST, NULL, 0, NI_NUMERICHOST);
            if (s != 0) {
                printf("getnameinfo() failed: %s\n", gai_strerror(s));
                exit(EXIT_FAILURE);
            }
            if (strcmp(ifa->ifa_name, "lo") != 0) { // ignore loopback interface
                append(&topology[++curr_node], host);
            }

        } else if (family == AF_INET6) {
            s = getnameinfo(ifa->ifa_addr, sizeof(struct sockaddr_in6), host, NI_MAXHOST, NULL, 0, NI_NUMERICHOST);
            if (s != 0) {
                printf("getnameinfo() failed: %s\n", gai_strerror(s));
                exit(EXIT_FAILURE);
            }
            if (strcmp(ifa->ifa_name, "lo") != 0) { // ignore loopback interface
                append(&topology[++curr_node], host);
            }
        }
    }

    printf("Network Topology:\n");
    print_topology(topology, num_nodes);

    destroy_topology(topology, num_nodes);

    exit(EXIT_SUCCESS);
}