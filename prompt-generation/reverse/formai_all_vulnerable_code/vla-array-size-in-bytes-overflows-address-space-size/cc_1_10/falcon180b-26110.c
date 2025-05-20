//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 100

struct subnet {
    char name[20];
    int mask;
    int num_hosts;
    int num_subnets;
};

void print_subnet(struct subnet subnet) {
    printf("Subnet Name: %s\n", subnet.name);
    printf("Subnet Mask: %d.%d.%d.%d\n", (subnet.mask >> 24) & 0xFF, (subnet.mask >> 16) & 0xFF, (subnet.mask >> 8) & 0xFF, subnet.mask & 0xFF);
    printf("Number of Hosts: %d\n", subnet.num_hosts);
    printf("Number of Subnets: %d\n\n", subnet.num_subnets);
}

int main() {
    int num_subnets, i;

    printf("Enter the number of subnets (1-%d): ", MAX_SUBNETS);
    scanf("%d", &num_subnets);

    struct subnet subnets[num_subnets];

    for (i = 0; i < num_subnets; i++) {
        printf("Enter subnet %d name: ", i+1);
        scanf("%s", subnets[i].name);

        printf("Enter subnet %d mask: ", i+1);
        scanf("%d", &subnets[i].mask);

        printf("Enter subnet %d number of hosts: ", i+1);
        scanf("%d", &subnets[i].num_hosts);

        printf("Enter subnet %d number of subnets: ", i+1);
        scanf("%d", &subnets[i].num_subnets);
    }

    printf("\n");

    for (i = 0; i < num_subnets; i++) {
        print_subnet(subnets[i]);
    }

    return 0;
}