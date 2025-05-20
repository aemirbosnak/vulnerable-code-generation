//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CIDR 32

typedef struct subnet_info {
    uint32_t network_address;
    uint32_t broadcast_address;
    uint32_t subnet_mask;
    uint8_t cidr;
    char *network_address_str;
    char *broadcast_address_str;
    char *subnet_mask_str;
} subnet_info;

void print_usage() {
    printf("Usage: subnetcalc <ip_address> <cidr>\n");
    printf("Example: subnetcalc 192.168.1.0/24\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage();
        return EXIT_FAILURE;
    }

    char *ip_address_str = argv[1];
    int cidr = atoi(argv[2]);

    if (cidr < 0 || cidr > MAX_CIDR) {
        printf("Invalid CIDR: %d\n", cidr);
        return EXIT_FAILURE;
    }

    struct in_addr ip_address;

    if (!inet_aton(ip_address_str, &ip_address)) {
        printf("Invalid IP address: %s\n", ip_address_str);
        return EXIT_FAILURE;
    }

    uint32_t ip_address_int = ntohl(ip_address.s_addr);

    uint32_t subnet_mask_int = (0xFFFFFFFF << (32 - cidr));

    uint32_t network_address_int = ip_address_int & subnet_mask_int;

    uint32_t broadcast_address_int = network_address_int | ~subnet_mask_int;

    char network_address_str[INET_ADDRSTRLEN];
    char broadcast_address_str[INET_ADDRSTRLEN];
    char subnet_mask_str[INET_ADDRSTRLEN];

    inet_ntop(AF_INET, &network_address_int, network_address_str, INET_ADDRSTRLEN);
    inet_ntop(AF_INET, &broadcast_address_int, broadcast_address_str, INET_ADDRSTRLEN);
    inet_ntop(AF_INET, &subnet_mask_int, subnet_mask_str, INET_ADDRSTRLEN);

    subnet_info subnet_info = {
        .network_address = network_address_int,
        .broadcast_address = broadcast_address_int,
        .subnet_mask = subnet_mask_int,
        .cidr = cidr,
        .network_address_str = network_address_str,
        .broadcast_address_str = broadcast_address_str,
        .subnet_mask_str = subnet_mask_str,
    };

    printf("Network Address: %s\n", subnet_info.network_address_str);
    printf("Broadcast Address: %s\n", subnet_info.broadcast_address_str);
    printf("Subnet Mask: %s\n", subnet_info.subnet_mask_str);
    printf("CIDR: %d\n", subnet_info.cidr);

    return EXIT_SUCCESS;
}