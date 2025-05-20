//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <arpa/inet.h>

#define MAX_IP_LENGTH 16
#define MAX_CIDR_LENGTH 3

// Function prototypes
void calculate_subnet(const char *ip_str, int cidr);
void display_usage();

int main(int argc, char *argv[]) {
    if (argc != 3) {
        display_usage();
        return 1;
    }

    // Check for a valid IP address and CIDR
    char *ip_str = argv[1];
    int cidr = atoi(argv[2]);

    // Validate the CIDR range
    if (cidr < 0 || cidr > 32) {
        printf("Error: CIDR must be between 0 and 32.\n");
        return 1;
    }

    // Calculate and display the subnet information
    calculate_subnet(ip_str, cidr);
    return 0;
}

void calculate_subnet(const char *ip_str, int cidr) {
    struct in_addr ip_addr;
    if (inet_pton(AF_INET, ip_str, &ip_addr) <= 0) {
        printf("Error: Invalid IP address format.\n");
        return;
    }

    // Create subnet mask from CIDR
    uint32_t mask = (cidr == 0) ? 0 : htonl(~((1 << (32 - cidr)) - 1));
    uint32_t network = htonl(ntohl(ip_addr.s_addr) & ntohl(mask));

    // Prepare output
    struct in_addr subnet_mask_addr;
    subnet_mask_addr.s_addr = mask;

    struct in_addr network_addr;
    network_addr.s_addr = network;

    printf("IP Address: %s\n", ip_str);
    printf("CIDR Notation: /%d\n", cidr);
    printf("Subnet Mask: %s\n", inet_ntoa(subnet_mask_addr));
    printf("Network Address: %s\n", inet_ntoa(network_addr));
    printf("Broadcast Address: %s\n", inet_ntoa((struct in_addr){ .s_addr = ntohl(network) | ~ntohl(mask) }));

    // Calculate the number of valid hosts
    int host_bits = 32 - cidr;
    unsigned long num_hosts = (1UL << host_bits) - 2;  // Subtract 2 for network and broadcast

    printf("Total Number of Valid Hosts: %lu\n", num_hosts);

    // Optionally display the first and last IPs in the subnet range
    struct in_addr first_ip;
    struct in_addr last_ip;

    first_ip.s_addr = htonl(ntohl(network) + 1); // First usable IP
    last_ip.s_addr = htonl(ntohl(network) | ~ntohl(mask) - 1); // Last usable IP

    printf("First Usable IP: %s\n", inet_ntoa(first_ip));
    printf("Last Usable IP: %s\n", inet_ntoa(last_ip));
}

void display_usage() {
    printf("Usage: subnet_calculator <IP address> <CIDR>\n");
    printf("Example: subnet_calculator 192.168.1.1 24\n");
}