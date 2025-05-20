//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>

// Structure to hold subnet information
typedef struct subnet {
    struct in_addr network_address;
    struct in_addr broadcast_address;
    struct in_addr subnet_mask;
    uint32_t prefix_length;
    uint32_t num_hosts;
} subnet_t;

// Function to calculate subnet information
int calculate_subnet(const char *ip_address, const char *prefix_length, subnet_t *subnet) {
    // Validate input
    if (ip_address == NULL || prefix_length == NULL || subnet == NULL) {
        return -1;
    }

    // Convert IP address to binary
    struct in_addr ip_binary;
    if (inet_aton(ip_address, &ip_binary) == 0) {
        return -2;
    }

    // Convert prefix length to integer
    int prefix_length_int = atoi(prefix_length);
    if (prefix_length_int < 0 || prefix_length_int > 32) {
        return -3;
    }

    // Calculate network address
    subnet->network_address.s_addr = ip_binary.s_addr & htonl(0xFFFFFFFF << (32 - prefix_length_int));

    // Calculate broadcast address
    subnet->broadcast_address.s_addr = ip_binary.s_addr | htonl(0xFFFFFFFF >> prefix_length_int);

    // Calculate subnet mask
    subnet->subnet_mask.s_addr = htonl(0xFFFFFFFF << (32 - prefix_length_int));

    // Set prefix length
    subnet->prefix_length = prefix_length_int;

    // Calculate number of hosts
    subnet->num_hosts = (1 << (32 - prefix_length_int)) - 2;

    return 0;
}

// Function to print subnet information
void print_subnet(const subnet_t *subnet) {
    if (subnet == NULL) {
        return;
    }

    // Convert IP addresses to strings
    char network_address_str[INET_ADDRSTRLEN];
    char broadcast_address_str[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &subnet->network_address, network_address_str, INET_ADDRSTRLEN);
    inet_ntop(AF_INET, &subnet->broadcast_address, broadcast_address_str, INET_ADDRSTRLEN);

    // Print subnet information
    printf("Network Address: %s\n", network_address_str);
    printf("Broadcast Address: %s\n", broadcast_address_str);
    printf("Subnet Mask: %s\n", inet_ntoa(subnet->subnet_mask));
    printf("Prefix Length: %u\n", subnet->prefix_length);
    printf("Number of Hosts: %u\n", subnet->num_hosts);
}

// Main function
int main(int argc, char **argv) {
    // Check if arguments are provided
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <IP Address> <Prefix Length>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Allocate subnet structure
    subnet_t *subnet = malloc(sizeof(subnet_t));
    if (subnet == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    // Calculate subnet information
    int status = calculate_subnet(argv[1], argv[2], subnet);
    if (status != 0) {
        fprintf(stderr, "Error calculating subnet: %d\n", status);
        free(subnet);
        return EXIT_FAILURE;
    }

    // Print subnet information
    print_subnet(subnet);

    // Free subnet structure
    free(subnet);

    return EXIT_SUCCESS;
}