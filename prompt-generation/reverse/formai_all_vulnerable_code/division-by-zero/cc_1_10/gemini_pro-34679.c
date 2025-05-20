//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Declare the structure to store the subnet information
typedef struct {
    unsigned int subnet_mask;
    unsigned int network_address;
    unsigned int broadcast_address;
    unsigned int usable_host_range;
    unsigned int number_of_subnets;
    unsigned int number_of_hosts_per_subnet;
} SubnetInfo;

// Function to calculate the subnet information
SubnetInfo calculate_subnet(unsigned int ip_address, unsigned int subnet_mask) {
    SubnetInfo subnet_info;

    // Calculate the network address
    subnet_info.network_address = ip_address & subnet_mask;

    // Calculate the broadcast address
    subnet_info.broadcast_address = subnet_info.network_address | ~subnet_mask;

    // Calculate the usable host range
    subnet_info.usable_host_range = subnet_info.broadcast_address - subnet_info.network_address - 1;

    // Calculate the number of subnets
    subnet_info.number_of_subnets = pow(2, 32 - count_bits(subnet_mask));

    // Calculate the number of hosts per subnet
    subnet_info.number_of_hosts_per_subnet = subnet_info.usable_host_range / subnet_info.number_of_subnets;

    // Return the subnet information
    return subnet_info;
}

// Function to count the number of bits set in a number
int count_bits(unsigned int number) {
    int count = 0;
    while (number) {
        count += number & 1;
        number >>= 1;
    }
    return count;
}

// Function to print the subnet information
void print_subnet_info(SubnetInfo subnet_info) {
    printf("Subnet mask: %u\n", subnet_info.subnet_mask);
    printf("Network address: %u\n", subnet_info.network_address);
    printf("Broadcast address: %u\n", subnet_info.broadcast_address);
    printf("Usable host range: %u\n", subnet_info.usable_host_range);
    printf("Number of subnets: %u\n", subnet_info.number_of_subnets);
    printf("Number of hosts per subnet: %u\n", subnet_info.number_of_hosts_per_subnet);
}

// Main function
int main() {
    // Declare the variables
    unsigned int ip_address, subnet_mask;

    // Get the IP address from the user
    printf("Enter the IP address: ");
    scanf("%u", &ip_address);

    // Get the subnet mask from the user
    printf("Enter the subnet mask: ");
    scanf("%u", &subnet_mask);

    // Calculate the subnet information
    SubnetInfo subnet_info = calculate_subnet(ip_address, subnet_mask);

    // Print the subnet information
    print_subnet_info(subnet_info);

    return 0;
}