//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_OCTETS 4
#define MAX_BITS 32

typedef struct {
    unsigned char octets[MAX_OCTETS];
    unsigned int bits;
} IPAddress;

typedef struct {
    IPAddress network;
    IPAddress broadcast;
    IPAddress subnet_mask;
    unsigned int num_hosts;
} SubnetInfo;

void print_usage(char *program_name) {
    printf("Usage: %s <IP address> <subnet mask>\n", program_name);
    printf("Example: %s 192.168.1.0 255.255.255.0\n", program_name);
}

int parse_ip_address(char *ip_address_string, IPAddress *ip_address) {
    char *pch;
    int i;

    pch = strtok(ip_address_string, ".");
    if (pch == NULL) {
        return -1;
    }
    ip_address->octets[0] = atoi(pch);

    for (i = 1; i < MAX_OCTETS; i++) {
        pch = strtok(NULL, ".");
        if (pch == NULL) {
            return -1;
        }
        ip_address->octets[i] = atoi(pch);
    }

    return 0;
}

int parse_subnet_mask(char *subnet_mask_string, IPAddress *subnet_mask) {
    char *pch;
    int i;

    pch = strtok(subnet_mask_string, ".");
    if (pch == NULL) {
        return -1;
    }
    subnet_mask->octets[0] = atoi(pch);

    for (i = 1; i < MAX_OCTETS; i++) {
        pch = strtok(NULL, ".");
        if (pch == NULL) {
            return -1;
        }
        subnet_mask->octets[i] = atoi(pch);
    }

    return 0;
}

int calculate_subnet_info(IPAddress *ip_address, IPAddress *subnet_mask, SubnetInfo *subnet_info) {
    int i;

    // Calculate network address
    for (i = 0; i < MAX_OCTETS; i++) {
        subnet_info->network.octets[i] = ip_address->octets[i] & subnet_mask->octets[i];
    }

    // Calculate broadcast address
    for (i = 0; i < MAX_OCTETS; i++) {
        subnet_info->broadcast.octets[i] = ip_address->octets[i] | ~subnet_mask->octets[i];
    }

    // Calculate subnet mask in binary format
    subnet_info->subnet_mask.bits = 0;
    for (i = 0; i < MAX_OCTETS; i++) {
        subnet_info->subnet_mask.bits += __builtin_popcount(subnet_mask->octets[i]);
    }

    // Calculate number of hosts
    subnet_info->num_hosts = pow(2, MAX_BITS - subnet_info->subnet_mask.bits) - 2;

    return 0;
}

void print_subnet_info(SubnetInfo *subnet_info) {
    int i;

    printf("Network address: ");
    for (i = 0; i < MAX_OCTETS; i++) {
        printf("%d", subnet_info->network.octets[i]);
        if (i < MAX_OCTETS - 1) {
            printf(".");
        }
    }
    printf("\n");

    printf("Broadcast address: ");
    for (i = 0; i < MAX_OCTETS; i++) {
        printf("%d", subnet_info->broadcast.octets[i]);
        if (i < MAX_OCTETS - 1) {
            printf(".");
        }
    }
    printf("\n");

    printf("Subnet mask: ");
    for (i = 0; i < MAX_OCTETS; i++) {
        printf("%d", subnet_info->subnet_mask.octets[i]);
        if (i < MAX_OCTETS - 1) {
            printf(".");
        }
    }
    printf("/%d\n", subnet_info->subnet_mask.bits);

    printf("Number of hosts: %d\n", subnet_info->num_hosts);
}

int main(int argc, char *argv[]) {
    IPAddress ip_address;
    IPAddress subnet_mask;
    SubnetInfo subnet_info;

    if (argc != 3) {
        print_usage(argv[0]);
        return 1;
    }

    if (parse_ip_address(argv[1], &ip_address) != 0) {
        printf("Error parsing IP address.\n");
        return 1;
    }

    if (parse_subnet_mask(argv[2], &subnet_mask) != 0) {
        printf("Error parsing subnet mask.\n");
        return 1;
    }

    if (calculate_subnet_info(&ip_address, &subnet_mask, &subnet_info) != 0) {
        printf("Error calculating subnet information.\n");
        return 1;
    }

    print_subnet_info(&subnet_info);

    return 0;
}