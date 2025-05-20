//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

// Function to calculate the network address
unsigned int calculate_network_address(unsigned int ip_address, unsigned int subnet_mask) {
    return ip_address & subnet_mask;
}

// Function to calculate the broadcast address
unsigned int calculate_broadcast_address(unsigned int ip_address, unsigned int subnet_mask) {
    return ip_address | ~subnet_mask;
}

// Function to calculate the number of hosts per subnet
unsigned int calculate_num_hosts(unsigned int subnet_mask) {
    return (~subnet_mask) >> 1;
}

// Function to print the subnet information
void print_subnet_info(unsigned int ip_address, unsigned int subnet_mask) {
    unsigned int network_address = calculate_network_address(ip_address, subnet_mask);
    unsigned int broadcast_address = calculate_broadcast_address(ip_address, subnet_mask);
    unsigned int num_hosts = calculate_num_hosts(subnet_mask);

    printf("IP Address: %s\n", inet_ntoa(*(struct in_addr *)&ip_address));
    printf("Subnet Mask: %s\n", inet_ntoa(*(struct in_addr *)&subnet_mask));
    printf("Network Address: %s\n", inet_ntoa(*(struct in_addr *)&network_address));
    printf("Broadcast Address: %s\n", inet_ntoa(*(struct in_addr *)&broadcast_address));
    printf("Number of Hosts per Subnet: %u\n", num_hosts);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <ip_address> <subnet_mask>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Convert the IP address and subnet mask to unsigned integers
    unsigned int ip_address = inet_addr(argv[1]);
    unsigned int subnet_mask = inet_addr(argv[2]);

    // Check if the IP address and subnet mask are valid
    if (ip_address == INADDR_NONE || subnet_mask == INADDR_NONE) {
        printf("Invalid IP address or subnet mask\n");
        return EXIT_FAILURE;
    }

    // Calculate and print the subnet information
    print_subnet_info(ip_address, subnet_mask);

    return EXIT_SUCCESS;
}