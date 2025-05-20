//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the maximum number of bits in an IPv4 address
#define MAX_BITS 32

// Define the maximum number of subnets
#define MAX_SUBNETS 255

// Define the maximum number of hosts per subnet
#define MAX_HOSTS 255

// Define the structure of a subnet
typedef struct {
    unsigned int subnet_address;
    unsigned int subnet_mask;
    unsigned int broadcast_address;
    unsigned int first_usable_host;
    unsigned int last_usable_host;
    unsigned int number_of_hosts;
} subnet_t;

// Function to calculate the subnet mask
unsigned int calculate_subnet_mask(unsigned int prefix_length) {
    return (0xFFFFFFFF << (MAX_BITS - prefix_length));
}

// Function to calculate the broadcast address
unsigned int calculate_broadcast_address(unsigned int subnet_address, unsigned int subnet_mask) {
    return (subnet_address | ~subnet_mask);
}

// Function to calculate the first usable host address
unsigned int calculate_first_usable_host(unsigned int subnet_address) {
    return (subnet_address + 1);
}

// Function to calculate the last usable host address
unsigned int calculate_last_usable_host(unsigned int broadcast_address) {
    return (broadcast_address - 1);
}

// Function to calculate the number of hosts per subnet
unsigned int calculate_number_of_hosts(unsigned int prefix_length) {
    return (pow(2, (MAX_BITS - prefix_length)) - 2);
}

// Function to print the subnet information
void print_subnet_information(subnet_t subnet) {
    printf("Subnet Address: %u.%u.%u.%u\n",
        (subnet.subnet_address >> 24) & 0xFF,
        (subnet.subnet_address >> 16) & 0xFF,
        (subnet.subnet_address >> 8) & 0xFF,
        subnet.subnet_address & 0xFF);
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
    printf("First Usable Host Address: %u.%u.%u.%u\n",
        (subnet.first_usable_host >> 24) & 0xFF,
        (subnet.first_usable_host >> 16) & 0xFF,
        (subnet.first_usable_host >> 8) & 0xFF,
        subnet.first_usable_host & 0xFF);
    printf("Last Usable Host Address: %u.%u.%u.%u\n",
        (subnet.last_usable_host >> 24) & 0xFF,
        (subnet.last_usable_host >> 16) & 0xFF,
        (subnet.last_usable_host >> 8) & 0xFF,
        subnet.last_usable_host & 0xFF);
    printf("Number of Hosts per Subnet: %u\n", subnet.number_of_hosts);
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the user has provided the correct number of arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <prefix length>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Parse the prefix length from the command line argument
    unsigned int prefix_length = atoi(argv[1]);

    // Check if the prefix length is valid
    if (prefix_length < 0 || prefix_length > MAX_BITS) {
        fprintf(stderr, "Invalid prefix length: %u\n", prefix_length);
        return EXIT_FAILURE;
    }

    // Calculate the subnet mask
    unsigned int subnet_mask = calculate_subnet_mask(prefix_length);

    // Calculate the broadcast address
    unsigned int broadcast_address = calculate_broadcast_address(0, subnet_mask);

    // Calculate the first usable host address
    unsigned int first_usable_host = calculate_first_usable_host(0);

    // Calculate the last usable host address
    unsigned int last_usable_host = calculate_last_usable_host(broadcast_address);

    // Calculate the number of hosts per subnet
    unsigned int number_of_hosts = calculate_number_of_hosts(prefix_length);

    // Print the subnet information
    subnet_t subnet = {
        .subnet_address = 0,
        .subnet_mask = subnet_mask,
        .broadcast_address = broadcast_address,
        .first_usable_host = first_usable_host,
        .last_usable_host = last_usable_host,
        .number_of_hosts = number_of_hosts
    };
    print_subnet_information(subnet);

    return EXIT_SUCCESS;
}