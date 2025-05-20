//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    unsigned int ip_address;
    unsigned int subnet_mask;
    unsigned int network_address;
    unsigned int broadcast_address;
    unsigned int number_of_hosts;
} subnet_info;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <CIDR notation>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *cidr_notation = argv[1];

    // Parse the CIDR notation.
    char *ip_address_string = strtok(cidr_notation, "/");
    char *subnet_mask_string = strtok(NULL, "/");

    if (ip_address_string == NULL || subnet_mask_string == NULL) {
        printf("Invalid CIDR notation: %s\n", cidr_notation);
        return EXIT_FAILURE;
    }

    // Convert the IP address and subnet mask to unsigned integers.
    unsigned int ip_address = inet_addr(ip_address_string);
    unsigned int subnet_mask = inet_addr(subnet_mask_string);

    // Calculate the network address, broadcast address, and number of hosts.
    subnet_info subnet_info = {
        .ip_address = ip_address,
        .subnet_mask = subnet_mask,
        .network_address = ip_address & subnet_mask,
        .broadcast_address = ip_address | ~subnet_mask,
        .number_of_hosts = (1 << (32 - ntohl(subnet_mask))) - 2
    };

    // Print the subnet information.
    printf("IP address: %s\n", ip_address_string);
    printf("Subnet mask: %s\n", subnet_mask_string);
    printf("Network address: %s\n", inet_ntoa(subnet_info.network_address));
    printf("Broadcast address: %s\n", inet_ntoa(subnet_info.broadcast_address));
    printf("Number of hosts: %u\n", subnet_info.number_of_hosts);

    return EXIT_SUCCESS;
}