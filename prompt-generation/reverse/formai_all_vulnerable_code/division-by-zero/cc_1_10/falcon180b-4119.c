//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 1000

struct subnet {
    char name[20];
    int mask;
    int num_hosts;
    int num_subnets;
    int first_host;
    int last_host;
};

void calculate_subnets(int num_hosts, int num_subnets, int mask, struct subnet *subnets) {
    int hosts_per_subnet = num_hosts / num_subnets;
    int last_subnet_hosts = num_hosts % num_subnets;

    int i = 0;
    while (i < num_subnets) {
        subnets[i].name[0] = '\0';
        sprintf(subnets[i].name, "Subnet %d", i+1);
        subnets[i].mask = mask;
        subnets[i].num_hosts = hosts_per_subnet;
        subnets[i].num_subnets = num_subnets;

        if (i < last_subnet_hosts) {
            subnets[i].num_hosts++;
        }

        subnets[i].first_host = (i * hosts_per_subnet) + 1;
        subnets[i].last_host = subnets[i].first_host + subnets[i].num_hosts - 1;

        i++;
    }
}

void print_subnets(struct subnet *subnets, int num_subnets) {
    for (int i = 0; i < num_subnets; i++) {
        printf("Subnet %d:\n", i+1);
        printf("  Name: %s\n", subnets[i].name);
        printf("  Mask: %d.%d.%d.%d\n", (subnets[i].mask >> 24) & 0xFF, (subnets[i].mask >> 16) & 0xFF, (subnets[i].mask >> 8) & 0xFF, subnets[i].mask & 0xFF);
        printf("  Number of hosts: %d\n", subnets[i].num_hosts);
        printf("  Number of subnets: %d\n", subnets[i].num_subnets);
        printf("  First host: %d\n", subnets[i].first_host);
        printf("  Last host: %d\n\n", subnets[i].last_host);
    }
}

int main() {
    int num_hosts, num_subnets;

    printf("Enter the number of hosts: ");
    scanf("%d", &num_hosts);

    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    if (num_hosts < num_subnets * 2) {
        printf("Error: Not enough hosts for the number of subnets.\n");
        return 1;
    }

    struct subnet subnets[MAX_SUBNETS];
    calculate_subnets(num_hosts, num_subnets, 24, subnets);

    print_subnets(subnets, num_subnets);

    return 0;
}