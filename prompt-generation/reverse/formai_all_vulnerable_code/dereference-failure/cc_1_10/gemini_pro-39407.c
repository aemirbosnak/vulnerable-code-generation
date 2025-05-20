//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_IP_ADDR_LEN 16
#define MAX_SUBNET_MASK_LEN 16

struct ip_addr {
    uint8_t octets[4];
};

struct subnet_mask {
    uint8_t octets[4];
};

struct subnet_calc_result {
    struct ip_addr network_address;
    struct ip_addr broadcast_address;
    uint32_t num_hosts;
};

int parse_ip_addr(const char *ip_addr_str, struct ip_addr *ip_addr) {
    int octet_count = 0;
    char *ip_addr_str_copy = strdup(ip_addr_str);
    char *octet_str = strtok(ip_addr_str_copy, ".");
    while (octet_str != NULL && octet_count < 4) {
        ip_addr->octets[octet_count] = atoi(octet_str);
        octet_count++;
        octet_str = strtok(NULL, ".");
    }
    free(ip_addr_str_copy);
    return octet_count == 4;
}

int parse_subnet_mask(const char *subnet_mask_str, struct subnet_mask *subnet_mask) {
    int octet_count = 0;
    char *subnet_mask_str_copy = strdup(subnet_mask_str);
    char *octet_str = strtok(subnet_mask_str_copy, ".");
    while (octet_str != NULL && octet_count < 4) {
        subnet_mask->octets[octet_count] = atoi(octet_str);
        octet_count++;
        octet_str = strtok(NULL, ".");
    }
    free(subnet_mask_str_copy);
    return octet_count == 4;
}

struct subnet_calc_result calculate_subnet(const struct ip_addr *ip_addr, const struct subnet_mask *subnet_mask) {
    struct subnet_calc_result result;
    for (int i = 0; i < 4; i++) {
        result.network_address.octets[i] = ip_addr->octets[i] & subnet_mask->octets[i];
        result.broadcast_address.octets[i] = result.network_address.octets[i] | ~subnet_mask->octets[i];
    }
    uint32_t subnet_mask_bits = 0;
    for (int i = 0; i < 4; i++) {
        subnet_mask_bits += __builtin_clz(~subnet_mask->octets[i]);
    }
    result.num_hosts = (1 << (32 - subnet_mask_bits)) - 2;
    return result;
}

void print_ip_addr(const struct ip_addr *ip_addr) {
    printf("%u.%u.%u.%u\n", ip_addr->octets[0], ip_addr->octets[1], ip_addr->octets[2], ip_addr->octets[3]);
}

void print_subnet_calc_result(const struct subnet_calc_result *result) {
    printf("Network Address: ");
    print_ip_addr(&result->network_address);
    printf("Broadcast Address: ");
    print_ip_addr(&result->broadcast_address);
    printf("Number of Hosts: %u\n", result->num_hosts);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <ip address> <subnet mask>\n", argv[0]);
        return 1;
    }
    struct ip_addr ip_addr;
    if (!parse_ip_addr(argv[1], &ip_addr)) {
        printf("Invalid IP address: %s\n", argv[1]);
        return 1;
    }
    struct subnet_mask subnet_mask;
    if (!parse_subnet_mask(argv[2], &subnet_mask)) {
        printf("Invalid subnet mask: %s\n", argv[2]);
        return 1;
    }
    struct subnet_calc_result result = calculate_subnet(&ip_addr, &subnet_mask);
    print_subnet_calc_result(&result);
    return 0;
}