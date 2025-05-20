//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s IP_ADDRESS/[NETMASK]\n", argv[0]);
        return 1;
    }

    char *ip_address = strtok(argv[1], "/");
    char *netmask = strtok(NULL, "/");

    if (!ip_address || !netmask) {
        fprintf(stderr, "Invalid IP address or netmask format.\n");
        return 1;
    }

    struct in_addr inaddr;
    if (inet_pton(AF_INET, ip_address, &inaddr) == 0) {
        fprintf(stderr, "Invalid IPv4 address format.\n");
        return 1;
    }

    int mask = atoi(netmask);
    if (mask < 0 || mask > 32) {
        fprintf(stderr, "Invalid netmask format. Netmask should be between 0 and 32.\n");
        return 1;
    }

    printf("IP address: %s\n", ip_address);
    printf("Netmask: /%d\n", mask);

    uint32_t network = ntohl(inaddr.s_addr) & htonl(~((1 << (32 - mask)) - 1));
    uint32_t broadcast = network | htonl((1 << (32 - mask)) - 1);
    uint32_t first_host = (network == broadcast) ? 0 : ntohl(network) + 1;
    uint32_t last_host = (broadcast == 0xffffffff) ? 0 : ntohl(broadcast) - 1;
    uint32_t num_hosts = last_host - first_host + 1;

    printf("Network: %d.%d.%d.%d\n",
           (network >> 24) & 0xff,
           (network >> 16) & 0xff,
           (network >> 8) & 0xff,
           network & 0xff);
    printf("Broadcast: %d.%d.%d.%d\n",
           (broadcast >> 24) & 0xff,
           (broadcast >> 16) & 0xff,
           (broadcast >> 8) & 0xff,
           broadcast & 0xff);
    printf("First host: %d.%d.%d.%d\n",
           (first_host >> 24) & 0xff,
           (first_host >> 16) & 0xff,
           (first_host >> 8) & 0xff,
           first_host & 0xff);
    printf("Last host: %d.%d.%d.%d\n",
           (last_host >> 24) & 0xff,
           (last_host >> 16) & 0xff,
           (last_host >> 8) & 0xff,
           last_host & 0xff);
    printf("Number of hosts: %u\n", num_hosts);

    return 0;
}