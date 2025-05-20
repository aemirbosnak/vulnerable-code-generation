//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 256
#define MAX_IP_ADDR_LENGTH 16

typedef struct {
    char ip_addr[MAX_IP_ADDR_LENGTH];
    char subnet_mask[MAX_IP_ADDR_LENGTH];
    char broadcast_addr[MAX_IP_ADDR_LENGTH];
    int num_hosts;
} Subnet;

void print_subnet(Subnet *subnet) {
    printf("IP Address: %s\n", subnet->ip_addr);
    printf("Subnet Mask: %s\n", subnet->subnet_mask);
    printf("Broadcast Address: %s\n", subnet->broadcast_addr);
    printf("Number of Hosts: %d\n\n", subnet->num_hosts);
}

int main() {
    int num_subnets;
    Subnet subnets[MAX_SUBNETS];
    char input_ip[MAX_IP_ADDR_LENGTH];
    char input_subnet_mask[MAX_IP_ADDR_LENGTH];
    char input_broadcast_addr[MAX_IP_ADDR_LENGTH];
    int input_num_hosts;

    // Get number of subnets from user
    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    // Get subnet information for each subnet
    for (int i = 0; i < num_subnets; i++) {
        printf("\nSubnet %d:\n", i+1);

        // Get IP address from user
        printf("Enter the IP address: ");
        scanf("%s", input_ip);
        strcpy(subnets[i].ip_addr, input_ip);

        // Get subnet mask from user
        printf("Enter the subnet mask: ");
        scanf("%s", input_subnet_mask);
        strcpy(subnets[i].subnet_mask, input_subnet_mask);

        // Calculate broadcast address
        char *dot = strchr(subnets[i].ip_addr, '.');
        int last_octet = atoi(dot+1);
        sprintf(subnets[i].broadcast_addr, "%s.%d", subnets[i].ip_addr, last_octet + subnets[i].num_hosts - 1);

        // Get number of hosts from user
        printf("Enter the number of hosts: ");
        scanf("%d", &input_num_hosts);
        subnets[i].num_hosts = input_num_hosts;
    }

    // Print subnet information for each subnet
    for (int i = 0; i < num_subnets; i++) {
        print_subnet(&subnets[i]);
    }

    return 0;
}