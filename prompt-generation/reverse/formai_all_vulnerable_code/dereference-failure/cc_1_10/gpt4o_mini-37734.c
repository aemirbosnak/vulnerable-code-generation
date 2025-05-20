//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_OCTETS 4
#define MAX_MASK 32

void print_help() {
    printf("Usage: ./subnet_calculator <IP_address> <subnet_mask>\n");
    printf("Example: ./subnet_calculator 192.168.1.10 255.255.255.0\n");
    printf("OR: ./subnet_calculator 192.168.1.10 24\n");
}

int validate_ip(const char *ip) {
    struct sockaddr_in sa;
    return inet_pton(AF_INET, ip, &(sa.sin_addr)) != 0;
}

int validate_mask(const char *mask) {
    int ip_mask;
    if (sscanf(mask, "%d", &ip_mask) == 1 && ip_mask >= 0 && ip_mask <= 32) {
        return 1;
    }
    
    return 0;
}

void calculate_subnet(const char *ip, const char *mask) {
    unsigned char ip_octets[MAX_OCTETS];
    int subnet_mask;

    if (strchr(mask, '.') != NULL) {
        sscanf(mask, "%hhu.%hhu.%hhu.%hhu", &ip_octets[0], &ip_octets[1], &ip_octets[2], &ip_octets[3]);
        subnet_mask = mask ? 0 : -1; // Default to an invalid mask.
    } else {
        subnet_mask = atoi(mask);
    }

    // Convert IP from string to unsigned char array
    sscanf(ip, "%hhu.%hhu.%hhu.%hhu", &ip_octets[0], &ip_octets[1], &ip_octets[2], &ip_octets[3]);

    // Calculate the subnet address
    if (subnet_mask <= 32 && subnet_mask > 0) {
        unsigned char subnet_octets[MAX_OCTETS] = {0};

        for (int i = 0; i < 4; i++) {
            unsigned char mask_byte = (subnet_mask >= 8) ? 255 : (1 << (8 - subnet_mask)) - 1;
            subnet_octets[i] = ip_octets[i] & (~mask_byte);
            subnet_mask -= 8;
        }

        // Print results
        printf("\nIP Address: %d.%d.%d.%d\n", ip_octets[0], ip_octets[1], ip_octets[2], ip_octets[3]);
        printf("Subnet Mask: %s (%d)\n", mask, subnet_mask < 0 ? -subnet_mask : subnet_mask);
        printf("Subnet: %d.%d.%d.%d\n", subnet_octets[0], subnet_octets[1], subnet_octets[2], subnet_octets[3]);

    } else {
        printf("Invalid subnet mask!\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_help();
        return 1;
    }

    const char *ip_address = argv[1];
    const char *subnet_mask = argv[2];

    if (!validate_ip(ip_address)) {
        printf("Invalid IP Address!\n");
        return 1;
    }

    if (!validate_mask(subnet_mask)) {
        printf("Invalid Subnet Mask!\n");
        return 1;
    }

    calculate_subnet(ip_address, subnet_mask);

    return 0;
}