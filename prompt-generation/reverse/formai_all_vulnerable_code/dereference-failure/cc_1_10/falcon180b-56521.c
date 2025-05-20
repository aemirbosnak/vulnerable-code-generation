//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 1000

typedef struct {
    char *name;
    int num_hosts;
    int subnet_mask;
    int num_subnets;
} Subnet;

void add_subnet(Subnet *subnets, int num_subnets, char *name, int num_hosts, int subnet_mask) {
    if (num_subnets >= MAX_SUBNETS) {
        printf("Error: Maximum number of subnets reached.\n");
        exit(1);
    }

    subnets[num_subnets].name = strdup(name);
    subnets[num_subnets].num_hosts = num_hosts;
    subnets[num_subnets].subnet_mask = subnet_mask;
    subnets[num_subnets].num_subnets = 0;

    num_subnets++;
}

void print_subnets(Subnet *subnets, int num_subnets) {
    for (int i = 0; i < num_subnets; i++) {
        printf("Subnet %d:\n", i + 1);
        printf("  Name: %s\n", subnets[i].name);
        printf("  Number of hosts: %d\n", subnets[i].num_hosts);
        printf("  Subnet mask: %d.%d.%d.%d\n\n", 
            (subnets[i].subnet_mask >> 24) & 0xFF,
            (subnets[i].subnet_mask >> 16) & 0xFF,
            (subnets[i].subnet_mask >> 8) & 0xFF,
            subnets[i].subnet_mask & 0xFF);
    }
}

int main() {
    Subnet subnets[MAX_SUBNETS];
    int num_subnets = 0;

    add_subnet(subnets, num_subnets, "Subnet 1", 254, 0xffffff00);
    add_subnet(subnets, num_subnets, "Subnet 2", 126, 0xffffff80);
    add_subnet(subnets, num_subnets, "Subnet 3", 62, 0xfffffc00);

    print_subnets(subnets, num_subnets);

    return 0;
}