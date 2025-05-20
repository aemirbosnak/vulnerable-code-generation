//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_IP_ADDR_LEN 16
#define MAX_SUBNET_MASK_LEN 16
#define MAX_CIDR_LEN 3

typedef struct {
    uint8_t octets[4];
} ip_addr_t;

typedef struct {
    uint8_t octets[4];
    uint8_t mask_len;
} subnet_mask_t;

typedef struct {
    ip_addr_t ip_addr;
    subnet_mask_t subnet_mask;
} network_t;

void print_ip_addr(ip_addr_t *ip_addr) {
    printf("%u.%u.%u.%u\n", ip_addr->octets[0], ip_addr->octets[1], ip_addr->octets[2], ip_addr->octets[3]);
}

void print_subnet_mask(subnet_mask_t *subnet_mask) {
    printf("%u.%u.%u.%u/%u\n", subnet_mask->octets[0], subnet_mask->octets[1], subnet_mask->octets[2], subnet_mask->octets[3], subnet_mask->mask_len);
}

void print_network(network_t *network) {
    printf("IP address: ");
    print_ip_addr(&network->ip_addr);
    printf("Subnet mask: ");
    print_subnet_mask(&network->subnet_mask);
}

int parse_ip_addr(char *ip_addr_str, ip_addr_t *ip_addr) {
    int octets[4];
    if (sscanf(ip_addr_str, "%u.%u.%u.%u", &octets[0], &octets[1], &octets[2], &octets[3]) != 4) {
        return -1;
    }
    for (int i = 0; i < 4; i++) {
        if (octets[i] > 255) {
            return -1;
        }
        ip_addr->octets[i] = octets[i];
    }
    return 0;
}

int parse_subnet_mask(char *subnet_mask_str, subnet_mask_t *subnet_mask) {
    int mask_len;
    if (sscanf(subnet_mask_str, "%u.%u.%u.%u/%u", &subnet_mask->octets[0], &subnet_mask->octets[1], &subnet_mask->octets[2], &subnet_mask->octets[3], &mask_len) != 5) {
        return -1;
    }
    for (int i = 0; i < 4; i++) {
        if (subnet_mask->octets[i] > 255) {
            return -1;
        }
    }
    if (mask_len < 0 || mask_len > 32) {
        return -1;
    }
    subnet_mask->mask_len = mask_len;
    return 0;
}

int parse_network(char *network_str, network_t *network) {
    char *ip_addr_str;
    char *subnet_mask_str;
    ip_addr_str = strtok(network_str, "/");
    if (ip_addr_str == NULL) {
        return -1;
    }
    subnet_mask_str = strtok(NULL, "/");
    if (subnet_mask_str == NULL) {
        return -1;
    }
    if (parse_ip_addr(ip_addr_str, &network->ip_addr) != 0) {
        return -1;
    }
    if (parse_subnet_mask(subnet_mask_str, &network->subnet_mask) != 0) {
        return -1;
    }
    return 0;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <network>\n", argv[0]);
        return -1;
    }
    network_t network;
    if (parse_network(argv[1], &network) != 0) {
        printf("Invalid network format\n");
        return -1;
    }
    print_network(&network);
    return 0;
}