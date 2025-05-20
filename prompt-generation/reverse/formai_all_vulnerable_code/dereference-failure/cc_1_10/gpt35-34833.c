//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <ifaddrs.h>
#include <netdb.h>

#define MAX_IFACE_LEN 32
#define MAX_IP_ADDR_LEN 16
#define MAX_MAC_ADDR_LEN 18

struct NetworkNode {
    char mac_addr[MAX_MAC_ADDR_LEN];
    char ip_addr[MAX_IP_ADDR_LEN];
};

int main () {
    struct ifaddrs *ifaddr, *ifa;
    int family, s;
    char host[MAX_IFACE_LEN], ip_addr[MAX_IP_ADDR_LEN];
    int nodes_count = 0;
    struct NetworkNode nodes[255];

    if (getifaddrs(&ifaddr) == -1) {
        printf("Error: could not retrieve network interfaces\n");
        return 1;
    }

    // Parse all interfaces and store nodes
    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
        if (!ifa->ifa_addr) continue;

        family = ifa->ifa_addr->sa_family;

        if (family == AF_INET) { // IPv4 addresses only
            s = getnameinfo(ifa->ifa_addr, sizeof(struct sockaddr_in),
                    host, MAX_IFACE_LEN, NULL, 0, NI_NUMERICHOST);

            if (s != 0) {
                printf("Error: getnameinfo() failed: %s\n", gai_strerror(s));
                return 1;
            }

            // Add node to list
            strcpy(nodes[nodes_count].ip_addr, host);
            nodes_count++;
        }
    }

    // Print found nodes
    printf("Found %d nodes in network:\n", nodes_count);
    for (int i = 0; i < nodes_count; i++) {
        printf("%d. Node IP: %s\n", i+1, nodes[i].ip_addr);
    }

    freeifaddrs(ifaddr);
    return 0;
}