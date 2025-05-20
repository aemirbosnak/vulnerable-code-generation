//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <string.h>

#define MAX_IP_ADDR_LEN 16

typedef struct {
    uint32_t addr;
    uint8_t prefix;
} IPAddr;

typedef struct {
    IPAddr network;
    IPAddr broadcast;
    uint32_t num_hosts;
    uint32_t num_subnets;
} SubnetInfo;

uint32_t ip_addr_to_uint(char *ip_addr) {
    uint32_t addr = 0;
    char *p = ip_addr;
    for (int i = 0; i < 4; i++) {
        addr <<= 8;
        addr |= atoi(p);
        while (*p && *p != '.') p++;
        if (*p == '.') p++;
    }
    return addr;
}

void uint_to_ip_addr(uint32_t addr, char *ip_addr) {
    int i;
    for (i = 3; i >= 0; i--) {
        sprintf(ip_addr + i * 3, "%d.", addr & 0xFF);
        addr >>= 8;
    }
    ip_addr[i * 3 - 1] = '\0';
}

SubnetInfo calculate_subnet_info(IPAddr network, uint8_t prefix) {
    SubnetInfo info;
    info.network.addr = network.addr & (UINT32_MAX << (32 - prefix));
    info.broadcast.addr = info.network.addr | (UINT32_MAX >> prefix);
    info.num_hosts = (1 << (32 - prefix)) - 2;
    info.num_subnets = (1 << prefix) - 2;
    return info;
}

void print_subnet_info(SubnetInfo info) {
    char network_addr[MAX_IP_ADDR_LEN];
    char broadcast_addr[MAX_IP_ADDR_LEN];
    uint_to_ip_addr(info.network.addr, network_addr);
    uint_to_ip_addr(info.broadcast.addr, broadcast_addr);
    printf("Network address: %s\n", network_addr);
    printf("Broadcast address: %s\n", broadcast_addr);
    printf("Number of hosts: %u\n", info.num_hosts);
    printf("Number of subnets: %u\n", info.num_subnets);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <ip address> <prefix>\n", argv[0]);
        return EXIT_FAILURE;
    }

    IPAddr network;
    network.addr = ip_addr_to_uint(argv[1]);
    network.prefix = atoi(argv[2]);

    SubnetInfo info = calculate_subnet_info(network, network.prefix);
    print_subnet_info(info);

    return EXIT_SUCCESS;
}