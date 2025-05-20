//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: detailed
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef uint32_t ipv4_addr_t;

typedef struct {
    ipv4_addr_t network;        /* network address */
    ipv4_addr_t subnet;         /* subnet mask */
    ipv4_addr_t broadcast;      /* broadcast address */
    ipv4_addr_t first_host;     /* first host address */
    ipv4_addr_t last_host;      /* last host address */
} subnet_t;

int main(int argc, char *argv[]) {

    if (argc != 3) {
        printf("Usage: %s <ip address> <subnet mask>\n", argv[0]);
        return 1;
    }

    char *ip_str = argv[1];
    char *mask_str = argv[2];

    char *tok;
    ipv4_addr_t ip = 0;
    int i = 0;
    for (tok = strtok(ip_str, "."); tok && *tok; tok = strtok(NULL, ".")) {
        uint8_t octet = atoi(tok);
        if (octet > 255) {
            printf("Invalid IP address\n");
            return 1;
        }
        ip |= octet << (24 - (8 * i++));
    }

    ipv4_addr_t mask = 0;
    i = 0;
    for (tok = strtok(mask_str, "."); tok && *tok; tok = strtok(NULL, ".")) {
        uint8_t octet = atoi(tok);
        if (octet > 255) {
            printf("Invalid subnet mask\n");
            return 1;
        }
        mask |= octet << (24 - (8 * i++));
    }

    /* calculate network address */
    ipv4_addr_t network = ip & mask;

    /* calculate broadcast address */
    ipv4_addr_t broadcast = network | (~mask);

    /* calculate number of hosts */
    int num_hosts = (~mask) & 0x7FFFFFFF;

    /* calculate first host address */
    ipv4_addr_t first_host = network + 1;

    /* calculate last host address */
    ipv4_addr_t last_host = broadcast - 1;

    /* create subnet structure */
    subnet_t subnet = {network, mask, broadcast, first_host, last_host};

    /* output subnet information */
    printf("Subnet Information:\n");
    printf(" IP address: %s\n", ip_str);
    printf(" Subnet mask: %s\n", mask_str);
    printf(" Network address: %d.%d.%d.%d\n", (int)(subnet.network >> 24),
           (int)(subnet.network >> 16) & 0xff, (int)(subnet.network >> 8) & 0xff,
           (int)(subnet.network & 0xff));
    printf(" Broadcast address: %d.%d.%d.%d\n", (int)(subnet.broadcast >> 24),
           (int)(subnet.broadcast >> 16) & 0xff, (int)(subnet.broadcast >> 8) & 0xff,
           (int)(subnet.broadcast & 0xff));
    printf(" First host address: %d.%d.%d.%d\n", (int)(subnet.first_host >> 24),
           (int)(subnet.first_host >> 16) & 0xff, (int)(subnet.first_host >> 8) & 0xff,
           (int)(subnet.first_host & 0xff));
    printf(" Last host address: %d.%d.%d.%d\n", (int)(subnet.last_host >> 24),
           (int)(subnet.last_host >> 16) & 0xff, (int)(subnet.last_host >> 8) & 0xff,
           (int)(subnet.last_host & 0xff));
    printf(" Number of hosts: %d\n", num_hosts);

    return 0;
}