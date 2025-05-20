//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

// Define a structure to hold subnet information
typedef struct {
    char ip[16]; // Store IPv4 address as a string
    char mask[16]; // Store subnet mask as a string
    char network[16]; // Network address
    char broadcast[16]; // Broadcast address
    int host_count; // Number of available hosts
} SubnetInfo;

// Function to convert string IP to binary format and back
int ip_to_binary(const char *ip, uint32_t *binary) {
    return inet_pton(AF_INET, ip, binary);
}

// Function to convert binary format back to string IP
void binary_to_ip(uint32_t binary, char *ip) {
    struct in_addr addr;
    addr.s_addr = htonl(binary);
    strcpy(ip, inet_ntoa(addr));
}

// Function to compute the subnet details
void calculate_subnet(SubnetInfo *subnet) {
    uint32_t ip_binary, mask_binary, network_binary, broadcast_binary;
    
    // Convert IP and subnet mask from string to binary
    if (ip_to_binary(subnet->ip, &ip_binary) != 1 || 
        ip_to_binary(subnet->mask, &mask_binary) != 1) {
        printf("Invalid IP address or subnet mask.\n");
        exit(EXIT_FAILURE);
    }

    // Calculate network address
    network_binary = ip_binary & mask_binary;
    binary_to_ip(network_binary, subnet->network);

    // Calculate broadcast address
    broadcast_binary = network_binary | ~mask_binary;
    binary_to_ip(broadcast_binary, subnet->broadcast);

    // Calculate the number of hosts
    int mask_bits = __builtin_popcount(mask_binary); // Count 1s in mask
    subnet->host_count = (1 << (32 - mask_bits)) - 2; // 2 for network and broadcast addresses
}

// Function to display subnet information
void display_subnet_info(const SubnetInfo *subnet) {
    printf("IP Address: %s\n", subnet->ip);
    printf("Subnet Mask: %s\n", subnet->mask);
    printf("Network Address: %s\n", subnet->network);
    printf("Broadcast Address: %s\n", subnet->broadcast);
    printf("Available Hosts: %d\n", subnet->host_count);
}

// Main function - entry point of the program
int main() {
    SubnetInfo subnet;

    // Prompt user for input
    printf("Enter IP address (e.g., 192.168.1.1): ");
    fgets(subnet.ip, sizeof(subnet.ip), stdin);
    strtok(subnet.ip, "\n"); // Remove newline character
    
    printf("Enter Subnet Mask (e.g., 255.255.255.0): ");
    fgets(subnet.mask, sizeof(subnet.mask), stdin);
    strtok(subnet.mask, "\n"); // Remove newline character

    // Calculate subnet information
    calculate_subnet(&subnet);

    // Display the calculated subnet information
    display_subnet_info(&subnet);

    return EXIT_SUCCESS;
}