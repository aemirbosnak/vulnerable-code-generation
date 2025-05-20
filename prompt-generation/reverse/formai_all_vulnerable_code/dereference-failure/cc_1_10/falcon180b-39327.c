//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_SUBNETS 32
#define MAX_SUBNET_SIZE 32
#define IP_ADDRESS_LENGTH 4

typedef struct {
    int size;
    int mask;
    char *ip;
} Subnet;

void print_subnet(Subnet subnet) {
    printf("Subnet size: %d\n", subnet.size);
    printf("Subnet mask: %d.%d.%d.%d\n", (subnet.mask >> 24) & 0xFF, (subnet.mask >> 16) & 0xFF, (subnet.mask >> 8) & 0xFF, subnet.mask & 0xFF);
    printf("IP address: %s\n", subnet.ip);
}

void calculate_subnet(int num_subnets, int subnet_size, char *ip_address, Subnet *subnets) {
    int subnet_mask = 0xffffffff;
    int subnet_index = 0;

    while (subnet_index < num_subnets) {
        subnets[subnet_index].size = subnet_size;
        subnets[subnet_index].mask = subnet_mask;
        subnets[subnet_index].ip = malloc(IP_ADDRESS_LENGTH + 1);
        sprintf(subnets[subnet_index].ip, "%s.%d", ip_address, subnet_index + 1);
        subnet_mask += subnet_size;
        subnet_index++;
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <num_subnets> <subnet_size>\n", argv[0]);
        return 1;
    }

    int num_subnets = atoi(argv[1]);
    int subnet_size = atoi(argv[2]);

    if (num_subnets <= 0 || num_subnets > MAX_SUBNETS || subnet_size <= 0 || subnet_size > MAX_SUBNET_SIZE) {
        printf("Invalid input\n");
        return 1;
    }

    Subnet subnets[MAX_SUBNETS];
    calculate_subnet(num_subnets, subnet_size, "192.168.1.0", subnets);

    for (int i = 0; i < num_subnets; i++) {
        print_subnet(subnets[i]);
    }

    return 0;
}