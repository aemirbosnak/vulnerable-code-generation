//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <ip address> <subnet mask> <cidr notation>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in sa;
    memset(&sa, 0, sizeof(sa));
    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = inet_addr(argv[1]);

    struct in_addr subnet_mask;
    memset(&subnet_mask, 0, sizeof(subnet_mask));
    inet_pton(AF_INET, argv[2], &subnet_mask);

    unsigned int cidr_notation = atoi(argv[3]);

    unsigned int subnet_mask_bits = 0;
    for (int i = 0; i < 32; i++) {
        if ((subnet_mask.s_addr & (1 << i)) != 0) {
            subnet_mask_bits++;
        }
    }

    if (cidr_notation != subnet_mask_bits) {
        fprintf(stderr, "Invalid CIDR notation\n");
        exit(EXIT_FAILURE);
    }

    struct in_addr network_address;
    memset(&network_address, 0, sizeof(network_address));
    network_address.s_addr = sa.sin_addr.s_addr & subnet_mask.s_addr;

    struct in_addr broadcast_address;
    memset(&broadcast_address, 0, sizeof(broadcast_address));
    broadcast_address.s_addr = network_address.s_addr | ~subnet_mask.s_addr;

    unsigned int host_bits = 32 - subnet_mask_bits;
    unsigned int num_hosts = (1 << host_bits) - 2;

    printf("IP Address: %s\n", argv[1]);
    printf("Subnet Mask: %s\n", argv[2]);
    printf("CIDR Notation: %u\n", cidr_notation);
    printf("Network Address: %s\n", inet_ntoa(network_address));
    printf("Broadcast Address: %s\n", inet_ntoa(broadcast_address));
    printf("Number of Hosts: %u\n", num_hosts);

    return EXIT_SUCCESS;
}