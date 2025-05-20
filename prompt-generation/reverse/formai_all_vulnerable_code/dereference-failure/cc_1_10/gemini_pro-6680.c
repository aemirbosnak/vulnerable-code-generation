//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

// Define the maximum number of subnets
#define MAX_SUBNETS 10

// Define the structure of a subnet
typedef struct {
    char *name;
    char *address;
    char *netmask;
    int prefix_length;
    int num_hosts;
} subnet_t;

// Define the function to calculate the number of hosts in a subnet
int calculate_num_hosts(int prefix_length) {
    return (1 << (32 - prefix_length)) - 2;
}

// Define the function to print the subnet information
void print_subnet(subnet_t *subnet) {
    printf("Subnet %s:\n", subnet->name);
    printf("    Address: %s\n", subnet->address);
    printf("    Netmask: %s\n", subnet->netmask);
    printf("    Prefix length: %d\n", subnet->prefix_length);
    printf("    Number of hosts: %d\n", subnet->num_hosts);
}

// Define the main function
int main() {
    // Create an array of subnets
    subnet_t subnets[MAX_SUBNETS];

    // Initialize the subnets
    for (int i = 0; i < MAX_SUBNETS; i++) {
        subnets[i].name = NULL;
        subnets[i].address = NULL;
        subnets[i].netmask = NULL;
        subnets[i].prefix_length = 0;
        subnets[i].num_hosts = 0;
    }

    // Get the user input
    printf("Enter the subnet information:\n");
    for (int i = 0; i < MAX_SUBNETS; i++) {
        printf("Subnet %d:\n", i + 1);
        printf("    Name: ");
        scanf("%s", subnets[i].name);
        printf("    Address: ");
        scanf("%s", subnets[i].address);
        printf("    Netmask: ");
        scanf("%s", subnets[i].netmask);
        printf("    Prefix length: ");
        scanf("%d", &subnets[i].prefix_length);

        // Calculate the number of hosts in the subnet
        subnets[i].num_hosts = calculate_num_hosts(subnets[i].prefix_length);
    }

    // Print the subnet information
    printf("\nSubnet information:\n");
    for (int i = 0; i < MAX_SUBNETS; i++) {
        print_subnet(&subnets[i]);
    }

    // Free the memory allocated for the subnets
    for (int i = 0; i < MAX_SUBNETS; i++) {
        free(subnets[i].name);
        free(subnets[i].address);
        free(subnets[i].netmask);
    }

    return 0;
}