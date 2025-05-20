//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_MASK 32

typedef struct {
    char subnet[MAX_SUBNET_SIZE];
    char subnet_mask[MAX_SUBNET_MASK];
    int num_hosts;
} subnet_t;

void calculate_subnets(int num_subnets, int num_hosts, char *ip_address) {
    subnet_t subnets[MAX_SUBNETS];
    int i, j, k, n;
    char *subnet_ip;
    char *subnet_mask;

    // Initialize the first subnet
    strcpy(subnets[0].subnet, ip_address);
    subnets[0].subnet_mask[0] = '\0';
    subnets[0].num_hosts = num_hosts;

    // Calculate the remaining subnets
    for (i = 1; i < num_subnets; i++) {
        // Calculate the subnet IP address
        subnet_ip = malloc(MAX_SUBNET_SIZE);
        strcpy(subnet_ip, ip_address);
        n = atoi(strtok(subnet_ip, "."));
        n++;
        sprintf(subnet_ip, "%d.%d.%d.%d", n >> 24, (n >> 16) & 0xFF, (n >> 8) & 0xFF, n & 0xFF);

        // Calculate the subnet mask
        subnet_mask = malloc(MAX_SUBNET_MASK);
        for (j = 0; j < strlen(subnets[i-1].subnet_mask); j++) {
            if (subnets[i-1].subnet_mask[j] == '1') {
                strcat(subnet_mask, "1");
            } else {
                strcat(subnet_mask, "0");
            }
        }

        // Calculate the number of hosts in the subnet
        k = 0;
        for (j = 0; j < strlen(subnet_mask); j++) {
            if (subnet_mask[j] == '1') {
                k++;
            }
        }
        subnets[i].num_hosts = num_hosts / k;

        // Store the subnet information
        strcpy(subnets[i].subnet, subnet_ip);
        strcpy(subnets[i].subnet_mask, subnet_mask);
        free(subnet_ip);
        free(subnet_mask);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <IP address> <subnet mask> <number of subnets>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    char *subnet_mask = argv[2];
    int num_subnets = atoi(argv[3]);

    int num_hosts = 0;
    char *endptr;
    num_hosts = strtol(subnet_mask, &endptr, 10);

    calculate_subnets(num_subnets, num_hosts, ip_address);

    return 0;
}