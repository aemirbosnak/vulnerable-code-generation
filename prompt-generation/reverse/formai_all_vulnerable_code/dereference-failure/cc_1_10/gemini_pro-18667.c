//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store subnet information
typedef struct {
    char *cidr;
    int prefix_length;
    char *network_address;
    char *broadcast_address;
    char *subnet_mask;
    int num_hosts;
} Subnet;

// Function to calculate subnet information
Subnet calculate_subnet(char *cidr) {
    Subnet subnet;

    // Parse the CIDR notation
    char *slash = strchr(cidr, '/');
    if (slash == NULL) {
        fprintf(stderr, "Invalid CIDR notation\n");
        exit(EXIT_FAILURE);
    }

    subnet.cidr = strdup(cidr);
    subnet.prefix_length = atoi(slash + 1);

    // Calculate the network address
    char *ip_address = strtok(cidr, "/");
    char *octets[4];
    for (int i = 0; i < 4; i++) {
        octets[i] = strtok(NULL, ".");
    }

    for (int i = 0; i < 4; i++) {
        int octet = atoi(octets[i]);
        if (i < subnet.prefix_length) {
            subnet.network_address[i] = octet;
        } else {
            subnet.network_address[i] = 0;
        }
    }

    // Calculate the broadcast address
    for (int i = 0; i < 4; i++) {
        int octet = subnet.network_address[i];
        if (i < subnet.prefix_length) {
            subnet.broadcast_address[i] = octet | (255 << (8 - subnet.prefix_length));
        } else {
            subnet.broadcast_address[i] = 255;
        }
    }

    // Calculate the subnet mask
    for (int i = 0; i < 4; i++) {
        int octet = subnet.network_address[i];
        if (i < subnet.prefix_length) {
            subnet.subnet_mask[i] = 255 << (8 - subnet.prefix_length);
        } else {
            subnet.subnet_mask[i] = 0;
        }
    }

    // Calculate the number of hosts
    subnet.num_hosts = pow(2, 32 - subnet.prefix_length) - 2;

    return subnet;
}

// Function to print subnet information
void print_subnet(Subnet subnet) {
    printf("CIDR notation: %s\n", subnet.cidr);
    printf("Prefix length: %d\n", subnet.prefix_length);
    printf("Network address: %s\n", subnet.network_address);
    printf("Broadcast address: %s\n", subnet.broadcast_address);
    printf("Subnet mask: %s\n", subnet.subnet_mask);
    printf("Number of hosts: %d\n", subnet.num_hosts);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <cidr_notation>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    Subnet subnet = calculate_subnet(argv[1]);
    print_subnet(subnet);

    return EXIT_SUCCESS;
}