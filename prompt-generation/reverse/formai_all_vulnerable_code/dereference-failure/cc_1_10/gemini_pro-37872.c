//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define ERROR -1
#define MAX_BITS 32

typedef struct {
    uint32_t ip_addr;
    uint8_t prefix_len;
    uint32_t subnet_mask;
    uint32_t broadcast_addr;
    uint32_t network_addr;
    uint32_t host_min;
    uint32_t host_max;
    uint32_t num_hosts;
} subnet_info_t;

int validate_ip_addr(char *ip_str) {
    uint32_t ip_addr = 0;
    int octets = 0;
    char *octet_str;

    for (octet_str = strtok(ip_str, "."); octet_str != NULL; octet_str = strtok(NULL, ".")) {
        int octet = atoi(octet_str);
        if (octet < 0 || octet > 255) {
            return ERROR;
        }
        ip_addr = (ip_addr << 8) | octet;
        octets++;
    }

    if (octets != 4) {
        return ERROR;
    }

    return ip_addr;
}

int validate_prefix_len(uint8_t prefix_len) {
    if (prefix_len < 0 || prefix_len > MAX_BITS) {
        return ERROR;
    }

    return 0;
}

subnet_info_t calculate_subnet(uint32_t ip_addr, uint8_t prefix_len) {
    subnet_info_t subnet;

    subnet.ip_addr = ip_addr;
    subnet.prefix_len = prefix_len;

    // Calculate subnet mask
    subnet.subnet_mask = 0xFFFFFFFF << (MAX_BITS - prefix_len);

    // Calculate broadcast address
    subnet.broadcast_addr = ip_addr | ~subnet.subnet_mask;

    // Calculate network address
    subnet.network_addr = ip_addr & subnet.subnet_mask;

    // Calculate host min and max
    subnet.host_min = subnet.network_addr + 1;
    subnet.host_max = subnet.broadcast_addr - 1;

    // Calculate number of hosts
    subnet.num_hosts = (1 << (MAX_BITS - prefix_len)) - 2;

    return subnet;
}

void print_subnet_info(subnet_info_t subnet) {
    printf("IP Address: %u.%u.%u.%u\n",
            (subnet.ip_addr >> 24) & 0xFF,
            (subnet.ip_addr >> 16) & 0xFF,
            (subnet.ip_addr >> 8) & 0xFF,
            subnet.ip_addr & 0xFF);
    printf("Prefix Length: %u\n", subnet.prefix_len);
    printf("Subnet Mask: %u.%u.%u.%u\n",
            (subnet.subnet_mask >> 24) & 0xFF,
            (subnet.subnet_mask >> 16) & 0xFF,
            (subnet.subnet_mask >> 8) & 0xFF,
            subnet.subnet_mask & 0xFF);
    printf("Broadcast Address: %u.%u.%u.%u\n",
            (subnet.broadcast_addr >> 24) & 0xFF,
            (subnet.broadcast_addr >> 16) & 0xFF,
            (subnet.broadcast_addr >> 8) & 0xFF,
            subnet.broadcast_addr & 0xFF);
    printf("Network Address: %u.%u.%u.%u\n",
            (subnet.network_addr >> 24) & 0xFF,
            (subnet.network_addr >> 16) & 0xFF,
            (subnet.network_addr >> 8) & 0xFF,
            subnet.network_addr & 0xFF);
    printf("Host Min: %u.%u.%u.%u\n",
            (subnet.host_min >> 24) & 0xFF,
            (subnet.host_min >> 16) & 0xFF,
            (subnet.host_min >> 8) & 0xFF,
            subnet.host_min & 0xFF);
    printf("Host Max: %u.%u.%u.%u\n",
            (subnet.host_max >> 24) & 0xFF,
            (subnet.host_max >> 16) & 0xFF,
            (subnet.host_max >> 8) & 0xFF,
            subnet.host_max & 0xFF);
    printf("Number of Hosts: %u\n", subnet.num_hosts);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <ip_address> <prefix_length>\n", argv[0]);
        return 1;
    }

    char *ip_str = argv[1];
    uint32_t ip_addr = validate_ip_addr(ip_str);
    if (ip_addr == ERROR) {
        printf("Invalid IP address: %s\n", ip_str);
        return 1;
    }

    uint8_t prefix_len = atoi(argv[2]);
    if (validate_prefix_len(prefix_len) == ERROR) {
        printf("Invalid prefix length: %u\n", prefix_len);
        return 1;
    }

    subnet_info_t subnet = calculate_subnet(ip_addr, prefix_len);
    print_subnet_info(subnet);

    return 0;
}