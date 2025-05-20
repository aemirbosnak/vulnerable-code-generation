//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the structure of a subnet
typedef struct subnet {
    unsigned int address;
    unsigned int netmask;
    unsigned int broadcast;
    unsigned int usable_hosts;
} subnet_t;

// Function to calculate the subnet mask
unsigned int calculate_netmask(unsigned int prefix_length) {
    return (0xFFFFFFFF << (32 - prefix_length));
}

// Function to calculate the broadcast address
unsigned int calculate_broadcast(unsigned int address, unsigned int netmask) {
    return (address | ~netmask);
}

// Function to calculate the number of usable hosts
unsigned int calculate_usable_hosts(unsigned int netmask) {
    return (pow(2, (32 - netmask)) - 2);
}

// Function to print the subnet information
void print_subnet(subnet_t subnet) {
    printf("Subnet Address: %u.%u.%u.%u\n",
           (subnet.address >> 24) & 0xFF,
           (subnet.address >> 16) & 0xFF,
           (subnet.address >> 8) & 0xFF,
           subnet.address & 0xFF);
    printf("Netmask: %u.%u.%u.%u\n",
           (subnet.netmask >> 24) & 0xFF,
           (subnet.netmask >> 16) & 0xFF,
           (subnet.netmask >> 8) & 0xFF,
           subnet.netmask & 0xFF);
    printf("Broadcast Address: %u.%u.%u.%u\n",
           (subnet.broadcast >> 24) & 0xFF,
           (subnet.broadcast >> 16) & 0xFF,
           (subnet.broadcast >> 8) & 0xFF,
           subnet.broadcast & 0xFF);
    printf("Usable Hosts: %u\n", subnet.usable_hosts);
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the user has provided enough arguments
    if (argc != 3) {
        printf("Usage: %s <IP address> <prefix length>\n", argv[0]);
        return 1;
    }

    // Parse the IP address and prefix length
    unsigned int address = inet_addr(argv[1]);
    unsigned int prefix_length = atoi(argv[2]);

    // Calculate the subnet mask, broadcast address, and number of usable hosts
    unsigned int netmask = calculate_netmask(prefix_length);
    unsigned int broadcast = calculate_broadcast(address, netmask);
    unsigned int usable_hosts = calculate_usable_hosts(netmask);

    // Create a subnet structure
    subnet_t subnet;
    subnet.address = address;
    subnet.netmask = netmask;
    subnet.broadcast = broadcast;
    subnet.usable_hosts = usable_hosts;

    // Print the subnet information
    print_subnet(subnet);

    return 0;
}