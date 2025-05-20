//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define MAX_OCTETS 4
#define MAX_BITS 32
#define MAX_SUBNETS 256

typedef struct {
    unsigned char octets[MAX_OCTETS];
    unsigned int bits;
} IPAddress;

typedef struct {
    unsigned int num_hosts;
    unsigned int subnet_mask;
} Subnet;

bool is_valid_ip_address(IPAddress *ip) {
    for (int i = 0; i < MAX_OCTETS; i++) {
        if (ip->octets[i] > 255) {
            return false;
        }
    }
    return true;
}

bool is_valid_subnet_mask(unsigned int subnet_mask) {
    if (subnet_mask > 32) {
        return false;
    }
    return true;
}

IPAddress *get_ip_address(char *ip_address_str) {
    IPAddress *ip = malloc(sizeof(IPAddress));
    char *pch = strtok(ip_address_str, ".");
    for (int i = 0; i < MAX_OCTETS; i++) {
        ip->octets[i] = atoi(pch);
        pch = strtok(NULL, ".");
    }
    return ip;
}

unsigned int get_subnet_mask(char *subnet_mask_str) {
    return atoi(subnet_mask_str);
}

void print_ip_address(IPAddress *ip) {
    for (int i = 0; i < MAX_OCTETS; i++) {
        printf("%u", ip->octets[i]);
        if (i < MAX_OCTETS - 1) {
            printf(".");
        }
    }
}

void print_subnet_mask(unsigned int subnet_mask) {
    printf("%u", subnet_mask);
}

void print_subnet(Subnet *subnet) {
    print_ip_address(subnet->subnet_mask);
    printf(" ");
    print_ip_address(subnet->num_hosts);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <ip_address> <subnet_mask>\n", argv[0]);
        return 1;
    }

    IPAddress *ip = get_ip_address(argv[1]);
    if (!is_valid_ip_address(ip)) {
        printf("Invalid IP address: %s\n", argv[1]);
        return 1;
    }

    unsigned int subnet_mask = get_subnet_mask(argv[2]);
    if (!is_valid_subnet_mask(subnet_mask)) {
        printf("Invalid subnet mask: %s\n", argv[2]);
        return 1;
    }

    Subnet subnets[MAX_SUBNETS];
    int num_subnets = 0;

    for (int i = 0; i < MAX_BITS; i++) {
        if (subnet_mask & (1 << i)) {
            Subnet subnet;
            subnet.subnet_mask = subnet_mask & ((1 << i) - 1);
            subnet.num_hosts = (1 << (32 - i)) - 2;
            subnets[num_subnets++] = subnet;
        }
    }

    printf("Subnets:\n");
    for (int i = 0; i < num_subnets; i++) {
        print_subnet(&subnets[i]);
        printf("\n");
    }

    return 0;
}