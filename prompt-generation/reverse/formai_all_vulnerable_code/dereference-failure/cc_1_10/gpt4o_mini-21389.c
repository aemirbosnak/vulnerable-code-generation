//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_IP_LENGTH 16
#define MAX_CIDR_LENGTH 4

void print_usage() {
    printf("Usage: subnet_calculator <IP_ADDRESS> <CIDR>\n");
    printf("Example: subnet_calculator 192.168.1.1 24\n");
}

void calculate_subnet(char *ip_address, int cidr) {
    struct in_addr ip;
    struct in_addr subnet_mask;
    struct in_addr subnet_address;
    struct in_addr broadcast_address;

    // Convert dotted-decimal to binary form
    if (inet_pton(AF_INET, ip_address, &ip) != 1) {
        fprintf(stderr, "Invalid IP address format.\n");
        exit(EXIT_FAILURE);
    }

    // Calculate subnet mask
    uint32_t mask = htonl((~0U) << (32 - cidr));
    subnet_mask.s_addr = mask;

    // Calculate subnet address
    subnet_address.s_addr = ip.s_addr & subnet_mask.s_addr;

    // Calculate broadcast address
    broadcast_address.s_addr = subnet_address.s_addr | ~subnet_mask.s_addr;

    // Convert results back to dotted-decimal format
    char subnet_str[MAX_IP_LENGTH];
    char broadcast_str[MAX_IP_LENGTH];
    char mask_str[MAX_IP_LENGTH];

    inet_ntop(AF_INET, &subnet_address, subnet_str, MAX_IP_LENGTH);
    inet_ntop(AF_INET, &broadcast_address, broadcast_str, MAX_IP_LENGTH);
    inet_ntop(AF_INET, &subnet_mask, mask_str, MAX_IP_LENGTH);

    // Output
    printf("\nSubnet Information:\n");
    printf("--------------------\n");
    printf("Input IP Address      : %s\n", ip_address);
    printf("CIDR Notation         : /%d\n", cidr);
    printf("Subnet Mask           : %s\n", mask_str);
    printf("Subnet Address        : %s\n", subnet_str);
    printf("Broadcast Address     : %s\n", broadcast_str);

    uint32_t address = ntohl(subnet_address.s_addr);
    uint32_t end_address = ntohl(broadcast_address.s_addr);

    printf("Usable IP Addresses:\n");
    printf("--------------------------\n");
    for (uint32_t i = address + 1; i < end_address; i++) {
        struct in_addr addr;
        addr.s_addr = htonl(i);
        char addr_str[MAX_IP_LENGTH];
        inet_ntop(AF_INET, &addr, addr_str, MAX_IP_LENGTH);
        printf("%s\n", addr_str);
    }
    printf("--------------------------\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage();
        return EXIT_FAILURE;
    }

    char *ip_address = argv[1];
    int cidr = atoi(argv[2]);

    if (cidr < 0 || cidr > 32) {
        fprintf(stderr, "CIDR must be between 0 and 32.\n");
        return EXIT_FAILURE;
    }

    calculate_subnet(ip_address, cidr);
    return EXIT_SUCCESS;
}