//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBNETS 100
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_ADDRESSES 256
#define MAX_SUBNET_MASKS 32

typedef struct {
    char name[MAX_SUBNET_SIZE];
    char address[MAX_SUBNET_ADDRESSES];
    char mask[MAX_SUBNET_MASKS];
    int size;
} subnet_t;

int main(int argc, char *argv[]) {
    int num_subnets = 0;
    subnet_t subnets[MAX_SUBNETS];

    // Parse command line arguments
    if (argc < 3) {
        printf("Usage: %s <subnet_address> <subnet_mask>\n", argv[0]);
        return 1;
    }

    strcpy(subnets[num_subnets].address, argv[1]);
    strcpy(subnets[num_subnets].mask, argv[2]);

    // Determine subnet size
    int i = 0;
    while (subnets[num_subnets].mask[i] == '255' && i < MAX_SUBNET_MASKS) {
        i++;
    }
    subnets[num_subnets].size = i * 8;

    // Calculate subnet addresses and names
    for (int j = 0; j < MAX_SUBNET_ADDRESSES; j++) {
        sprintf(subnets[num_subnets].address + strlen(subnets[num_subnets].address), ".%d", j + 1);
        sprintf(subnets[num_subnets].mask + strlen(subnets[num_subnets].mask), ".%d", subnets[num_subnets].size - i * 8 + 1);
        strcpy(subnets[num_subnets].name, subnets[num_subnets].address);
        strcat(subnets[num_subnets].name, "/");
        strcat(subnets[num_subnets].name, subnets[num_subnets].mask);
        num_subnets++;
    }

    // Print subnet information
    printf("Subnet Addresses:\n");
    for (int k = 0; k < num_subnets; k++) {
        printf("%s\n", subnets[k].address);
    }

    printf("\nSubnet Names:\n");
    for (int l = 0; l < num_subnets; l++) {
        printf("%s\n", subnets[l].name);
    }

    return 0;
}