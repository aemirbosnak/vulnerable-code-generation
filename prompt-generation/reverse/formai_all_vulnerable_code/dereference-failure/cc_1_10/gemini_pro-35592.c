//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_IP_ADDR_LEN 16
#define MAX_SUBNET_MASK_LEN 16
#define MAX_CIDR_PREFIX_LEN 3

// Structures
typedef struct {
    unsigned char octets[4];
} IPAddress;

typedef struct {
    unsigned char octets[4];
} SubnetMask;

// Function prototypes
void print_usage(char *argv[]);
int validate_ip_address(char *ip_addr);
int validate_subnet_mask(char *subnet_mask);
int validate_cidr_prefix(char *cidr_prefix);
void calculate_subnet_info(IPAddress *ip_addr, SubnetMask *subnet_mask, int cidr_prefix);
void print_subnet_info(IPAddress *ip_addr, SubnetMask *subnet_mask, int cidr_prefix);

// Main function
int main(int argc, char *argv[]) {
    // Check for the correct number of arguments
    if (argc != 4) {
        print_usage(argv);
        return EXIT_FAILURE;
    }

    // Validate the IP address
    if (!validate_ip_address(argv[1])) {
        printf("Error: Invalid IP address '%s'\n", argv[1]);
        return EXIT_FAILURE;
    }

    // Validate the subnet mask
    if (!validate_subnet_mask(argv[2])) {
        printf("Error: Invalid subnet mask '%s'\n", argv[2]);
        return EXIT_FAILURE;
    }

    // Validate the CIDR prefix
    if (!validate_cidr_prefix(argv[3])) {
        printf("Error: Invalid CIDR prefix '%s'\n", argv[3]);
        return EXIT_FAILURE;
    }

    // Convert the IP address and subnet mask to binary
    IPAddress ip_addr;
    SubnetMask subnet_mask;
    sscanf(argv[1], "%hhu.%hhu.%hhu.%hhu", &ip_addr.octets[0], &ip_addr.octets[1], &ip_addr.octets[2], &ip_addr.octets[3]);
    sscanf(argv[2], "%hhu.%hhu.%hhu.%hhu", &subnet_mask.octets[0], &subnet_mask.octets[1], &subnet_mask.octets[2], &subnet_mask.octets[3]);

    // Calculate the subnet information
    int cidr_prefix = atoi(argv[3]);
    calculate_subnet_info(&ip_addr, &subnet_mask, cidr_prefix);

    // Print the subnet information
    print_subnet_info(&ip_addr, &subnet_mask, cidr_prefix);

    return EXIT_SUCCESS;
}

// Print usage information
void print_usage(char *argv[]) {
    printf("Usage: %s <IP address> <subnet mask> <CIDR prefix>\n", argv[0]);
    printf("Example: %s 192.168.1.0 255.255.255.0 24\n", argv[0]);
}

// Validate IP address
int validate_ip_address(char *ip_addr) {
    char *dot_ptr;
    int octet_count = 0;

    // Check for the correct number of octets
    dot_ptr = strchr(ip_addr, '.');
    while (dot_ptr != NULL) {
        octet_count++;
        dot_ptr = strchr(dot_ptr + 1, '.');
    }
    if (octet_count != 3) {
        return 0;
    }

    // Check for valid octet values
    char *octet_ptr = strtok(ip_addr, ".");
    while (octet_ptr != NULL) {
        int octet = atoi(octet_ptr);
        if (octet < 0 || octet > 255) {
            return 0;
        }
        octet_ptr = strtok(NULL, ".");
    }

    return 1;
}

// Validate subnet mask
int validate_subnet_mask(char *subnet_mask) {
    char *dot_ptr;
    int octet_count = 0;

    // Check for the correct number of octets
    dot_ptr = strchr(subnet_mask, '.');
    while (dot_ptr != NULL) {
        octet_count++;
        dot_ptr = strchr(dot_ptr + 1, '.');
    }
    if (octet_count != 3) {
        return 0;
    }

    // Check for valid octet values
    char *octet_ptr = strtok(subnet_mask, ".");
    while (octet_ptr != NULL) {
        int octet = atoi(octet_ptr);
        if (octet < 0 || octet > 255) {
            return 0;
        }
        octet_ptr = strtok(NULL, ".");
    }

    return 1;
}

// Validate CIDR prefix
int validate_cidr_prefix(char *cidr_prefix) {
    int prefix = atoi(cidr_prefix);

    if (prefix < 0 || prefix > 32) {
        return 0;
    }

    return 1;
}

// Calculate subnet information
void calculate_subnet_info(IPAddress *ip_addr, SubnetMask *subnet_mask, int cidr_prefix) {
    // Calculate the network address
    IPAddress network_addr;
    for (int i = 0; i < 4; i++) {
        network_addr.octets[i] = ip_addr->octets[i] & subnet_mask->octets[i];
    }

    // Calculate the broadcast address
    IPAddress broadcast_addr;
    for (int i = 0; i < 4; i++) {
        broadcast_addr.octets[i] = network_addr.octets[i] | ~subnet_mask->octets[i];
    }

    // Calculate the number of hosts
    int num_hosts = (1 << (32 - cidr_prefix)) - 2;

    // Calculate the wildcard mask
    SubnetMask wildcard_mask;
    for (int i = 0; i < 4; i++) {
        wildcard_mask.octets[i] = ~subnet_mask->octets[i];
    }

    // Calculate the host range
    char host_range[MAX_IP_ADDR_LEN];
    sprintf(host_range, "%hhu.%hhu.%hhu.%hhu - %hhu.%hhu.%hhu.%hhu", network_addr.octets[0], network_addr.octets[1], network_addr.octets[2], network_addr.octets[3] + 1, broadcast_addr.octets[0], broadcast_addr.octets[1], broadcast_addr.octets[2], broadcast_addr.octets[3] - 1);
}

// Print subnet information
void print_subnet_info(IPAddress *ip_addr, SubnetMask *subnet_mask, int cidr_prefix) {
    char ip_addr_str[MAX_IP_ADDR_LEN];
    sprintf(ip_addr_str, "%hhu.%hhu.%hhu.%hhu", ip_addr->octets[0], ip_addr->octets[1], ip_addr->octets[2], ip_addr->octets[3]);

    char subnet_mask_str[MAX_SUBNET_MASK_LEN];
    sprintf(subnet_mask_str, "%hhu.%hhu.%hhu.%hhu", subnet_mask->octets[0], subnet_mask->octets[1], subnet_mask->octets[2], subnet_mask->octets[3]);

    printf("\n");
    printf("IP Address: %s\n", ip_addr_str);
    printf("Subnet Mask: %s\n", subnet_mask_str);
    printf("CIDR Prefix: %d\n", cidr_prefix);
    printf("\n");
}