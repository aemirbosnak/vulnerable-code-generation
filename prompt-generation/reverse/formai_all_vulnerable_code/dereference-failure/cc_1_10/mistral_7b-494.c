//MISTRAL-7B DATASET v1.0 Category: Subnet Calculator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define BITS_PER_LONG (sizeof(unsigned long) * 8)
#define IP_LEN 4
#define SUBNET_SIZE_MIN 1
#define SUBNET_SIZE_MAX 32

typedef unsigned long ip_address;

bool is_valid_subnet_size(int subnet_size) {
    return (subnet_size >= SUBNET_SIZE_MIN && subnet_size <= SUBNET_SIZE_MAX);
}

void ip_to_long(const char* ip_str, ip_address* ip) {
    int i, octet;
    for (i = 0; i < IP_LEN; i++) {
        octet = atoi(strtok(NULL, "."));
        *ip |= (octet & 0xFF) << (8 * (IP_LEN - i - 1));
    }
}

void print_binary(unsigned long num) {
    int i, j;
    for (i = BITS_PER_LONG; i > 0; i -= 8) {
        for (j = i; j >= i - 8; j--)
            printf("%c", (num >> j & 1) ? '1' : '0');
        printf(" ");
    }
    printf("\b\n");
}

void calculate_subnet_info(ip_address ip, int subnet_size) {
    unsigned long mask, broadcast, usable_hosts;

    if (!is_valid_subnet_size(subnet_size)) {
        printf("Invalid subnet size.\n");
        return;
    }

    mask = ~((1 << subnet_size) - 1);
    ip &= mask;

    broadcast = ip | ~mask;
    usable_hosts = ip + 1;
    usable_hosts &= mask;

    printf("IP address: ");
    print_binary(ip);
    printf("Subnet mask: ");
    print_binary(mask);
    printf("Broadcast address: ");
    print_binary(broadcast);
    printf("Usable hosts: ");
    print_binary(usable_hosts);
    printf("\n");
}

int main(int argc, char** argv) {
    if (argc != 4) {
        printf("Usage: %s <IP address> <subnet size in bits> <display binary flag(0/1)>\n", argv[0]);
        return 1;
    }

    int subnet_size = atoi(argv[2]);
    bool binary_flag = atoi(argv[3]) == 1;

    ip_address ip;
    ip_to_long(argv[1], &ip);
    calculate_subnet_info(ip, subnet_size);

    return 0;
}