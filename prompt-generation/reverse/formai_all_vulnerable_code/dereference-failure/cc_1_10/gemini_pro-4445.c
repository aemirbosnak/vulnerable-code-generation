//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

// Define the maximum number of bits in an IPv4 address
#define MAX_BITS 32

// Define the maximum number of subnets that can be created
#define MAX_SUBNETS 256

// Define the structure of a subnet
typedef struct {
    unsigned int ip_address; // The IP address of the subnet
    unsigned int subnet_mask; // The subnet mask of the subnet
    unsigned int broadcast_address; // The broadcast address of the subnet
    unsigned int number_of_hosts; // The number of hosts in the subnet
} subnet_t;

// Function to calculate the subnet mask for a given number of bits
unsigned int calculate_subnet_mask(unsigned int num_bits) {
    unsigned int subnet_mask = 0;
    for (unsigned int i = 0; i < num_bits; i++) {
        subnet_mask |= (1 << (MAX_BITS - 1 - i));
    }
    return subnet_mask;
}

// Function to calculate the broadcast address for a given IP address and subnet mask
unsigned int calculate_broadcast_address(unsigned int ip_address, unsigned int subnet_mask) {
    unsigned int broadcast_address = ip_address | ~subnet_mask;
    return broadcast_address;
}

// Function to calculate the number of hosts in a given subnet
unsigned int calculate_number_of_hosts(unsigned int subnet_mask) {
    unsigned int number_of_hosts = pow(2, (MAX_BITS - 32 + subnet_mask));
    return number_of_hosts - 2;
}

// Function to create a subnet for a given IP address and number of bits
subnet_t create_subnet(unsigned int ip_address, unsigned int num_bits) {
    subnet_t subnet;
    subnet.ip_address = ip_address;
    subnet.subnet_mask = calculate_subnet_mask(num_bits);
    subnet.broadcast_address = calculate_broadcast_address(ip_address, subnet.subnet_mask);
    subnet.number_of_hosts = calculate_number_of_hosts(subnet.subnet_mask);
    return subnet;
}

// Function to print the details of a given subnet
void print_subnet(subnet_t subnet) {
    printf("IP Address: %u.%u.%u.%u\n",
        (subnet.ip_address >> 24) & 0xFF,
        (subnet.ip_address >> 16) & 0xFF,
        (subnet.ip_address >> 8) & 0xFF,
        subnet.ip_address & 0xFF);
    printf("Subnet Mask: %u.%u.%u.%u\n",
        (subnet.subnet_mask >> 24) & 0xFF,
        (subnet.subnet_mask >> 16) & 0xFF,
        (subnet.subnet_mask >> 8) & 0xFF,
        subnet.subnet_mask & 0xFF);
    printf("Broadcast Address: %u.%u.%u.%u\n",
        (subnet.broadcast_address >> 24) & 0xFF,
        (subnet.broadcast_address >> 16) & 0xFF,
        (subnet.broadcast_address >> 8) & 0xFF,
        subnet.broadcast_address & 0xFF);
    printf("Number of Hosts: %u\n", subnet.number_of_hosts);
}

// Function to create a list of all possible subnets for a given IP address
subnet_t* create_subnet_list(unsigned int ip_address) {
    subnet_t* subnet_list = malloc(sizeof(subnet_t) * MAX_SUBNETS);
    for (unsigned int i = 0; i < MAX_SUBNETS; i++) {
        subnet_list[i] = create_subnet(ip_address, i + 1);
    }
    return subnet_list;
}

// Function to print the list of all possible subnets for a given IP address
void print_subnet_list(subnet_t* subnet_list) {
    for (unsigned int i = 0; i < MAX_SUBNETS; i++) {
        print_subnet(subnet_list[i]);
        printf("\n");
    }
}

// Main function
int main() {
    // Get the IP address from the user
    unsigned int ip_address;
    printf("Enter the IP address: ");
    scanf("%u", &ip_address);

    // Create a list of all possible subnets for the given IP address
    subnet_t* subnet_list = create_subnet_list(ip_address);

    // Print the list of all possible subnets
    print_subnet_list(subnet_list);

    // Free the memory allocated for the subnet list
    free(subnet_list);

    return 0;
}