//Falcon2-11B DATASET v1.0 Category: Subnet Calculator ; Style: asynchronous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SUBNET_LEN 16

int calculate_subnet(char* subnet, int subnet_length) {
    int last_octet, cidr_bits, total_bits, hosts_per_octet;
    int i, j, host_bits, subnet_bits;

    last_octet = atoi(subnet + subnet_length - 1);
    if (last_octet <= 0 || last_octet >= 255) {
        printf("Invalid subnet mask\n");
        return -1;
    }

    cidr_bits = (8 * subnet_length) - 2;
    total_bits = 32 - cidr_bits;

    host_bits = (8 * (32 - cidr_bits)) - 1;
    subnet_bits = (8 * cidr_bits) - 1;

    hosts_per_octet = (1 << subnet_bits) - 1;

    for (i = 0; i < subnet_length; i++) {
        for (j = 0; j < 8; j++) {
            if (subnet[i] & (1 << j)) {
                break;
            }
        }

        if (j < 8) {
            host_bits = host_bits - 1 << j;
            hosts_per_octet = hosts_per_octet + 1;
        }
    }

    printf("Number of hosts in subnet: %d\n", hosts_per_octet);
    return 0;
}

int main() {
    char subnet[MAX_SUBNET_LEN + 1];
    int subnet_length;

    printf("Enter the subnet mask in the form of 'x.x.x.x' (255.255.255.0 for /24 subnet): ");
    fgets(subnet, sizeof(subnet), stdin);
    subnet[strcspn(subnet, "\n")] = '\0';

    subnet_length = strlen(subnet);
    if (subnet_length > MAX_SUBNET_LEN) {
        printf("Subnet mask is too long\n");
        return -1;
    }

    if (calculate_subnet(subnet, subnet_length) == -1) {
        return -1;
    }

    return 0;
}