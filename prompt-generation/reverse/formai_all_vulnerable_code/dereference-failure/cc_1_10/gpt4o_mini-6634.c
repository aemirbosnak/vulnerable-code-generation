//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <arpa/inet.h>

#define MAX_BUFFER 256
#define MAX_SUBNET_MASK 32

void print_usage() {
    printf("Usage: subnet_calculator <IP_ADDRESS> <SUBNET_MASK>\n");
    printf("Example: subnet_calculator 192.168.10.10 24\n");
}

uint32_t calculate_network_address(uint32_t ip_address, uint32_t subnet_mask) {
    return ip_address & subnet_mask;
}

uint32_t calculate_broadcast_address(uint32_t network_address, uint32_t subnet_mask) {
    return network_address | ~subnet_mask;
}

uint32_t calculate_first_host(uint32_t network_address) {
    return network_address + 1;
}

uint32_t calculate_last_host(uint32_t broadcast_address) {
    return broadcast_address - 1;
}

void print_ip(uint32_t ip) {
    printf("%d.%d.%d.%d", (ip >> 24) & 0xFF, (ip >> 16) & 0xFF, (ip >> 8) & 0xFF, ip & 0xFF);
}

uint32_t cidr_to_mask(int cidr) {
    return (cidr == 0) ? 0 : ~((1U << (32 - cidr)) - 1);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage();
        return 1;
    }

    char *ip_str = argv[1];
    int cidr_mask = atoi(argv[2]);

    if (cidr_mask < 0 || cidr_mask > MAX_SUBNET_MASK) {
        printf("Error: Subnet mask must be between 0 and 32.\n");
        return 1;
    }

    struct sockaddr_in sa;
    inet_pton(AF_INET, ip_str, &(sa.sin_addr));
    uint32_t ip_address = ntohl(sa.sin_addr.s_addr);
    uint32_t subnet_mask = cidr_to_mask(cidr_mask);

    uint32_t network_address = calculate_network_address(ip_address, subnet_mask);
    uint32_t broadcast_address = calculate_broadcast_address(network_address, subnet_mask);
    uint32_t first_host = calculate_first_host(network_address);
    uint32_t last_host = calculate_last_host(broadcast_address);

    printf("IP Address: ");
    print_ip(ip_address);
    printf("\n");

    printf("Subnet Mask: ");
    print_ip(subnet_mask);
    printf("\n");

    printf("Network Address: ");
    print_ip(network_address);
    printf("\n");

    printf("Broadcast Address: ");
    print_ip(broadcast_address);
    printf("\n");

    printf("First Host: ");
    print_ip(first_host);
    printf("\n");

    printf("Last Host: ");
    print_ip(last_host);
    printf("\n");

    return 0;
}