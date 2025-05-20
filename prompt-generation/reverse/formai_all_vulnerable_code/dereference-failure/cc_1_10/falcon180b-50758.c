//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 32
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_MASK 32

typedef struct {
    char subnet[MAX_SUBNET_SIZE];
    char mask[MAX_SUBNET_MASK];
    int num_hosts;
} Subnet;

typedef struct {
    int num_subnets;
    Subnet subnets[MAX_SUBNETS];
} SubnetCalculator;

void subnetCalculatorInit(SubnetCalculator* sc) {
    sc->num_subnets = 0;
}

void subnetCalculatorAddSubnet(SubnetCalculator* sc, char* subnet, char* mask, int num_hosts) {
    if (sc->num_subnets >= MAX_SUBNETS) {
        printf("Error: Maximum number of subnets reached.\n");
        return;
    }

    strncpy(sc->subnets[sc->num_subnets].subnet, subnet, MAX_SUBNET_SIZE);
    strncpy(sc->subnets[sc->num_subnets].mask, mask, MAX_SUBNET_MASK);
    sc->subnets[sc->num_subnets].num_hosts = num_hosts;

    sc->num_subnets++;
}

int main(int argc, char** argv) {
    SubnetCalculator sc;
    subnetCalculatorInit(&sc);

    int i;
    for (i = 1; i < argc; i++) {
        char* subnet = argv[i];
        char* mask = strchr(subnet, '/');
        if (mask == NULL) {
            printf("Error: Invalid subnet format.\n");
            return 1;
        }

        *mask = '\0';
        mask++;
        int num_hosts = atoi(mask);

        subnetCalculatorAddSubnet(&sc, subnet, mask, num_hosts);
    }

    printf("Subnet Calculator Results:\n");
    printf("-------------------------\n");

    for (i = 0; i < sc.num_subnets; i++) {
        printf("Subnet %d:\n", i+1);
        printf("  Subnet: %s\n", sc.subnets[i].subnet);
        printf("  Mask:   %s\n", sc.subnets[i].mask);
        printf("  Num Hosts: %d\n", sc.subnets[i].num_hosts);
        printf("\n");
    }

    return 0;
}