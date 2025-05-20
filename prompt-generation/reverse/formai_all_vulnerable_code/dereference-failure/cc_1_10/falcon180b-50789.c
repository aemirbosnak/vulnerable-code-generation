//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SUBNETS 100
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_MASK_SIZE 32

typedef struct {
    char *name;
    int size;
    char *mask;
    int num_hosts;
} Subnet;

void print_subnet(Subnet *subnet) {
    printf("Subnet Name: %s\n", subnet->name);
    printf("Subnet Size: %d\n", subnet->size);
    printf("Subnet Mask: %s\n", subnet->mask);
    printf("Number of Hosts: %d\n", subnet->num_hosts);
}

int main() {
    int num_subnets, i;
    Subnet subnets[MAX_SUBNETS];

    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    for (i = 0; i < num_subnets; i++) {
        subnets[i].name = malloc(MAX_SUBNET_SIZE * sizeof(char));
        subnets[i].mask = malloc(MAX_SUBNET_MASK_SIZE * sizeof(char));

        printf("Enter the name of subnet %d: ", i+1);
        scanf("%s", subnets[i].name);

        printf("Enter the size of subnet %d: ", i+1);
        scanf("%d", &subnets[i].size);

        int j;
        for (j = 0; j < subnets[i].size; j++) {
            printf("Enter the %dth bit of the subnet mask for subnet %d: ", j, i+1);
            scanf("%d", &subnets[i].mask[j]);
        }

        subnets[i].mask[subnets[i].size] = '\0';
        subnets[i].num_hosts = pow(2, subnets[i].size) - 2; // subtract 2 for network and broadcast addresses
    }

    printf("Subnet Information:\n");
    for (i = 0; i < num_subnets; i++) {
        print_subnet(&subnets[i]);
    }

    return 0;
}