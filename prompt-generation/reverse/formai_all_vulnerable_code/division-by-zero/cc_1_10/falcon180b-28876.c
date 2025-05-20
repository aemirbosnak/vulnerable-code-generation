//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 100
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_MASK_LEN 32

typedef struct {
    char name[MAX_SUBNET_SIZE];
    char ip[MAX_SUBNET_SIZE];
    char mask[MAX_SUBNET_MASK_LEN];
    int num_hosts;
} subnet_t;

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <ip address> <subnet mask>\n", argv[0]);
        return 1;
    }

    subnet_t subnets[MAX_SUBNETS];
    int num_subnets = 0;

    char *ip = argv[1];
    char *mask = argv[2];

    int ip_parts[4];
    int mask_parts[4];

    sscanf(ip, "%d.%d.%d.%d", &ip_parts[0], &ip_parts[1], &ip_parts[2], &ip_parts[3]);
    sscanf(mask, "%d.%d.%d.%d", &mask_parts[0], &mask_parts[1], &mask_parts[2], &mask_parts[3]);

    int num_ips = 1 << (32 - mask_parts[3]);
    int num_hosts = num_ips - 1;

    for (int i = 0; i < num_hosts; i++) {
        int ip_part = i / (num_hosts / 256);
        int host_part = i % (num_hosts / 256);

        sprintf(subnets[num_subnets].ip, "%d.%d.%d.%d", ip_parts[0], ip_parts[1], ip_parts[2], (ip_parts[3] & ~mask_parts[3]) | (host_part << (8 - mask_parts[3])));
        sprintf(subnets[num_subnets].mask, "%d.%d.%d.%d", mask_parts[0], mask_parts[1], mask_parts[2], mask_parts[3]);
        subnets[num_subnets].num_hosts = num_hosts;

        num_subnets++;
    }

    printf("Subnet Name\tIP Address\tSubnet Mask\t# of Hosts\n");
    for (int i = 0; i < num_subnets; i++) {
        printf("%-32s %-15s %-15s %d\n", subnets[i].name, subnets[i].ip, subnets[i].mask, subnets[i].num_hosts);
    }

    return 0;
}