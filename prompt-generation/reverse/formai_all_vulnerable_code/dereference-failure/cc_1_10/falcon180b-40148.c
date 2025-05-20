//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *ip;
    int subnet_mask;
} Subnet;

Subnet *create_subnet(char *ip, int subnet_mask) {
    Subnet *subnet = (Subnet *)malloc(sizeof(Subnet));
    if (subnet == NULL) {
        printf("Failed to allocate memory.\n");
        exit(1);
    }

    subnet->ip = strdup(ip);
    subnet->subnet_mask = subnet_mask;

    return subnet;
}

void print_subnet(Subnet *subnet) {
    printf("IP: %s\n", subnet->ip);
    printf("Subnet mask: %d\n", subnet->subnet_mask);
}

void destroy_subnet(Subnet *subnet) {
    free(subnet->ip);
    free(subnet);
}

int main() {
    Subnet *subnets[MAX_SIZE];
    int num_subnets = 0;

    char *ip = "192.168.0.0";
    int subnet_mask = 24;
    subnets[num_subnets++] = create_subnet(ip, subnet_mask);

    ip = "10.0.0.0";
    subnet_mask = 16;
    subnets[num_subnets++] = create_subnet(ip, subnet_mask);

    for (int i = 0; i < num_subnets; i++) {
        print_subnet(subnets[i]);
    }

    for (int i = 0; i < num_subnets; i++) {
        destroy_subnet(subnets[i]);
    }

    return 0;
}