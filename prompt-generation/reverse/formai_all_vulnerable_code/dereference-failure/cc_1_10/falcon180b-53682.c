//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 16
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_MASK 32

typedef struct {
    char name[MAX_SUBNET_SIZE];
    char mask[MAX_SUBNET_MASK];
    char *subnets[MAX_SUBNETS];
    int num_subnets;
} Subnet;

Subnet *create_subnet(char *name, char *mask) {
    Subnet *subnet = (Subnet *)malloc(sizeof(Subnet));
    strcpy(subnet->name, name);
    strcpy(subnet->mask, mask);
    subnet->num_subnets = 0;
    return subnet;
}

void add_subnet(Subnet *subnet, char *subnet_name) {
    if (subnet->num_subnets >= MAX_SUBNETS) {
        printf("Error: Maximum number of subnets reached.\n");
        return;
    }
    subnet->subnets[subnet->num_subnets] = (char *)malloc(strlen(subnet_name) + 1);
    strcpy(subnet->subnets[subnet->num_subnets], subnet_name);
    subnet->num_subnets++;
}

void print_subnets(Subnet *subnet) {
    printf("Subnets:\n");
    for (int i = 0; i < subnet->num_subnets; i++) {
        printf("%s\n", subnet->subnets[i]);
    }
}

int main() {
    Subnet *subnet1 = create_subnet("192.168.1.0", "255.255.255.0");
    add_subnet(subnet1, "192.168.1.1");
    add_subnet(subnet1, "192.168.1.2");
    add_subnet(subnet1, "192.168.1.3");
    add_subnet(subnet1, "192.168.1.4");
    print_subnets(subnet1);

    Subnet *subnet2 = create_subnet("10.0.0.0", "255.0.0.0");
    add_subnet(subnet2, "10.0.0.1");
    add_subnet(subnet2, "10.0.0.2");
    add_subnet(subnet2, "10.0.0.3");
    add_subnet(subnet2, "10.0.0.4");
    print_subnets(subnet2);

    return 0;
}