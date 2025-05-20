//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNET_SIZE 32
#define IP_OCTET_SIZE 3

typedef struct {
    char ip[IP_OCTET_SIZE];
    char mask[IP_OCTET_SIZE];
    char wildcard[IP_OCTET_SIZE];
} Subnet;

void print_subnet(Subnet *subnet) {
    printf("IP Address: %s\n", subnet->ip);
    printf("Subnet Mask: %s\n", subnet->mask);
    printf("Wildcard Mask: %s\n", subnet->wildcard);
}

void calculate_subnet(Subnet *subnet, char *ip, char *mask) {
    int i;
    for (i = 0; i < IP_OCTET_SIZE; i++) {
        subnet->ip[i] = ip[i];
        subnet->mask[i] = mask[i];
    }
    subnet->wildcard[IP_OCTET_SIZE - 1] = '0';
    for (i = IP_OCTET_SIZE - 2; i >= 0; i--) {
        if (subnet->mask[i] == '0') {
            subnet->wildcard[i] = '0';
        } else {
            subnet->wildcard[i] = '1';
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s IPAddress SubnetMask\n", argv[0]);
        return 1;
    }

    Subnet subnet;
    strcpy(subnet.ip, argv[1]);
    strcpy(subnet.mask, argv[2]);

    calculate_subnet(&subnet, subnet.ip, subnet.mask);

    print_subnet(&subnet);

    return 0;
}