//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    char ip[16];
    int subnet_bits;
    int host_bits;
    int i, j;
    int subnet_mask[4];
    int host_mask[4];
    char subnet_ip[16];
    char host_ip[16];

    // Get the IP address and subnet bits from command line arguments
    if(argc!= 3) {
        printf("Usage: %s <IP address> <subnet bits>\n", argv[0]);
        exit(1);
    }
    strcpy(ip, argv[1]);
    subnet_bits = atoi(argv[2]);

    // Convert IP address to integer representation
    int ip_int[4];
    for(i=0; i<4; i++) {
        ip_int[i] = atoi(strtok(ip, "."));
    }

    // Calculate the subnet mask
    for(i=0; i<4; i++) {
        subnet_mask[i] = (1 << (8-subnet_bits)) - 1;
    }

    // Calculate the host mask
    for(i=0; i<4; i++) {
        host_mask[i] = ~subnet_mask[i];
    }

    // Convert subnet mask to IP address format
    for(i=0; i<4; i++) {
        sprintf(&subnet_ip[i*3], "%d", subnet_mask[i]);
    }
    subnet_ip[15] = '\0';

    // Calculate the subnet IP address
    for(i=0; i<4; i++) {
        ip_int[i] &= subnet_mask[i];
    }
    for(i=0; i<4; i++) {
        sprintf(&host_ip[i*3], "%d", ip_int[i]);
    }
    host_ip[15] = '\0';

    // Print the results
    printf("IP address: %s\n", ip);
    printf("Subnet mask: %s\n", subnet_ip);
    printf("Subnet IP address: %s\n", host_ip);

    return 0;
}