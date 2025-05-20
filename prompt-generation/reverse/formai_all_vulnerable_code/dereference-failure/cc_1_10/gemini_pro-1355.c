//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_IP_ADDR_LEN 16 // Longest possible IPv4 address (e.g., "255.255.255.255")
#define MAX_SUBNET_MASK_LEN 16 // Longest possible subnet mask (e.g., "255.255.255.0")
#define MAX_CIDR_LEN 32 // Maximum number of bits in an IPv4 address

// Function prototypes
int parse_ip_addr(char *ip_addr, unsigned int *ip_addr_num);
int parse_subnet_mask(char *subnet_mask, unsigned int *subnet_mask_num);
int calculate_cidr_prefix(unsigned int subnet_mask_num);
void print_subnet_info(unsigned int ip_addr_num, unsigned int subnet_mask_num, int cidr_prefix);

// Main function
int main(int argc, char *argv[]) {
    // Check for valid number of arguments
    if (argc != 3) {
        printf("Usage: <program_name> <IP address> <subnet mask>\n");
        return EXIT_FAILURE;
    }

    // Parse the IP address
    unsigned int ip_addr_num;
    if (parse_ip_addr(argv[1], &ip_addr_num) != 0) {
        printf("Error: Invalid IP address\n");
        return EXIT_FAILURE;
    }

    // Parse the subnet mask
    unsigned int subnet_mask_num;
    if (parse_subnet_mask(argv[2], &subnet_mask_num) != 0) {
        printf("Error: Invalid subnet mask\n");
        return EXIT_FAILURE;
    }

    // Calculate the CIDR prefix
    int cidr_prefix = calculate_cidr_prefix(subnet_mask_num);

    // Print the subnet information
    print_subnet_info(ip_addr_num, subnet_mask_num, cidr_prefix);

    return EXIT_SUCCESS;
}

// Parse an IPv4 address string into a 32-bit unsigned integer
int parse_ip_addr(char *ip_addr, unsigned int *ip_addr_num) {
    // Check for NULL input
    if (ip_addr == NULL || ip_addr_num == NULL) {
        return -1;
    }

    // Split the IP address into octets
    char *octets[4];
    int num_octets = 0;
    char *p = strtok(ip_addr, ".");
    while (p != NULL && num_octets < 4) {
        octets[num_octets++] = p;
        p = strtok(NULL, ".");
    }

    // Check for valid number of octets
    if (num_octets != 4) {
        return -1;
    }

    // Convert each octet to an unsigned integer
    for (int i = 0; i < 4; i++) {
        int octet_value = atoi(octets[i]);
        if (octet_value < 0 || octet_value > 255) {
            return -1;
        }
        *ip_addr_num |= octet_value << (24 - 8 * i);
    }

    return 0;
}

// Parse a subnet mask string into a 32-bit unsigned integer
int parse_subnet_mask(char *subnet_mask, unsigned int *subnet_mask_num) {
    // Check for NULL input
    if (subnet_mask == NULL || subnet_mask_num == NULL) {
        return -1;
    }

    // Split the subnet mask into octets
    char *octets[4];
    int num_octets = 0;
    char *p = strtok(subnet_mask, ".");
    while (p != NULL && num_octets < 4) {
        octets[num_octets++] = p;
        p = strtok(NULL, ".");
    }

    // Check for valid number of octets
    if (num_octets != 4) {
        return -1;
    }

    // Convert each octet to an unsigned integer
    for (int i = 0; i < 4; i++) {
        int octet_value = atoi(octets[i]);
        if (octet_value < 0 || octet_value > 255) {
            return -1;
        }
        *subnet_mask_num |= octet_value << (24 - 8 * i);
    }

    return 0;
}

// Calculate the CIDR prefix from a subnet mask
int calculate_cidr_prefix(unsigned int subnet_mask_num) {
    int cidr_prefix = 0;

    // Count the number of consecutive 1s in the subnet mask
    while (subnet_mask_num & (1 << (31 - cidr_prefix))) {
        cidr_prefix++;
    }

    return cidr_prefix;
}

// Print the subnet information
void print_subnet_info(unsigned int ip_addr_num, unsigned int subnet_mask_num, int cidr_prefix) {
    // Convert IP address to dotted-decimal notation
    char ip_addr_str[MAX_IP_ADDR_LEN];
    sprintf(ip_addr_str, "%d.%d.%d.%d",
            (ip_addr_num >> 24) & 0xFF,
            (ip_addr_num >> 16) & 0xFF,
            (ip_addr_num >> 8) & 0xFF,
            ip_addr_num & 0xFF);

    // Convert subnet mask to dotted-decimal notation
    char subnet_mask_str[MAX_SUBNET_MASK_LEN];
    sprintf(subnet_mask_str, "%d.%d.%d.%d",
            (subnet_mask_num >> 24) & 0xFF,
            (subnet_mask_num >> 16) & 0xFF,
            (subnet_mask_num >> 8) & 0xFF,
            subnet_mask_num & 0xFF);

    // Print the subnet information
    printf("IP address: %s\n", ip_addr_str);
    printf("Subnet mask: %s\n", subnet_mask_str);
    printf("CIDR prefix: %d\n", cidr_prefix);
}