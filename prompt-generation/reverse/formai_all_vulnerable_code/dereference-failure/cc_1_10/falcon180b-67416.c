//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 100
#define MAX_SUBNET_SIZE 32

typedef struct {
    char subnet_address[MAX_SUBNET_SIZE];
    char subnet_mask[MAX_SUBNET_SIZE];
    char first_host[MAX_SUBNET_SIZE];
    char last_host[MAX_SUBNET_SIZE];
    char broadcast_address[MAX_SUBNET_SIZE];
} Subnet;

void print_subnet_info(Subnet *subnet) {
    printf("Subnet Address: %s\n", subnet->subnet_address);
    printf("Subnet Mask: %s\n", subnet->subnet_mask);
    printf("First Host: %s\n", subnet->first_host);
    printf("Last Host: %s\n", subnet->last_host);
    printf("Broadcast Address: %s\n", subnet->broadcast_address);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <IP Address>\n", argv[0]);
        return 1;
    }

    Subnet subnets[MAX_SUBNETS];
    int num_subnets = 0;

    char *ip_address = argv[1];
    int num_octets = 0;
    char *token = strtok(ip_address, ".");
    while (token!= NULL) {
        num_octets++;
        token = strtok(NULL, ".");
    }

    if (num_octets!= 4) {
        printf("Invalid IP Address\n");
        return 1;
    }

    int subnet_size = 0;
    printf("Enter subnet size (1-32): ");
    scanf("%d", &subnet_size);

    if (subnet_size < 1 || subnet_size > 32) {
        printf("Invalid subnet size\n");
        return 1;
    }

    char subnet_address[MAX_SUBNET_SIZE];
    strcpy(subnet_address, ip_address);

    int subnet_mask_size = 32 - subnet_size;
    char subnet_mask[MAX_SUBNET_SIZE];
    memset(subnet_mask, '1', subnet_mask_size);
    memset(subnet_mask + subnet_mask_size, '0', subnet_size);

    char first_host[MAX_SUBNET_SIZE];
    char last_host[MAX_SUBNET_SIZE];
    char broadcast_address[MAX_SUBNET_SIZE];

    strcpy(first_host, subnet_address);
    strcat(first_host, "1");

    strcpy(last_host, subnet_address);
    strcat(last_host, "254");

    strcpy(broadcast_address, subnet_address);
    strcat(broadcast_address, "255");

    printf("\nSubnet Information:\n");
    print_subnet_info(&subnets[num_subnets]);

    return 0;
}