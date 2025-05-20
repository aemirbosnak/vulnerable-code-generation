//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10

struct subnet {
    char *ip;
    char *mask;
};

int main(int argc, char **argv) {
    char *ip;
    char *mask;
    char *subnet_ip, *subnet_mask;
    int num_subnets, i;

    if (argc!= 3) {
        printf("Usage: %s <IP address> <subnet mask>\n", argv[0]);
        exit(1);
    }

    ip = argv[1];
    mask = argv[2];

    if (strlen(ip)!= 15 || strlen(mask)!= 15) {
        printf("Invalid IP address or subnet mask\n");
        exit(1);
    }

    num_subnets = 0;
    for (i = 0; i < 32; i++) {
        if (mask[i] == '1') {
            subnet_ip = malloc(16);
            subnet_mask = malloc(16);
            sprintf(subnet_ip, "192.168.%d.%d", (i / 8) + 2, (i % 8) + 1);
            sprintf(subnet_mask, "255.255.255.%d", (i % 8) * 8 + 8);
            printf("%s %s\n", subnet_ip, subnet_mask);
            num_subnets++;
        }
    }

    if (num_subnets == 0) {
        printf("No subnets found\n");
    } else if (num_subnets > MAX_SUBNETS) {
        printf("Too many subnets (maximum %d)\n", MAX_SUBNETS);
    }

    return 0;
}