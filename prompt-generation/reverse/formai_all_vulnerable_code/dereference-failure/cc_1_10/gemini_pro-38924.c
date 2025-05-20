//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IP_ADDR_LEN 16

// Structure to store IP address and subnet mask
typedef struct ip_subnet {
    char ip_addr[IP_ADDR_LEN];
    char subnet_mask[IP_ADDR_LEN];
} ip_subnet_t;

// Function to convert IP address from string to binary
void ip_addr_to_binary(char *ip_addr, char *binary_ip) {
    int i, j;
    char *octet;

    // Split IP address into octets
    octet = strtok(ip_addr, ".");
    for (i = 0; i < 4; i++) {
        // Convert each octet to binary and store in binary_ip
        for (j = 7; j >= 0; j--) {
            binary_ip[i * 8 + j] = (octet[0] & (1 << j)) ? '1' : '0';
        }
        // Get next octet
        octet = strtok(NULL, ".");
    }
}

// Function to convert subnet mask from string to binary
void subnet_mask_to_binary(char *subnet_mask, char *binary_mask) {
    int i, j;

    // Convert subnet mask to binary and store in binary_mask
    for (i = 0; i < 32; i++) {
        binary_mask[i] = (subnet_mask[i / 8] & (1 << (7 - i % 8))) ? '1' : '0';
    }
}

// Function to calculate network address
void calculate_network_address(ip_subnet_t *subnet, char *network_addr) {
    int i;

    // Perform bitwise AND operation between IP address and subnet mask to get network address
    for (i = 0; i < 32; i++) {
        network_addr[i] = subnet->ip_addr[i] & subnet->subnet_mask[i];
    }
}

// Function to calculate broadcast address
void calculate_broadcast_address(ip_subnet_t *subnet, char *broadcast_addr) {
    int i;

    // Perform bitwise OR operation between network address and inverse of subnet mask to get broadcast address
    for (i = 0; i < 32; i++) {
        broadcast_addr[i] = subnet->ip_addr[i] | ~subnet->subnet_mask[i];
    }
}

// Function to calculate number of hosts
int calculate_num_hosts(char *subnet_mask) {
    int num_hosts = 0;
    int i;

    // Count the number of 0s in the subnet mask
    for (i = 0; i < 32; i++) {
        if (subnet_mask[i] == '0') {
            num_hosts++;
        }
    }

    // Return the number of hosts
    return (1 << num_hosts) - 2;
}

// Function to print subnet information
void print_subnet_info(ip_subnet_t *subnet, char *network_addr, char *broadcast_addr, int num_hosts) {
    printf("Subnet Information:\n");
    printf("IP Address: %s\n", subnet->ip_addr);
    printf("Subnet Mask: %s\n", subnet->subnet_mask);
    printf("Network Address: %s\n", network_addr);
    printf("Broadcast Address: %s\n", broadcast_addr);
    printf("Number of Hosts: %d\n", num_hosts);
}

int main() {
    ip_subnet_t subnet;
    char binary_ip[32];
    char binary_mask[32];
    char network_addr[32];
    char broadcast_addr[32];
    int num_hosts;

    // Get IP address and subnet mask from user
    printf("Enter IP address: ");
    scanf("%s", subnet.ip_addr);
    printf("Enter subnet mask: ");
    scanf("%s", subnet.subnet_mask);

    // Convert IP address and subnet mask to binary
    ip_addr_to_binary(subnet.ip_addr, binary_ip);
    subnet_mask_to_binary(subnet.subnet_mask, binary_mask);

    // Calculate network address
    calculate_network_address(&subnet, network_addr);

    // Calculate broadcast address
    calculate_broadcast_address(&subnet, broadcast_addr);

    // Calculate number of hosts
    num_hosts = calculate_num_hosts(binary_mask);

    // Print subnet information
    print_subnet_info(&subnet, network_addr, broadcast_addr, num_hosts);

    return 0;
}