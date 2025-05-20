//Falcon2-11B DATASET v1.0 Category: Subnet Calculator ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to calculate subnet mask
void calculate_subnet_mask(int net_mask, char *result) {
    int i;
    char *ip_address;

    for (i = 0; i < 32; i++) {
        if (net_mask & 1) {
            result[i] = '1';
        } else {
            result[i] = '0';
        }
        net_mask = 1;
    }

    ip_address = (char*)malloc(32 * sizeof(char));
    strcpy(ip_address, result);
    printf("Subnet Mask: %s\n", ip_address);
}

// Function to calculate subnet prefix
int calculate_subnet_prefix(int net_mask) {
    int i;
    int prefix = 0;

    for (i = 0; i < 32; i++) {
        if (net_mask & 1) {
            prefix++;
        }
        net_mask = 1;
    }

    return prefix;
}

// Function to calculate CIDR
void calculate_cidr(int net_mask, int prefix, char *result) {
    int i;
    char *ip_address;

    for (i = 0; i < 32; i++) {
        if (net_mask & 1) {
            result[i] = '1';
        } else {
            result[i] = '0';
        }
        net_mask = 1;
    }

    ip_address = (char*)malloc(32 * sizeof(char));
    strcpy(ip_address, result);
    printf("CIDR: %s/%d\n", ip_address, prefix);
}

int main() {
    int net_mask = 24;
    int prefix = calculate_subnet_prefix(net_mask);
    char result[32];

    calculate_cidr(net_mask, prefix, result);

    return 0;
}